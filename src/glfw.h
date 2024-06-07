#ifndef GLFW_H
#define GLFW_H
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>

extern vec3 cameraPos;
extern vec3 cameraFront;
extern vec3 cameraUp;
extern float fov;
// Handles the stuff when you increase your window size (for example, going full screen with f11 etc)
void framebuffer_size_callback (GLFWwindow *window, int width, int height);

// Handles input, movement, zoom, moving around etc.
void processInput (GLFWwindow *window);
// Initialize a GLFW window automatically
GLFWwindow* initGLFW(void);

// Makes looking around with mouse possible.
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);

// Makes zoom in and zoom out possible.
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

#endif