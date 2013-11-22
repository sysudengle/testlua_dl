//
//  Player.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__Player__
#define __ddl_plane__Player__

#include "cocos2d.h"
#include "MacroParam.h"
#include "PlayerManager.h"
#include "Entity.h"
#include "JsonFileReader.h"

USING_NS_CC;

class PlayerManager;
class JsonFileReader;

class Player: public Entity
{
public:
    Player();
    ~Player();
    
    static Player *createFromJsonFile(int iLevel);
    bool initWithJsonFile(int iLevel);
    
    void blow();
    void moveTo(CCPoint location);
    void blowDone();
    
    CC_SYNTHESIZE(PlayerManager *, m_pPlayerManager, PlayerManager);
};

#endif /* defined(__ddl_plane__Player__) */
