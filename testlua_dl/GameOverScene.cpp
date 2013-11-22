//
//  GameOverScene.cpp
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#include "GameOverScene.h"

USING_NS_CC;

GameOverScene *GameOverScene::create(int score)
{
    GameOverScene *pRet = new GameOverScene();
    //pRet->score = score;
    if(pRet && pRet->init(score))
    {
        //pRet->getHighestHistoryScore();
        //pRet->refreshHighestScore();
        CCLog("!!");
        pRet->autorelease();
    }
    else
    {
        delete pRet;
        pRet = NULL;
    }
    return pRet;
}

bool GameOverScene::init(int score)
{
    bool ret = false;
    
    do {
        //CC_BREAK_IF(CCScene::init());
        
        this->score = score;
        getHighestHistoryScore();
        refreshHighestScore();
        
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        
        CCLabelTTF *contentLabel = CCLabelTTF::create("Game Over~~", "Marker Felt", 100);
        contentLabel->setPosition(ccp(winSize.width / 2, winSize.height / 2));
        
        CCLayerGradient *layer = CCLayerGradient::create(ccc4(0, 0, 0, 120), ccc4(255, 255, 255, 120));
        //layer->addChild(contentLabel);
        
        
        CCSprite *background = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("gameover.png"));
        background->setScaleX(winSize.width / background->getContentSize().width);
        background->setScaleY(winSize.height / background->getContentSize().height);
        background->setAnchorPoint(ccp(0, 0));
        background->setPosition(CCPointZero);
        
        scoreLabel = CCLabelBMFont::create(CCString::createWithFormat("%d", score)->getCString(), "font.fnt");
        scoreLabel->setPosition(ccp(winSize.width / 2, winSize.height / 2));
        
        highestScoreLabel = CCLabelBMFont::create(CCString::createWithFormat("%d", highestScore)->getCString(), "font.fnt");
        highestScoreLabel->setPosition(ccp(winSize.width / 2, winSize.height / 2 + 300));
        
        CCMenuItemImage *playItem = CCMenuItemImage::create("btn_finish.png", "btn_finish.png", this, menu_selector(GameOverScene::menuPlayCallBack));
        //playItem->setPosition(ccp(winSize.width / 2, winSize.height / 2));
        CCMenu *pMenu = CCMenu::create(playItem, NULL);
        pMenu->setPosition(ccp(winSize.width / 2, winSize.height / 2 - playItem->getContentSize().height));
        
        layer->addChild(background);
        layer->addChild(pMenu);
        layer->addChild(highestScoreLabel);
        layer->addChild(scoreLabel);
        
        this->addChild(layer);
        ret = true;
    } while (0);
    
    return ret;
}

void GameOverScene::menuPlayCallBack(CCObject *pSender)
{
//    CCDirector::sharedDirector()->replaceScene(RunGameScene::create());
    lua_State *pLua = CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState();
    luaL_dofile(pLua, CCFileUtils::sharedFileUtils()->fullPathForFilename("SceneManager.lua").c_str());
    lua_getglobal(pLua, "gameRunScene");
    lua_call(pLua, 0, 0);
}

bool GameOverScene::fileExist()
{
    if(!CCUserDefault::sharedUserDefault()->getBoolForKey("fileExistXml"))
    {
        CCUserDefault::sharedUserDefault()->setBoolForKey("fileExistXml", true);
        CCUserDefault::sharedUserDefault()->setIntegerForKey("HighestScore", 0);
        CCUserDefault::sharedUserDefault()->flush();
        return false;
    }
    else
    {
        return true;
    }
}

void GameOverScene::getHighestHistoryScore()
{
    if(fileExist())
    {
        highestScore = CCUserDefault::sharedUserDefault()->getIntegerForKey("HighestScore", 0);
    }
}

void GameOverScene::refreshHighestScore()
{
    if(score > highestScore)
    {
        CCUserDefault::sharedUserDefault()->setIntegerForKey("HighestScore", score);
        highestScore = score;
    }
}