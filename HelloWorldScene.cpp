#include "HelloWorldScene.h"
#include "shader/Shaders.hpp"
#include "shader/shaderaction/ChangeColorBy.hpp"

USING_NS_CC;

Scene* HelloWorld::createScene() {
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init() {
    //////////////////////////////
    // 1. super init first
    if (!LayerColor::initWithColor(Color4B(150, 100, 150, 0))) {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png", "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    closeItem->setPosition(Vec2(
        origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
        origin.y + closeItem->getContentSize().height / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label =
        Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);

    // position the label on the center of the screen
    label->setPosition(
        Vec2(origin.x + visibleSize.width / 2,
             origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                             visibleSize.height / 2 + origin.y));

    auto spr2 = Sprite::create("HelloWorld.png");
    spr2->setPosition(Vec2(visibleSize.width / 2 + origin.x - 100,
                           visibleSize.height / 2 + origin.y));

    /*
    {
        auto s = GLProgram::createWithByteArrays(cocos2d::LightHsvShaderVert,
                                                 cocos2d::LightHsvShaderFrag);
        auto state = GLProgramState::getOrCreateWithGLProgram(s);
        sprite->setGLProgramState(state);
        state->setUniformVec3("u_color", Vec3(0.2, 0.0, 0.0));
    }*/
    auto change = ChangeColorBy::create(ChangeColorType::HSV,
                                        Vec3(1.0, -1.0, 1.0), false, 1.0);
    sprite->runAction(Sequence::create(DelayTime::create(5.0), change,
                                       FadeOut::create(0.5), NULL));

    {
        auto s = GLProgram::createWithByteArrays(cocos2d::LightHsvShaderVert,
                                                 cocos2d::LightHsvShaderFrag);
        auto state = GLProgramState::getOrCreateWithGLProgram(s);
        spr2->setGLProgramState(state);
        state->setUniformVec3("u_color", Vec3(0.0, 0.0, 0.0));
    }

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    this->addChild(spr2, 1);

    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender) {
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
