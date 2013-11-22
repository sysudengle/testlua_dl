//
//  Bullet.cpp
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#include "Bullet.h"

Bullet::Bullet()
{
    m_bUsed = false;
    m_iType = BULLET_FLAG;
    setVisible(false);
}

Bullet::~Bullet()
{
    
}

Bullet *Bullet::createFromJsonFile(int iBulletType)
{
    Bullet *pBullet = new Bullet();
    if(pBullet && pBullet->initWithJsonFile(iBulletType))
    {
        pBullet->autorelease();
    }
    else
    {
        delete pBullet;
        pBullet = NULL;
    }
    CCAssert(pBullet != NULL, "Bullet not NULL");
    return pBullet;
}

bool Bullet::initWithJsonFile(int iBulletType)
{
    bool bRet = false;
    do {
        CCAssert(iBulletType == 1 || iBulletType == 2, "error Bullet type");
        m_iBulletType = iBulletType;
        JsonFileReader::sharedJsonFileReader()->readBulletData(this);
/*        if(iBulletType == en_normalBullet)
        {
            m_pSprite = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(NORMAL_BULLET_IMAGE));
        }
        else //(iBulletType == en_normalBullet == en_doubleBullet)
        {
            m_pSprite = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(DOUBLE_BULLET_IMAGE));
        }*/
        
        this->addChild(m_pSprite);
        
        bRet = true;
    } while (0);
    return bRet;
}

void Bullet::update(float dt)
{
    moveAction();
}

void Bullet::moveAction()
{
    this->setPositionY(this->getPositionY() + m_iSpeed);
        
    if(this->getPositionY() > WIN_HEIGHT)
    {
        moveDone();
    }
}

void Bullet::stopAction()
{
    unscheduleUpdate();
}

void Bullet::startAction()
{
    scheduleUpdate();
}