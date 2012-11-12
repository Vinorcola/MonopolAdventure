#include "TerrainListModel.hpp"






TerrainListModel::TerrainListModel(QList<TerrainData*>& terrains) :
    QAbstractListModel(),
    m_TerrainsData(terrains)
{
    
}





QVariant TerrainListModel::data(const QModelIndex& index,
                                int role) const
{
    if (index.isValid() && index.row() < rowCount())
    {
        if (role == Qt::DisplayRole)
        {
            return m_TerrainsData.at(index.row())->getTitre();
        }
    }
    
    return QVariant();
}





int TerrainListModel::rowCount(const QModelIndex&) const
{
    return m_TerrainsData.count();
}





void TerrainListModel::insertTerrain(TerrainData* terrain)
{
    if (!m_TerrainsData.contains(terrain))
    {
        // Calcul du rang d'insertion par rapport à l'index du terrain.
        int rang(0);
        while (rang < m_TerrainsData.count() && m_TerrainsData.at(rang)->getIndex() < terrain->getIndex())
        {
            rang++;
        }
        
        beginInsertRows(QModelIndex(), rang, rang);
        m_TerrainsData.insert(rang, terrain);
        endInsertRows();
    }
}





TerrainData* TerrainListModel::enleveTerrain(int row)
{
    TerrainData* terrain(0);
    if (row >= 0 && row < m_TerrainsData.count())
    {
        beginRemoveRows(QModelIndex(), row, row);
        terrain = m_TerrainsData.takeAt(row);
        endInsertRows();
    }
    
    return terrain;
}

