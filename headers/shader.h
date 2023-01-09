#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    unsigned int id;
    Shader(){}
    Shader &use();

    void compile(const char *vertexSource, const char *fragmentSource, const char *geometrySource = nullptr);
    
    void setFloat(const char *name, float value, bool useShader = false);
    void setInt(const char *name, int value, bool useShader = false);
    
    void setVector2f(const char *name, float x, float y, bool useShader = false);
    void setVector2f(const char *name, const glm::vec2 &value, bool useShader = false);

    void setVector3f(const char *name, float x, float y, float z, bool useShader = false);
    void setVector3f(const char *name, const glm::vec3 &value, bool useShader = false);

    void setVector4f(const char *name, float x, float y, float z, float w, bool useShader = false);
    void setVector4f(const char *name, const glm::vec4 &value, bool useShader = false);

    void setMatrix4(const char *name, const glm::mat4 &matrix, bool useShader = false);

private:
    void checkCompileErrors(unsigned int object, std::string type);
};


#endif