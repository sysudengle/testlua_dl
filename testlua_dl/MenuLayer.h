//
//  MenuLayer.h
//  testlua_dl
//
//  Created by user on 13-11-15.
//
//

#ifndef __testlua_dl__MenuLayer__
#define __testlua_dl__MenuLayer__

#include "cocos2d.h"
#include "MacroAll.h"
#include "GameRunScene.h"
#include "JsonFileReader.h"
#include "CCLuaEngine.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};

USING_NS_CC;

class GameRunScene;
class JsonFileReader;

class MenuLayer: public CCLayer
{
public:
    MenuLayer();
    ~MenuLayer();
    
    CREATE_FUNC_WITH_SCENE(MenuLayer, GameRunScene);
    bool init(GameRunScene *pScene);
    
    void menuPauseCallBack(CCObject *pSender);
    
    void updateAndAddScore(int iScore);
    
    void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    
    void gameOverScene(CCObject *pObj);
    CC_SYNTHESIZE(GameRunScene *, m_pScene, Scene);
    CC_SYNTHESIZE(int, m_iScore, Score);
    
    CC_SYNTHESIZE(CCString *, m_pPauseNorImage, PauseNorImage);
    CC_SYNTHESIZE(CCString *, m_pPausePressImage, PausePressImage);
    CC_SYNTHESIZE(CCString *, m_pResumeNorImage, ResumeNorImage);
    CC_SYNTHESIZE(CCString *, m_pResumePressImage, ResumePressImage);
protected:
    CCMenuItemSprite *m_pPauseItem;
    CCLabelBMFont *m_pScoreLabel;
    bool m_bIspause;
};



#endif /* defined(__testlua_dl__MenuLayer__) */
