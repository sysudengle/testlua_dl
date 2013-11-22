//
//  PlayerManager.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__PlayerManager__
#define __ddl_plane__PlayerManager__

#include "cocos2d.h"
#include "MacroAll.h"
#include "SpriteLayer.h"
#include "Player.h"

USING_NS_CC;

class Player;
class SpriteLayer;

class PlayerManager: public CCLayer
{
public:
    bool initWithLevel(SpriteLayer *layer, int level);
    CREATE_FUNC_WITH_TWO_PARAM(PlayerManager, SpriteLayer *, int);

    //Touch operation
    void movePlayer(CCTouch *pTouch, CCEvent *pEvent);
    CCPoint getPlayerPosition();

    CC_SYNTHESIZE(SpriteLayer *, m_layer, SpriteLayer);
    CC_SYNTHESIZE(Player *, m_pPlayer, Player);
};

#endif /* defined(__ddl_plane__PlayerManager__) */
