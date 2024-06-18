#ifndef SHADER_H
#define SHADER_H
#include <cglm/mat4.h>
#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cglm/cglm.h>

// This function inputs a shader source file, i.e /path/to/shader/file.glsl, reads the content of the file,
// Saves the content in a string variable, and returns the same variable
const char* shaderSource(const char* shaderPath);

// Builds, compiles, links, and makes the  shaders programs, returns the same shader program and deletes the now useless shaders
unsigned int shaderProgramAll(const char* vertexSource, const char* fragmentSource);

// Makes the Projection matrix and sends it into the shader.
void shaderProjection(float SCR_WIDTH, float SCR_HEIGHT, unsigned int shaderProgram, float fov);

// Makes the view matrix and sends it into the shader.
void shaderView(vec3 cameraPos, vec3 cameraFront, vec3 cameraUp, unsigned int shaderProgram);

// Makes the model matrix and sends it into the shader.
void shaderTransform(unsigned int shaderProgram);





#endif  