//
//  Bonus.cpp
//  testlua_dl
//
//  Created by user on 13-11-13.
//
//

#include "Bonus.h"

Bonus::Bonus()
{
    m_iType = BONUS_FLAG;
}

Bonus::~Bonus()
{
    
}

Bonus *Bonus::createFromJsonFile(int iBonusType)
{
    Bonus *pBonus = new Bonus();
    if(pBonus && pBonus->initWithJsonFile(iBonusType))
    {
        pBonus->autorelease();
    }
    else
    {
        delete pBonus;
        pBonus = NULL;
    }
    CCAssert(pBonus != NULL, "Bonus not NULL");
    return pBonus;

}

bool Bonus::initWithJsonFile(int iBonusType)
{
    bool bRet = false;
    do {
        m_iBonusType = iBonusType;
        
        setSprite(CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()
                    ->spriteFrameByName(CCString::createWithFormat("ufo%d.png", iBonusType)->getCString())));
        this->addChild(m_pSprite);
        
        bRet = true;
    } while (0);
    
    return bRet;
}

void Bonus::setActivated(bool bActivated)
{
    Entity::setActivated(bActivated);
    if(bActivated) moveAction();
}

void Bonus::moveAction()
{
    CCSize bonusSize = m_pSprite->getContentSize();
    
    CCMoveBy* move1 = CCMoveBy::create(0.5f, CCPointMake(0, -150));
    CCMoveBy* move2 = CCMoveBy::create(0.3f, CCPointMake(0, 100));
    CCMoveBy* move3 = CCMoveBy::create(1.0f, CCPointMake(0, 0 - WIN_HEIGHT - bonusSize.height / 2));
    //CCLog("size: %f %f %f", 0 - WIN_HEIGHT - bonusSize.height / 2, WIN_HEIGHT, bonusSize.height);
    CCCallFunc* moveDone = CCCallFunc::create(this,callfunc_selector(Bonus::moveDone));
    CCFiniteTimeAction* sequence = CCSequence::create(move1, move2, move3, moveDone, NULL);
    
    m_pSprite->runAction(sequence);
}

void Bonus::resetPosition()
{
    CCSize bonusSize = m_pSprite->getContentSize();
    int minX = bonusSize.width/2;
    int maxX = WIN_WIDTH - bonusSize.width / 2;
    int rangeX = maxX-minX;
    int actualX = (rand() % rangeX) + minX;
    
    m_pSprite->setPosition(CCPointZero);
    this->setPosition(ccp(actualX, WIN_HEIGHT + bonusSize.height / 2));
}