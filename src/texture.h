#ifndef TEXTURE_H
#define TEXTURE_H

// Generates  a texture in OpenGL and returns it
unsigned int generateTexture(void);

// Loads the texture file from source file and "links" it with the a openGL texture generated before
void textureload(const char* fileLocation);

// Configuration files about how texture behave in specific circumstances
void textureParameters(void);


#endif  