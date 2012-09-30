#include "TerrainListModel.hpp"






TerrainListModel::TerrainListModel(Regroupement* regroupement,
                                   QObject *parent) :
    QAbstractListModel(parent),
    m_regroupement(regroupement)
{
    
}





QVariant TerrainListModel::data(const QModelIndex& index,
                                int role) const
{
    if (index.isValid() && index.row() < rowCount())
    {
        if (role == Qt::DisplayRole)
        {
            return m_regroupement->getTerrain(index.row())->getTitre();
        }
    }
    
    return QVariant();
}





int TerrainListModel::rowCount(const QModelIndex&) const
{
    return m_regroupement->getNombreTerrains();
}





void TerrainListModel::transfererTerrain(int row,
                                         TerrainListModel* autreModele)
{
    if (row >= 0 && row < rowCount() && autreModele)
    {
        beginRemoveRows(QModelIndex(), row, row);
        autreModele->beginInsertRows(QModelIndex(), autreModele->rowCount(), autreModele->rowCount());
        
        m_regroupement->getTerrain(row)->editRegroupement(autreModele->m_regroupement);
        
        endRemoveRows();
        autreModele->endInsertRows();
    }
}

