//
//  GameModeIcon.cpp
//  FingerHero
//
//  Created by AIRIA on 14-8-20.
//
//

#include "GameModeIcon.h"
#include "ExitConfirm.h"

enum Tag{
    kTagCircle
};

GameModeIcon *GameModeIcon::create(std::string name,ModeIconType type)
{
    auto icon = new GameModeIcon();
    if(icon && icon->init())
    {
        icon->autorelease();
        icon->setName(name);
        icon->setType(type);
        return icon;
    }
    CC_SAFE_FREE(icon);
    return nullptr;
}

bool GameModeIcon::init()
{
    if(!Node::init())
    {
        return false;
    }
    
    auto stopEvent = EventListenerCustom::create(EVENT_SELECT_GAME_MODE, [this](EventCustom *customEvent)->void{
        auto userData = customEvent->getUserData();
        auto type = static_cast<ModeIconType*>(userData);
        if (*type!=getType())
        {
            auto circle = static_cast<BaseSprite*>(getChildByTag(kTagCircle));
            circle->stopAllActions();
        }
    });
    
    getEventDispatcher()->addEventListenerWithFixedPriority(stopEvent, 1);
    
    return true;
}

void GameModeIcon::onEnter()
{
    Node::onEnter();
    auto circle = BaseSprite::create("circle.png");
    auto direction = rand()%2;
    if(direction==0)
    {
        direction = -1;
    }
    auto duration = rand()%5/10+0.3;
    auto degree = rand()%20+5;
    auto rotateBy = RotateBy::create(duration, degree*direction);
    circle->runAction(RepeatForever::create(rotateBy));
    circle->setTag(kTagCircle);
    addChild(circle);
    circle->setTouchHandler([this](Ref *pSender)->void{
        auto target = static_cast<BaseSprite*>(pSender);
        target->setColor(Color3B::YELLOW);
        target->getEventDispatcher()->removeEventListenersForTarget(target);
        EventCustom event(EVENT_SELECT_GAME_MODE);
        auto userData = &m_eType;
        event.setUserData(userData);
        this->getEventDispatcher()->dispatchEvent(&event);
        Director::getInstance()->getRunningScene()->addChild(ExitConfirm::create());
    });
    auto label = Label::createWithSystemFont(m_sName, GAME_FONT, 40);
    label->setPositionY(5);
    addChild(label);
}

void GameModeIcon::onExit()
{
    Node::onExit();
    getEventDispatcher()->removeEventListenersForTarget(this);
}

void GameModeIcon::touchHandler(cocos2d::Ref *pSender)
{
    
}
