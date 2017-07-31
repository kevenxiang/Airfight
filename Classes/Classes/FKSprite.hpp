//
//  FKSprite.hpp
//  Airfight
//
//  Created by xiang on 2017/7/27.
//
//

#ifndef FKSprite_hpp
#define FKSprite_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;

//自定义精灵类
class FKSprite : public cocos2d::Sprite {
private:
    //生命值
    int _lifeValue;
    //血条
    LoadingBar *_HP;
    //血条的更新量
    float _HPInterval;
public:
    // 静态的create函数
    static FKSprite *createWithSpriteFrameName(const std::string filename) {
        FKSprite *sprite = new FKSprite();
        if (sprite && sprite->initWithSpriteFrameName(filename)) {
            sprite->autorelease();
            return sprite;
        }
        CC_SAFE_DELETE(sprite);
        return nullptr;
    }
    
    // setter和getter
    void setLifeValue(int lifeValue) {
        _lifeValue = lifeValue;
    }
    
    int getLifeValue() {
        return _lifeValue;
    }
    
    void setHP(LoadingBar *HP) {
        _HP = HP;
    }
    
    LoadingBar *getHP() {
        return _HP;
    }
    
    void setHPInterval(float HPInterval) {
        _HPInterval = HPInterval;
    }
    
    float getHPInterval() {
        return _HPInterval;
    }

};

#endif /* FKSprite_hpp */


























