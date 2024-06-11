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
    GLFWwindow* window = initGLFW(SCR_WIDTH, SCR_HEIGHT);

    // Texture stuff, generates, loads the texture files

    // Makes a shader program
    unsigned int shaderGrid = shaderProgramAll("../shaders/floorGrid.vert", "../shaders/floorGrid.frag");
    unsigned int shaderCube = shaderProgramAll("../shaders/vertex.glsl", "../shaders/fragment.glsl");
    unsigned int texture = generateTexture();
    textureload("../resources/textures/dark.png");
    // render loop, the main engine thing
    while (!glfwWindowShouldClose(window))
    {   

        shaderProjection((float)SCR_WIDTH, (float)SCR_HEIGHT, shaderGrid, fov);
        shaderView(cameraPos, cameraFront, cameraUp, shaderGrid);
        shaderModel(shaderGrid);
        drawGrid(shaderGrid);


  

        processInput(window);
        glfwSwapBuffers(window);

        glfwPollEvents();

    }

    glDeleteProgram(shaderGrid);
    glfwTerminate();
    return 0;
}