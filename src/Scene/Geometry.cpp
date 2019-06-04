#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Geometry.h"
#include <vector>
#include <algorithm>

GLuint defaultVAO, defaultVBO, defaultNBO, defaultEBO;
GLuint floorVAO, floorVBO, floorNBO, floorEBO, floorTBO;
GLuint vertexshader, fragmentshader, shaderprogram;
GLuint modelviewPos;
GLuint floorviewPos, colorPos;
glm::mat4 model;
glm::mat4 floorModel;
shape lastUsed = NONE;


GLubyte texture[256][256][3] ; // ** NEW ** texture (from grsites.com)
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


void bindFloor(std::vector<glm::vec3>& floorVertices,std::vector<glm::vec3>& floorNormals,std::vector<unsigned int>& floorIndices) {
    glBindVertexArray(floorVAO);

    glBindBuffer(GL_ARRAY_BUFFER, floorVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * floorVertices.size(), &floorVertices[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);

    glBindBuffer(GL_ARRAY_BUFFER, floorNBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * floorNormals.size(), &floorNormals[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, floorEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * floorIndices.size(), &floorIndices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void solidModel(float size,std::vector<glm::vec3>& modelVertices,std::vector<glm::vec3>& modelNormals,std::vector<unsigned int>& modelIndices) {
    model = glm::scale(glm::mat4(1.0f), glm::vec3(size, size, size));
    glUniformMatrix4fv(modelviewPos, 1, GL_FALSE, &(view * model)[0][0]);
    bindModel(modelVertices,modelNormals,modelIndices);

    glBindVertexArray(defaultVAO);
    glDrawElements(GL_TRIANGLES , modelIndices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void solidFloor(float size, std::vector<glm::vec3>& floorVertices,std::vector<glm::vec3>& floorNormals,std::vector<unsigned int>& floorIndices) {
    floorModel = glm::scale(glm::mat4(1.0f), glm::vec3(size, size, size));
    glUniformMatrix4fv(floorviewPos, 1, GL_FALSE, &(floorModel)[0][0]);
    glUniform3f(colorPos, 1.0f, 1.0f, 1.0f);
    bindFloor(floorVertices,floorNormals,floorIndices);
    drawtexture(FLOOR, texNames[0]);

    glBindVertexArray(floorVAO);
    glDrawElements(GL_TRIANGLES, sizeof(floorinds), GL_UNSIGNED_BYTE, 0);
    glBindVertexArray(0);
}

void pitch(double angle, std::vector<glm::vec3>& modelVertices) {
    for (auto &v: modelVertices) {
        auto v0 = v[0], v1 = v[1];
        v[0] = v0 * cos(angle) - v1 * sin(angle);
        v[1] = v0 * sin(angle) + v1 * cos(angle);
    }
}


void roll(double angle, std::vector<glm::vec3>& modelVertices) {
    for(auto &v: modelVertices)
    {
        auto v0 = v[1], v1 = v[2];
        v[1] = v0 * cos(angle)-v1*sin(angle);
        v[2] = v0 * sin(angle)+v1*cos(angle);
    }

}

void yaw(double angle,  std::vector<glm::vec3>& modelVertices)
{
    for(auto &v: modelVertices)
    {
        auto v0 = v[2], v1 = v[0];
        v[2] = v0 * cos(angle)-v1*sin(angle);
        v[0] = v0 * sin(angle)+v1*cos(angle);
    }
}



// Very basic code to read a ppm file
// And then set up buffers for texture coordinates
void inittexture (const char * filename, GLuint program) {
    int i,j,k ;
    FILE * fp ;
    assert(fp = fopen(filename,"rb")) ;
    fscanf(fp,"%*s %*d %*d %*d%*c") ;
    for (i = 0 ; i < 256 ; i++)
        for (j = 0 ; j < 256 ; j++)
            for (k = 0 ; k < 3 ; k++)
                fscanf(fp,"%c",&(texture[i][j][k])) ;
    fclose(fp) ;

    // Set up Texture Coordinates
    glGenTextures(1, texNames) ;
    glBindVertexArray(floorVAO);
    glBindBuffer(GL_ARRAY_BUFFER, floorTBO) ;
    glBufferData(GL_ARRAY_BUFFER, sizeof (floortex), floortex,GL_STATIC_DRAW);
    // Use layout location 2 for texcoords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);

    glActiveTexture(GL_TEXTURE0) ;
    glEnable(GL_TEXTURE_2D) ;

    glBindTexture (GL_TEXTURE_2D, texNames[0]) ;
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB, 256, 256, 0, GL_RGB, GL_UNSIGNED_BYTE,texture) ;
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR) ;
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR) ;
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT) ;
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT) ;
    glBindVertexArray(0);
    // Define a sampler.  See page 709 in red book, 7th ed.
    GLint texsampler ;
    texsampler = glGetUniformLocation(program, "tex") ;
    // Note that the value assigned to the texture sampler is n, where n is the active
    // texture number provided to glActiveTexture(). In this case, it's texture unit 0.
    glUniform1i(texsampler,0) ;
    istex = glGetUniformLocation(program,"istex") ;
}

void drawtexture(GLuint object, GLuint texture) {
    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(floorTBO);
    glDrawElements(GL_TRIANGLES, sizeof(floorinds), GL_UNSIGNED_BYTE, 0);
    glBindVertexArray(0);
}

void move(double x, double y, double z, std::vector<glm::vec3> &modelVertices) {

    for(auto &v: modelVertices)
    {
        v[0]+=x;
        v[1]+=y;
        v[2]+=z;
    }

}

