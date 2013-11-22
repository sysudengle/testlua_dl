//
//  PlayerManager.cpp
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#include "PlayerManager.h"

bool PlayerManager::initWithLevel(SpriteLayer *layer, int iLevel)
{
    bool bRet = false;
    do {
        m_layer = layer;
        
        m_pPlayer = Player::createFromJsonFile(iLevel);
        m_pPlayer->setPosition(ccp(WIN_WIDTH /2, m_pPlayer->getSprite()->getContentSize().height / 2));
        this->addChild(m_pPlayer, PLAYER_ZORDER);
        
        bRet = true;
    } while (0);
    return bRet;
}

void PlayerManager::movePlayer(CCTouch *pTouch, CCEvent *pEvent)
{
    if (m_pPlayer->getIsAlive())
    {
        CCPoint beginPoint=pTouch->getLocationInView();
        beginPoint=CCDirector::sharedDirector()->convertToGL(beginPoint);
       
        CCPoint endPoint=pTouch->getPreviousLocationInView();
        endPoint=CCDirector::sharedDirector()->convertToGL(endPoint);
        
        CCPoint offSet =ccpSub(beginPoint,endPoint);                // get offset
        CCPoint toPoint=ccpAdd(m_pPlayer->getPosition(), offSet);   // real destinate point
        
        m_pPlayer->moveTo(toPoint);
    }

}

CCPoint PlayerManager::getPlayerPosition()
{
    return m_pPlayer->getPosition();
}

