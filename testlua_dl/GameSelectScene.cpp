//
//  GameSelectScene.cpp
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#include "GameSelectScene.h"

USING_NS_CC;

GameSelectScene* GameSelectScene::create()
{
    GameSelectScene *pRet = new GameSelectScene();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

CCScene* GameSelectScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameSelectScene *layer = GameSelectScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameSelectScene::init()
{
    do {
        
        CC_BREAK_IF(!CCLayerGradient::initWithColor(ccc4(0, 0, 0, 120), ccc4(255, 255, 255, 120)));
        
        // Title Label
        CCLabelTTF* pLabel = CCLabelTTF::create(GAME_SELECT_TITLE, GAME_SELET_TITLE_FONT, GAME_SELET_TITLE_SIZE);
        CCSize size = WIN_SIZE;
        pLabel->setPosition( ccp(size.width / 2, size.height - 20) );
        this->addChild(pLabel, 1);
        
        CCSprite* pSprite = CCSprite::create("HelloWorld.png");
        pSprite->setPosition( ccp(size.width/2, size.height/2) );
        
        
        CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                              "CloseNormal.png",
                                                              "CloseSelected.png",
                                                              this,
                                                              menu_selector(GameSelectScene::menuCloseCallback) );
        pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
        
        CCMenuItemImage *pGame1Item = CCMenuItemImage::create(
                                                              "button_game_start.png",
                                                              "button_press.png",
                                                              this,
                                                              menu_selector(GameSelectScene::menuGame1Enter));
        pGame1Item->setPosition(ccp(size.width / 2, size.height / 2));
        // Game1 item
        CCMenu *pmenu = CCMenu::create(pCloseItem, pGame1Item, NULL);
        pmenu->setPosition(CCPointZero);
        // add the sprite as a child to this layer
        this->addChild(pmenu, 0);
    } while(0);
    return true;
}

void GameSelectScene::menuGame1Enter(CCObject *pSender)
{
    SceneManager::sharedSceneManager()->changeScene(SceneManager::en_GameRunScene);
}

void GameSelectScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
