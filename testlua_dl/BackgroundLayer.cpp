//
//  BackgroundLayer.cpp
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#include "BackgroundLayer.h"

BackgroundLayer::BackgroundLayer()
{
    
}

BackgroundLayer::~BackgroundLayer()
{
    
}

bool BackgroundLayer::init(GameRunScene *pScene)
{
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!CCLayer::init());
        
        this->m_pScene = pScene;
        
        
        //background upper
        background1 = CCSprite::createWithSpriteFrame(
                                                      CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(BACKGROUND_IMAGE));
        background1->setAnchorPoint(ccp(0, 0));
        background1->setPosition(ccp(0, 0));
        this->addChild(background1);
        
        
        //background lower
        background2 = CCSprite::createWithSpriteFrame(
                                                      CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(BACKGROUND_IMAGE));
        background2->setAnchorPoint(ccp(0, 0));
        background2->setPosition(ccp(0, background1->getContentSize().height - 2));
        this->addChild(background2);
        
        autoResize();
        
        this->scheduleUpdate();
        
        bRet  = true;
    } while (0);
    
    return bRet;
}

void BackgroundLayer::update(float dt)
{
    backgroundMove();
}

void BackgroundLayer::backgroundMove()
{
    //CCLog("background move");
    background1->setPositionY(background1->getPositionY() - 2);
    background2->setPositionY(background1->getPositionY() + background2->getContentSize().height - 2);
    if(background2->getPositionY() == 0)
    {
        background1->setPositionY(0);
    }
}

void BackgroundLayer::autoResize()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    float scaleX = winSize.width / background1->getContentSize().width;
    float scaleY = winSize.height / background1->getContentSize().height;
    
    // auto adjust to the screen
    background1->setScaleX(scaleX);
    background1->setScaleY(scaleY);
    
    background2->setScaleX(scaleX);
    background2->setScaleY(scaleY);
}