#include "RegroupementListModel.hpp"






RegroupementListModel::RegroupementListModel(QList<RegroupementData*>& regroupements) :
    QAbstractListModel(),
    m_regroupements(regroupements),
    m_modeleRegroupementsSelectionnables(new SelectionRegroupementListModel(regroupements, this))
{
    /* Si le modèle de données ne possède qu'un seul regroupement, on l'interdit à la sélection. Sinon, on
     * interdit le deuxième à la sélection.
     */
    if (regroupements.count() > 1)
    {
        m_modeleRegroupementsSelectionnables->notifyRegroupementInactif(m_regroupements.at(1));
    }
    else
    {
        m_modeleRegroupementsSelectionnables->notifyRegroupementInactif(m_regroupements.first());
    }
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





SelectionRegroupementListModel* RegroupementListModel::getModeleRegroupementsSelectionnables() const
{
    return m_modeleRegroupementsSelectionnables;
}





RegroupementData* RegroupementListModel::getRegroupementAt(int row) const
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





int RegroupementListModel::createRegroupement()
{
    int rang(m_regroupements.count());
    beginInsertRows(QModelIndex(), rang, rang);
    m_modeleRegroupementsSelectionnables->beginInsertRows(QModelIndex(), rang, rang);
    
    m_regroupements.append(new RegroupementData);
    
    endInsertRows();
    m_modeleRegroupementsSelectionnables->endInsertRows();
    
    return rang;
}





void RegroupementListModel::deleteRegroupementAt(int row)
{
    /* On vérifie bien que le regroupement ne possède plus aucun terrainavant de la supprimer.
     */
    if (row >= 0 && row < rowCount() && m_regroupements.at(row)->getModeleTerrains()->rowCount() == 0)
    {
        beginRemoveRows(QModelIndex(), row, row);
        m_modeleRegroupementsSelectionnables->beginRemoveRows(QModelIndex(), row, row);
        
        delete m_regroupements.takeAt(row);
        
        endRemoveRows();
        m_modeleRegroupementsSelectionnables->endRemoveRows();
    }
}

