//
//  ExitConfirm.cpp
//  FingerHero
//
//  Created by AIRIA on 14-8-20.
//
//

#include "ExitConfirm.h"
#include "BaseSprite.h"

bool ExitConfirm::init()
{
    if(!BaseLayer::init())
    {
        return false;
    }
    
    auto colorLayer = LayerColor::create(Color4B(0, 0, 0, 0),m_WinSize.width,m_WinSize.height);
    colorLayer->runAction(FadeTo::create(0.2f, 128));
    addChild(colorLayer);
    return true;
}

void ExitConfirm::onEnter()
{
    BaseLayer::onEnter();
    auto popNode = Node::create();
    auto header = Sprite::createWithSpriteFrameName("pop_header.png");
    auto left = BaseSprite::create("pop_left.png");
    auto right = BaseSprite::create("pop_right.png");
    
    left->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
    right->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    header->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    popNode->addChild(left);
    popNode->addChild(right);
    popNode->addChild(header);
    left->setPosition(Point(-3,0));
    right->setPosition(Point(-3,0));
    m_pBody->addChild(popNode);
    popNode->setPosition(Point(DESIGN_WIDTH/2,DESIGN_HEIGHT/2));
    
    auto cancle = Label::createWithSystemFont("结束", GAME_FONT, 25);
    cancle->setColor(Color3B(37,142,247));

    auto yes = Label::createWithSystemFont("继续玩", GAME_FONT, 25);
    yes->setColor(Color3B(37,142,247));
    left->addChild(cancle);
    right->addChild(yes);
    auto size = left->getContentSize();
    cancle->setPosition(Point(size.width/2,size.height/2+7));
    yes->setPosition(cancle->getPosition());
    
    popNode->setOpacity(0);
    popNode->setScale(2.0);
    
    auto fadeIn = FadeIn::create(0.2f);
    auto scaleAct = ScaleTo::create(0.2f, 1.0f);
    auto spawn = Spawn::create(fadeIn,scaleAct, NULL);
    popNode->runAction(spawn);
    
}