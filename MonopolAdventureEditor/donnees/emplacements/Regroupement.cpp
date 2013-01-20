#include "Regroupement.hpp"

#include "donnees/Plateau.hpp"





Regroupement::Regroupement(const bool modeEdition) :
    QAbstractListModel(),
    m_titre(tr("Nouveau regroupement")),
    m_couleur(255, 255, 255),
    m_terrains(),
    m_modeEdition(modeEdition)
{
    
}





Regroupement::Regroupement(const Regroupement* regroupement) :
    QAbstractListModel(),
    m_titre(regroupement->m_titre),
    m_couleur(regroupement->m_couleur),
    m_terrains(regroupement->m_terrains),
    m_modeEdition(true)
{
    
}





const QString& Regroupement::getTitre() const
{
    return m_titre;
}





void Regroupement::editTitre(const QString& titre)
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





const QColor& Regroupement::getCouleur() const
{
    return m_couleur;
}





void Regroupement::editCouleur(const QColor& couleur)
{
    if (couleur.isValid())
    {
        m_couleur = couleur;
    }
    else
    {
        m_couleur.setRgb(255, 255, 255);
    }
}





int Regroupement::getNombreTerrains() const
{
    return m_terrains.count();
}





Terrain* Regroupement::getTerrainAt(int index) const
{
    return m_terrains.at(index);
}





void Regroupement::transfereTerrainA(Regroupement* regroupement,
                                     int rowTerrain)
{
    
    if (rowTerrain >= 0 && rowTerrain < m_terrains.count()
     && regroupement != this && !regroupement->m_terrains.contains(m_terrains.at(rowTerrain)))
    {
        beginRemoveRows(QModelIndex(), rowTerrain, rowTerrain);
        regroupement->insertTerrain(m_terrains.takeAt(rowTerrain));
        endRemoveRows();
    }
}





void Regroupement::insertTerrain(Terrain* terrain)
{
    if (!m_terrains.contains(terrain))
    {
        int rang(m_terrains.count());
        beginInsertRows(QModelIndex(), rang, rang);
        /** @todo Placer le terrain en fonction de son index. */
        m_terrains.append(terrain);
        endInsertRows();
        
        if (!m_modeEdition)
        {
            terrain->m_regroupement = this;
            if (terrain->m_elementGraphique)
            {
                terrain->m_elementGraphique->updateCouleurRegroupement(m_couleur);
            }
        }
    }
}





void Regroupement::enleveTerrain(Terrain* terrain)
{
    if (m_terrains.contains(terrain))
    {
        int rang(m_terrains.indexOf(terrain));
        beginRemoveRows(QModelIndex(), rang, rang);
        m_terrains.removeOne(terrain);
        endRemoveRows();
    }
}





void Regroupement::termineEdition()
{
    m_modeEdition = false;
    
    for (int i(0), iEnd(m_terrains.count()); i < iEnd; i++)
    {
        Terrain* terrain(m_terrains.at(i));
        terrain->m_regroupement = this;
        if (terrain->m_elementGraphique)
        {
            terrain->m_elementGraphique->updateCouleurRegroupement(m_couleur);
        }
    }
}





void Regroupement::saveInFile(QDataStream& ecriture,
                              const Plateau* plateau) const
{
    ecriture << m_titre
             << m_couleur
             << (quint8) m_terrains.count();// Ecriture du nombre de terrains présents.
    
    for (int i(0), iEnd(m_terrains.count()); i < iEnd; i++)
    {
        ecriture << plateau->getIdentifiantEmplacement(m_terrains.at(i));
    }
}





void Regroupement::loadFromFile(QDataStream& lecture,
                                const quint16 version,
                                const Plateau* plateau)
{
    switch (version)
    {
        default:
            quint8 nbTerrains;
            lecture >> m_titre
                    >> m_couleur
                    >> nbTerrains;
            
            for (int i(0); i < nbTerrains; i++)
            {
                quint8 terrain;
                lecture >> terrain;
                insertTerrain(static_cast<Terrain*>((Emplacement*) plateau->getEmplacement(terrain)));
            }
    }
}





QVariant Regroupement::data(const QModelIndex& index,
                          int role) const
{
    if (index.isValid() && index.row() < rowCount())
    {
        if (role == Qt::DisplayRole)
        {
            return m_terrains.at(index.row())->getTitre();
        }
        if (role == Qt::BackgroundRole && index.row() % 2 == 1)
        {
            // Pour toutes les lignes impairs, on grise le fond.
            return QBrush(QColor(192, 192, 192));
        }
    }
    
    return QVariant();
}





int Regroupement::rowCount(const QModelIndex&) const
{
    return m_terrains.count();
}

