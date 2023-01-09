#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include "stb_image.h"
#include <string>
#include <map>


class Tex2D
{
public:
    unsigned int id;
    unsigned int width, height;
    unsigned int internalFormat;
    unsigned int imageFormat;

    unsigned int wrapS;
    unsigned int wrapT;
    unsigned int filterMin;
    unsigned int filterMax;

    Tex2D();

    void generate(unsigned int width, unsigned int height, unsigned char *data);
    void bind() const;

};

Tex2D loadTexture(const char *file, bool alpha)
{
    Tex2D texture;
    if (alpha)
    {
        texture.internalFormat = GL_RGBA;
        texture.imageFormat = GL_RGBA;
    }

    int width, height, nrChannels;
    unsigned char *data = stbi_load(file, &width, &height, &nrChannels, 0);
    texture.generate(width, height, data);
    stbi_image_free(data);
    return texture;
}

#endif


