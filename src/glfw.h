#ifndef GLFW_H
#define GLFW_H
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

// Handles the stuff when you increase your window size (for example, going full screen with f11 etc)
void framebuffer_size_callback (GLFWwindow *window, int width, int height);

// Handles input, movement, zoom, moving around etc.
void processInput (GLFWwindow *window, vec3 cameraPos, vec3 cameraFront, vec3 cameraUp);
// Initialize a GLFW window automatically
GLFWwindow* initGLFW(void);

#endif