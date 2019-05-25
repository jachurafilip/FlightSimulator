/******************************************************************************/
/* This is the program skeleton for homework 1 in CSE167 by Ravi Ramamoorthi  */
/* Based on an assignment designed by former TA Aner Ben-Artzi                */
/* The idea is to draw a teapot, that can be moved by a crystal ball          */
/* interface                                                                  */
/* Rewritten by Hoang Tran in July 2016 to exclusively use modern OpenGL.     */
/******************************************************************************/


// May need to replace with absolute path on some systems
#define DIRECTORY "/home/filip/FlightSimulator/"
#define PATH_TO_TEAPOT_OBJ_FILE  "/home/filip/FlightSimulator/src/Scene/Plane.obj"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Geometry.h"
#include "shaders.h"
#include "Transform.h"
#include <string>
#include <sstream>
#include "FreeImage.h"
#include "grader.h"

int amount; // The amount of rotation for each arrow press

vec3 eye; // The (regularly updated) vector coordinates of the eye location 
vec3 up;  // The (regularly updated) vector coordinates of the up location 
const vec3 eyeinit(-20.0,2.0,0.0); // Initial eye position, also for resets
const vec3 upinit(0.0,1.0,0.0); // Initial up position, also for resets
const int amountinit = 5; //Initial step amount for camera movement, also for resets

bool useGlu; // Toggle use of "official" opengl/glm transform vs user code
int w = 500, h = 500; // width and height 

Grader grader;
bool allowGrader = false;

// Constants to set up lighting on the teapot
const vec4 light_position(0,5,10,1);    // Position of light 0
const vec4 light_position1(0,5,-10,1);  // Position of light 1
const vec4 light_specular(0.6,0.3,0,1);    // Specular of light 0
const vec4 light_specular1(0,0.3,0.6,1);   // Specular of light 1
const vec4 one(1,1,1,1);                 // Specular on teapot
const vec4 medium(0.5,0.5,0.5,1);        // Diffuse on teapot
const vec4 small(0.2,0.2,0.2,1);         // Ambient on teapot
const GLfloat high = 100;                      // Shininess of teapot
vec4 light0,light1;

// Variables to set uniform params for lighting fragment shader 
GLuint islight; 
GLuint light0posn; 
GLuint light0color; 
GLuint light1posn; 
GLuint light1color; 
GLuint ambient; 
GLuint diffuse; 
GLuint specular; 
GLuint shininess;
GLuint color;

// Uniform variables used for the transformation matrices
GLuint projectionPosition;
mat4 view, projection;

// New helper transformation function to transform vector by the view matrix
void transformvec (const vec4 input, vec4& output) {
	output = view * input;
}

// Deallocate any dynamically allocated memory here
void cleanup() {
	destroyBufferObjects();
}

std::string imgNumber(int num) {
	std::stringstream ss;
	//Return 3-digit number (or more if num > 999, but this case shouldn't be encountered)
	if(num < 10) {
		ss << "00" << num;
	} else if(num < 100) {
		ss << "0" << num;
	} else {
		ss << num;
	}
	return ss.str();
}


void printHelp() {
	std::cout << "\npress 'h' to print this message again.\n" 
		<< "press ']' or '[' to change the amount of rotation that\n"
		<< "occurs with each arrow press.\n" 
		<< "press 'i' to run image grader test cases\n"
		<< "press 'g' to switch between using glm::lookAt or your own LookAt.\n"     
		<< "press 'r' to reset the transformation (eye and up).\n"
		<< "press ESC to quit.\n";  
}


//  You will need to enter code for the arrow keys 
//  When an arrow key is pressed, it will call your transform functions



// This function gets called when the window size gets changed
void reshape(GLFWwindow* window, int width,int height){
	w = width;
	h = height;
	glViewport(0,0,w,h);
	// Set the projection matrix based on the current perspective, then pass
	// the calculated matrix onto the shader program. Remember that the field of
	// view is in radians!
	projection = glm::perspective(90.0f * glm::pi<float>() / 180.0f, (float)w / (float)h, 0.01f, 100.0f);
	glUniformMatrix4fv(projectionPosition, 1, GL_FALSE, &projection[0][0]);
}



void init() {
	// Set up initial position for eye,up and amount
	// As well as booleans 
    glMatrixMode(GL_MODELVIEW);
	eye = eyeinit; 
	up = upinit; 
	amount = amountinit;
	useGlu = true;

	glEnable(GL_DEPTH_TEST);

	// The lighting is enabled using the same framework as in mytest 3 
	// Except that we use two point lights
	// For now, lights and materials are set in display.  Will move to init 
	// later, per update lights


	vertexshader = initshaders(GL_VERTEX_SHADER,DIRECTORY"src/Scene/light.vert");
	fragmentshader = initshaders(GL_FRAGMENT_SHADER,DIRECTORY"src/Scene/light.frag");
	shaderprogram = initprogram(vertexshader,fragmentshader); 
	islight = glGetUniformLocation(shaderprogram,"islight");        
	light0posn = glGetUniformLocation(shaderprogram,"light0posn");       
	light0color = glGetUniformLocation(shaderprogram,"light0color");       
	light1posn = glGetUniformLocation(shaderprogram,"light1posn");       
	light1color = glGetUniformLocation(shaderprogram,"light1color");       
	ambient = glGetUniformLocation(shaderprogram,"ambient");       
	diffuse = glGetUniformLocation(shaderprogram,"diffuse");       
	specular = glGetUniformLocation(shaderprogram,"specular");       
	shininess = glGetUniformLocation(shaderprogram,"shininess");       
	color = glGetUniformLocation(shaderprogram, "color");

	// Get the uniform locations of the transformation matrices
	projectionPosition = glGetUniformLocation(shaderprogram, "projection");
	modelviewPos = glGetUniformLocation(shaderprogram, "modelview");

	// Other initializations here
	initBufferObjects();
	// Load 3D model of the teapot so it can be drawn later.
    parse(PATH_TO_TEAPOT_OBJ_FILE);

}

void display(GLFWwindow* window) {
	glClearColor(0,0,1,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	const vec3 center(0.0,0.0,0.0);

	if (useGlu) {
		view = glm::lookAt(eye, center, up);
	}
	else {
		view = Transform::lookAt(eye,up); 
	}

	transformvec(light_position,light0); 
	transformvec(light_position1,light1); 
	glUniform4fv(light0posn,1,&light0[0]); 
	glUniform4fv(light0color,1,&light_specular[0]); 
	glUniform4fv(light1posn,1,&light1[0]);
	glUniform4fv(light1color,1,&light_specular1[0]);
 
	glUniform4fv(ambient,1,&small[0]);
	glUniform4fv(diffuse,1,&small[0]);
	glUniform4fv(specular,1,&one[0]);
	glUniform1f(shininess, high);
	glUniform1i(islight,true);

	solidTeapot(4.5f);
}

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_REPEAT || action == GLFW_PRESS)
    {


    switch(key) {
        case GLFW_KEY_ESCAPE:
            cout << "ESC";
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            break;
        case GLFW_KEY_RIGHT_BRACKET:
            amount++;
            std::cout << "amount set to " << amount << "\n";
            break;
        case GLFW_KEY_LEFT_BRACKET:
            amount--;
            std::cout << "amount set to " << amount << "\n";
            break;
        case GLFW_KEY_I:
            if(useGlu) {
                std::cout << "Please disable glm::LookAt by pressing 'g'"
                          << " before running tests\n";
            }
            else if(!allowGrader) {
                std::cout << "Error: no input file specified for grader\n";
            } else {
                std::cout << "Running tests...\n";
                grader.runTests();
                std::cout << "Done! [ESC to quit]\n";
            }
            break;
        case GLFW_KEY_G:
            useGlu = !useGlu;
            std::cout << "Using glm::LookAt set to: "
                      << (useGlu ? " true " : " false ") << "\n";
            break;
        case GLFW_KEY_H:
            printHelp();
            break;
        case GLFW_KEY_R:  // reset eye and up vectors
            eye = eyeinit;
            up = upinit;
            amount = amountinit;
            std::cout << "eye and up vectors reset, amount set to " << amountinit << "\n";
            break;
        case GLFW_KEY_LEFT: //left
            roll(-amount*M_PI/180);
            break;
        case GLFW_KEY_UP: //up
            pitch(amount*M_PI/180);
            break;
        case GLFW_KEY_RIGHT: //right
            roll(amount*M_PI/180);
            break;
        case GLFW_KEY_DOWN: //down
            pitch(-amount*M_PI/180);
            break;
        default:
            break;
    }
    }
}

