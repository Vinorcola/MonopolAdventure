#include "RegroupementListModel.hpp"






RegroupementListModel::RegroupementListModel(QList<Regroupement*>& regroupements) :
    QAbstractListModel(),
    m_regroupements(regroupements),
    m_modeleRegroupementsSelectionnables(new SelectionRegroupementListModel(regroupements, this))
{
    /* On interdit le premier regroupement à la sélection (celui en cours dédition par défaut).
     */
    m_modeleRegroupementsSelectionnables->notifyRegroupementInactif(regroupements.first());
}





SelectionRegroupementListModel* RegroupementListModel::getModeleRegroupementsSelectionnables() const
{
    return m_modeleRegroupementsSelectionnables;
}





Regroupement* RegroupementListModel::getRegroupementAt(int row) const
{
    if (row >= 0 && row < rowCount())
    {
        return m_regroupements.at(row);
    }
    
    return 0;
}





int RegroupementListModel::createRegroupement()
{
    int rang(m_regroupements.count());
    beginInsertRows(QModelIndex(), rang, rang);
    m_modeleRegroupementsSelectionnables->beginInsertRows(QModelIndex(), rang, rang);
    
    m_regroupements.append(new Regroupement(true));
    
    endInsertRows();
    m_modeleRegroupementsSelectionnables->endInsertRows();
    
    return rang;
}





void RegroupementListModel::deleteRegroupementAt(int row)
{
    /* On vérifie bien que le regroupement ne possède plus aucun terrainavant de la supprimer.
     */
    if (row >= 0 && row < rowCount() && m_regroupements.at(row)->rowCount() == 0)
    {
        beginRemoveRows(QModelIndex(), row, row);
        m_modeleRegroupementsSelectionnables->beginRemoveRows(QModelIndex(), row, row);
        
        delete m_regroupements.takeAt(row);
        
        endRemoveRows();
        m_modeleRegroupementsSelectionnables->endRemoveRows();
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





int RegroupementListModel::rowCount(const QModelIndex&) const
{
    return m_regroupements.count();
}





void RegroupementListModel::editTitreRegroupement(Regroupement* regroupement,
                                                  const QString& titre)
{
    if (m_regroupements.contains(regroupement))
    {
        regroupement->editTitre(titre);
        QModelIndex index(createIndex(m_regroupements.indexOf(regroupement), 0));
        emit dataChanged(index, index);
        m_modeleRegroupementsSelectionnables->notifyDataChanged(index);
    }
}





void RegroupementListModel::editCouleurRegroupement(Regroupement* regroupement,
                                                    const QColor& couleur)
{
    if (m_regroupements.contains(regroupement))
    {
        regroupement->editCouleur(couleur);
        QModelIndex index(createIndex(m_regroupements.indexOf(regroupement), 0));
        emit dataChanged(index, index);
        m_modeleRegroupementsSelectionnables->notifyDataChanged(index);
    }
}

