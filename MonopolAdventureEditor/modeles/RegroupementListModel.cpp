#include "RegroupementListModel.hpp"






RegroupementListModel::RegroupementListModel(QList<Regroupement*>& regroupements,
                                             QObject* parent) :
    QAbstractListModel(parent),
    m_regroupements(regroupements),
    m_modeleSecondaire(new SelectionRegroupementListModel(regroupements, this))
{
    
}





void RegroupementListModel::createRegroupement()
{
    /* Création du nouveau regroupement.
     */
    Regroupement* regroupement(new Regroupement);
    
    
    /* Insertion du nouveau regroupement dans le modèle de données.
     */
    beginInsertRows(QModelIndex(), m_regroupements.count(), m_regroupements.count());
    m_modeleSecondaire->beginInsertRows(QModelIndex(), m_regroupements.count(), m_regroupements.count());
    
    m_regroupements.append(regroupement);
    
    endInsertRows();
    m_modeleSecondaire->endInsertRows();
}





QVariant RegroupementListModel::data(const QModelIndex& index,
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





void RegroupementListModel::deleteRegroupement(int row)
{
    if (row >= 0 && row < rowCount())
    {
        /* On enlève le regroupement du modèle de données et on le supprime.
         */
        beginRemoveRows(QModelIndex(), row, row);
        m_modeleSecondaire->beginRemoveRows(QModelIndex(), row, row);
        
        delete m_regroupements.takeAt(row);
        
        endRemoveRows();
        m_modeleSecondaire->endRemoveRows();
    }
}





SelectionRegroupementListModel* RegroupementListModel::getModeleSecondaire() const
{
    return m_modeleSecondaire;
}





Regroupement* RegroupementListModel::getRegroupement(const int row) const
{
    if (row >= 0 && row < rowCount())
    {
        return m_regroupements.at(row);
    }
    
    return 0;
}





int RegroupementListModel::rowCount(const QModelIndex&) const
{
    return m_regroupements.count();
}





void RegroupementListModel::notifyRegroupementSelectionne(int row)
{
    if (row >= 0 && row < rowCount())
    {
        m_modeleSecondaire->m_rangRegroupementInactif = row;
    }
}

