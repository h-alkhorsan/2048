#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shader.h"
#include "texture.h"

class Renderer
{
public:
    Renderer(Shader &shader);
    ~Renderer();

    void draw(Tex2D &texture, glm::vec2 position, glm::vec2 size);
    
private:
    Shader shader;
    unsigned int quadVAO;

    void initRenderData();
};

#endif