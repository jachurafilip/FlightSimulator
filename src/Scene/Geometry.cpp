#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Geometry.h"
#include <algorithm>

GLuint defaultVAO, defaultVBO, defaultNBO, defaultEBO;
GLuint vertexshader, fragmentshader, shaderprogram;
GLuint modelviewPos;
glm::mat4 model;
shape lastUsed = NONE;

std::vector <glm::vec3> modelVertices;
std::vector <glm::vec3> modelNormals;
std::vector <unsigned int> modelIndices;


void initBufferObjects() {
	glGenVertexArrays(1, &defaultVAO);
	glGenBuffers(1, &defaultVBO);
	glGenBuffers(1, &defaultNBO);
	glGenBuffers(1, &defaultEBO);
}


void destroyBufferObjects() {
	glDeleteVertexArrays(1, &defaultVAO);
	glDeleteBuffers(1, &defaultVBO);
	glDeleteBuffers(1, &defaultNBO);
	glDeleteBuffers(1, &defaultEBO);
}

// OBJ file parser func
void parse(const char * filepath) {
	FILE* fp;
	float x, y, z;
	int fx, fy, fz, ignore;
	int c1, c2;
	float minY = INFINITY, minZ = INFINITY;
	float maxY = -INFINITY, maxZ = -INFINITY;

	fp = fopen(filepath, "rb");

	if (fp == NULL) {
		std::cerr << "Error loading file: " << filepath << std::endl;
		std::getchar();
		exit(-1);
	}

	while (!feof(fp)) {
		c1 = fgetc(fp);
		while (!(c1 == 'v' || c1 == 'f')) {
			c1 = fgetc(fp);
			if (feof(fp))
				break;
		}
		c2 = fgetc(fp);

		if ((c1 == 'v') && (c2 == ' ')) {
			fscanf(fp, "%f %f %f", &x, &y, &z);
			modelVertices.push_back(glm::vec3(x, y, z));
			if (y < minY) minY = y;
			if (z < minZ) minZ = z;
			if (y > maxY) maxY = y;
			if (z > maxZ) maxZ = z;
		}
		else if ((c1 == 'v') && (c2 == 'n')) {
			fscanf(fp, "%f %f %f", &x, &y, &z);
			modelNormals.push_back(glm::normalize(glm::vec3(x, y, z)));
		}
		else if (c1 == 'f')
		{
			fscanf(fp, "%d//%d %d//%d %d//%d", &fx, &ignore, &fy, &ignore, &fz, &ignore);
			modelIndices.push_back(fx - 1);
			modelIndices.push_back(fy - 1);
			modelIndices.push_back(fz - 1);
		}
	}

	fclose(fp);
	float avgY = (minY + maxY) / 2.0f - 0.0234f;
	float avgZ = (minZ + maxZ) / 2.0f;
	for (unsigned int i = 0; i < modelVertices.size(); ++i) {
		glm::vec3 shiftedVertex = (modelVertices[i] - glm::vec3(0.0f, avgY, avgZ)) * glm::vec3(0.975f, 0.975f, 0.975f);
		modelVertices[i] = shiftedVertex;
	}
}

void bindModel() {
	glBindVertexArray(defaultVAO);

	glBindBuffer(GL_ARRAY_BUFFER, defaultVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * modelVertices.size(), &modelVertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0); // This allows usage of layout location 0 in the vertex shader
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	glBindBuffer(GL_ARRAY_BUFFER, defaultNBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * modelNormals.size(), &modelNormals[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1); // This allows usage of layout location 1 in the vertex shader
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, defaultEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * modelIndices.size(), &modelIndices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	lastUsed = PLANE;
}

void solidModel(float size) {
	model = glm::scale(glm::mat4(1.0f), glm::vec3(size, size, size));
	glUniformMatrix4fv(modelviewPos, 1, GL_FALSE, &(view * model)[0][0]);
    bindModel();

	glBindVertexArray(defaultVAO);
	glDrawElements(GL_TRIANGLES , modelIndices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0); // Unbind the VAO when done
}

void pitch(double angle) {
    for(auto &v: modelVertices)
    {
        auto v0 = v[0], v1 = v[1];
        v[0] = v0 * cos(angle)-v1*sin(angle);
        v[1] = v0 * sin(angle)+v1*cos(angle);
    }


}

void roll(double angle) {
    for(auto &v: modelVertices)
    {
        auto v0 = v[1], v1 = v[2];
        v[1] = v0 * cos(angle)-v1*sin(angle);
        v[2] = v0 * sin(angle)+v1*cos(angle);
    }

}

void yaw(double angle)
{
    for(auto &v: modelVertices)
    {
        auto v0 = v[2], v1 = v[0];
        v[2] = v0 * cos(angle)-v1*sin(angle);
        v[0] = v0 * sin(angle)+v1*cos(angle);
    }
}
