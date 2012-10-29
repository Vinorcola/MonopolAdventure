#include "TerrainListModel.hpp"






TerrainListModel::TerrainListModel(const QList<TerrainData*>& terrains) :
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
            return m_TerrainsData.at(index.row())->titre;
        }
    }
    
    return QVariant();
}





int TerrainListModel::rowCount(const QModelIndex&) const
{
    return m_TerrainsData.count();
}

