#include "PileCartes.hpp"

#include "donnees/cartes/Carte.hpp"





PileCartes::PileCartes() :
    QAbstractListModel(),
    m_titre(tr("Nouvelle pile de cartes")),
    m_cartes()
{
    
}





PileCartes::PileCartes(const PileCartes* pileCartes) :
    QAbstractListModel(),
    m_titre(pileCartes->m_titre),
    m_cartes()
{
    for (int i(0), iEnd(pileCartes->m_cartes.count()); i < iEnd; i++)
    {
        m_cartes.append(new Carte(pileCartes->m_cartes.at(i), this));
    }
}





PileCartes::~PileCartes()
{
    for (int i(0), iEnd(m_cartes.count()); i < iEnd; i++)
    {
        delete m_cartes.takeLast();
    }
}





const QString& PileCartes::getTitre() const
{
    return m_titre;
}





void PileCartes::editTitre(const QString& titre)
{
    if (titre.isNull())
    {
        m_titre = "";
    }
    else
    {
        m_titre = titre;
    }
}





int PileCartes::getNombreCartes() const
{
    return m_cartes.count();
}





Carte* PileCartes::getCarteAt(int index) const
{
    return m_cartes.at(index);
}





int PileCartes::createCarte()
{
    int rang(m_cartes.count());
    
    beginInsertRows(QModelIndex(), rang, rang);
    m_cartes.append(new Carte(this));
    endInsertRows();
    
    return rang;
}





void PileCartes::deleteCarteAt(int row)
{
    if (row >= 0 && row < rowCount())
    {
        beginRemoveRows(QModelIndex(), row, row);
        delete m_cartes.takeAt(row);
        endRemoveRows();
    }
}





QModelIndex PileCartes::helper_createIndexFromRow(int row)
{
    return createIndex(row, 0);
}





QVariant PileCartes::data(const QModelIndex& index,
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





int PileCartes::rowCount(const QModelIndex&) const
{
    return m_cartes.count();
}

