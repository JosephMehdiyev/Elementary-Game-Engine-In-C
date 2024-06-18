#include "shader.h"


// A file reader that outputs the source code in strings
const char* shaderSource(const char* shaderPath) 
{
    char* buffer = 0;
    unsigned long length;
    FILE* f = fopen (shaderPath, "rb");
    if ( f == NULL)
    {
        printf("ERROR: FAILED TO INITIALIZE SHADER SOURCE FILE\n");
    }

    /* Saves the string to a buffer */
    if (f)
    {
      fseek (f, 0, SEEK_END);
      length = (unsigned)ftell (f);
      fseek (f, 0, SEEK_SET);
      buffer = malloc(length + 1);
      buffer[length] = '\0';
      if (buffer)
      {
        fread (buffer, 1, length, f);
      }
      fclose (f);
    }
    
    const char* data;
    data = buffer;
    return data;
}

// Builds, compiles, linkes the shader and returns finalized product. The name will be changed soon
unsigned int shaderProgramAll(const char* vertexSource, const char* fragmentSource)
{
    // build and compile shaders  
    //
    // Shader source files
    const char* vertexShaderSource = shaderSource(vertexSource);
    const char* fragmentShaderSource = shaderSource(fragmentSource);
    // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR: SHADER VERTEX COMPILATION FAILED\n");
    }

    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("ERROR: SHADER FRAGMENT COMPILATION FAILED\n");
    }

    // link shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

     // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("ERROR: SHADER PROGRAM LINKING FAILED\n");
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}


void shaderProjection(float SCR_WIDTH, float SCR_HEIGHT, unsigned int shaderProgram, float fov)
{
    mat4 projection = GLM_MAT4_IDENTITY_INIT;
    glm_perspective(glm_rad(fov), (float)SCR_WIDTH/(float)SCR_HEIGHT, 0.1f, 100.0f, projection);
    int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projection[0]);   

}

void shaderView(vec3 cameraPos, vec3 cameraFront, vec3 cameraUp, unsigned int shaderProgram)
{
    mat4 view = GLM_MAT4_IDENTITY_INIT;
    glm_translate(view, (vec3){0.0f, 0.0f, -3.0f} );  
    vec3 buffer;
    glm_vec3_add(cameraPos,cameraFront,buffer);
    glm_lookat(cameraPos, buffer, cameraUp, view);
    int viewLoc = glGetUniformLocation(shaderProgram, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view[0]);
}
// Is also called model matrix
void shaderTransform(unsigned int shaderProgram)
{
    mat4 model = GLM_MAT4_IDENTITY_INIT;
    glm_rotate(model, (float)glfwGetTime() * glm_rad(50.0f), (vec3){0.5f, 1.0f, 0.0f});
    int modelLoc = glGetUniformLocation(shaderProgram, "transform");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model[0]);     

}



