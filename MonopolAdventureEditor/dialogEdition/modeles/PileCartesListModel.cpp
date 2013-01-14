#include "PileCartesListModel.hpp"





PileCartesListModel::PileCartesListModel(QList<PileCartes*>& pilesCartes) :
    QAbstractListModel(),
    m_pilesCartes(pilesCartes)
{
    
}





QVariant PileCartesListModel::data(const QModelIndex& index,
                                   int role) const
{
    if (index.isValid() && index.row() < rowCount())
    {
        if (role == Qt::DisplayRole)
        {
            return m_pilesCartes.at(index.row())->getTitre();
        }
    }
    
    return QVariant();
}





PileCartes* PileCartesListModel::getPileCartesAt(int row) const
{
    if (row >= 0 && row < rowCount())
    {
        return m_pilesCartes.at(row);
    }
    
    return 0;
}





int PileCartesListModel::rowCount(const QModelIndex&) const
{
    return m_pilesCartes.count();
}





int PileCartesListModel::createPileCartes()
{
    int rang(m_pilesCartes.count());
    
    beginInsertRows(QModelIndex(), rang, rang);
    m_pilesCartes.append(new PileCartes);
    endInsertRows();
    
    return rang;
}





void PileCartesListModel::deletePileCartesAt(int row)
{
    if (row >= 0 && row < rowCount())
    {
        beginRemoveRows(QModelIndex(), row, row);
        delete m_pilesCartes.takeAt(row);
        endRemoveRows();
    }
}





void PileCartesListModel::editTitrePileCartes(PileCartes* pileCartes,
                                              const QString& titre)
{
    if (m_pilesCartes.contains(pileCartes))
    {
        pileCartes->editTitre(titre);
        QModelIndex index(createIndex(m_pilesCartes.indexOf(pileCartes), 0));
        emit dataChanged(index, index);
    }
}

