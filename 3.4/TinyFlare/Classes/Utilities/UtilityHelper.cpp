//
//  UtilityHelper.cpp
//  TinyFlare
//
//  Created by wang haibo on 15/3/31.
//
//

#include "UtilityHelper.h"
USING_NS_CC;

std::string UtilityHelper::getLocalString(const char* key)
{
    ValueMap dict;
    LanguageType lt= CCApplication::getInstance()->getCurrentLanguage();
    switch (lt) {
        case LanguageType::CHINESE:
            dict = FileUtils::getInstance()->getValueMapFromFile("chinese.plist");
            CCASSERT(!dict.empty(), "cannot create dictionary");
            break;
            
        default:
            dict = FileUtils::getInstance()->getValueMapFromFile("english.plist");
            CCASSERT(!dict.empty(), "cannot create dictionary");
            break;
    }
    
    Value ret = dict[key];
    
    return ret.asString();
}

void UtilityHelper::screenshot(const std::string& fileName,const std::function<void(const std::string&)>& callback)
{
    Image::Format format;
    //进行后缀判断
    if(std::string::npos != fileName.find_last_of(".")){
        auto extension = fileName.substr(fileName.find_last_of("."),fileName.length());
        if (!extension.compare(".png")) {
            format = Image::Format::PNG;
        } else if(!extension.compare(".jpg")) {
            format = Image::Format::JPG;
        } else{
            CCLOG("cocos2d: the image can only be saved as JPG or PNG format");
            return;
        }
    } else {
        CCLOG("cocos2d: the image can only be saved as JPG or PNG format");
        return ;
    }
    //获取屏幕尺寸，初始化一个空的渲染纹理对象
    cocos2d::Size winSize = Director::getInstance()->getWinSize();
    auto renderTexture = RenderTexture::create(winSize.width, winSize.height, Texture2D::PixelFormat::RGBA8888);
    //清空并开始获取
    renderTexture->beginWithClear(0.0f, 0.0f, 0.0f, 0.0f);
    //遍历场景节点对象，填充纹理到RenderTexture中
    Director::getInstance()->getRunningScene()->visit();
    //结束获取
    renderTexture->end();
    //保存文件
    renderTexture->saveToFile(fileName , format);
    //使用schedule在下一帧中调用callback函数
    auto fullPath = FileUtils::getInstance()->getWritablePath() + fileName;
    auto scheduleCallback = [&,fullPath,callback](float dt){
        callback(fullPath);
    };
    auto _schedule = Director::getInstance()->getRunningScene()->getScheduler();
    _schedule->schedule(scheduleCallback, Director::getInstance(), 0.0f,0,0.0f, false, "screenshot");
}

bool UtilityHelper::checkCircleIntersectWithSegment(const Vec2& center, float radius, const Vec2& start, const Vec2& end)
{
    bool ret = false;
    Vec2 d = (end - start).getNormalized();
    Vec2 e = center - start;
    
    float a = e.dot(d);
    
    float a2 = a*a;
    float e2 = center.distanceSquared(start);
    float r2 = radius*radius;
    
    if ((r2 + a2) < e2)
        ret = false;
    else
    {
        Vec2 v1 = (start - center).getNormalized();
        Vec2 v2 = (end - center).getNormalized();
        float f = v1.dot(v2);
        if(f > 0)
            ret = false;
        else
            ret = true;
    }
    ////这个判断算法只是粗略检测，当两点之间距离是小于半径2倍时会穿透。
    return ret;
}