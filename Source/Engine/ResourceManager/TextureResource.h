#ifndef __TEXTURELOADER_H__
#define __TEXTURELOADER_H__

#include <string>
#include <png.h>
#include "ResourceManager.h"
#include "Rendering/GLES.h"

//-----------------------------------------------------------------------------------------------------------
//  class TextureResourceLoader
//-----------------------------------------------------------------------------------------------------------

class GLESTextureResourceExtraData : public IResourceExtraData
{
    friend class TextureResourceLoader;

public:
    GLESTextureResourceExtraData();
    virtual ~GLESTextureResourceExtraData();

    GLuint  GetTexture() const { return this->texture; }

private:
    GLuint  texture;
};


//-----------------------------------------------------------------------------------------------------------
//  class TextureResourceLoader
//-----------------------------------------------------------------------------------------------------------
/*
 * I assume that no other textures than .png format are required.
 * But if something exotic happens, we should use this as a base class
 * and register the subclasses only to the resource manager. Each subclass should
 * provide it's own pattern.
 */

class TextureResourceLoader : public IResourceLoader
{
public:
    virtual const std::string&  GetPattern() const override;
    virtual bool                UseRawFile() const override { return false; }
    virtual bool                DiscardRawBufferAfterLoad() const override { return true; }
    virtual unsigned int        GetLoadedResourceSize(char *rawBuffer, unsigned int rawSize) override;
    virtual bool                LoadResource(char *rawBuffer, unsigned int rawSize, std::shared_ptr<ResourceHandle> handle) override;

private:
    static void ReadPngData(png_structp pngPtr, png_bytep data, png_size_t length);
};


#endif // __TEXTURELOADER_H__