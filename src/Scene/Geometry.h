#ifndef _GLUT_SHAPES_REPLACEMENT
#define _GLUT_SHAPES_REPLACEMENT

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#ifndef GLM_FORCE_RADIANS
#define GLM_FORCE_RADIANS
#endif
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>


enum {Vertices, Colors, Elements} ;
enum {FLOOR} ;

extern GLuint defaultVAO, defaultVBO, defaultNBO, defaultEBO;
extern GLuint floorVAO, floorVBO, floorNBO, floorEBO, floorTBO;
extern GLuint vertexshader, fragmentshader, shaderprogram;
extern GLuint modelviewPos;
extern GLuint floorviewPos, colorPos;
extern glm::mat4 model, view, floorModel;
enum shape{NONE, PLANE, CUBE, SPHERE};
extern shape lastUsed;
void initBufferObjects();
void destroyBufferObjects();



void parse(const char*, std::vector<glm::vec3>& modelVertices,std::vector<glm::vec3>& modelNormals,std::vector<unsigned int>& modelIndices);
void yaw(double angle, std::vector<glm::vec3>& modelVertices );
void pitch(double angle, std::vector<glm::vec3>& modelVertices);
void roll(double angle, std::vector<glm::vec3>& modelVertices);

void move(double x, double y, double z, std::vector<glm::vec3>& modelVertices);


void bindModel(std::vector<glm::vec3>& modelVertices,std::vector<glm::vec3>& modelNormals,std::vector<unsigned int>& modelIndices);
void solidModel(float, std::vector<glm::vec3>& modelVertices,std::vector<glm::vec3>& modelNormals,std::vector<unsigned int>& modelIndices);
void Texture();

#endif
