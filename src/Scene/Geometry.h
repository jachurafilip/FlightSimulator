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

const GLfloat floorverts[4][3] = {
        { 0.5, 0.5, 0.0 },{ -0.5, 0.5, 0.0 },{ -0.5, -0.5, 0.0 },{ 0.5, -0.5, 0.0 }
};
const GLfloat floorcol[4][3] = {
        { 1.0, 1.0, 1.0 },{ 1.0, 1.0, 1.0 },{ 1.0, 1.0, 1.0 },{ 1.0, 1.0, 1.0 }
};
const GLubyte floorinds[1][6] = { { 0, 1, 2, 0, 2, 3 } };
const GLfloat floortex[4][2] = {
        { 1.0, 1.0 },{ 0.0, 1.0 },{ 0.0, 0.0 },{ 1.0, 0.0 }
};

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

void inittexture (const char * filename, GLuint program) ;
void drawtexture(GLuint object, GLuint texture) ;

extern std::vector <glm::vec3> modelVertices;
extern std::vector <glm::vec3> modelNormals;
extern std::vector <unsigned int> modelIndices;

void parse(const char*);
void yaw(double angle);
void pitch(double angle);
void roll(double angle);

void bindModel();
void solidModel(float);
void bindFloor();
void solidFloor(float);

#endif
