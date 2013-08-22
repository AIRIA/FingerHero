//
//  ExitConfirm.cpp
//  FingerHero
//
//  Created by AIRIA on 14-8-20.
//
//

#include "ExitConfirm.h"
#include "BaseSprite.h"

#define ALERT_TIME 0.2f

enum Tag{
    kTagBgLayer,
    kTagPopNode,
    kTagLeftNode,
    kTagRightNode
};

bool ExitConfirm::init()
{
    if(!BaseLayer::init())
    {
        return false;
    }
    initBgLayer();
    return true;
}

void ExitConfirm::initBgLayer()
{
    auto colorLayer = LayerColor::create(Color4B(0, 0, 0, 0),m_WinSize.width,m_WinSize.height);
    colorLayer->runAction(FadeTo::create(0.2f, 128));
    colorLayer->setTag(kTagBgLayer);
    addChild(colorLayer);
    auto event = EventListenerTouchOneByOne::create();
    event->setSwallowTouches(true);
    event->onTouchBegan = [](Touch *touch,Event *event)->bool{
        return true;
    };
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(event, colorLayer);
}

void ExitConfirm::hideExitWindow(float delay)
{
    log("%s","hide exit window");
    auto fadeOut = FadeOut::create(ALERT_TIME);
    auto scaleOut = ScaleTo::create(m_fScaleFactor, ALERT_TIME);
    auto popNode = static_cast<Sprite*>(getChildByTag(kTagPopNode));
    auto target = static_cast<BaseSprite*>(popNode->getChildByTag(kTagRightNode));
    target->setColor(Color3B(255,255,255));
    popNode->runAction(Spawn::create(scaleOut, nullptr));
    auto bgLayer = static_cast<LayerColor*>(getChildByTag(kTagBgLayer));
    auto seq = Sequence::create(fadeOut->clone(),CallFunc::create(CC_CALLBACK_0(Node::removeFromParent, this)), nullptr);
    bgLayer->runAction(seq);
    this->runFadeAction(popNode, ALERT_TIME, 0);
}


void ExitConfirm::onEnter()
{
    BaseLayer::onEnter();
    auto popNode = Sprite::create();
    popNode->setTag(kTagPopNode);
    auto header = Sprite::createWithSpriteFrameName("pop_header.png");
    auto left = BaseSprite::create("pop_left.png");
    auto right = BaseSprite::create("pop_right.png");
    
    left->setAnchorPoint(Point::ANCHOR_TOP_RIGHT);
    right->setAnchorPoint(Point::ANCHOR_TOP_LEFT);
    left->setTouchBegan([](Ref *pSender)->void{
        auto target = static_cast<BaseSprite*>(pSender);
        target->setColor(Color3B(230,230,230));
    });
    
    right->setTouchBegan([](Ref *pSender)->void{
        auto target = static_cast<BaseSprite*>(pSender);
        target->setColor(Color3B(230,230,230));
    });
    
    right->setTag(kTagRightNode);
    right->setTouchHandler([&](Ref *pSender)->void{
        isShowExit = false;
    });
    
    left->setTouchHandler([](Ref *pSender)->void{
        auto target = static_cast<BaseSprite*>(pSender);
        target->setColor(Color3B(255,255,255));
        exit(0);
    });
    
    header->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    popNode->addChild(left);
    popNode->addChild(right);
    popNode->addChild(header);
    popNode->setScale(m_fScaleFactor);
    popNode->setPosition(VisibleRect::center());
    addChild(popNode);
    
    auto tip = Label::createWithSystemFont("您确定要退出么?", GAME_FONT, 35);
    tip->setColor(Color3B::BLACK);
    auto headerSize = header->getContentSize();
    tip->setPosition(Point(headerSize.width/2,headerSize.height/2));
    header->addChild(tip);
    
    auto cancle = Label::createWithSystemFont("结束", GAME_FONT, 33);
    cancle->setColor(Color3B(0,122,255));
    
    auto yes = Label::createWithSystemFont("继续玩", GAME_FONT, 33);
    yes->setColor(Color3B(0,122,255));
    left->addChild(cancle);
    right->addChild(yes);
    auto size = left->getContentSize();
    cancle->setPosition(Point(size.width/2,size.height/2+7));
    yes->setPosition(cancle->getPosition());

    popNode->setOpacity(0);
    popNode->setScale(m_fScaleFactor*1.3);
    
    auto fadeIn = FadeIn::create(ALERT_TIME);
    auto scaleAct = ScaleTo::create(ALERT_TIME, m_fScaleFactor);
    auto spawn = Spawn::create(scaleAct, nullptr);
    runFadeAction(popNode, ALERT_TIME, 255);
    popNode->runAction(spawn);
    runAction(fadeIn);
    
    getEventDispatcher()->addCustomEventListener(EVENT_HIDE_EXIT, [this](EventCustom *customEvent)->void{
        this->hideExitWindow();
        getEventDispatcher()->removeCustomEventListeners(EVENT_HIDE_EXIT);
    });
    
}

void ExitConfirm::runFadeAction(cocos2d::Node *node,float duration,float alpha)
{
    Vector<Node*> children = node->getChildren();
    auto fadeTo = FadeTo::create(duration, alpha);
    node->runAction(fadeTo);
    for (auto it = children.begin(); it!=children.end(); it++) {
        auto node = *it;
        runFadeAction(node, duration, alpha);
    }
}











