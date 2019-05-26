

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
#include <PlaneController.h>
#include "FreeImage.h"
#include "grader.h"
int amount; // The amount of rotation for each arrow press
vec3 eye; // The (regularly updated) vector coordinates of the eye location 
vec3 up;  // The (regularly updated) vector coordinates of the up location 
const vec3 eyeinit(-20.0,5.0,0.0); // Initial eye position, also for resets
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
		<< "press ']' or '[' to change the accuracy of each operation\n"
		<< "press i/o to throttle up/down\n"
		<< "press Up/Down to steer the plane vertically\n"
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

mat3 rotate(const float degrees, const vec3& axis) {
    // YOUR CODE FOR HW1 HERE

    mat3 I = mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);
    mat3 aa = mat3(axis[0]*axis[0], axis[0]*axis[1], axis[0]*axis[2],
                   axis[0]*axis[1], axis[1]*axis[1], axis[1]*axis[2],
                   axis[0]*axis[2], axis[1]*axis[2], axis[2]*axis[2]);
    mat3 A = mat3(0, axis[2], -axis[1], -axis[2], 0, axis[0], axis[1], -axis[0], 0);

    float radians = pi/180.0 * degrees;
    // You will change this return call
    return cos(radians) * I + (1-cos(radians))*aa + sin(radians)*A;
}

void cameraUp(float degrees, vec3& eye, vec3& up) {
    // YOUR CODE FOR HW1 HERE
    vec3 p = glm::cross(eye, up);
    p = glm::normalize(p);
    eye = eye * Transform::rotate(-degrees, p);
    up = up * Transform::rotate(-degrees, p);
    // eye = eye * Transform::rotate(-degrees, up);
}

void cameraLeft(float degrees, vec3& eye, vec3& up) {
    cout<<degrees<<endl;
    for(int i=0; i<3; i++)
        cout<<eye[i]<<" "<<up[i]<<endl;
    eye = eye * Transform::rotate(-degrees, up);
}


