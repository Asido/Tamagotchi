#ifndef __GAMELOGIC_H__
#define __GAMELOGIC_H__

#include <memory>
#include <map>
#include <list>

#include "Actors/Actor.h"

//-----------------------------------------------------------------------------------------------------------
//  class GameLogic
//-----------------------------------------------------------------------------------------------------------

class GameView;
class ActorFactory;
class HudFactory;
class XMLElement;

typedef std::map< ActorId, std::shared_ptr<Actor> > ActorMap;
typedef std::list< std::shared_ptr<GameView> >      GameViewList;

class GameLogic
{
    friend class TamagotchiEngine;

public:
    GameLogic();
    ~GameLogic();

    bool                                Init();
    
    virtual void                        AddGameView(std::shared_ptr<GameView> gameView, ActorId actorId=INVALID_ACTOR_ID);
    virtual void                        RemoveGameView(std::shared_ptr<GameView> gameView);

    bool                                LoadScene(const std::string &sceneFile);
    bool                                UnloadCurrentScene();

    virtual std::shared_ptr<Actor>      GetActor(ActorId actorId);
    virtual std::shared_ptr<Actor>      CreateActor(const std::string &actorResource, tinyxml2::XMLElement *override, const Eigen::Matrix4f *initialTransform=NULL);
    virtual void                        DestroyActor(ActorId actorId);

    virtual void                        OnUpdate(float delta);

private:
    ActorMap                            actors;
    GameViewList                        gameViews;
    std::shared_ptr<ActorFactory>       actorFactory;
    std::shared_ptr<HudFactory>         hudFactory;
};

#endif // __GAMELOGIC_H__