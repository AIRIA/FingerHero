//
//  BaseSprite.cpp
//  CatchPanda
//
//  Created by AIRIA on 14-8-13.
//
//

#include "BaseSprite.h"

BaseSprite *BaseSprite::create(std::string fileName)
{
    auto sprite = new BaseSprite();
    if(sprite&&sprite->initWithSpriteFrameName(fileName))
    {
        sprite->autorelease();
        sprite->addEventListener();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return nullptr;
}

void BaseSprite::setTouchHandler(std::function<void(Ref *pSender)> callback)
{
    this->touchHandler = callback;
}
void BaseSprite::setTouchBegan(std::function<void(Ref *pSender)> callback)
{
    this->beganHandler = callback;
}
void BaseSprite::setTouchMoved(std::function<void(Ref *pSender)> callback)
{
    this->moveHandler = callback;
}

bool BaseSprite::isContainPoint(cocos2d::Touch *touch)
{
    auto locationNode = convertToNodeSpace(touch->getLocation());
    auto size = getContentSize();
    auto rect = Rect(0, 0, size.width, size.height);
    return rect.containsPoint(locationNode);
}


void BaseSprite::addEventListener()
{
    auto eventListener = EventListenerTouchOneByOne::create();
    eventListener->setSwallowTouches(true);
    eventListener->onTouchBegan = [](Touch *touch,Event *event)->bool
    {
        auto target = static_cast<BaseSprite*>(event->getCurrentTarget());
       
        if(target->isContainPoint(touch))
        {
            if (target->beganHandler)
            {
                target->beganHandler(target);
            }
            return true;
        }
        return false;
        
    };
    
    eventListener->onTouchMoved = [](Touch *touch,Event *event)->void
    {
        auto target = static_cast<BaseSprite*>(event->getCurrentTarget());
        if(target->moveHandler)
        {
            target->moveHandler(target);
        }
    };
    
    eventListener->onTouchEnded = [](Touch *touch,Event *event)->void
    {
        auto target = static_cast<BaseSprite*>(event->getCurrentTarget());
        target->setColor(Color3B::WHITE);
        if(target->isContainPoint(touch))
        {
            if(target->touchHandler)
            {
                target->touchHandler(target);
            }
        }
        
    };
    
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);
}