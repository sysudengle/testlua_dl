//
//  BackgroundLayer.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__BackgroundLayer__
#define __ddl_plane__BackgroundLayer__

#include "cocos2d.h"
#include "MacroAll.h"

#include "GameRunScene.h"

USING_NS_CC;

class GameRunScene;

class BackgroundLayer: public CCLayer
{
public:
    BackgroundLayer();
    ~BackgroundLayer();
    
    CREATE_FUNC_WITH_SCENE(BackgroundLayer, GameRunScene);
    bool init(GameRunScene *pScene);
    
    void update(float dt);
    
    CC_SYNTHESIZE(GameRunScene *, m_pScene, Scene);
protected:
    void autoResize();
    void backgroundMove();
    
    CCSprite *background1;
    CCSprite *background2;
};


#endif /* defined(__ddl_plane__BackgroundLayer__) */
