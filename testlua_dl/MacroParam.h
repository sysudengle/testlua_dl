//
//  MacroParam.h
//  ddl_plane
//
//  Created by user on 13-10-30.
//
//

#ifndef __ddl_plane__MacroParam__
#define __ddl_plane__MacroParam__

/*********** Global *********************/
#define WIN_SIZE CCDirector::sharedDirector()->getWinSize()
#define WIN_WIDTH CCDirector::sharedDirector()->getWinSize().width
#define WIN_HEIGHT CCDirector::sharedDirector()->getWinSize().height
#define INFINITY 9999999
#define JSON_FILES_NUM 4

#define WIN_WIDTH_MID CCDirector::sharedDirector()->getWinSize().width/2
#define WIN_HEIGHT_MID CCDirector::sharedDirector()->getWinSize().height/2

/*********** GameSelectScene ****************/
#define GAME_SELECT_TITLE "dengle"
#define GAME_SELET_TITLE_FONT "Thonburi"
#define GAME_SELET_TITLE_SIZE 34

#define CLOSE_NORMAL_IMAGE "CloseNormal.png"
#define CLOSE_SELECTED_IMAGE "CloseSelected.png"

/*********** GameRunScene ****************/
#define SHOOT_BACKGROUND_PLIST "shoot_background.plist"
#define SHOOT_PLIST "shoot.plist"
#define BULLET_ZORDER 1
#define PLAYER_ZORDER 2
#define ENEMY_ZORDER 3
#define BONUS_ZORDER 4
// Background
#define BACKGROUND_IMAGE "background.png"

//Player
#define HERO_IMAGE1 "hero1.png"
//Touch
#define TOUCH_LAYER_PRIORITY 0
#define PLAYER_LEVEL 1
#define PLAYER_ZORDER 1


//Bullet
#define DEFAULT_Bullet_LEVEL 1
#define DOUBLE_BULLET_LEVEL 2
#define NORMAL_BULLET_IMAGE "bullet1.png"
#define DOUBLE_BULLET_IMAGE "bullet2.png"
#define MAX_NORMAL_BULLET_NUM 5
#define MAX_DOUBLE_BULLET_NUM 5

#define USE_BIG_BOMB "use bigbomb"

//Bonus
#define MAX_BONUS_TYPE_NUM 2
#define BONUS_APPEAR_DURATION 3
#define BONUS_TYPE_BEGIN_NUM 1
//Enemy
#define ENEMY_TYPE_NUM 3
#define SMALL_ENEMY_IMAGE "enemy1.png"
#define MIDDLE_ENEMY_IMAGE "enemy2.png"
#define BIG_ENEMY_IMAGE "enemy3_n1.png"

const int ENEMY_ANIMATION_FRAMES_NUM[ENEMY_TYPE_NUM + 1] = {-1, 4, 4, 6};
const int ENEMY_HP[ENEMY_TYPE_NUM + 1] = {-1, 1, 3, 5};

//each type of Enemy objects' number in its list when initialized
#define MAX_SMALL_ENEMY_NUM 5
#define MAX_MIDDLE_ENEMY_NUM 5
#define MAX_BIG_ENEMY_NUM 5

#define SMALL_ENEMY_RATE 2
#define MIDDLE_ENEMY_RATE 5
#define BIG_ENEMY_RATE 7

//Animation frame number
#define BIG_ENEMY_ANIMATION_NUM 2

//Enemy level
#define DEFAULT_Enemy_LEVEL 1

#define ENEMY_APPEAR_DURATION 0.3
#define ENEMY_TYPE_NUM 3

#define ALL_ENEMY_BLOW "all die"

//Enemy Manager
#define ENEMY_MANAGER_JSON_INDEX 0

//Bullet Manager
#define STOP_SHOOT "stop shoot"

////collision detect
#define ENEMY_FLAG 1
#define BULLET_FLAG 1<<1
#define PLAYER_FLAG 1<<2
#define BONUS_FLAG 1<<3
#define JUDGE_OFFSET 0
#define ENEMY_BULLET_COL 3<<JUDGE_OFFSET
#define ENEMY_PLAYER_COL 5<<JUDGE_OFFSET
#define PLAYER_BONUS_COL 12<<JUDGE_OFFSET

#define ADD_ENTITY_TO_COL_LIST "add to col"
#define REMOVE_ENTITY_FROM_COL_LIST "delete from col"

/*********** GameOverScene ****************/
#define GAME_OVER_SIGNAL "game over"
/*********** GameWinScene ****************/

/*********** JsonFile *******************/
#define ENEMY_JSON_INDEX 0
#define PLAYER_JSON_INDEX 1
#define BULLET_JSON_INDEX 2
#define BONUS_JSON_INDEX 3

#endif /* defined(__ddl_plane__MacroParam__) */
