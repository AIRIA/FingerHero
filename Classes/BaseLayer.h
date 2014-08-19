//
//  BaseLayer.h
//  FingerHero
//
//  Created by AIRIA on 14-8-19.
//
//

#ifndef __FingerHero__BaseLayer__
#define __FingerHero__BaseLayer__

#include "CommonHeaders.h"

class BaseLayer:public Layer
{
public:
    virtual bool init();
    CREATE_FUNC(BaseLayer);
    virtual void run();
protected:
    SpriteFrameCache *m_pSpriteFrameCache;
    Size m_WinSize;
    float m_fScaleFactor;
};

#endif /* defined(__FingerHero__BaseLayer__) */
