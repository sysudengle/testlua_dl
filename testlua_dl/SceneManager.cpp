//
//  SceneManager.cpp
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#include "SceneManager.h"

SceneManager *SceneManager::m_sceneManager = NULL;

SceneManager::SceneManager()
{
    
}

SceneManager *SceneManager::sharedSceneManager()
{
    if(m_sceneManager == NULL)
    {
        m_sceneManager = new SceneManager();
    }
    return m_sceneManager;
}

void SceneManager::changeScene(int en_SceneType)
{
    CCScene *pNewScene = NULL;
    
    CCLog("choice select %d", en_SceneType);
    switch (en_SceneType) {
        case en_GameSelectScene:
            pNewScene = GameSelectScene::scene();
            break;
        case en_GameRunScene:
            //pNewScene = GameRunScene::create();
            break;
        case en_GameOverScene:
            break;
        case en_GameWinScene:
            break;
        default:
            break;
    }
    
    if(pNewScene == NULL) return;
    
    CCDirector *pDirector = CCDirector::sharedDirector();
    CCScene *pRuningScene = CCDirector::sharedDirector()->getRunningScene();
    
    if(pRuningScene == NULL)
    {
        pDirector->runWithScene(pNewScene);
    }
    else
    {
        pDirector->replaceScene(pNewScene);
    }
}