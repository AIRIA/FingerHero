//
//  BaseSprite.h
//  CatchPanda
//
//  Created by AIRIA on 14-8-13.
//
//

#ifndef __CatchPanda__BaseSprite__
#define __CatchPanda__BaseSprite__

#include "CommonHeaders.h"

class BaseSprite:public Sprite
{
public:
    static BaseSprite *create(std::string fileName);
    void setTouchHandler(std::function<void(Ref *pSender)> callback);
    void setTouchBegan(std::function<void(Ref *pSender)> callback);
    void setTouchMoved(std::function<void(Ref *pSender)> callback);
    
protected:
    void addEventListener();
    std::function<void(Ref *pSender)> touchHandler = nullptr;
    std::function<void(Ref *pSender)> moveHandler = nullptr;
    std::function<void(Ref *pSender)> beganHandler = nullptr;
    
    bool isContainPoint(Touch *touch);
};

#endif /* defined(__CatchPanda__BaseSprite__) */
