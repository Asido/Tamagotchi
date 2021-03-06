#ifndef __SHADER_H__
#define __SHADER_H__

#include <memory>
#include <string>

#include <Eigen/Dense>
using namespace Eigen;

#include "Rendering/GLES.h"
#include "StringUtilities.h"

typedef unsigned int ShaderId;
const ShaderId INVALID_SHADER_ID = 0;

//-----------------------------------------------------------------------------------------------------------
//  class Shader
//-----------------------------------------------------------------------------------------------------------

class RenderComponent;

class Shader
{
public:
    static ShaderId GetIdFromName(const std::string &name) { return StringUtilities::Hash(name); }

    Shader();
    ~Shader();

    virtual bool    Init(GLuint vertexShader, GLuint fragmentShader) = 0;
    virtual bool    PrepareToRender() = 0;

protected:
    bool            LinkProgram();
    bool            ValidateProgram();

protected:
    GLuint program;
    GLuint vertexShader, fragmentShader;
};


//-----------------------------------------------------------------------------------------------------------
//  class SpriteShader
//-----------------------------------------------------------------------------------------------------------

enum {
    DEFAULT_VERTEX_ATTRIB_POSITION=0,
    DEFAULT_VERTEX_ATTRIB_TEXTURE
};

typedef struct {
    Vector3f positionCoords;
    Vector2f textureCoords;
} DefaultVertexData;

class SpriteShader : public Shader
{
public:
    static ShaderId GetIdStatic();

    virtual bool    Init(GLuint vertexShader, GLuint fragmentShader) override;
    virtual bool    PrepareToRender() override;

    void            SetTexture(GLuint texture) { this->glTexture = texture; }
    void            SetMvpMatrix(const Matrix4f &mvp) { this->mvpMatrix = mvp; }

private:
    bool            LoadUniformLocation(GLenum uniform, const std::string &uniformVar);

private:
    static const std::string name;

    enum DefaultShaderUniforms {
        DEFAULT_SHADER_UNIFORM_MVP=0,
        DEFAULT_SHADER_UNIFORM_TEXTURE,
        DEFAULT_SHADER_UNIFORM_COUNT
    };
    GLuint  uniforms[DEFAULT_SHADER_UNIFORM_COUNT];

    GLuint      glTexture;
    Matrix4f    mvpMatrix;
};

#endif // __SHADER_H__