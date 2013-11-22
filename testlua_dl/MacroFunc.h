//
//  GlobalMacro.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef ddl_plane_MacroFunc_h
#define ddl_plane_MacroFunc_h

#define CREATE_FUNC_WITH_SCENE(__TYPE__, __SCENETYPE__) \
static __TYPE__* create(__SCENETYPE__ *scene) \
{ \
__TYPE__ *pRet = new __TYPE__(); \
if (pRet && pRet->init(scene)) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = NULL; \
return NULL; \
} \
}

#define CREATE_FUNC_WITH_PARAM(__TYPE__, __PARAMTYPE__) \
static __TYPE__* create(__PARAMTYPE__ param) \
{ \
__TYPE__ *pRet = new __TYPE__(); \
if (pRet && pRet->initWithLevel(param)) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = NULL; \
return NULL; \
} \
}

#define CREATE_FUNC_WITH_TWO_PARAM(__TYPE__, __PARAMTYPE1__, __PARAMTYPE2__) \
static __TYPE__* create(__PARAMTYPE1__ param1, __PARAMTYPE2__ param2) \
{ \
__TYPE__ *pRet = new __TYPE__(); \
if (pRet && pRet->initWithLevel(param1, param2)) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = NULL; \
return NULL; \
} \
}

#endif
