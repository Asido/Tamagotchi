#ifndef __TAMAGOTCHIENGINE_H__
#define __TAMAGOTCHIENGINE_H__

#include <memory>
#include "defines.h"
#include "Rendering/GLES.h"
#include "Rendering/FontManager.h"
#include "GameLogic.h"
#include "EngineConfig.h"
#include "UI/GameView.h"
#include "UI/ScreenElement.h"
#include "ResourceManager/ResourceManager.h"

//-----------------------------------------------------------------------------------------------------------
//  class TamagotchiEngine
//-----------------------------------------------------------------------------------------------------------

class ResourceManager;
class IRenderer;
class ShaderManager;
class EngineConfig;

class TamagotchiEngine
{
public:
    TamagotchiEngine();
    virtual ~TamagotchiEngine();

    bool Init(GLint width, GLint height);

    void FrameUpdate(float delta);
    void FrameRender();

    void HandleScreenEvent(const ScreenEvent &event);

    std::shared_ptr<ResourceManager>    GetResourceManager() const { return this->resourceMgr; }
    std::shared_ptr<FontManager>        GetFontManager() const { return this->fontMgr; }
    std::shared_ptr<IRenderer>          GetRenderer() const { return this->renderer; }
    std::shared_ptr<ShaderManager>      GetShaderManager() const { return this->shaderMgr; }
    std::shared_ptr<GameLogic>          GetGameLogic() const { return this->gameLogic; }
    std::shared_ptr<EngineConfig>       GetEngineConfig() const { return this->engineConfig; }

protected:
    // Game specific initialization which must be defined by subclass.
    virtual std::shared_ptr<GameLogic>  CreateGameLogic() = 0;
    virtual std::shared_ptr<GameView>   CreateFirstView() = 0;

private:
    GLint width;
    GLint height;

    GLint shaderProgram;

    std::shared_ptr<ResourceManager>    resourceMgr;
    std::shared_ptr<FontManager>        fontMgr;
    std::shared_ptr<IRenderer>          renderer;
    std::shared_ptr<ShaderManager>      shaderMgr;
    std::shared_ptr<GameLogic>          gameLogic;
    std::shared_ptr<EngineConfig>       engineConfig;
};

extern TamagotchiEngine *g_engine;

#endif // __TAMAGOTCHIENGINE_H__