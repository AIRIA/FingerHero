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
    virtual void onEnter();
    virtual bool init();
    CREATE_FUNC(ExitConfirm);
};

#endif /* defined(__FingerHero__ExitConfirm__) */
