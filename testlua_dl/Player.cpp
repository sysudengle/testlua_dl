//
//  Player.cpp
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#include "Player.h"

Player *Player::createFromJsonFile(int iLevel)
{
    Player *pPlayer = new Player();
    if(pPlayer && pPlayer->initWithJsonFile(iLevel))
    {
        pPlayer->autorelease();
    }
    else
    {
        delete pPlayer;
        pPlayer = NULL;
    }
    CCAssert(pPlayer != NULL, "player not NULL");
    return pPlayer;
}

Player::Player()
{
    m_bUsed = true;
    m_iType = PLAYER_FLAG;
}

Player::~Player()
{
    
}

bool Player::initWithJsonFile(int iLevel)
{
    bool bRet = false;
    do {
        JsonFileReader::sharedJsonFileReader()->readPlayerData(this);
//        m_pSprite = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(HERO_IMAGE1));
        this->addChild(m_pSprite);
        
        setActivated(true);
        bRet = true;
    } while (0);
    return bRet;
}

void Player::blow()
{
    CCAnimation* animation=CCAnimation::create();
//    int iFramesNum = ENEMY_ANIMATION_FRAMES_NUM[m_iEnemyType];
    animation->setDelayPerUnit(0.1f);
    
    for(int i = 1; i <= 4; i++)
    {
        animation
        ->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()
                         ->spriteFrameByName(CCString::createWithFormat("hero_blowup_n%d.png", i)->getCString()) );
    }
    animation->setRestoreOriginalFrame(true);
    CCAnimate* animate=CCAnimate::create(animation);
    CCCallFunc *blowDoneAction = CCCallFunc::create(this, callfunc_selector(Player::blowDone));
    
    CCSequence* sequence=CCSequence::create(animate, blowDoneAction, NULL);
    m_pSprite->runAction(sequence);
}

void Player::blowDone()
{
    setActivated(false);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(GAME_OVER_SIGNAL, this);
}

void Player::moveTo(CCPoint location)
{
    if(m_bIsAlive && !CCDirector::sharedDirector()->isPaused())
    {
        CCPoint actualPoint;
        CCSize winSize=CCDirector::sharedDirector()->getWinSize();
        CCSize planeSize = m_pSprite->getContentSize();
        
        //bounding detect
        CCLog("%f %f", location.x, planeSize.width / 2);
        if (location.x<planeSize.width/2)
        {
            location.x=planeSize.width/2;
        }
        if (location.x>winSize.width-planeSize.width/2)
        {
            location.x=winSize.width-planeSize.width/2;
        }
        if (location.y<planeSize.height/2)
        {
            location.y=planeSize.height/2;
        }
        if (location.y>winSize.height-planeSize.height/2)
        {
            location.y=winSize.height-planeSize.height/2;
        }
        this->setPosition(location);
    }

}