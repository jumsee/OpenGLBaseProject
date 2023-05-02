﻿#pragma once
#include <string>
#include <unordered_map>

#include "glm/glm.hpp"

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader
{
private:
    std::string filePath;
    unsigned int rendererID;
    std::unordered_map<std::string, int> uniformLocationCache;

public:
    Shader(const std::string& filepath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    void SetUniform1i(const std::string& name, int value);
    void SetUniform1f(const std::string& name, float value);
    void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);

private:
    int GetUniformLocation(const std::string& name);
    unsigned CompileShader(unsigned type, const std::string& source);
    unsigned CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
    ShaderProgramSource ParseShader(const std::string& filepath);
};
