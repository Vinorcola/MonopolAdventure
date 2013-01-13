#include "SelectionRegroupementListModel.hpp"





SelectionRegroupementListModel::SelectionRegroupementListModel(QList<Regroupement*>& regroupements,
                                                               QObject* parent) :
    QAbstractListModel(parent),
    m_regroupements(regroupements),
    m_rangRegroupementInactif(regroupements.isEmpty() ? -1 : 0)// Sélection du premier regroupement.
{
    
}





QVariant SelectionRegroupementListModel::data(const QModelIndex& index,
                                              int role) const
{
    if (index.isValid() && index.row() < rowCount())
    {
        if (role == Qt::DisplayRole)
        {
            return m_regroupements.at(index.row())->getTitre();
        }
        
        if (role == Qt::DecorationRole)
        {
            return m_regroupements.at(index.row())->getCouleur();
        }
    }
    
    return QVariant();
}





Qt::ItemFlags SelectionRegroupementListModel::flags(const QModelIndex& index) const
{
    if (index.isValid() && index.row() < rowCount() && index.row() != m_rangRegroupementInactif)
    {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    }
    
    return Qt::NoItemFlags;
}





Regroupement* SelectionRegroupementListModel::getRegroupementAt(int row) const
{
    if (row >= 0 && row < rowCount())
    {
        return m_regroupements.at(row);
    }
    
    return 0;
}





bool SelectionRegroupementListModel::isSelectionnable(int row) const
{
    return row != m_rangRegroupementInactif;
}





int SelectionRegroupementListModel::rowCount(const QModelIndex&) const
{
    return m_regroupements.count();
}





void SelectionRegroupementListModel::notifyRegroupementInactif(Regroupement* regroupement)
{
    m_rangRegroupementInactif = m_regroupements.indexOf(regroupement);
}





void SelectionRegroupementListModel::notifyDataChanged(const QModelIndex& index)
{
    emit dataChanged(index, index);
}

