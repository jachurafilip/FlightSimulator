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

// These buffer objects should only be used for shapes defined in this file.
// For user-defined objects, please make separate VAOs, VBOs, etc.
extern GLuint defaultVAO, defaultVBO, defaultNBO, defaultEBO;
// The default shaders used.
extern GLuint vertexshader, fragmentshader, shaderprogram;
// Default associated variables
extern GLuint modelviewPos;
extern glm::mat4 model, view;
// Other variables
enum shape{NONE, PLANE, CUBE, SPHERE};
extern shape lastUsed;
void initBufferObjects();
void destroyBufferObjects();

extern std::vector <glm::vec3> modelVertices;
extern std::vector <glm::vec3> modelNormals;
extern std::vector <unsigned int> modelIndices;
// Helper function to parse an OBJ file
void parse(const char*);
void yaw(double angle);
void pitch(double angle);
void roll(double angle);

// To save time, only (re)bind the teapot buffers when needed
void bindModel();
void solidModel(float);

#endif
