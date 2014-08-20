//
//  GameModeIcon.h
//  FingerHero
//
//  Created by AIRIA on 14-8-20.
//
//

#ifndef __FingerHero__GameModeIcon__
#define __FingerHero__GameModeIcon__

#include "BaseSprite.h"

class GameModeIcon:public Node
{
public:
    virtual void onEnter();
    virtual void onExit();
    virtual bool init();
    static GameModeIcon *create(std::string name,ModeIconType type);
    CC_SYNTHESIZE(std::string , m_sName, Name);
    CC_SYNTHESIZE(ModeIconType, m_eType, Type);
    
protected:
    static void touchHandler(Ref *pSender);
};

#endif /* defined(__FingerHero__GameModeIcon__) */
