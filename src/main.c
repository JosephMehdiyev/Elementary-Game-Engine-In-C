#include <cglm/mat4.h>
#include "shader.h" 
#include <stb/stb_image.h>
#include <cglm/cglm.h>
#include <GLFW/glfw3.h>
#include "texture.h"
#include "glfw.h"
#include "render.h"


// SETTINGS
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;


int main(void)
{

    // initialize glfw window 
    GLFWwindow* window = initGLFW((int)SCR_WIDTH, (int)SCR_HEIGHT);

    // Texture stuff, generates, loads the texture files

    // Makes a shader program
    unsigned int shaderGrid = shaderProgramAll("../shaders/floorGrid.vert", "../shaders/floorGrid.frag");

    textureParameters();
    unsigned int texture = generateTexture();
    (void)texture;
    textureload("../resources/textures/dark.png");


    // render loop, the main engine thing
    while (!glfwWindowShouldClose(window))
    {   

        shaderProjection((float)SCR_WIDTH, (float)SCR_HEIGHT, shaderGrid, fov);
        shaderView(cameraPos, cameraFront, cameraUp, shaderGrid);
        shaderTransform(shaderGrid);

        drawGrid(shaderGrid);

        glfwSwapBuffers(window);

        processInput(window);

        glfwPollEvents();

    }

    glDeleteProgram(shaderGrid);
    glfwTerminate();
    return 0;
}