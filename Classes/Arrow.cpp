//
//  Arrow.cpp
//  FingerHero
//
//  Created by AIRIA on 14-8-25.
//
//

#include "Arrow.h"

Arrow *Arrow::create(ArrowType arrowType)
{
    auto arrow = new Arrow();
    std::string fileName = "";
    switch (arrowType) {
        case kArrowUp:
            fileName = "up.png";
            break;
        case kArrowDown:
            fileName = "down.png";
            break;
        case kArrowLeft:
            fileName = "left.png";
            break;
        case kArrowRight:
            fileName = "right.png";
            break;
        case kArrowPoint:
            fileName = "point.png";
            break;
        default:
            break;
    }
    
    if(arrow&&arrow->initWithSpriteFrameName(fileName))
    {
        arrow->autorelease();
        return arrow;
    }
    CC_SAFE_DELETE(arrow);
    return nullptr;
}