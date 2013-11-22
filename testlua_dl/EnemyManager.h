//
//  EnemyManager.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__EnemyManager__
#define __ddl_plane__EnemyManager__

#include "cocos2d.h"
#include "BulletType.h"
#include "MacroAll.h"
#include "SpriteLayer.h"
#include "Enemy.h"
#include "EnemyType.h"
#include "JsonFileReader.h"

USING_NS_CC;

class Enemy;
class SpriteLayer;
class Bullet;
class Enemy;
class JsonFileReader;

class EnemyManager: public CCLayer
{
public:
    EnemyManager();
    ~EnemyManager();
    
    bool initWithLevel(SpriteLayer *layer, int iEnemyType);
    CREATE_FUNC_WITH_TWO_PARAM(EnemyManager, SpriteLayer *, int);
    
    void update(float dt);
    void addNewEnemy(float dt);
    void removeEnemy(Enemy *pEnemy);
    
    void allEnemyBlow(CCObject *pObj);
    
    CC_SYNTHESIZE(int, m_iLevel, Level);
    CC_SYNTHESIZE(CCArray *, m_smallEnemyList, SmallList);
    CC_SYNTHESIZE(CCArray *, m_middleEnemyList, MiddleList);
    CC_SYNTHESIZE(CCArray *, m_bigEnemyList, BigList);
    
    CC_SYNTHESIZE(int, m_iDuration, Duration);
    CC_SYNTHESIZE(int, m_iSpeedRange, SpeedRange);
    CC_SYNTHESIZE(int, m_iSpeedBounder, SpeedBounder);
    CC_SYNTHESIZE(float, m_fGrowthRate, GrowthRate);
    CC_SYNTHESIZE(SpriteLayer *, m_layer, SpriteLayer);
protected:
    void initEnemyList();
    Enemy *getEnemyFromList(int iEnemyType);
    void returnEnemyToList(Enemy *pEnemy);
    void changeEnemyLevel(int iLevel);
    int getRamdonPositionX(Enemy *pEnemy);
    int getRamdonEnemyType();
    int getRamdonSpeed();
};


#endif /* defined(__ddl_plane__EnemyManager__) */
