//
//  MenuScene.hpp
//  Airfight
//
//  Created by xiang on 2017/7/15.
//
//

#ifndef MenuScene_hpp
#define MenuScene_hpp

#include <stdio.h>
#include "cocos2d.h"

class GameMenu : public cocos2d::Layer {
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();
    
    CREATE_FUNC(GameMenu);

};


#endif /* MenuScene_hpp */
