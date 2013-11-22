//
//  GameSelectScene.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__GameSelectScene__
#define __ddl_plane__GameSelectScene__

#include "cocos2d.h"
#include "MacroParam.h"
#include "SceneManager.h"

USING_NS_CC;

class SceneManager;

class GameSelectScene: public cocos2d::CCLayerGradient
{
public:
    static GameSelectScene *create();
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    void menuCloseCallback(CCObject* pSender);
    
    void menuGame1Enter(CCObject* pSender);
    
};
#endif /* defined(__ddl_plane__GameSelectScene__) */
