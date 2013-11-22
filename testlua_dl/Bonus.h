//
//  Bonus.h
//  testlua_dl
//
//  Created by user on 13-11-13.
//
//

#ifndef __testlua_dl__Bonus__
#define __testlua_dl__Bonus__

#include "cocos2d.h"
#include "MacroParam.h"
#include "BonusManager.h"
#include "Entity.h"
#include "BonusType.h"

USING_NS_CC;

class BonusManager;

class Bonus: public Entity
{
public:
    Bonus();
    ~Bonus();
    
    static Bonus *createFromJsonFile(int iBonusType);
    bool initWithJsonFile(int iBonusType);
    
    void moveAction();
    //void moveDone();
    void resetPosition();
    
    virtual void setActivated(bool bActivated);
    CC_SYNTHESIZE(int, m_iBonusType, BonusType);
    CC_SYNTHESIZE(BonusManager *, m_pBonusManager, BonusManager);
};

#endif /* defined(__testlua_dl__Bonus__) */
