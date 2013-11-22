//
//  BonusManager.h
//  testlua_dl
//
//  Created by user on 13-11-13.
//
//

#ifndef __testlua_dl__BonusManager__
#define __testlua_dl__BonusManager__

#include "cocos2d.h"
#include "MacroAll.h"
#include "SpriteLayer.h"
#include "Bonus.h"

USING_NS_CC;

class Bonus;
class SpriteLayer;

class BonusManager: public CCLayer
{
public:
    BonusManager();
    ~BonusManager();
    
    CREATE_FUNC_WITH_PARAM(BonusManager, SpriteLayer *);
    bool initWithLevel(SpriteLayer *layer);
    void initBonusList();
    
    
    void addNewBonus(float dt);
    void removeBonus();
    
    CC_SYNTHESIZE(Bonus *, m_pBonusActive, BonusActive);
    CC_SYNTHESIZE(CCArray *, m_BonusList, BonusList);
    CC_SYNTHESIZE(SpriteLayer *, m_layer, SpriteLayer);
protected:
//    int m_iMinDuration;
};


#endif /* defined(__testlua_dl__BonusManager__) */
