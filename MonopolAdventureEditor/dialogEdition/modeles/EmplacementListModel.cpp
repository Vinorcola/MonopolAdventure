#include "EmplacementListModel.hpp"





EmplacementListModel::EmplacementListModel(const QList<Emplacement*>& emplacements,
                                           Emplacement* emplacementInactif,
                                           QObject* parent) :
    QAbstractListModel(parent),
    m_emplacements(emplacements),
    m_rangEmplacementInactif(m_emplacements.indexOf(emplacementInactif))
{
    
}






QVariant EmplacementListModel::data(const QModelIndex& index,
                                    int role) const
{
    if (index.isValid() && index.row() < rowCount())
    {
        if (role == Qt::DisplayRole)
        {
            return m_emplacements.at(index.row())->getTitre();
        }
    }
    
    return QVariant();
}





Qt::ItemFlags EmplacementListModel::flags(const QModelIndex& index) const
{
    if (index.isValid() && index.row() < rowCount() && index.row() != m_rangEmplacementInactif)
    {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    }
    
    return Qt::NoItemFlags;
}





Emplacement* EmplacementListModel::getEmplacementAt(int row) const
{
    if (row >= 0 && row < rowCount())
    {
        return m_emplacements.at(row);
    }
    
    return 0;
}





int EmplacementListModel::rowCount(const QModelIndex&) const
{
    return m_emplacements.count();
}

