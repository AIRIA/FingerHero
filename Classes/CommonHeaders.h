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

using namespace cocos2d;

#define DESIGN_WIDTH 640
#define DESIGN_HEIGHT 960

#define EVENT_SELECT_GAME_MODE "select_game_mode"//选择完游戏模式后派发
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
