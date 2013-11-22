//
//  TouchLayer.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__TouchLayer__
#define __ddl_plane__TouchLayer__
#include "cocos2d.h"
#include "GameRunScene.h"
#include "TouchLayerDelegate.h"

USING_NS_CC;

class TouchLayerDelegate;
class GameRunScene;

class TouchLayer: public CCLayer
{
public:
//    CC_SYNTHESIZE(TouchLayerDelegate *, m_pDelegate, Delegate);
    
    CREATE_FUNC_WITH_SCENE(TouchLayer, GameRunScene);
    bool init(GameRunScene *scene);
    
    void registerWithTouchDispatcher();
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void keyBackClicked();
    void onExit();
    
    virtual TouchLayerDelegate * getDelegate(void);
    virtual void setDelegate(CCLayer * var);
    
    CC_SYNTHESIZE(GameRunScene *, m_pScene, Scene);
//    CC_SYNTHESIZE(CCParticleSystem *, galaxy, Galaxy);
protected:
    void singleClick(float dt);
    
    TouchLayerDelegate *m_pDelegate;
    bool m_bClicked;
};


#endif /* defined(__ddl_plane__TouchLayer__) */
