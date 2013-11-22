//
//  GameRunScene.cpp
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//
#include "GameRunScene.h"

GameRunScene::GameRunScene()
{
    
}

GameRunScene::~GameRunScene()
{
    
}

bool GameRunScene::init()
{
    if(CCScene::init())
    {
        this->scheduleUpdate();
        return true;
    }
    else
    {
        return false;
    }
    
}

void GameRunScene::update(float dt)
{
    
}


void GameRunScene::updateScore(int iScore)
{
    m_pMenuLayer->updateAndAddScore(iScore);
}
