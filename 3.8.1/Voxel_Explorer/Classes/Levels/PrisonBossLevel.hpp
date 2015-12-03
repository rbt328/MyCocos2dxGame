//
//  PrisonBossLevel.hpp
//  Voxel_Explorer
//
//  Created by wang haibo on 15/12/3.
//
//

#ifndef PrisonBossLevel_hpp
#define PrisonBossLevel_hpp

#include "StandardLevel.h"
class PrisonBossLevel : public StandardLevel
{
public:
    PrisonBossLevel();
    
    virtual bool build();
    virtual void generateAreaStyle();
    virtual bool createMonsters();
    virtual bool createSummoningMonsters(const cocos2d::Vec2& mapPos);
    
    virtual bool createEliteMonster(int tileIndex);
    virtual void createSiegeMonsters(const cocos2d::Vec2& pos);
    
private:
    Area*               m_pArenaRoom;
    int                 m_nArenaDoor;
};

#endif /* PrisonBossLevel_hpp */
