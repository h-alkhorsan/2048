#include "../headers/renderer.h"
Renderer::Renderer(Shader &shader)
{
    this->shader = shader;
    this->initRenderData();


}

Renderer::~Renderer()
{
    glDeleteVertexArrays(1, &this->quadVAO);
}


void Renderer::draw(Tex2D &tex, glm::vec2 pos, glm::vec2 size)
{
    this->shader.use();
    glm::mat4 model = glm::mat4(1.0f);

}


void Renderer::initRenderData()
{
    unsigned int VBO;

    float vertices[] = {
        // pos      //tex


    };

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}