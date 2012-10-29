#ifndef STRUCTURESEDITIONLISTEREGROUPEMENTS_HPP
#define STRUCTURESEDITIONLISTEREGROUPEMENTS_HPP

#include <QColor>
#include <QHash>
#include <QPair>
#include <QString>

#include "dialogEdition/modeles/TerrainListModel.hpp"
class Terrain;





/**
 * @class TerrainData StructureEditionListeRegroupements.hpp dialogEdition/StructureEditionListeRegroupements.hpp
 * Structure de données contenant les informations d'un terrain.
 */
class TerrainData
{
    public:
        int index;///< Index du terrain sur le plateau.
        QString titre;///< Titre du terrain.
        Terrain* pointeur;///< Pointeur vers l'objet terrain.
};





/**
 * @class RegroupementData StructureEditionListeRegroupements.hpp dialogEdition/StructureEditionListeRegroupements.hpp
 * Structure de données contenant les informations d'un regroupement à éditer.
 */
class RegroupementData
{
    public:
        QString titre;///< Titre du regroupement.
        QColor couleur;///< Couleur du regroupement.
        QList<TerrainData*> terrains;///< Liste des terrains (avec leur index général et leur nom).
        TerrainListModel* modeleTerrains;///< Modèle de données permettant d'afficher la liste des terrains.
        
        
        
    public:
        RegroupementData() :
            titre(""),
            couleur(255, 255, 255),
            terrains(),
            modeleTerrains(0)
        {
            
        }
        
        
        
        ~RegroupementData()
        {
            if (modeleTerrains)
            {
                delete modeleTerrains;
            }
        }
};

#endif // STRUCTURESEDITIONLISTEREGROUPEMENTS_HPP
