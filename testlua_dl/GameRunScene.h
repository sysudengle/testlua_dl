//
//  GameRunScene.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//
#ifndef __ddl_plane__GameRunScene__
#define __ddl_plane__GameRunScene__

#include "cocos2d.h"

#include "SceneManager.h"

#include "BackgroundLayer.h"
#include "SpriteLayer.h"
#include "MenuLayer.h"
#include "TouchLayer.h"

class BackgroundLayer;
class SpriteLayer;
class TouchLayer;
class MenuLayer;

class GameRunScene: public CCScene
{
public:
    GameRunScene();
    ~GameRunScene();
    virtual bool init();
    
    void update(float dt);
    
    void updateScore(int iScore);
    
    CC_SYNTHESIZE(BackgroundLayer *, m_pBackgroundLayer, BackgroundLayer);
    CC_SYNTHESIZE(SpriteLayer *, m_pSpriteLayer, SpriteLayer);
    CC_SYNTHESIZE(TouchLayer *, m_pTouchLayer, TouchLayer);
    CC_SYNTHESIZE(MenuLayer *, m_pMenuLayer, MenuLayer);
    
    CREATE_FUNC(GameRunScene);
    
    //CC_SYNTHESIZE(int, score, Score);
};

#endif

