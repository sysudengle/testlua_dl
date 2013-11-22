//
//  Entity.cpp
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#include "Entity.h"

Entity::Entity()
{
    m_bActive = false;
}

Entity::~Entity()
{
    
}

void Entity::bindSprite(CCSprite *pSprite)
{
    setSprite(pSprite);
}

void Entity::moveDone()
{
    setActivated(false);
    CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOVE_ENTITY_FROM_COL_LIST, this);
}

void Entity::getRemove()
{
    this->removeFromParentAndCleanup(true);
}

void Entity::blow()
{
    CCLog("old blow");
    setActivated(false);
}

CCRect Entity::boundingBox()
{
    CCRect spriteRect = m_pSprite->boundingBox();
    CCPoint point = this->convertToWorldSpace(ccp(spriteRect.origin.x, spriteRect.origin.y));
    point = this->getParent()->convertToWorldSpace(point);
    spriteRect.origin.x = point.x;
    spriteRect.origin.y = point.y;
    //CCLog("point %f %f", point.x, point.y);
    return spriteRect;
}

bool Entity::getVisible()
{
    return m_bVisible;
}

void Entity::setActivated(bool bActivated)
{
    setUsed(bActivated);
    setVisible(bActivated);
    setActive(bActivated);
    (bActivated)? scheduleUpdate():unscheduleUpdate();
    if(bActivated)
        CCNotificationCenter::sharedNotificationCenter()->postNotification(ADD_ENTITY_TO_COL_LIST, this);
    //else
        //CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOVE_ENTITY_FROM_COL_LIST, this);
}

bool Entity::getHurtAndDie(int iDamage)
{
    m_iHp -= iDamage;
    if(m_iHp <= 0)
    {
        CCNotificationCenter::sharedNotificationCenter()->postNotification(REMOVE_ENTITY_FROM_COL_LIST, this);
        setActive(false);
        blow();
    }
}
