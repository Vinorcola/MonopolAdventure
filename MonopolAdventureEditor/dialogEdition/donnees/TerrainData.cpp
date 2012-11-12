#include "TerrainData.hpp"





TerrainData::TerrainData(Terrain* terrain) :
    m_index(0)/** @todo Index des terrains. */,
    m_titre(terrain->getTitre()),
    m_pointeur(terrain)
{
    
}





int TerrainData::getIndex() const
{
    return m_index;
}





const QString& TerrainData::getTitre() const
{
    return m_titre;
}





Terrain* TerrainData::getTerrain() const
{
    return m_pointeur;
}

