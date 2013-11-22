//
//  Entity.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__Entity__
#define __ddl_plane__Entity__

#include "cocos2d.h"
#include "MacroAll.h"

USING_NS_CC;

class Entity: public CCNode
{
public:
    Entity();
    virtual ~Entity();
    
//    virtual bool initWithJsonFile() = 0;
    
    void bindSprite(CCSprite *pSprite);
    
    virtual void moveDone();
    virtual void blow();
    void getRemove();
    CCRect boundingBox();
    
    virtual void setActivated(bool bActivated);
    bool getVisible();
    virtual bool getHurtAndDie(int iDamage);
    
    CC_SYNTHESIZE(int, m_iId, Id);
    CC_SYNTHESIZE(int, m_iType, Type);
    CC_SYNTHESIZE(CCString *, m_sName, Name);
    
    CC_SYNTHESIZE(int, m_iDamage, Damage);
    CC_SYNTHESIZE(int, m_iDefense, Defense);
    CC_SYNTHESIZE(int, m_iHp, Hp);
    CC_SYNTHESIZE(int, m_iSpeed, Speed);
    CC_SYNTHESIZE(bool, m_bIsAlive, IsAlive);
    CC_SYNTHESIZE(bool, m_bActive, Active);
    CC_SYNTHESIZE(int, m_iLevel, Level);
    CC_SYNTHESIZE(int, m_iScore, Score);
    CC_SYNTHESIZE(bool, m_bUsed, Used);
    CC_SYNTHESIZE(CCSprite *, m_pSprite, Sprite);
protected:
};
#endif /* defined(__ddl_plane__Entity__) */
