#include "EditionListeRegroupements.hpp"





EditionListeRegroupements::EditionListeRegroupements(QList<Regroupement*>& regroupements) :
    m_listeOriginale(regroupements),
    m_listeEditable(),
    m_modeleRegroupementsEditables(0),
    m_modeleRegroupementsSelectionnables(0)
{
    /* Création de la liste éditable.
     * L'index des terrains va servir à ordonner les terrains. On attribut à chaque terrain un index unique qui
     * s'incrémente au fur et à mesure.
     */
    int indexTerrain(0);
    for (int i(0), iEnd(m_listeOriginale.count()); i < iEnd; ++i)
    {
        Regroupement* regroupement(m_listeOriginale.at(i));
        
        /* Création et configuration d'un nouveau regroupementData.
         */
        RegroupementData* regroupementData;
        regroupementData->titre = regroupement->getTitre();
        regroupementData->couleur = regroupement->getCouleur();
        
        /* Configuration de la liste des terrains.
         */
        for (int j(0), jEnd(regroupement->getNombreTerrains()); j < jEnd; ++j)
        {
            Terrain* terrain(regroupement->getTerrain(j));
            regroupementData->terrains.at(i)->index = indexTerrain;
            regroupementData->terrains.at(i)->titre = terrain->getTitre();
            regroupementData->terrains.at(i)->pointeur = terrain;
            
            indexTerrain++;
        }
        
        /* Configuration du modèle de données.
         */
        regroupementData->modeleTerrains = new TerrainListModel(regroupementData->terrains);
        
        /* Ajout du nouveau regroupementData dans la liste.
         */
        m_listeEditable << regroupementData;
    }
}

