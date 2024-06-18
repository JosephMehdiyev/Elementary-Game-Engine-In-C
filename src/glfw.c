#include <cglm/types.h>
#include <cglm/vec3.h>
#include <stdbool.h>
#include <stdio.h>
#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>
#include "glfw.h"


bool firstMouse = true;
float yaw   = -90.0f;
float pitch =  0.0f;
float lastX =  800.0f / 2.0;
float lastY =  600.0 / 2.0;
float fov   =  45.0f;
vec3 cameraFront = {0.0f, 0.0f, -1.0f};
//Position of camera i.e where the camera is
vec3 cameraPos = {0.0f, 3.0f, 0.0f};
vec3 cameraUp = {0.0f, 1.0f, 0.0f};
bool gridflag = true;

// SETTINGS



void framebuffer_size_callback (GLFWwindow *window, int width, int height) 
{
    glViewport(0, 0, width, height);
    (void)(window);
}
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = (float)(xposIn);
    float ypos = (float)(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f; 
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    vec3 front;
    front[0] = (float)(cos(glm_rad(yaw)) * cos(glm_rad(pitch)));
    front[1] = (float)sin(glm_rad(pitch));
    front[2] = (float)(sin(glm_rad(yaw)) * cos(glm_rad(pitch)));
    glm_vec3_normalize_to(front,cameraFront);
    (void)(window);

}



void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    fov -= (float)yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;
    (void)(window);
    (void)(xoffset);
}



void processInput (GLFWwindow *window) 
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }   
    const float cameraSpeed = 0.01f; 
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        vec3 buffer;
        glm_vec3_scale(cameraFront, cameraSpeed, buffer);
        glm_vec3_add(cameraPos, buffer, cameraPos);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        vec3 buffer;
        glm_vec3_scale(cameraFront, cameraSpeed, buffer);
        glm_vec3_sub(cameraPos, buffer, cameraPos);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        vec3 buffer1, buffer2;
        glm_vec3_crossn(cameraFront, cameraUp, buffer1);
        glm_vec3_scale(buffer1, cameraSpeed, buffer2);
        glm_vec3_sub(cameraPos, buffer2, cameraPos);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        vec3 buffer1, buffer2;
        glm_vec3_crossn(cameraFront, cameraUp, buffer1);
        glm_vec3_scale(buffer1, cameraSpeed, buffer2);
        glm_vec3_add(cameraPos, buffer2, cameraPos);
    }
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        glm_vec3_add(cameraPos, cameraUp, cameraPos);
    }
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        glm_vec3_sub(cameraPos, cameraUp, cameraPos);
    }
    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
    {
        gridflag = false;
    }
}

GLFWwindow* initGLFW(int SCR_WIDTH, int SCR_HEIGHT)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create glfw window
    
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Cormat", NULL, NULL);
    if (window == NULL)
    {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //GLAD: load OPENGL function pointers

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD \n");
    }    

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    return window;
}







