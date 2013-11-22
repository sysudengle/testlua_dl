//
//  BonusManager.cpp
//  testlua_dl
//
//  Created by user on 13-11-13.
//
//

#include "BonusManager.h"

BonusManager::BonusManager()
{
    m_pBonusActive = NULL;
    m_BonusList = CCArray::createWithCapacity(MAX_BONUS_TYPE_NUM);
    m_BonusList->retain();
}

BonusManager::~BonusManager()
{
    m_BonusList->release();
}

bool BonusManager::initWithLevel(SpriteLayer *pLayer)
{
    bool bRet = false;
    do {
        m_layer = pLayer;
        
        initBonusList();
        schedule(schedule_selector(BonusManager::addNewBonus), BONUS_APPEAR_DURATION);
        
        bRet = true;
    } while (0);
    return bRet;

}

void BonusManager::initBonusList()
{
    Bonus *pBonus = NULL;
    
    for(int iBonusType = BONUS_TYPE_BEGIN_NUM; iBonusType <= MAX_BONUS_TYPE_NUM; iBonusType++)
    {
        pBonus = Bonus::createFromJsonFile(iBonusType);
        
        m_BonusList->addObject(pBonus);
        this->addChild(pBonus);
    }
}

void BonusManager::addNewBonus(float dt)
{
    if(m_pBonusActive && (!m_pBonusActive->getUsed()))
    {
        removeBonus();
    }
    
    if(!m_pBonusActive)
    {
        int iBonusType = rand() % MAX_BONUS_TYPE_NUM;
        
        CCLog("type index %d", iBonusType);
        m_pBonusActive = (Bonus *)m_BonusList->objectAtIndex(iBonusType);
    
        m_pBonusActive->resetPosition();
        m_pBonusActive->setActivated(true);
        //CCLog("Bonus position: %f %f", m_pBonusActive->getPositionX(), m_pBonusActive->getPositionY());
        //CCLog("sprite position: %f %f", m_pBonusActive->getSprite()->getPositionX(), m_pBonusActive->getSprite()->getPositionY());
    }
}

void BonusManager::removeBonus()
{
    m_pBonusActive->setActivated(false);
    m_pBonusActive = NULL;

}