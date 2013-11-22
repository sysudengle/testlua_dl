//
//  Enemy.cpp
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#include "Enemy.h"

Enemy::Enemy()
{
    //default setting
    m_bUsed = false;
    m_iType = ENEMY_FLAG;
    m_bVisible = false;
}

Enemy::~Enemy()
{
    
}

Enemy *Enemy::createFromJsonFile(int iEnemyType, int iSpeed)
{
    Enemy *pEnemy = new Enemy();
    if(pEnemy && pEnemy->initWithJsonFile(iEnemyType, iSpeed))
    {
        pEnemy->autorelease();
    }
    else
    {
        delete pEnemy;
        pEnemy = NULL;
    }
    CCAssert(pEnemy != NULL, "Enemy not NULL");
    return pEnemy;
}

bool Enemy::initWithJsonFile(int iEnemyType, int iSpeed)
{
    bool bRet = false;
    do {
        
        //scheduleUpdate();
        m_iEnemyType = iEnemyType;
        m_iSpeed = iSpeed;
        /**
         * read from json file to initialize
         */
        JsonFileReader::sharedJsonFileReader()->readEnemyData(this);
/*        switch (m_iEnemyType) {
            case en_smallEnemy:
            {
                m_pSprite = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(SMALL_ENEMY_IMAGE));
                break;
            }
            case en_middleEnemy:
            {
                m_pSprite = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(MIDDLE_ENEMY_IMAGE));
                break;
            }
            case en_bigEnemy:
            {
                m_pSprite = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(BIG_ENEMY_IMAGE));
                //setAnimation(BIG_ENEMY_ANIMATION_NUM);
                break;
            }
            default:
                break;
        }*/
        
        this->addChild(m_pSprite);
        
        bRet = true;
    } while (0);
    return bRet;
}

void Enemy::update(float dt)
{
    moveAction();
}

void Enemy::moveAction()
{
    this->setPositionY(this->getPositionY() + m_iSpeed);
    
    if(this->getPositionY() < 0)
    {
        moveDone();
    }
}

void Enemy::stopAction()
{
    unscheduleUpdate();
}

void Enemy::startAction()
{
    scheduleUpdate();
}

/*void Enemy::setAnimation(int iAnimationNum)
{
    if(iAnimationNum < 1) return;
    
    CCArray *animationFrames = CCArray::create();
    
    for(int i = 1; i <= iAnimationNum; i++)
    {
        CCSpriteFrame *enemyFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName
                (CCString::createWithFormat("enemy%d_n%d.png", m_iEnemyType, i)->getCString());
        CCLog("%s", CCString::createWithFormat("enemy%d_n%d.png", m_iEnemyType, i)->getCString());
        animationFrames->addObject(enemyFrame);
    }
    CCAnimation *animation = CCAnimation::createWithSpriteFrames(animationFrames);
    animation->setDelayPerUnit(0.15f);
    CCAnimate *animate = CCAnimate::create(animation);
    m_pSprite->runAction(animate);
}*/

void Enemy::blow()
{
    CCLog("enemy blow");
    //blow animation
    /*
     * only for test here, it will be altered to read from Json file later
     */
    stopAction();
    
    CCAnimation* animation=CCAnimation::create();
    int iFramesNum = ENEMY_ANIMATION_FRAMES_NUM[m_iEnemyType];
    animation->setDelayPerUnit(0.1f);
    
    for(int i = 1; i <= iFramesNum; i++)
    {
        animation
        ->addSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()
        ->spriteFrameByName(CCString::createWithFormat("enemy%d_down%d.png", m_iEnemyType, i)->getCString()) );
    }
    animation->setRestoreOriginalFrame(true);
    CCAnimate* animate=CCAnimate::create(animation);
    CCCallFunc *blowDoneAction = CCCallFunc::create(this, callfunc_selector(Enemy::blowDone));
    
    CCSequence* sequence=CCSequence::create(animate, blowDoneAction, NULL);
    m_pSprite->runAction(sequence);
    
    //recover hp
    m_iHp = ENEMY_HP[m_iEnemyType];
}

void Enemy::getHurt(int iDamage)
{
    m_iHp -= iDamage;
    if(m_iHp <= 0)
    {
        blow();
    }
}

void Enemy::blowDone()
{
    setActivated(false);
}