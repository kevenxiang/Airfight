//
//  MenuScene.cpp
//  Airfight
//
//  Created by xiang on 2017/7/15.
//
//

#include "MenuScene.hpp"
#include "ui/CocosGUI.h"
#include "PreLoadScene.hpp"
#include "AudioControlScene.hpp"

USING_NS_CC;
using namespace ui;

Scene *GameMenu::createScene() {
    auto scene = Scene::create();
    auto layer = GameMenu::create();
    scene->addChild(layer);
    return scene;
}

bool GameMenu::init() {
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getWinSize();
    
    //"开始游戏" 按钮
    auto start_button = Button::create("button.png");
    start_button->setScale(3);
    start_button->setTitleText("开始游戏");
    start_button->setTitleFontName("");
    start_button->setTitleFontSize(5);
    start_button->setPosition(Vec2(visibleSize.width/2, visibleSize.height * 0.7));
    start_button->addTouchEventListener([](Ref *pSender,Widget::TouchEventType type){
        if (type == Widget::TouchEventType::ENDED) {
            //切换到Preload场景
            auto transition = TransitionSlideInL::create(2.0, PreLoad::createScene());
            Director::getInstance()->replaceScene(transition);
        }
    });
    this->addChild(start_button);
    
    //"游戏设置"按钮
    auto set_button = Button::create("button.png");
    set_button->setScale(3);
    set_button->setTitleText("游戏设置");
    set_button->setTitleFontName("");
    set_button->setTitleFontSize(5);
    set_button->setPosition(Vec2(visibleSize.width/2, visibleSize.height * 0.55));
    set_button->addTouchEventListener([](Ref *pSender,Widget::TouchEventType type){
        if (type == Widget::TouchEventType::ENDED) {
            //切换到AudioControl场景
            auto transition = TransitionSlideInL::create(2.0f, AudioControl::createScene());
            Director::getInstance()->replaceScene(transition);
        }
    });
    this->addChild(set_button);
    
    //“退出游戏”按钮
    auto close_button = Button::create("button.png");
    close_button->setScale(3);
    close_button->setTitleText("退出游戏");
    close_button->setTitleFontName("");
    close_button->setTitleFontSize(5);
    close_button->setPosition(Vec2(visibleSize.width/2, visibleSize.height * 0.4));
    close_button->addTouchEventListener([](Ref *pSender, Widget::TouchEventType type){
        if (type == Widget::TouchEventType::ENDED) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
            MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
            return;
#endif
            Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
            exit(0);
#endif
        }
    });
    this->addChild(close_button);
    
    // 公司名
    auto banner_text = Text::create("疯狂软件", "Arial-BoldMT", 10);
    banner_text->setPosition(Vec2(visibleSize.width/2, visibleSize.height*0.18));
    this->addChild(banner_text);
    
    // 网址
    auto email_text = Text::create("www.fkit.org", "Arial-BoldMT", 10);
    email_text->setPosition(Vec2(visibleSize.width/2, visibleSize.height*0.14));
    this->addChild(email_text);
    
    return true;
}






































