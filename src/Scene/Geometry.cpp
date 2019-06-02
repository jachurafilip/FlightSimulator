#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Geometry.h"
#include <vector>
#include <algorithm>
#include <../lib/SOIL/src/SOIL.h>


GLfloat texCoords[] = {
        0.0f, 0.0f,  // Lower-left corner
        1.0f, 0.0f,  // Lower-right corner
        0.5f, 1.0f   // Top-center corner
};
GLuint texture;


GLuint defaultVAO, defaultVBO, defaultNBO, defaultEBO;
GLuint floorVAO, floorVBO, floorNBO, floorEBO, floorTBO;
GLuint vertexshader, fragmentshader, shaderprogram;
GLuint modelviewPos;
GLuint floorviewPos, colorPos;
glm::mat4 model;
glm::mat4 floorModel;
shape lastUsed = NONE;

GLuint texNames[1] ;
GLuint istex ;


void initBufferObjects() {
	glGenVertexArrays(1, &defaultVAO);
	glGenBuffers(1, &defaultVBO);
	glGenBuffers(1, &defaultNBO);
	glGenBuffers(1, &defaultEBO);
    glGenVertexArrays(1, &floorVAO);
    glGenBuffers(1, &floorVBO);
    glGenBuffers(1, &floorNBO);
    glGenBuffers(1, &floorEBO);
}


void destroyBufferObjects() {
	glDeleteVertexArrays(1, &defaultVAO);
	glDeleteBuffers(1, &defaultVBO);
	glDeleteBuffers(1, &defaultNBO);
	glDeleteBuffers(1, &defaultEBO);
    glDeleteVertexArrays(1, &floorVAO);
    glDeleteBuffers(1, &floorVBO);
    glDeleteBuffers(1, &floorNBO);
    glDeleteBuffers(1, &floorEBO);
}

// OBJ file parser func
void parse(const char * filepath, std::vector<glm::vec3>& modelVertices,std::vector<glm::vec3>& modelNormals,std::vector<unsigned int>& modelIndices) {
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
			modelIndices.push_back(fx -1);
			modelIndices.push_back(fy -1);
			modelIndices.push_back(fz -1);
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

void bindModel(std::vector<glm::vec3>& modelVertices,std::vector<glm::vec3>& modelNormals,std::vector<unsigned int>& modelIndices) {
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



void solidModel(float size,std::vector<glm::vec3>& modelVertices,std::vector<glm::vec3>& modelNormals,std::vector<unsigned int>& modelIndices) {
    model = glm::scale(glm::mat4(1.0f), glm::vec3(size, size, size));
    glUniformMatrix4fv(modelviewPos, 1, GL_FALSE, &(view * model)[0][0]);
    bindModel(modelVertices,modelNormals,modelIndices);

    glBindVertexArray(defaultVAO);
    glDrawElements(GL_TRIANGLES , modelIndices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}


void pitch(double angle, std::vector<glm::vec3>& modelVertices) {
    for(int i =0; i<modelVertices.size();i++)
    {
        if(i<1568) {
            auto v0 = modelVertices[i][0], v1 = modelVertices[i][1];
            modelVertices[i][0] = v0 * cos(angle) - v1 * sin(angle);
            modelVertices[i][1] = v0 * sin(angle) + v1 * cos(angle);
        }
    }
}


void roll(double angle, std::vector<glm::vec3>& modelVertices) {
    for(int i =0; i<modelVertices.size();i++)
    {
        if(i<1568) {
            auto v0 = modelVertices[i][1], v1 = modelVertices[i][2];
            modelVertices[i][1] = v0 * cos(angle) - v1 * sin(angle);
            modelVertices[i][2] = v0 * sin(angle) + v1 * cos(angle);
        }
    }

}

void yaw(double angle,  std::vector<glm::vec3>& modelVertices)
{
    for(int i =0; i<modelVertices.size();i++) {
        if (i < 1568) {
            auto v0 = modelVertices[i][2], v1 = modelVertices[i][0];
            modelVertices[i][2] = v0 * cos(angle) - v1 * sin(angle);
            modelVertices[i][0] = v0 * sin(angle) + v1 * cos(angle);
        }
    }
}



// Very basic code to read a ppm file
// And then set up buffers for texture coordinates


void move(double x, double y, double z, std::vector<glm::vec3> &modelVertices) {

    for(int i =0; i<modelVertices.size();++i)
    {
        if(i>1567) {
            modelVertices[i][0] += 0.1*x;
            modelVertices[i][1] += 0.1*y;
            modelVertices[i][2] += z;
        }
    }
}

void Texture()
{
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    int width, height;
    unsigned char* image = SOIL_load_image("image.png", &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glBindTexture(GL_TEXTURE_2D, 0);


}

