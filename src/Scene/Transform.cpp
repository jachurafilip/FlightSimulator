// Transform.cpp: implementation of the Transform class.


#include "Transform.h"
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

//Please implement the following functions:

// Helper rotation function.
mat3 Transform::rotate(const float degrees, const vec3& axis) {
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

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
	cout<<degrees<<endl;
	for(int i=0; i<3; i++)
	printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));

	eye = eye * Transform::rotate(-degrees, up);
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
	printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
	// YOUR CODE FOR HW1 HERE
	vec3 p = glm::cross(eye, up);
	p = glm::normalize(p);
	eye = eye * Transform::rotate(-degrees, p);
	up = up * Transform::rotate(-degrees, p);
	// eye = eye * Transform::rotate(-degrees, up);
}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
	// YOUR CODE FOR HW1 HERE
	vec3 center = vec3(0, 0, 0);
	//new coordinate sys

	vec3 Z = -eye - center;
	Z = glm::normalize(Z);
	vec3 Y = up;
	vec3 X = glm::cross(Z, Y);
	Y = glm::cross(X, Z);
	X = glm::normalize(X);
	Y = glm::normalize(Y);
	// You will change this return call

	mat4 Result(1);
  Result[0][0] = X.x;
  Result[1][0] = X.y;
  Result[2][0] = X.z;
  Result[0][1] = Y.x;
  Result[1][1] = Y.y;
  Result[2][1] = Y.z;
  Result[0][2] =-Z.x;
  Result[1][2] =-Z.y;
  Result[2][2] =-Z.z;
  Result[3][0] =-dot(X, eye);
  Result[3][1] =-dot(Y, eye);
  Result[3][2] = dot(Z, eye);
    return Result;
	// return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
