//
//  HomeScene.cpp
//  FingerHero
//
//  Created by AIRIA on 14-8-19.
//
//

#include "HomeScene.h"
#include "BaseSprite.h"
#include "GameModeIcon.h"
#include "ExitConfirm.h"

#define ACTION_TIME 0.3f

bool HomeScene::init()
{
    if(!BaseLayer::init())
    {
        return false;
    }
    m_pSpriteFrameCache->addSpriteFramesWithFile("texture.plist");
    auto bg = LayerColor::create(Color4B(232,242,253,255), m_WinSize.width, m_WinSize.height);
    addChild(bg);
    return true;
}

void HomeScene::onEnter()
{
    BaseLayer::onEnter();
    showLoginIcon();
    showCopyright();
    showTitleLine();
    showGameMode();
    getEventDispatcher()->addCustomEventListener(EVENT_SHOW_EXIT, [](EventCustom *eventCustom)->void{
        if (isShowExit==false)
        {
            Director::getInstance()->getRunningScene()->addChild(ExitConfirm::create());
            isShowExit = true;
        }
        else
        {
            isShowExit = false;
            Director::getInstance()->getEventDispatcher()->dispatchEvent(new EventCustom(EVENT_HIDE_EXIT));
        }
    });
    
}

void HomeScene::showTitleLine()
{
    auto addLine = [](std::string title,Point position,Node *parent)->void{
        auto wrapper = Node::create();
        auto leftLine = Sprite::createWithSpriteFrameName("line.png");
        auto rightLine = Sprite::createWithSpriteFrameName("line.png");
        auto lineWidth = leftLine->getContentSize().width;
        auto lineHeight = leftLine->getContentSize().height;
        
        auto scaleX = (DESIGN_WIDTH-170)/lineWidth/2.0;
        auto scaleY = 10/lineHeight;
        leftLine->setScale(scaleX, scaleY);
        rightLine->setScale(scaleX, scaleY);
    
        leftLine->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
        rightLine->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
        leftLine->setPosition(Point(-300,0));
        rightLine->setPosition(Point(DESIGN_WIDTH+300,0));
        leftLine->runAction(MoveBy::create(ACTION_TIME, Point(300,0)));
        rightLine->runAction(MoveBy::create(ACTION_TIME, Point(-300,0)));
        wrapper->addChild(leftLine);
        wrapper->addChild(rightLine);
        auto titleLabel = Label::createWithSystemFont(title, GAME_FONT, 40);
        titleLabel->setColor(Color3B::BLACK);
        titleLabel->setPosition(Point(DESIGN_WIDTH/2,0));
        wrapper->addChild(titleLabel);
        wrapper->setPosition(position);
        parent->addChild(wrapper);
    };
    
    addLine("指尖狂人",Point(0,DESIGN_HEIGHT-50),m_pHeader);
    addLine("登录",Point(0,200),m_pFooter);
}

void HomeScene::showLoginIcon()
{
    auto show = [this](std::string fileName,Point position,float delay,std::function<void(Ref *target)> handler)->void{
        auto icon = BaseSprite::create(fileName);
        icon->setTouchHandler(handler);
        icon->setPosition(position-Point(0,200));
        auto showAction = MoveBy::create(ACTION_TIME, Point(0,200));
        icon->runAction(Sequence::create(DelayTime::create(delay),EaseBackOut::create(showAction), nullptr));
        m_pFooter->addChild(icon);
    };
    
    auto offset = 130;
    
    show("login_wechat.png",Point(offset,100),0.2,[](Ref *target)->void{
        MessageBox("微信登录", "BOX");
    });
    show("login_weibo.png",Point(DESIGN_WIDTH/2,100),ACTION_TIME/2+0.2,[](Ref *target)->void{
        MessageBox("微博登录", "BOX");
    });
    show("login_tencent.png",Point(DESIGN_WIDTH-offset,100),ACTION_TIME+0.2,[](Ref *target)->void{
        MessageBox("QQ登录", "BOX");
    });
}

struct GameMode
{
    std::string name;
    ModeIconType type;
};

void HomeScene::showGameMode()
{
    std::vector<GameMode> modes = {{"经典",kModeTypeClassic},{"街机",kModeTypeArcade},{"急速",kModeTypeSpeed},
    {"双向",kModeTypeDouble},{"PK",kModeTypePK},{"反向",kModeTypeReverse},
    {"设定",kModeTypeSetting},{"排行",kModeTypeRank},{"评分",kModeTypeGrade}};
    
    auto gapH = (DESIGN_WIDTH-200)/2;
    auto gapV = 180;
    for(auto i=0;i<modes.size();i++)
    {
        auto row = i/3;
        auto col = i%3;
        auto gameMode = modes.at(i);
        auto icon = GameModeIcon::create(gameMode.name,gameMode.type);
        icon->setPosition(Point(col*gapH+100,DESIGN_HEIGHT-row*gapV-170));
        m_pHeader->addChild(icon);
    }
}

void HomeScene::showCopyright()
{
    auto label = Label::createWithSystemFont("2014-1015 完美计划版权所有", GAME_FONT, 18);
    label->setColor(Color3B::BLACK);
    label->setPosition(Point(DESIGN_WIDTH/2,20));
    m_pFooter->addChild(label);
}

