#include "Regroupement.hpp"

#include "donnees/Plateau.hpp"





Regroupement::Regroupement() :
    m_titre(QObject::tr("Nouveau regroupement")),
    m_couleur(255, 255, 255),
    m_terrains()
{
    
}





const QString& Regroupement::getTitre() const
{
    return m_titre;
}





const QColor& Regroupement::getCouleur() const
{
    return m_couleur;
}





int Regroupement::getNombreTerrains() const
{
    return m_terrains.count();
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
                // On récupère l'id du terrain
                quint8 idTerrain;
                lecture >> idTerrain;
                
                // On récupère le terrain associé à l'id et on le configure
                Terrain* terrain(static_cast<Terrain*>((Emplacement*) plateau->getEmplacement(idTerrain)));
                terrain->m_regroupement = this;
                
                // On ajoute le terrain dans la liste du regroupement.
                m_terrains.append(terrain);
                
            }
    }
}

