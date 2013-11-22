//
//  SceneManager.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__SceneManager__
#define __ddl_plane__SceneManager__

#include "cocos2d.h"
#include "GameSelectScene.h"
#include "GameRunScene.h"
#include "GameWinScene.h"
#include "GameOverScene.h"

USING_NS_CC;

class GameSelectScene;
class GameRunScene;

class SceneManager: public CCObject
{
public:
    static SceneManager *sharedSceneManager();
    
    void changeScene(int en_SceneType);
    enum sceneType
    {
        en_GameSelectScene,
        en_GameRunScene,
        en_GameOverScene,
        en_GameWinScene
    };
protected:
    // SingleTon
    SceneManager();
    bool init();
    
    static SceneManager *m_sceneManager;
};

#endif /* defined(__ddl_plane__SceneManager__) */
