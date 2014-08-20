//
//  BaseLayer.cpp
//  FingerHero
//
//  Created by AIRIA on 14-8-19.
//
//

#include "BaseLayer.h"

void BaseLayer::onEnter()
{
    Layer::onEnter();
    m_pBody = __createScaleLayer(Point::ANCHOR_MIDDLE, VisibleRect::center());
    m_pHeader = __createScaleLayer(Point::ANCHOR_MIDDLE_TOP, VisibleRect::top());
    m_pFooter = __createScaleLayer(Point::ANCHOR_MIDDLE_BOTTOM, VisibleRect::bottom());
}

bool BaseLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    m_WinSize = Director::getInstance()->getWinSize();
    m_fScaleFactor = m_WinSize.width/DESIGN_WIDTH;
    m_pSpriteFrameCache = SpriteFrameCache::getInstance();
    
    return true;
}

void BaseLayer::run()
{
    auto scene = Scene::create();
    scene->addChild(this);
    auto runningScene = Director::getInstance()->getRunningScene();
    if (runningScene==nullptr)
    {
        Director::getInstance()->runWithScene(scene);
    }
    else
    {
        Director::getInstance()->replaceScene(scene);
    }
}

auto BaseLayer::__createScaleLayer(const cocos2d::Point &anchorPoint, const cocos2d::Point &position) -> Layer*
{
    auto layer = Layer::create();
    layer->setContentSize(Size(DESIGN_WIDTH,DESIGN_HEIGHT));
    layer->setScale(m_fScaleFactor);
    layer->ignoreAnchorPointForPosition(false);
    layer->setAnchorPoint(anchorPoint);
    layer->setPosition(position);
    this->addChild(layer);
    return layer;
}