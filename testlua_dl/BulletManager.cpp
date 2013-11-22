//
//  BulletManager.cpp
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#include "BulletManager.h"

BulletManager::BulletManager()
{
    m_iBigBombNum = 0;
    
    m_bulletList = CCArray::create();
    m_bulletList->retain();
    
    m_doubleBulletList = CCArray::create();
    m_doubleBulletList->retain();
    
    m_iLevel = DEFAULT_Bullet_LEVEL;
}

BulletManager::~BulletManager()
{
    m_bulletList->release();
    m_doubleBulletList->release();
    
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
}

bool BulletManager::initWithLevel(SpriteLayer *layer, int iLevel)
{
    bool bRet = false;
    do {
        m_layer = layer;
        
        //this->scheduleUpdate();
        CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(BulletManager::bigBombAttack), USE_BIG_BOMB, NULL);
        initBulletList();
        schedule(schedule_selector(BulletManager::addNewBullet), 0.1);
        
        bRet = true;
    } while (0);
    return bRet;
}

void BulletManager::initBulletList()
{
    for(int i = 0; i < MAX_NORMAL_BULLET_NUM; i++)
    {
        Bullet *pBullet = Bullet::createFromJsonFile(en_normalBullet);
        m_bulletList->addObject(pBullet);
        this->addChild(pBullet);
    }
    for(int i = 0; i < MAX_DOUBLE_BULLET_NUM; i++)
    {
        Bullet *pBullet = Bullet::createFromJsonFile(en_doubleBullet);
        m_doubleBulletList->addObject(pBullet);
        this->addChild(pBullet);
    }
}

void BulletManager::update(float dt)
{
    
}

void BulletManager::addNewBullet(float dt)
{
    switch (m_iLevel) {
        case en_normalBullet:
        {
            Bullet *pNewBullet = getBulletFromList();
            
            pNewBullet->setPosition(m_layer->getPlayerPosition());
            break;
        }
        case en_doubleBullet:
        {
            CCPoint playerLocation = m_layer->getPlayerPosition();
            Bullet *pNewBullet1 = getBulletFromList();
            Bullet *pNewBullet2 = getBulletFromList();
            
            pNewBullet1->setPosition(ccp(playerLocation.x - 20, playerLocation.y));
            pNewBullet2->setPosition(ccp(playerLocation.x + 20, playerLocation.y));
            break;
        }
        default:
            break;
    }
    //CCAssert(pNewBullet != NULL, "get NULL Bullet");
}

void BulletManager::removeBullet(Bullet *pBullet)
{
    returnBullletToList(pBullet);
}

void BulletManager::returnBullletToList(Bullet *pBullet)
{
    pBullet->setActivated(false);
}

Bullet *BulletManager::getBulletFromList()
{
    Bullet *pBullet = NULL;
    CCObject *pObject = NULL;
    CCArray *bulletList = NULL;
    bool bFinded = false;
    
    switch (m_iLevel) {
        case en_normalBullet:
        {
            bulletList = m_bulletList;
            break;
        }
        case en_doubleBullet:
        {
            bulletList = m_doubleBulletList;
            break;
        }
        default:
            break;
    }
    
    CCARRAY_FOREACH(bulletList, pObject)
    {
        pBullet = (Bullet *)pObject;
        
        if(!pBullet->getUsed())
        {
            bFinded = true;
            break;
        }
    }
    if(!bFinded)
    {
        pBullet = Bullet::createFromJsonFile(m_iLevel);
        //pBullet->setUsed(true);
        //pBullet->setVisible(false);
        bulletList->addObject(pBullet);
        this->addChild(pBullet);
    }
    
    CCAssert(pBullet != NULL, "get NULL bullet");
    pBullet->setActivated(true);
    return pBullet;
}

void BulletManager::changeBulletLevel(int iLevel)
{
    m_iLevel = iLevel;
}

void BulletManager::updateBullet(int iBulletType)
{
    m_iLevel = iBulletType;
    scheduleOnce(schedule_selector(BulletManager::returnToNormalBullet), 5);
}

void BulletManager::returnToNormalBullet()
{
    m_iLevel = en_normalBullet;
}

void BulletManager::bigBombAttack(CCObject *pObj)
{
    if(m_iBigBombNum > 0)
    {
        m_iBigBombNum--;
        CCNotificationCenter::sharedNotificationCenter()->postNotification(ALL_ENEMY_BLOW, this);
    }
}

void BulletManager::addNewBigBomb()
{
    m_iBigBombNum++;
}

void BulletManager::stopShoot()
{
    unscheduleAllSelectors();
}