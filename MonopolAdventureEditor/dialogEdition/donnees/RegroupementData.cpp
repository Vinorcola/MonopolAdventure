#include "RegroupementData.hpp"





RegroupementData::RegroupementData() :
    m_titre(QObject::tr("Nouveau regroupement")),
    m_couleur(255, 255, 255),
    m_terrains(),
    m_modeleTerrains(new TerrainListModel(m_terrains))
{
    
}





RegroupementData::RegroupementData(Regroupement* regroupement) :
    m_titre(regroupement->getTitre()),
    m_couleur(regroupement->getCouleur()),
    m_terrains(),
    m_modeleTerrains(0)
{
    // Création des structures de données pour les terrains.
    for (int i(0), iEnd(regroupement->getNombreTerrains()); i < iEnd; ++i)
    {
        m_terrains << new TerrainData(regroupement->getTerrain(i));
    }
    
    // Création du modèle de données.
    m_modeleTerrains = new TerrainListModel(m_terrains);
}





RegroupementData::~RegroupementData()
{
    delete m_modeleTerrains;
}





const QString& RegroupementData::getTitre() const
{
    return m_titre;
}




void RegroupementData::editTitre(const QString& titre)
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





const QColor& RegroupementData::getCouleur() const
{
    return m_couleur;
}





void RegroupementData::editCouleur(const QColor& couleur)
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





TerrainListModel* RegroupementData::getModeleTerrains() const
{
    return m_modeleTerrains;
}





const QList<TerrainData*>& RegroupementData::getListeTerrains() const
{
    return m_terrains;
}





void RegroupementData::transfereTerrainA(RegroupementData* regroupement,
                                         int rowTerrain)
{
    if (rowTerrain >= 0 && rowTerrain < m_terrains.count())
    {
        regroupement->m_modeleTerrains->insertTerrain(m_modeleTerrains->removeTerrainAt(rowTerrain));
    }
}

