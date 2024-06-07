#ifndef SHADER_H
#define SHADER_H
#include <cglm/mat4.h>
#include <GLFW/glfw3.h>
// This function inputs a shader source file, i.e /path/to/shader/file.glsl, reads the content of the file,
// Saves the content in a string variable, and returns the same variable
const char* shaderSource(const char* shaderPath);

// Builds, compiles, links, and makes the  shaders programs, returns the same shader program and deletes the now useless shaders
unsigned int shaderProgramtest(void);

mat4* shaderProjection(float SCR_WIDTH, float SCR_HEIGHT, unsigned int shaderProgram, float fov);

mat4* shaderView(vec3 cameraPos, vec3 cameraFront, vec3 cameraUp, unsigned int shaderProgram);

mat4* shaderModel(unsigned int shaderProgram);





#endif  