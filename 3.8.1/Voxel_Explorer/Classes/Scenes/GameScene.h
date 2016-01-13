//
//  GameScene.h
//  Voxel_Explorer
//
//  Created by wang haibo on 15/9/24.
//
//

#ifndef __Voxel_Explorer__GameScene__
#define __Voxel_Explorer__GameScene__

#include "cocos2d.h"
#include "LoadingLayer.hpp"
class LoadingLayer;
class GameScene : public cocos2d::Layer
{
    GameScene();
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init() override;
    
    CREATE_FUNC(GameScene);
    
    virtual void onEnter() override;
    virtual void onExit() override;
    virtual void update(float delta) override;
private:
    float timedt;
    bool isLoading;
    LoadingLayer* loadingLayer;
};

#endif /* defined(__Voxel_Explorer__GameScene__) */
