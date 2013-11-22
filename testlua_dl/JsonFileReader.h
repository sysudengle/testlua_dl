//
//  JsonFileReader.h
//  testlua_dl
//
//  Created by user on 13-11-14.
//
//

#ifndef __testlua_dl__JsonFileReader__
#define __testlua_dl__JsonFileReader__

#include "cocos2d.h"
#include "MacroAll.h"
#include "Enemy.h"
#include "Bonus.h"
#include "Player.h"
#include "Bullet.h"
#include "JsonType.h"
#include "EnemyManager.h"
#include "MenuLayer.h"
#include <cstring>

USING_NS_CC;
using namespace std;

class Enemy;
class Bullet;
class Player;
class Bonus;
class EnemyManager;
class MenuLayer;

class JsonFileReader: public CCObject
{
public:
    static JsonFileReader *sharedJsonFileReader();
    bool init();
    
    void readEnemyData(Enemy *pEnemy);
    void readPlayerData(Player *pPlayer);
    void readBulletData(Bullet *pBullet);
    void readBonusData(Bonus *pBonus);
    
    void readMenuLayer(MenuLayer *pMenuLayer);
    
    void readEnemyManagerData(EnemyManager *pEnemyManager);
    
    CC_SYNTHESIZE(string, m_sEnemyContent, EnemyContent);
    CC_SYNTHESIZE(string, m_sPlayerContent, PlayerContent);
    CC_SYNTHESIZE(string, m_sBulletContent, BulletContent);
    CC_SYNTHESIZE(string, m_sBonusContent, BonusContent);
protected:
    static JsonFileReader *m_pJsonFileReader;
    string m_Data[JSON_FILES_NUM];
    
    int m_jsonIndexList[JSON_FILES_NUM];
};


#endif /* defined(__testlua_dl__JsonFileReader__) */
