//
//  JsonFileReader.cpp
//  testlua_dl
//
//  Created by user on 13-11-14.
//
//

#include "JsonFileReader.h"

JsonFileReader *JsonFileReader::m_pJsonFileReader = NULL;

JsonFileReader *JsonFileReader::sharedJsonFileReader()
{
    if(m_pJsonFileReader == NULL)
    {
        m_pJsonFileReader = new JsonFileReader();
        m_pJsonFileReader->init();
    }
    return m_pJsonFileReader;
}

bool JsonFileReader::init()
{
    CCFileUtils *pFileUtil = CCFileUtils::sharedFileUtils();
    string fileNames[JSON_FILES_NUM] = {"Enemy.json", "Player.json", "Bullet.json", "Bonus.json"};
    unsigned long lLen = 0;
    unsigned char *pBuffer = NULL;
    
    m_jsonIndexList[ENEMY_JSON_INDEX] = ENEMY_JSON_INDEX;
    m_jsonIndexList[PLAYER_JSON_INDEX] = PLAYER_JSON_INDEX;
    m_jsonIndexList[BULLET_JSON_INDEX] = BULLET_JSON_INDEX;
    m_jsonIndexList[BONUS_JSON_INDEX] = BONUS_JSON_INDEX;
    
    for(int i = 0; i < JSON_FILES_NUM; i++)
    {
        string path = pFileUtil->fullPathForFilename(fileNames[i].c_str());
        
        pBuffer = pFileUtil->getFileData(path.c_str(), "r", &lLen);
        m_Data[i] = string((char *)pBuffer, lLen);
        printf("%s", m_Data[i].c_str());
    }
    return true;
}

void JsonFileReader::readEnemyData(Enemy *pEnemy)
{
    Json::Value oValue;
    Json::Reader oReader;
    
    oReader.parse(m_Data[ENEMY_JSON_INDEX], oValue);
    Json::Value oEnemyValue = oValue[pEnemy->getEnemyType()];
    
    pEnemy->setHp(oEnemyValue["hp"].asInt());
//    pEnemy->setSpeed(oEnemyValue["speed"].asInt());
    pEnemy->setLevel(oEnemyValue["level"].asInt());
    pEnemy->setScore(oEnemyValue["score"].asInt());
    pEnemy->setSprite(CCSprite::createWithSpriteFrame
            (CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(oEnemyValue["image"].asCString())));
}

void JsonFileReader::readPlayerData(Player *pPlayer)
{
    Json::Value oValue;
    Json::Reader oReader;
    
    oReader.parse(m_Data[PLAYER_JSON_INDEX], oValue);
    
    pPlayer->setSpeed(oValue["speed"].asInt());
    pPlayer->setIsAlive(oValue["isAlive"].asBool());
    pPlayer->setSprite(CCSprite::createWithSpriteFrame
            (CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(oValue["image"].asCString())));
}

void JsonFileReader::readBulletData(Bullet *pBullet)
{
    Json::Value oValue;
    Json::Reader oReader;
    
    oReader.parse(m_Data[BULLET_JSON_INDEX], oValue);
    Json::Value oBulletValue = oValue[pBullet->getbulletType()];
    
    pBullet->setSpeed(oBulletValue["speed"].asInt());
    pBullet->setDamage(oBulletValue["damage"].asInt());
    pBullet->setSprite(CCSprite::createWithSpriteFrame
            (CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(oBulletValue["image"].asCString())));

}

void JsonFileReader::readBonusData(Bonus *pBonus)
{
    
}

void JsonFileReader::readEnemyManagerData(EnemyManager *pEnemyManager)
{
    Json::Value oValue;
    Json::Reader oReader;
    
    oReader.parse(m_Data[ENEMY_JSON_INDEX], oValue);
    Json::Value oEnemyManagerValue = oValue[ENEMY_MANAGER_JSON_INDEX];
    
    pEnemyManager->setSpeedBounder(oEnemyManagerValue["speedFloor"].asInt());
    pEnemyManager->setSpeedRange(oEnemyManagerValue["speedRange"].asInt());
}

void JsonFileReader::readMenuLayer(MenuLayer *pMenuLayer)
{
    Json::Value oValue;
    Json::Reader oReader;
    unsigned long lLen = 0;
    unsigned char *pBuffer = NULL;
    CCFileUtils *pFileUtil = CCFileUtils::sharedFileUtils();
    string oData;
    
    string path = pFileUtil->fullPathForFilename("MenuLayer.json");
    
    pBuffer = pFileUtil->getFileData(path.c_str(), "r", &lLen);
    oData = string((char *)pBuffer, lLen);
    
    oReader.parse(oData, oValue);
    
    pMenuLayer->setPauseNorImage(CCString::create(oValue["gamePauseImageNor"].asString()));
    pMenuLayer->setPausePressImage(CCString::create(oValue["gamePauseImagePress"].asString()));
    pMenuLayer->setResumeNorImage(CCString::create(oValue["gameResumeImageNor"].asString()));
    pMenuLayer->setResumePressImage(CCString::create(oValue["gameResumeImagePress"].asString()));
    
//    pMenuLayer->setPauseNorSprite(CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(oValue["gamePauseImageNot"].asCString())));
//    pMenuLayer->setPausePressSprite(CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(oValue["gamePauseImagePress"].asCString())));
//    pMenuLayer->setResumeNorSprite(CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(oValue["gameResumeImageNot"].asCString())));
//    pMenuLayer->setResumePressSprite(CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(oValue["gameResumeImagePress"].asCString())));
}