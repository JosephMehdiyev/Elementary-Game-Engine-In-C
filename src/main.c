#include <stdlib.h>
#include <stdio.h>


#include "../include/glad/glad.h"
#include <GLFW/glfw3.h>

// SETTINGS
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;



void framebuffer_size_callback (GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
    (void)(window);
}
void processInput (GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 0);
}

int main(void) {
    // initialize glfw and configure
    
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
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //GLAD: load OPENGL function pointers

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD \n");
        return -1;
    }    
    
    // render loop, the main engine thingy

    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}