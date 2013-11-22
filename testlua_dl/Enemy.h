//
//  Enemy.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__Enemy__
#define __ddl_plane__Enemy__

#include "cocos2d.h"
#include "MacroParam.h"
#include "EnemyManager.h"
#include "Entity.h"
#include "EnemyType.h"
#include "JsonFileReader.h"

USING_NS_CC;

class EnemyManager;
class JsonFileReader;

class Enemy: public Entity
{
public:
    Enemy();
    ~Enemy();
    
    static Enemy *createFromJsonFile(int iEnemyType, int iSpeed);
    bool initWithJsonFile(int iEnemyType, int iSpeed);
    
    void update(float dt);
    
    void moveAction();
    //void moveDone();
    void stopAction();
    void startAction();
    
    void getHurt(int damage);
    
    //void setEnemyActivated(bool bActivated);
    void setAnimation(int iAnimationNum);
    
    void blow();
    void blowDone();
    
    //CC_SYNTHESIZE(bool, m_bUsed, Used);
    CC_SYNTHESIZE(int, m_iEnemyType, EnemyType);
    CC_SYNTHESIZE(EnemyManager *, m_pEnemyManager, EnemyManager);
};


#endif /* defined(__ddl_plane__Enemy__) */
