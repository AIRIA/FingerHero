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
    virtual void run();
    virtual void onEnter();
    CREATE_FUNC(BaseLayer);

protected:
    SpriteFrameCache *m_pSpriteFrameCache;
    Layer *m_pBody,*m_pHeader,*m_pFooter;
    
    Size m_WinSize;
    float m_fScaleFactor;
    
    Layer *__createScaleLayer(const Point &anchorPoint,const Point &position);
};

#endif /* defined(__FingerHero__BaseLayer__) */
