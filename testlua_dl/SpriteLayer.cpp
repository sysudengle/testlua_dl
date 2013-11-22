//
//  SpriteLayer.cpp
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#include "SpriteLayer.h"
#include "JsonFileReader.h"
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};
#include "CCLuaEngine.h"

SpriteLayer::SpriteLayer()
{
    m_CollisionList = CCArray::createWithCapacity(12);
    m_CollisionList->retain();
    
    m_CollisionRemoveList = CCArray::createWithCapacity(12);
    m_CollisionRemoveList->retain();
    
    /*JsonFileReader::sharedJsonFileReader();
    lua_State *pLua = CCLuaEngine::defaultEngine()->getLuaStack()->getLuaState();
    int iOpen = luaL_dofile(pLua, CCFileUtils::sharedFileUtils()->fullPathForFilename("SceneManager.lua").c_str());
    lua_getglobal(pLua, "gameOverScene");
    lua_call(pLua, 0, 0);*/
}

SpriteLayer::~SpriteLayer()
{
    m_CollisionList->release();
    m_CollisionRemoveList->release();
    
    CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
}

bool SpriteLayer::init(GameRunScene *pScene)
{
    bool bRet = false;
    
    do {
        CC_BREAK_IF(!CCLayer::init());
        
        this->m_pScene = pScene;
        
        CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(SpriteLayer::addEntityToList), ADD_ENTITY_TO_COL_LIST, NULL);
        CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(SpriteLayer::deleteEntityFromList), REMOVE_ENTITY_FROM_COL_LIST, NULL);

//        m_pPlayerManager = PlayerManager::create(this, PLAYER_LEVEL);
//        this->addChild(m_pPlayerManager, PLAYER_ZORDER);
        
        //m_pBonusManager = BonusManager::create(this);
        //this->addChild(m_pBonusManager);
        
        this->scheduleUpdate();
        
        bRet  = true;
    } while (0);
    
    return bRet;

}

void SpriteLayer::update(float dt)
{
    collisionDetect(dt);
}

void SpriteLayer::collisionDetect(float dt)
{
    CCObject *pObject = NULL;
    Entity *entity1 = NULL;
    Entity *entity2 = NULL;
    Entity *e1 = NULL;
    Entity *e2 = NULL;
    int iCollisionListCount = m_CollisionList->count();
    int iDetectResult;
    CCArray *removeList = CCArray::create();
    removeList->retain();
    
    //CCLog("collision number: %d", iCollisionListCount);
    for(int i = 0; i < iCollisionListCount; i++)
    {
        entity1 = (Entity *)m_CollisionList->objectAtIndex(i);
        
        if(!entity1->getActive()) continue;
        
        for(int j = i + 1; j < iCollisionListCount; j++)
        {
            entity2 = (Entity *)m_CollisionList->objectAtIndex(j);
            if(entity2->getActive() && entity1->boundingBox().intersectsRect(entity2->boundingBox()))
            {
                iDetectResult = (entity1->getType() | entity2->getType());// << JUDGE_OFFSET;
                //CCLog("%d %d %d", entity1->getType(), entity2->getType(), iDetectResult);
                if(iDetectResult == ENEMY_BULLET_COL)
                {
                    //e1==>enemy, e2==>bullet
                    //enemy blow, bullet remove
                    (entity1->getType()) == ENEMY_FLAG ? (e1 = entity1, e2 = entity2) : (e1 = entity2, e2 = entity1);
                    if(e1->getHurtAndDie(e2->getDamage()))
                        m_pScene->updateScore(e1->getScore());
                    e2->moveDone();
                    break;
                    CCLog("enemy and bullet collision");
                }
                else if(iDetectResult == ENEMY_PLAYER_COL)
                {
                    //e1==>player, e2==>enemy
                    //player blow, change scene to "game over scene"
                    (entity1->getType()) == PLAYER_FLAG ? (e1 = entity1, e2 = entity2) : (e1 = entity2, e2 = entity1);
                    e1->getHurtAndDie(INFINITY);
                    CCNotificationCenter::sharedNotificationCenter()->postNotification(STOP_SHOOT, this);
                    CCLog("enemy and player collision");
                    break;
                }
                else if(iDetectResult == PLAYER_BONUS_COL)
                {
                    //e1==>bonus, e2==>player
                    //bonus remove, update bullet
                    (entity1->getType()) == BONUS_FLAG ? (e1 = entity1, e2 = entity2) : (e1 = entity2, e2 = entity1);
                    Bonus *pBonus = (Bonus *)e1;
                    int iBonusType = pBonus->getBonusType();
                    CCLog("Bonus: %d", iBonusType);
                    if(iBonusType == en_multiBullet)
                    {
                        m_pBulletManager->updateBullet(en_doubleBullet);
                    }
                    else if(iBonusType == en_bigBomb)
                    {
                        m_pBulletManager->addNewBigBomb();
                    }
                    e1->moveDone();
                    break;
                    CCLog("player and bonus collision");
                }
                /**
                 * new collision could be implemented here~
                 */

            }
        }
    }
    CCARRAY_FOREACH(m_CollisionRemoveList, pObject)
    {
        entity1 = (Entity *)pObject;
//        entity1->setActivated(false);
        m_CollisionList->removeObject(entity1);
    }
    m_CollisionRemoveList->removeAllObjects();
 
}

void SpriteLayer::movePlayer(CCTouch *pTouch, CCEvent *pEvent)
{
    m_pPlayerManager->movePlayer(pTouch, pEvent);
}

CCPoint SpriteLayer::getPlayerPosition()
{
    return m_pPlayerManager->getPlayerPosition();
}

CCSize SpriteLayer::getPlayerSize()
{
    return m_pPlayerManager->getPlayer()->getSprite()->getContentSize();
}

void SpriteLayer::addEntityToList(cocos2d::CCObject *obj)
{
    m_CollisionList->addObject((Entity *)obj);
}

void SpriteLayer::deleteEntityFromList(cocos2d::CCObject *obj)
{
    m_CollisionRemoveList->addObject((Entity *)obj);
}