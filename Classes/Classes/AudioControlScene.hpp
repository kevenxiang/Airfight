//
//  AudioControlScene.hpp
//  Airfight
//
//  Created by xiang on 2017/7/15.
//
//

#ifndef AudioControlScene_hpp
#define AudioControlScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "extensions/GUI/CCControlExtension/CCControlSlider.h"
#include "MenuScene.hpp"
using namespace CocosDenshion;
using namespace cocos2d::extension;

class AudioControl : public cocos2d::Layer {
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();
    
    CREATE_FUNC(AudioControl);
};

#endif /* AudioControlScene_hpp */
