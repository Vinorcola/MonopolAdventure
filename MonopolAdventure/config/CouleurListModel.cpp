#include "CouleurListModel.hpp"




QList<int> CouleurListModel::m_listeCouleurUtilisee;
const QStringList CouleurListModel::m_listeCouleur(QStringList() << "" << "Bleu" << "Rouge" << "Vert" << "Jaune");





CouleurListModel::CouleurListModel(QObject* parent) :
    QAbstractListModel(parent),
    m_rangSelectionne(0)
{
    
}





int CouleurListModel::rowCount(const QModelIndex&) const
{
    return m_listeCouleur.size();
}





QVariant CouleurListModel::data(const QModelIndex& index,
                                int role) const
{
    if (index.isValid() && index.row() < rowCount())
    {
        if (role == Qt::DisplayRole)
        {
            return m_listeCouleur.at(index.row());
        }
    }
    
    return QVariant();
}





Qt::ItemFlags CouleurListModel::flags(const QModelIndex& index) const
{
    if (index.isValid() && index.row() < rowCount())
    {
        if (index.row() == m_rangSelectionne || !m_listeCouleurUtilisee.contains(index.row()))
        {
            return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
        }
    }
    
    return Qt::NoItemFlags;
}





void CouleurListModel::setSelectedItem(int row)
{
    if (row >= 0 && row < rowCount())
    {
        // On enlève l'élément précédemment sélectionné de la liste.
        if (m_rangSelectionne != 0)
        {
            m_listeCouleurUtilisee.removeOne(m_rangSelectionne);
        }
        
        // On enregistre le nouvel élément et on l'ajoute à la liste.
        m_rangSelectionne = row;
        if (row != 0)
        {
            m_listeCouleurUtilisee.append(row);
        }
    }
}

