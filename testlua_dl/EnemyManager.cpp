//
//  EnemyManager.cpp
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
    /* Json file will eat them
     */
//    m_iSpeedBounder = -15;
//    m_iSpeedRange = -30;
    
    m_smallEnemyList = CCArray::create();
    m_smallEnemyList->retain();
    
    m_middleEnemyList = CCArray::create();
    m_middleEnemyList->retain();
    
    m_bigEnemyList = CCArray::create();
    m_bigEnemyList->retain();
}

EnemyManager::~EnemyManager()
{
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
    m_smallEnemyList->release();
    m_middleEnemyList->release();
    m_bigEnemyList->release();
}

bool EnemyManager::initWithLevel(SpriteLayer *layer, int iLevel)
{
    bool bRet = false;
    do {
        m_iLevel = DEFAULT_Enemy_LEVEL;
        m_layer = layer;
        
        //this->scheduleUpdate();
        JsonFileReader::sharedJsonFileReader()->readEnemyManagerData(this);
        CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(EnemyManager::allEnemyBlow), ALL_ENEMY_BLOW, NULL);

        initEnemyList();
        schedule(schedule_selector(EnemyManager::addNewEnemy), ENEMY_APPEAR_DURATION);
        
        bRet = true;
    } while (0);
    return bRet;
}

void EnemyManager::initEnemyList()
{
    // store specific 
    for(int i = 0; i < MAX_SMALL_ENEMY_NUM; i++)
    {
        Enemy *pEnemy = Enemy::createFromJsonFile(en_smallEnemy, getRamdonSpeed());
        m_smallEnemyList->addObject(pEnemy);
        this->addChild(pEnemy);
    }
    for(int i = 0; i < MAX_MIDDLE_ENEMY_NUM; i++)
    {
        Enemy *pEnemy = Enemy::createFromJsonFile(en_middleEnemy, getRamdonSpeed());
        m_middleEnemyList->addObject(pEnemy);
        this->addChild(pEnemy);
    }
    for(int i = 0; i < MAX_BIG_ENEMY_NUM; i++)
    {
        Enemy *pEnemy = Enemy::createFromJsonFile(en_bigEnemy, getRamdonSpeed());
        m_bigEnemyList->addObject(pEnemy);
        this->addChild(pEnemy);
    }
}

void EnemyManager::update(float dt)
{
    
}

void EnemyManager::addNewEnemy(float dt)
{
    int iEnemyType = getRamdonEnemyType();
    
    Enemy *pEnemy = getEnemyFromList(iEnemyType);
    pEnemy->setPosition(ccp(getRamdonPositionX(pEnemy), WIN_HEIGHT + pEnemy->getSprite()->getContentSize().height / 2));
}

void EnemyManager::removeEnemy(Enemy *pEnemy)
{
    returnEnemyToList(pEnemy);
}

void EnemyManager::returnEnemyToList(Enemy *pEnemy)
{
    pEnemy->setActivated(false);
    //pEnemy->setVisible(false);
    //pEnemy->setUsed(false);
}

Enemy *EnemyManager::getEnemyFromList(int iEnemyType)
{
    Enemy *pEnemy = NULL;
    CCObject *pObject = NULL;
    CCArray *EnemyList = NULL;
    bool bFinded = false;
    
    switch (iEnemyType) {
        case en_smallEnemy:
        {
            EnemyList = m_smallEnemyList;
            break;
        }
        case en_middleEnemy:
        {
            EnemyList = m_middleEnemyList;
            break;
        }
        case en_bigEnemy:
        {
            EnemyList = m_bigEnemyList;
            break;
        }
        default:
            break;
    }
    
    CCARRAY_FOREACH(EnemyList, pObject)
    {
        pEnemy = (Enemy *)pObject;
        
        if(!pEnemy->getUsed())
        {
            bFinded = true;
            //pEnemy->setUsed(true);
            break;
        }
    }
    
    // There are no enemy unused in list
    if(!bFinded)
    {
        CCLog("new enemy allocated");
        pEnemy = Enemy::createFromJsonFile(iEnemyType, getRamdonSpeed());
        EnemyList->addObject(pEnemy);
        this->addChild(pEnemy);
    }
    
    CCAssert(pEnemy != NULL, "get NULL Enemy");
    pEnemy->setActivated(true);
    return pEnemy;
}

void EnemyManager::changeEnemyLevel(int iLevel)
{
    m_iLevel = iLevel;
}

int EnemyManager::getRamdonEnemyType()
{
    int iEnemyType = rand();
    if(iEnemyType % SMALL_ENEMY_RATE == 0) iEnemyType = en_smallEnemy;
    else if(iEnemyType % MIDDLE_ENEMY_RATE == 0) iEnemyType = en_middleEnemy;
    else if(iEnemyType % BIG_ENEMY_RATE == 0) iEnemyType = en_bigEnemy;
    else iEnemyType = en_smallEnemy;
    
    return iEnemyType;
}

int EnemyManager::getRamdonPositionX(Enemy *pEnemy)
{
    int iSpriteWidth = pEnemy->getSprite()->getContentSize().width;
    
    return random() % ((int)WIN_WIDTH - iSpriteWidth) + iSpriteWidth / 2;
}

int EnemyManager::getRamdonSpeed()
{
    return random() % m_iSpeedBounder + m_iSpeedRange;
}

void EnemyManager::allEnemyBlow(CCObject *pOb)
{
    CCObject *pObj = NULL;
    Enemy *pEnemy = NULL;
    
    CCARRAY_FOREACH(this->getChildren(), pObj)
    {
        pEnemy = (Enemy *)pObj;
        if(pEnemy->getActive())
        {
            pEnemy->getHurtAndDie(INFINITY);
        }
    }
}