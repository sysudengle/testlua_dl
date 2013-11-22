//
//  TouchLayer.cpp
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#include "TouchLayer.h"

bool TouchLayer::init(GameRunScene *pScene)
{
    bool ret = false;
    do {
        CC_BREAK_IF(!CCLayer::init());
        
        m_pScene = pScene;
//        m_pDelegate = pScene->getSpriteLayer();
        
        m_bClicked = false;
        
        //galaxy =CCParticleGalaxy::create();
        //galaxy->setAutoRemoveOnFinish(true);
        //galaxy->setPosition(scene->getPlayerLocation());
        //this->addChild(galaxy);
        
        this->setTouchEnabled(true);
        
        ret = true;
    } while (0);
    
    return ret;
}

void TouchLayer::registerWithTouchDispatcher()
{
    // param 3: whether to swallow the touch
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, TOUCH_LAYER_PRIORITY, true);
}


bool TouchLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLog("Touch Began!!");
    if(m_bClicked)
    {
        m_bClicked = false;
        CCLog("double click");
        //double click here~
        if(!CCDirector::sharedDirector()->isPaused())
        {
            CCNotificationCenter::sharedNotificationCenter()->postNotification(USE_BIG_BOMB, this);
        }
    }
    else
    {
        this->scheduleOnce(schedule_selector(TouchLayer::singleClick), 0.25f);
        m_bClicked = true;
    }
    return true;
}

void TouchLayer::singleClick(float dt)
{
    if(m_bClicked)
    {
        m_bClicked = false;
        CCLog("single click");
    }
}

void TouchLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    CCLog("Moved!");
    m_pDelegate->movePlayer(pTouch, pEvent);
    /*if(m_pScene->playerIsAlive())
    {
        //galaxy->setPosition(scene->getPlayerLocation());
    }*/
}

void TouchLayer::keyBackClicked()
{
    CCDirector::sharedDirector()->end();
}

void TouchLayer::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

TouchLayerDelegate * TouchLayer::getDelegate(void)
{
    return m_pDelegate;
}

void TouchLayer::setDelegate(CCLayer * var)
{
    m_pDelegate = dynamic_cast<TouchLayerDelegate *>(var);
}
