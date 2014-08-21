//
//  CommonHeaders.h
//  FingerHero
//
//  Created by AIRIA on 14-8-19.
//
//

#ifndef FingerHero_CommonHeaders_h
#define FingerHero_CommonHeaders_h

#include "cocos2d.h"
#include "VisibleRect.h"
#include "ShareVars.h"

using namespace cocos2d;

#define DESIGN_WIDTH 640
#define DESIGN_HEIGHT 960

#define EVENT_SELECT_GAME_MODE             "select_game_mode"//选择完游戏模式后派发
#define EVENT_SHOW_EXIT                    "show_exit"       //显示退出的确认面板
#define EVENT_HIDE_EXIT                    "hide_exit"

#define GAME_FONT              "Droid Sans Fallback"

enum ModeIconType{
    kModeTypeClassic,
    kModeTypeArcade,
    kModeTypePK,
    kModeTypeDouble,
    kModeTypeSpeed,
    kModeTypeSetting,
    kModeTypeRank,
    kModeTypeGrade,
    kModeTypeReverse
};



#endif
