//
//  HomeScene.h
//  FingerHero
//
//  Created by AIRIA on 14-8-19.
//
//

#ifndef __FingerHero__HomeScene__
#define __FingerHero__HomeScene__

#include "BaseLayer.h"

class HomeScene:public BaseLayer
{
public:
    virtual bool init();
    virtual void onEnter();
    CREATE_FUNC(HomeScene);
private:
    void showTitleLine();
    void showLoginIcon();
    void showGameMode();
    void showCopyright();
};

#endif /* defined(__FingerHero__HomeScene__) */
