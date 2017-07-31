//
//  GameScene.hpp
//  Airfight
//
//  Created by xiang on 2017/7/27.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "FKSprite.hpp"
#include "MenuScene.hpp"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

USING_NS_CC;

class Game : public cocos2d::Layer {
private:
    // 游戏背景图
    Sprite *_bg1;
    Sprite *_bg2;
    //玩家分机变量
    Sprite *_plane;
    // 屏幕宽度、高度的变量
    int _screenWidth, _screenHeight;
    // 游戏帧计数器
    int _count;
    // 敌机数组
    Vector<FKSprite *> _enemyVector;
    //子弹数组
    Vector<Sprite *> _bulletVector;
    // 分数值标签
    Label *_scoreLabel;
    // 分数
    int _scoreValue;
    // 大Boss
    FKSprite *_boss;
    // 大Boss子弹精灵数组
    Vector<Sprite *> _bossBulletVector;
    // 是否启动大Boss、大Boss是否开始移动和大Boss是否发射子弹
    bool _isStart,_isMove,_isShoot;
public:
    /**
     * 静态函数，创建Scene场景
     * 注意：在Cocos2d-x中没有Cocos2d-iPhone中的“id”,建议返回类实例的指针
     */
    static cocos2d::Scene *createScene();
    /**
     * init函数，完成初始化操作。
     * 注意：init函数在Cocos2d-x中返回bool值，而不是返回Cocos2d-iPhone中的“id”
     */
    virtual bool init();
    
    // 当Node节点进入“舞台”时调用
    virtual void onEnter();
    
    // 回调更新函数，该函数每一帧都会调用
    void update(float delta);
    // 背景图片滚动函数
    void updateBackground();
    // 更新玩家积分
    void updateHUD(float delta);
    
    // 更新敌机函数
    void enemyPlaneDive(float delta);
    // 敌机离开屏幕删除函数
    void removeEnemy(float delta);
    
    // 玩家飞机不断发射子弹函数
    void shootBullet(float delta);
    // 子弹离开屏幕删除函数
    void removeBullet(float delta);
    // 检测碰撞的函数
    void collisionDetection(float delta);
    
    // 获得动画函数
    Animation *getAnimationByName(std::string animName,float delay,int animNum);
    // 播放爆炸动画
    void playBombAnimate(std::string name,Vec2 position);
    
    // 启动大Boss
    void startBoss();
    // 移动大Boss
    void moveBoss();
    // 大Boss发射炮弹
    void shootBoss(float delta);
    
    // 游戏结束
    void gameOver(std::string message);
    // 重新开始
    void restart(int tag);
    
    /**
     * 使用CREATE_FUNC宏创建当前类的对象，返回的对象将会由自动释放池管理内存的释放
     */
    CREATE_FUNC(Game);
};

#endif /* GameScene_hpp */

































