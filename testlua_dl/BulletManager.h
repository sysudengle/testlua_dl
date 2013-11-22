//
//  BulletManager.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__BulletManager__
#define __ddl_plane__BulletManager__

#include "cocos2d.h"
#include "BulletType.h"
#include "MacroAll.h"
#include "SpriteLayer.h"
#include "Player.h"
#include "Bullet.h"

USING_NS_CC;

class Player;
class SpriteLayer;
class Bullet;

class BulletManager: public CCLayer
{
public:
    BulletManager();
    ~BulletManager();
    
    bool initWithLevel(SpriteLayer *layer, int iLevel);
    CREATE_FUNC_WITH_TWO_PARAM(BulletManager, SpriteLayer *, int);
    
    void update(float dt);
    void addNewBullet(float dt);
    void removeBullet(Bullet *pBullet);
    
    void updateBullet(int iBulletType);
    void returnToNormalBullet();
    
    void stopShoot();
    
    CC_SYNTHESIZE(int, m_iLevel, Level);
    CC_SYNTHESIZE(CCArray *, m_bulletList, BulletList);
    CC_SYNTHESIZE(CCArray *, m_doubleBulletList, DoubleBulletList);
    CC_SYNTHESIZE(SpriteLayer *, m_layer, SpriteLayer);
    
    void bigBombAttack(CCObject *pObj);
    void addNewBigBomb();
    CC_SYNTHESIZE(int, m_iBigBombNum, BigBombNum);
protected:
    void initBulletList();
    Bullet *getBulletFromList();
    void returnBullletToList(Bullet *pBullet);
    void changeBulletLevel(int iLevel);
};

#endif /* defined(__ddl_plane__BulletManager__) */
