//
//  PreLoadScene.hpp
//  Airfight
//
//  Created by xiang on 2017/7/15.
//
//

#ifndef PreLoadScene_hpp
#define PreLoadScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "MenuScene.hpp"

USING_NS_CC;
using namespace CocosDenshion;

// 3. 预加载类：完成预加载背景音乐、音效、精灵表单等准备工作
class PreLoad : public cocos2d::Layer {
protected:
    // 用来保存游戏需要加载的资源总数
    int _sourceCount;
    // 进度条
    ProgressTimer *_progress;
    // 进度条更新的次数
    float _progressInterval;
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();
    
    virtual void onEnterTransitionDidFinish();
    
    // 加载背景音乐
    void loadMusic(ValueVector musicFiles);
    // 加载游戏音效
    void loadEffect(ValueVector effectFiles);
    // 加载精灵表单
    void loadSpriteSheets(ValueVector spriteSheets);
    // 更新游戏进度条
    void progressUpdate();
    
    CREATE_FUNC(PreLoad);
};

#endif /* PreLoadScene_hpp */



















