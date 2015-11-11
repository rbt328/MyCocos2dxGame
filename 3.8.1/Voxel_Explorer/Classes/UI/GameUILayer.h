//
//  GameUILayer.h
//  Voxel_Explorer
//
//  Created by 创李 on 15/10/16.
//
//

#ifndef GameUILayer_h
#define GameUILayer_h

#include "WrapperUILayer.h"
class HudTipUi;
class TGridView;
class GameUILayer:public WrapperUILayer {
    
public:
    GameUILayer();
    virtual ~GameUILayer();
public:
    CREATE_FUNC(GameUILayer);
    virtual bool addEvents() override;
    void onEnter() override;
    void onExit()override;
protected:
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) override;
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) override;
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) override;
private:
    void onClickRole(Ref* ref);
    void onClickMap(Ref* ref);
    void onClickSearch(Ref* ref);
    void onClickDist(Ref* ref);
    void onClickMsg(Ref* ref);
    void onClickPause(Ref* ref);

    void onClickDistTipsFrame(Ref* ref);

    
    void onEventUpdateRoleProp(cocos2d::EventCustom *sender);
    void onEventRoleLevelUp(cocos2d::EventCustom *sender);
    void onEventRoleDead(cocos2d::EventCustom *sender);
    void onEvenetRoleHud(cocos2d::EventCustom *sender);
    
    
    void onEventUpdateMonsterProp(cocos2d::EventCustom *sender);
    void onEventMonsterHud(cocos2d::EventCustom *sender);
    void onEvenetMonsterDead(cocos2d::EventCustom *sender);
    
    bool checkSearchMapInfo(const cocos2d::Ray ray,std::string& infoIcon,std::string& infoDesc);
    
    bool registerTouchEvent();
    //更新角色信息
    void updateRoleUi();
    //更新怪物信息
    void updateMonsterUi();
    //更新游戏信息
    void updateGameInfo();
    //初始化消息框
    void initMessageFrame();
    //添加游戏文本信息
    void sendMessage(std::string msg,cocos2d::Color3B msgColor = cocos2d::Color3B::WHITE);
    void setMsgItem(std::string msg,cocos2d::Color3B msgColor = cocos2d::Color3B::WHITE);
private:
    bool _isOpenSmailMap;                       //是否打开小地图
    bool _isDist;
    cocos2d::ui::ListView*   m_pListMsgs;
    cocos2d::ui::ImageView*  m_pMsgFrame;
    
    cocos2d::ui::ImageView*  m_pRoleBtn;
    cocos2d::ui::LoadingBar* m_pRoleHpBar;
    cocos2d::ui::Text*       m_pRoleCurHp;
    cocos2d::ui::Text*       m_pRoleMaxHp;
    cocos2d::ui::LoadingBar* m_pRoleMpBar;
    cocos2d::ui::Text*       m_pRoleCurMp;
    cocos2d::ui::Text*       m_pRoleMaxMp;
    cocos2d::ui::LoadingBar* m_pRoleExpBar;
    cocos2d::ui::Text*       m_pRoleLevel;
    cocos2d::ui::Text*       m_pRoleName;
    cocos2d::ui::ImageView*  m_pRoleBuffers[8];
    
    cocos2d::ui::Layout*     m_pMonsterLayout;
    cocos2d::ui::ImageView*  m_pMonsterBtn;
    cocos2d::ui::LoadingBar* m_pMonsterHpBar;
    cocos2d::ui::Text*       m_pMonsterCurHp;
    cocos2d::ui::Text*       m_pMonsterMaxHp;
    cocos2d::ui::LoadingBar* m_pMonsterMpBar;
    cocos2d::ui::Text*       m_pMonsterCurMp;
    cocos2d::ui::Text*       m_pMonsterMaxMp;
    cocos2d::ui::Text*       m_pMonsterLevel;
    cocos2d::ui::Text*       m_pMonsterName;
    cocos2d::Sprite*         m_pMonsterIcon;
    
    cocos2d::ui::ImageView*  m_pMonsterBuffers[8];
    
    cocos2d::ui::ImageView*  m_pGameMsgBtn;
    cocos2d::ui::ImageView*  m_pGameMapBtn;
    cocos2d::ui::ImageView*  m_pGameSearchBtn;
    cocos2d::ui::ImageView*  m_pGameBagBtn;
    cocos2d::ui::ImageView*  m_pGameDistBtn;
    cocos2d::ui::ImageView*  m_pGamePauseBtn;
    
    cocos2d::ui::Text*       m_pGameGoldNum;            // 金币
    cocos2d::ui::Text*       m_pGameSilverNum;          // 银币
    cocos2d::ui::Text*       m_pGameCopperNum;          // 铜币
    cocos2d::ui::Text*       m_pGameLevelInfoName;      // 关卡名
    cocos2d::ui::Text*      m_pGameLevelInfoFloor;     // 关卡层数
    cocos2d::ui::Layout*    m_pGameDistTipsFrame;
    cocos2d::ui::Button*    m_pGameDistFrameCloseBtn;
    cocos2d::ui::Text*      m_pGameDistFrameDesc;
   
};

#endif /* GameUILayer_h */
