//
//  TouchLayerDelegate.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__TouchLayerDelegate__
#define __ddl_plane__TouchLayerDelegate__

#include "cocos2d.h"

USING_NS_CC;

// a proxy used to decoupling
class TouchLayerDelegate
{
public:
    virtual void movePlayer(CCTouch *pTouch, CCEvent *pEvent) = 0;
};

#endif /* defined(__ddl_plane__TouchLayerDelegate__) */
