#include "CarteListModel.hpp"





CarteListModel::CarteListModel(QList<Carte*>& cartes) :
    QAbstractListModel(),
    m_cartes(cartes)
{
    
}





QVariant CarteListModel::data(const QModelIndex& index,
                              int role) const
{
    if (index.isValid() && index.row() < rowCount())
    {
        if (role == Qt::DisplayRole)
        {
            return m_cartes.at(index.row())->getConsigne();
        }
        if (role == Qt::BackgroundRole && index.row() % 2 == 1)
        {
            // Pour toutes les lignes impairs, on grise le fond.
            return QBrush(QColor(192, 192, 192));
        }
    }
    
    return QVariant();
}





Carte* CarteListModel::getCarteAt(int row)
{
    if (row >= 0 && row < rowCount())
    {
        return m_cartes.at(row);
    }
    
    return 0;
}





int CarteListModel::createCarte()
{
    int rang(m_cartes.count());
    
    beginInsertRows(QModelIndex(), rang, rang);
    m_cartes.append(new Carte);
    endInsertRows();
    
    return rang;
}





void CarteListModel::deleteCarteAt(int row)
{
    if (row >= 0 && row < rowCount())
    {
        beginRemoveRows(QModelIndex(), row, row);
        delete m_cartes.takeAt(row);
        endRemoveRows();
    }
}





int CarteListModel::rowCount(const QModelIndex&) const
{
    return m_cartes.count();
}





QModelIndex CarteListModel::helper_createIndexFromRow(int row)
{
    return createIndex(row, 0);
}

