//
//  BaseLayer.cpp
//  FingerHero
//
//  Created by AIRIA on 14-8-19.
//
//

#include "BaseLayer.h"

bool BaseLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }
    m_WinSize = Director::getInstance()->getWinSize();
    
    auto m_fScaleWidth = m_WinSize.width/DESIGN_WIDTH;
    auto m_fScaleHeight = m_WinSize.height/DESIGN_HEIGHT;
    m_fScaleFactor = m_fScaleWidth>m_fScaleHeight?m_fScaleWidth:m_fScaleHeight;
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