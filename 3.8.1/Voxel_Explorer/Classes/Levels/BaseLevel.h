//
//  BaseLevel.h
//  Voxel_Explorer
//
//  Created by wang haibo on 15/9/24.
//
//

#ifndef __Voxel_Explorer__BaseLevel__
#define __Voxel_Explorer__BaseLevel__

#include "cocos2d.h"
#include "Area.h"
#include "Actor.hpp"
struct TileInfo
{
    typedef enum {
        INITIALISED     = 1<<0,     ///初始化状态
        PASSABLE        = 1<<1,     ///可通过状态
        USEABLE         = 1<<2,     ///可使用状态
        ATTACKABLE      = 1<<3,     ///可攻击状态
        PICKABLE        = 1<<4,     ///可拾取状态
        
    } FLAG;
    typedef enum {
        FORWARD = 0,
        LEFT,
        RIGHT,
        BACK,
        UNKNOWN
    } Direction;
    TerrainTile::TileType   m_Type;
    Area::AREA_TYPE         m_AreaType;
    
    bool        m_bVisited;
    int         m_Flag;
    int         m_nX;
    int         m_nY;
    Actor::ActorDir   m_Dir;
    TileInfo()
    {
        m_Type = TerrainTile::TT_CHASM;
        m_AreaType = Area::AT_UNKNOWN;
        m_Flag = INITIALISED;
        m_bVisited = false;
        m_nX = -1;
        m_nY = -1;
        m_Dir = Actor::AD_UNKNOWN;
    }
};
class BaseLevel : public cocos2d::Ref
{
    friend class Area;
protected:
    BaseLevel();
public:
    typedef enum{
        LT_STANDARD,
        LT_MAX
    }
    LEVEL_TYPE;
    
    void create();
    
    LEVEL_TYPE getLevelType() const;
    void setLevelType(LEVEL_TYPE type);
    
    int getWidth() const { return m_nWidth; }
    int getHeight() const { return m_nHeight; }
    int getLength() const { return m_nLenght; }
    
    std::vector<int> getNeighbours4() { return {-m_nWidth, +1, +m_nWidth, -1}; }
    std::vector<int> getNeighbours8() { return {+1, -1, +m_nWidth, -m_nWidth, +1+m_nWidth, +1-m_nWidth, -1+m_nWidth, -1-m_nWidth}; }
    std::vector<int> getNeighbours9() { return {0, +1, -1, +m_nWidth, -m_nWidth, +1+m_nWidth, +1-m_nWidth, -1+m_nWidth, -1-m_nWidth}; }
    
    cocos2d::Vec2 getSpawnPoint() const { return  m_spawnPoint; }
    
    void generateTerrainTiles(int x, int y , int width, int height, TerrainTile::TileType tileType, Area::AREA_TYPE areaType, Actor::ActorDir dir = Actor::AD_UNKNOWN);
    void setTerrainTile(int x, int y, TerrainTile::TileType tileType, Area::AREA_TYPE areaType , Actor::ActorDir dir = Actor::AD_UNKNOWN);
    int getTerrainTileFlag(int x, int y);
    void setTerrainTileFlag(int x, int y, int flag );
    void wrapTerrainTiles(int x, int y , int width, int height, TerrainTile::TileType type, TerrainTile::TileType withType);
    
    void updateTerrainTileFogOfWar(int x, int y , int width, int height, bool visited);
    bool checkMovable(Actor* actor, TileInfo& info);
    
    void load();
    void save();
    
public:
    virtual void showMap(bool show) = 0;
    virtual void updateAreaFogOfWarByPos(const cocos2d::Vec2& pos) = 0;
protected:
    virtual bool build() = 0;
    virtual bool createTerrain() = 0;
    virtual bool decorate() = 0;
    virtual bool createMonsters() = 0;
    virtual bool createUseableItems() = 0;

    virtual int calculateLevelMonsterCount() = 0;
private:
    int assignTerrainTileFlag(TerrainTile::TileType type);
protected:
    LEVEL_TYPE           m_Type;
    std::vector<TileInfo> m_Map;
    
    cocos2d::Vec2        m_spawnPoint;
    
    cocos2d::DrawNode*   m_pMapDrawNode;
    cocos2d::DrawNode*   m_pDebugDrawNode;
    
    int                 m_nWidth;
    int                 m_nHeight;
    int                 m_nLenght;
};

#endif /* defined(__Voxel_Explorer__BaseLevel__) */
