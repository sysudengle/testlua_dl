//
//  MenuLayer.cpp
//  testlua_dl
//
//  Created by user on 13-11-15.
//
//

#include "MenuLayer.h"

MenuLayer::MenuLayer()
{
    
}

MenuLayer::~MenuLayer()
{
    m_pPauseItem->removeAllChildrenWithCleanup(true);
//    m_pResumeNorImage->release();
//    m_pPausePressImage->release();
//    m_pResumeNorImage->release();
//    m_pResumePressImage->release();
}

bool MenuLayer::init(GameRunScene *pScene)
{
    bool bRet=false;
    do
    {
        CC_BREAK_IF(!CCLayer::init());
        
        m_pScene = pScene;
        m_iScore = 0;
        m_bIspause = false;
        
        CCSize winSize=CCDirector::sharedDirector()->getWinSize();
        this->setTouchEnabled(true);
        
        JsonFileReader::sharedJsonFileReader()->readMenuLayer(this);
        
        m_pPauseNorImage->retain();
        m_pPausePressImage->retain();
        m_pResumeNorImage->retain();
        m_pResumePressImage->retain();
        
        // pause item
        CCSprite *pNormalPause = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(m_pPauseNorImage->getCString()));
        CCSprite* pPressedPause=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(m_pPausePressImage->getCString()));
        m_pPauseItem = CCMenuItemSprite::create(pNormalPause, pPressedPause, this, menu_selector(MenuLayer::menuPauseCallBack));
        
        m_pPauseItem->setPosition(ccp(m_pPauseItem->getContentSize().width/2 + 10,winSize.height - m_pPauseItem->getContentSize().height/2));
        CCMenu *menuPause=CCMenu::create(m_pPauseItem,NULL);
        menuPause->setPosition(CCPointZero);
        this->addChild(menuPause);
        
        // score label
        m_pScoreLabel = CCLabelBMFont::create("0", "font.fnt");
        m_pScoreLabel->setAnchorPoint(ccp(0, 0.5));
        m_pScoreLabel->setPosition(ccp(m_pPauseItem->getContentSize().width + 15, winSize.height - m_pPauseItem->getContentSize().height/2));
        this->addChild(m_pScoreLabel);
        
        CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(MenuLayer::gameOverScene), GAME_OVER_SIGNAL, NULL);
        
        bRet=true;
    } while (0);
    
    return bRet;
}

void MenuLayer::menuPauseCallBack(CCObject *pSender)
{
    if(!m_bIspause)
    {
        CCSprite *pNormalPause = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(m_pResumeNorImage->getCString()));
        CCSprite* pPressedPause=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(m_pResumePressImage->getCString()));

        m_pPauseItem->setNormalImage(pNormalPause);
        m_pPauseItem->setSelectedImage(pPressedPause);

        CCDirector::sharedDirector()->pause();
    }
    else
    {
        CCSprite *pNormalPause = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(m_pPauseNorImage->getCString()));
        CCSprite* pPressedPause=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(m_pPausePressImage->getCString()));
        m_pPauseItem->setNormalImage(pNormalPause);
        m_pPauseItem->setSelectedImage(pPressedPause);
        CCDirector::sharedDirector()->resume();
    }
    m_bIspause = !m_bIspause;
    CCLog("pause press");
}

void MenuLayer::updateAndAddScore(int iScore)
{
    // update score
    m_iScore += iScore;
    m_pScoreLabel->setString(CCString::createWithFormat("%d", m_iScore)->getCString());
}
void MenuLayer::registerWithTouchDispatcher()
{
    // param 3: whether to swallow the touch
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -20, true);
}

bool MenuLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    return m_bIspause;
}

void MenuLayer::gameOverScene(CCObject *pObj)
{
    lua_State *pLua = CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState();
    luaL_dofile(pLua, CCFileUtils::sharedFileUtils()->fullPathForFilename("SceneManager.lua").c_str());
    lua_getglobal(pLua, "gameOverScene");
    lua_pushnumber(pLua, m_iScore);
    lua_call(pLua, 1, 0);
}