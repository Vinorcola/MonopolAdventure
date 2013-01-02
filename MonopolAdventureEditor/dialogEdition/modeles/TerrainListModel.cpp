#include "TerrainListModel.hpp"






TerrainListModel::TerrainListModel(QList<TerrainData*>& terrains) :
    QAbstractListModel(),
    m_terrainsData(terrains)
{
    
}





QVariant TerrainListModel::data(const QModelIndex& index,
                                int role) const
{
    if (index.isValid() && index.row() < rowCount())
    {
        if (role == Qt::DisplayRole)
        {
            return m_terrainsData.at(index.row())->getTitre();
        }
    }
    
    return QVariant();
}





int TerrainListModel::rowCount(const QModelIndex&) const
{
    return m_terrainsData.count();
}





void TerrainListModel::insertTerrain(TerrainData* terrain)
{
    if (!m_terrainsData.contains(terrain))
    {
        // Calcul du rang d'insertion par rapport à l'index du terrain.
        int rang(0);
        while (rang < m_terrainsData.count() && m_terrainsData.at(rang)->getIndex() < terrain->getIndex())
        {
            rang++;
        }
        
        beginInsertRows(QModelIndex(), rang, rang);
        m_terrainsData.insert(rang, terrain);
        endInsertRows();
    }
}





TerrainData* TerrainListModel::removeTerrainAt(int row)
{
    TerrainData* terrain(0);
    if (row >= 0 && row < rowCount())
    {
        beginRemoveRows(QModelIndex(), row, row);
        terrain = m_terrainsData.takeAt(row);
        endInsertRows();
    }
    
    return terrain;
}

