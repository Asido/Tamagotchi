#ifndef __XMLRESOURCE_H__
#define __XMLRESOURCE_H__

#include <string>
#include <memory>

#include <tinyxml2.h>

#include "ResourceManager.h"

//-----------------------------------------------------------------------------------------------------------
//  class XMLResourceExtraData
//-----------------------------------------------------------------------------------------------------------

class XMLResourceLoader;

class XMLResourceExtraData : public IResourceExtraData
{
    friend class XMLResourceLoader;

public:
    tinyxml2::XMLElement*   GetRoot();

private:
    bool                    ParseXML(char *rawBuffer);

private:
    tinyxml2::XMLDocument   xmlDocument;
};


//-----------------------------------------------------------------------------------------------------------
//  class XMLResourceLoader
//-----------------------------------------------------------------------------------------------------------

class XMLResourceLoader : public IResourceLoader
{
public:
    virtual const std::string&  GetPattern() const override;
    virtual bool                UseRawFile() const override { return false; }
    virtual bool                DiscardRawBufferAfterLoad() const override { return true; }
    virtual bool                AddNullZero() const override { return true; }
    virtual unsigned int        GetLoadedResourceSize(char *rawBuffer, unsigned int rawSize) override;
    virtual bool                LoadResource(char *rawBuffer, unsigned int rawSize, std::shared_ptr<ResourceHandle> handle) override;
};

#endif // __XMLRESOURCE_H__