//
//  Arrow.h
//  FingerHero
//
//  Created by AIRIA on 14-8-25.
//
//

#ifndef __FingerHero__Arrow__
#define __FingerHero__Arrow__

#include "CommonHeaders.h"

class Arrow:public Sprite
{
public:
    static Arrow *create(ArrowType arrowType);
    
    CC_SYNTHESIZE(ArrowType, m_eArrowType, ArrowType);
};

#endif /* defined(__FingerHero__Arrow__) */
