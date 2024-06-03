/* Loads the content of a GLSL Shader file into a char* variable */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/glad/glad.h"
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

// build and compile shaders  
void shaderCompile(unsigned int shaderName, const char* shaderSource)
{
    // build and compile shaders  
    //
    // vertex shader
    shaderName = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shaderName, 1, &shaderSource, NULL);
    glCompileShader(shaderName);
    // check errors
    int success;
    char infoLog[512];
    glGetShaderiv(shaderName, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shaderName, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
    }
}
