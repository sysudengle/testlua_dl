//
//  GameOverScene.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__GameOverScene__
#define __ddl_plane__GameOverScene__

#include "cocos2d.h"
#include "GameRunScene.h"
#include "CCLuaEngine.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};

USING_NS_CC;

class RunGameScene;

class GameOverScene: public CCScene
{
public:
    bool init(int score);
    static GameOverScene *create(int score);
//protected:
    void menuPlayCallBack(CCObject *pSender);
    bool fileExist();
    void getHighestHistoryScore();
    void refreshHighestScore();
    
    int score;
    int highestScore;
    CCLabelBMFont *scoreLabel;
    CCLabelBMFont *highestScoreLabel;
};

#endif /* defined(__ddl_plane__GameOverScene__) */
