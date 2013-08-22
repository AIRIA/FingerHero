//
//  ExitConfirm.h
//  FingerHero
//
//  Created by AIRIA on 14-8-20.
//
//

#ifndef __FingerHero__ExitConfirm__
#define __FingerHero__ExitConfirm__

#include "BaseLayer.h"

class ExitConfirm:public BaseLayer
{
public:
    void initBgLayer();
    
    virtual void onEnter();
    virtual bool init();
    CREATE_FUNC(ExitConfirm);
protected:
    void runFadeAction(Node *node,float duration,float alpha);
    void hideExitWindow(float delay=0.1f);
};

#endif /* defined(__FingerHero__ExitConfirm__) */
