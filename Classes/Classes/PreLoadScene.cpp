//
//  PreLoadScene.cpp
//  Airfight
//
//  Created by xiang on 2017/7/15.
//
//

#include "PreLoadScene.hpp"
#include "GameScene.hpp"

USING_NS_CC;

Scene *PreLoad::createScene() {
    
    auto scene = Scene::create();
    auto layer = PreLoad::create();
    scene->addChild(layer);
    return scene;

}

bool PreLoad::init() {
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    // 创建一个进度条
    auto barSprite = Sprite::create("loadingbar.png");
    // 初始化一个ProgressTimer进度条对象
    _progress = ProgressTimer::create(barSprite);
    // setPercentage:0.0f，表示并未加载任何资源，表现在屏幕上就是什么也看不见
    _progress->setPercentage(0.0f);
    // 由于图片大小关系，把scale设置成0.5，即缩小一半
    _progress->setScale(1.5f);
    // 设置进度条动画的起始位置，默认在图片的中点
    // 如果想要显示从左到右的一个动画效果，必须改成(0,y)
    _progress->setMidpoint(Point(0.0f, 0.5f));
    // barChangeRate表示是否改变水平或者垂直方向的比例，设置成1表示改变，0表示不改变
    _progress->setBarChangeRate(Point(1.0f,0.0f));
    // kCCProgressTimerTypeBar表示为条形进度条
    _progress->setType(ProgressTimer::Type::BAR);
    // 设置进度条位置在屏幕中心
    _progress->setPosition(Vec2(visibleSize.width/2+30, visibleSize.height/2));
    // 将进度条添加为当前层的子节点
    this->addChild(_progress);
    
    return true;
}

void PreLoad::onEnterTransitionDidFinish() {
    
    // 调用父类的onEnter方法
    Layer::onEnterTransitionDidFinish();
    /*
     注意：cocos2d-x3.0之后，Array和Dictionary都被废弃了，使用Vector和map替代
     cocos2d-x3.0新增数据类型Value，可以存储各种基本数据类型
     ValueVector就是保存Value的Vector集合：typedef std::vector<Value> ValueVector;
     ValueMap就是保存Value的Map集合：typedef std::unordered_map<std::string, Value> ValueMap;
     
     map{Sounds:{Vector(b0.map,b1.ma3)}}
     */
    // 加载preloadResources.plist配置文件,读取文件中的游戏资源名称列表，返回一个ValueMap对象
    ValueMap map = FileUtils::getInstance()->getValueMapFromFile("preloadResources.plist");
    // 通过key值取出每种不同类型资源的ValueVector数组
    ValueVector spriteSheets = map.at("SpriteSheets").asValueVector();
    ValueVector effects = map.at("Sounds").asValueVector();
    ValueVector musics = map.at("Musics").asValueVector();
    // 多个ValueVector数组的size相加得到需要加载的资源总数量
    _sourceCount = (unsigned int)spriteSheets.size() + (unsigned int)effects.size() + (unsigned int)musics.size();
    // 设置进度条更新次数=100/需要加载的资源数量
    _progressInterval = 100 / _sourceCount;
    // 依次加载资源
    loadMusic(musics);
    loadEffect(effects);
    loadSpriteSheets(spriteSheets);

}

// 加载背景音乐
void PreLoad::loadMusic(ValueVector musicFiles) {
    for (Value &v : musicFiles) {
        SimpleAudioEngine::getInstance()->preloadBackgroundMusic(v.asString().c_str());
        progressUpdate();
    }
}

// 加载声音
void PreLoad::loadEffect(ValueVector effectFiles) {
    for (Value &v:effectFiles) {
        SimpleAudioEngine::getInstance()->preloadEffect(v.asString().c_str());
        progressUpdate();
    }
}

// 加载精灵表单
void PreLoad::loadSpriteSheets(ValueVector spriteSheets) {
    /* 该函数会加载与plist文件名称相同但后缀为.png的纹理图片，把该plist的所有spriteFrame信息读取出来
     在之后的代码中可以通过
     Sprite::createWithSpriteFrameName(const std::string& spriteFrameName)函数获取对应的精灵帧
     本例中airfightSheet.plist对应airfightSheet.png
     */
    for (Value &v:spriteSheets) {
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(v.asString().c_str());
        progressUpdate();
    }
}

// 进度条更新函数
void PreLoad::progressUpdate() {
    // 每次调用该函数说明加载一个资源，自减更新资源总数
    if (--_sourceCount) {
        // 设置进度条百分比
        _progress->setPercentage(100.0f-(_progressInterval * _sourceCount));
    } else {
        // ProgressFromTo动作以渐进的方式显示图片
        // 第一个参数表示持续0.5秒，第二个参数表示进度条百分比开始，第三个参数表示一直到100
        auto pft = ProgressFromTo::create(0.5f, _progress->getPercentage(), 100);
        // 定义了一个CallFunc动作
        auto callFunc = CallFunc::create([=]{
            // 当加载资源完成，延迟2秒跳转到游戏主场景
            auto delay = DelayTime::create(2.0f);
            auto callFunc = CallFunc::create([]{
                Director::getInstance()->replaceScene(Game::createScene());
            });
            auto action = Sequence::create(delay, callFunc, NULL);
            this->runAction(action);
        });
        auto action = Sequence::create(pft, callFunc, NULL);
        // 进度条执行动作
        _progress->runAction(action);
    }
}

















