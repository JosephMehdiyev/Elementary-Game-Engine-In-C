#include <cglm/types.h>
#include <cglm/vec3.h>
#include <stdbool.h>
#include <stdio.h>
#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <cglm/cglm.h>





void framebuffer_size_callback (GLFWwindow *window, int width, int height) 
{
    glViewport(0, 0, width, height);
    (void)(window);
}

GLFWwindow* initGLFW(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create glfw window
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Cormat", NULL, NULL);
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

    return window;
}

void processInput (GLFWwindow *window, vec3 cameraPos, vec3 cameraFront, vec3 cameraUp) 
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }   
    const float cameraSpeed = 0.05f; // adjust accordingly
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
}





