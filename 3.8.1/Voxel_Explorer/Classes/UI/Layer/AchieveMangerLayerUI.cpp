//
//  ItemUI.cpp
//  Voxel_Explorer
//
//  Created by 创李 on 15/10/23.
//
//

#include "AchieveMangerLayerUI.h"
#include "UtilityHelper.h"
USING_NS_CC;
AchieveMangerLayerUI::AchieveMangerLayerUI()
{
    m_pItemImgLayer = nullptr;
    m_pAchieveTargetLayer = nullptr;
    m_pAchieveNameLayer = nullptr;
}

AchieveMangerLayerUI::~AchieveMangerLayerUI()
{
    
}
bool AchieveMangerLayerUI::init(cocos2d::Size size)
{
    if (!Layout::init())
        return false;
    setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    setContentSize(size);
//    setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
//    setBackGroundColor(Color3B::BLUE);
    
    m_pItemImgLayer = Layout::create();
    m_pItemImgLayer->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    m_pItemImgLayer->setContentSize(size);
    m_pItemImgLayer->setPosition(getContentSize()*0.5);
//    m_pItemImgLayer->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
//    m_pItemImgLayer->setBackGroundColor(Color3B::RED);
    addChild(m_pItemImgLayer);
    
    m_pAchieveNameLayer = Layout::create();
    m_pAchieveNameLayer->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    m_pAchieveNameLayer->setContentSize(size);
    m_pAchieveNameLayer->setPosition(getContentSize()*0.5);
//    m_pEquipMarkLayer->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
//    m_pEquipMarkLayer->setBackGroundColor(Color3B::YELLOW);
    addChild(m_pAchieveNameLayer);
    
    m_pAchieveTargetLayer = Layout::create();
    m_pAchieveTargetLayer->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
    m_pAchieveTargetLayer->setContentSize(size);
    m_pAchieveTargetLayer->setPosition(getContentSize()*0.5);
    //    m_pEquipMarkLayer->setBackGroundColorType(cocos2d::ui::Layout::BackGroundColorType::SOLID);
    //    m_pEquipMarkLayer->setBackGroundColor(Color3B::YELLOW);
    addChild(m_pAchieveTargetLayer);

   return true;
}
AchieveMangerLayerUI* AchieveMangerLayerUI::create(cocos2d::Size size)
{
    AchieveMangerLayerUI* itemUi = new (std::nothrow) AchieveMangerLayerUI();
    if (itemUi && itemUi->init(size))
    {
        itemUi->autorelease();
        return itemUi;
    }
    CC_SAFE_DELETE(itemUi);
    return nullptr;
}
void AchieveMangerLayerUI::setLayerContentSize(const cocos2d::Size &contentSize)
{
    setContentSize(contentSize);
    
    if (m_pItemImgLayer) {
         m_pItemImgLayer->setContentSize(contentSize);
        m_pItemImgLayer->setPosition(getContentSize()*0.5);
    }
    
    if (m_pAchieveTargetLayer) {
        m_pAchieveTargetLayer->setContentSize(contentSize);
        m_pAchieveTargetLayer->setPosition(getContentSize()*0.5);
    }
    
    if (m_pAchieveNameLayer) {
        m_pAchieveNameLayer->setContentSize(contentSize);
        m_pAchieveNameLayer->setPosition(getContentSize()*0.5);
    }
    
}
void AchieveMangerLayerUI::addItemAchieve(cocos2d::ui::ImageView* achieveItemUi,eAchievementDetailType achieveId,std::string itemIcon,std::string name,std::string targetDesc,bool isUnlockeAchieve,bool isCommple)
{
    m_Achieves.push_back(achieveId);
    cocos2d::Vec2 pt = achieveItemUi->getPosition();
    cocos2d::Size achieveItemSize = achieveItemUi->getContentSize();
    if (m_pItemImgLayer && m_pAchieveNameLayer && m_pAchieveTargetLayer)
    {
        ui::ImageView* img = static_cast<ui::ImageView*>(m_pItemImgLayer->getChildByTag(achieveId));
        if (!img ) {
            img = ui::ImageView::create();
            img->setScale(0.7);
            img->setTag(achieveId);
            img->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
            m_pItemImgLayer->addChild(img);

        }
        
        if (isCommple || isUnlockeAchieve) {
            img->loadTexture(itemIcon,TextureResType::PLIST);
        }
        if (!isUnlockeAchieve) {
            img->loadTexture("achieve_icon_07.png",TextureResType::PLIST);
        }
        img->setPosition(pt-cocos2d::Vec2(img->getContentSize().width,0));
        cocos2d::ui::Scale9Sprite* scale9sp=dynamic_cast<cocos2d::ui::Scale9Sprite*>(img->getVirtualRenderer());
        scale9sp->setState(cocos2d::ui::Scale9Sprite::State::GRAY);
        if (isCommple) {
           scale9sp->setState(cocos2d::ui::Scale9Sprite::State::NORMAL);
        }
        img->setCameraMask((unsigned short)cocos2d::CameraFlag::USER2);
        
        ui::TextBMFont* nameText = static_cast<ui::TextBMFont*>(m_pAchieveNameLayer->getChildByTag(achieveId));
        if (!nameText) {
            nameText = ui::TextBMFont::create();
            nameText->setFntFile(UtilityHelper::getLocalStringForUi("FONT_NAME"));
            nameText->setScale(0.28);
            nameText->setTag(achieveId);
            nameText->setColor(Color3B(105, 87, 055));
            m_pAchieveNameLayer->addChild(nameText);
        }
        UtilityHelper::getLineForText(nameText, name,achieveItemSize.width-img->getContentSize().width);
        nameText->setString(name);
        float textHeight =nameText->getContentSize().height*nameText->getScale();
        nameText->setAnchorPoint(cocos2d::Vec2::ANCHOR_TOP_LEFT);
        nameText->setPosition(cocos2d::Vec2(img->getPositionX()+img->getContentSize().width*0.55,pt.y+textHeight*0.88));
    
        if (isCommple) {
            nameText->setColor(Color3B(241, 222, 188));
        }
        if (!isUnlockeAchieve)
        {
            nameText->setString(UtilityHelper::getLocalStringForUi("ACHIEVE_ITEM_LOCK"));
            textHeight = nameText->getContentSize().height*nameText->getScale();
            nameText->setPosition(cocos2d::Vec2(img->getPositionX()+img->getContentSize().width*0.55,pt.y+textHeight*0.88));
        }
        nameText->setCameraMask((unsigned short)cocos2d::CameraFlag::USER2);
        
        
        ui::TextBMFont* targetText = static_cast<ui::TextBMFont*>(m_pAchieveTargetLayer->getChildByTag(achieveId));
        if (!targetText) {
            targetText = ui::TextBMFont::create();
            targetText->setFntFile(UtilityHelper::getLocalStringForUi("FONT_NAME"));
            targetText->setScale(0.20);
            targetText->setTag(achieveId);
            targetText->setAnchorPoint(cocos2d::Vec2::ANCHOR_TOP_LEFT);
            m_pAchieveTargetLayer->addChild(targetText);
            targetText->setColor(Color3B(105, 87, 055));

        }
        targetText->setVisible(true);

        UtilityHelper::getLineForText(targetText, targetDesc,achieveItemSize.width-img->getContentSize().width);
        targetText->setString(targetDesc);
        
        targetText->setPosition(cocos2d::Vec2(nameText->getPositionX(),nameText->getPositionY() - textHeight));


        if (isCommple) {
            targetText->setColor(Color3B(185, 153, 109));
        }
        if (!isUnlockeAchieve)
        {
            targetText->setVisible(false);
        }
        targetText->setCameraMask((unsigned short)cocos2d::CameraFlag::USER2);

    }
}

void AchieveMangerLayerUI::removeItems()
{
    if (m_pItemImgLayer) {
        m_pItemImgLayer->removeAllChildren();
    }
    
    if (m_pAchieveNameLayer) {
        m_pAchieveNameLayer->removeAllChildren();
    }
    
    if (m_pAchieveTargetLayer) {
        m_pAchieveTargetLayer->removeAllChildren();
    }

    m_Achieves.clear();
}

