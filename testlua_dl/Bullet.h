//
//  Bullet.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__Bullet__
#define __ddl_plane__Bullet__

#include "cocos2d.h"
#include "BulletType.h"
#include "MacroAll.h"
#include "Entity.h"
#include "BulletManager.h"
#include "JsonFileReader.h"

class Entity;
class JsonFileReader;
//class BulletManager;

class Bullet: public Entity
{
public:
    Bullet();
    ~Bullet();
    
    static Bullet *createFromJsonFile(int iBulletType);
    bool initWithJsonFile(int iBulletType);
    
    void moveAction();
    //void moveDone();
    void stopAction();
    void startAction();
    
//    void setBulletActivated(bool bActivated);
//    CC_SYNTHESIZE(PlayerManager *, m_pPlayerManager, PlayerManager);
//    CC_SYNTHESIZE(bool, m_bUsed, Used);
    CC_SYNTHESIZE(int, m_iBulletType, bulletType);
    void update(float dt);
protected:
};


#endif /* defined(__ddl_plane__Bullet__) */
