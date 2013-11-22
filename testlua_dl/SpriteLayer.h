//
//  SpriteLayer.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__SpriteLayer__
#define __ddl_plane__SpriteLayer__

#include "cocos2d.h"
#include "MacroAll.h"
#include "PlayerManager.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "BonusManager.h"
#include "TouchLayerDelegate.h"
#include "json.h"
#include "reader.h"
#include "GameRunScene.h"
#include <cstring>

USING_NS_CC;
using namespace std;

class GameRunScene;
class PlayerManager;
class BulletManager;
class EnemyManager;
class BonusManager;
class TouchLayerDelegate;

class SpriteLayer: public CCLayer, public TouchLayerDelegate
{
public:
    SpriteLayer();
    ~SpriteLayer();
    
    CREATE_FUNC_WITH_SCENE(SpriteLayer, GameRunScene);
    bool init(GameRunScene *pScene);
    
    void update(float dt);
    void collisionDetect(float dt);
    
    void movePlayer(CCTouch *pTouch, CCEvent *pEvent);
    CCPoint getPlayerPosition();
    CCSize getPlayerSize();
    
    void addEntityToList(CCObject *obj);
    void deleteEntityFromList(CCObject *obj);
    
    CC_SYNTHESIZE(CCArray *, m_CollisionList, CollisionList);
    CC_SYNTHESIZE(CCArray *, m_CollisionRemoveList, CollisionRemoveList);
    
    CC_SYNTHESIZE(PlayerManager *, m_pPlayerManager, PlayerManager);
    CC_SYNTHESIZE(BulletManager *, m_pBulletManager, BulletManager);
    CC_SYNTHESIZE(EnemyManager *, m_pEnemyManager, EnemyManager);
    CC_SYNTHESIZE(BonusManager *, m_pBonusManager, BonusManager);
    CC_SYNTHESIZE(GameRunScene *, m_pScene, Scene);
};


#endif /* defined(__ddl_plane__SpriteLayer__) */
