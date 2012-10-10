#include "SelectionRegroupementListModel.hpp"





SelectionRegroupementListModel::SelectionRegroupementListModel(QList<Regroupement*>& regroupements,
                                                               QObject* parent) :
    QAbstractListModel(parent),
    m_regroupements(regroupements),
    m_rangRegroupementInactif(regroupements.isEmpty() ? -1 : 0)
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





int SelectionRegroupementListModel::rowCount(const QModelIndex& parent) const
{
    return m_regroupements.count();
}





void SelectionRegroupementListModel::notifyRegroupementInactif(int row)
{
    if (row >= 0 && row < rowCount())
    {
        m_rangRegroupementInactif = row;
    }
}

