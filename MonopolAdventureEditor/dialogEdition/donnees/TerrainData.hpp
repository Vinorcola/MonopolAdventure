#ifndef TERRAINDATA_HPP
#define TERRAINDATA_HPP

#include "donnees/emplacements/Terrain.hpp"





/**
 * @class TerrainData TerrainData.hpp dialogEdition/donnees/TerrainData.hpp
 * Structure de données contenant les informations d'un terrain à afficher lors de l'édition d'un regroupement.
 * 
 * Elle permet surtout d'aléger l'édition des regroupements, car on a juste besoin d'afficher le titre des terrains.
 */
class TerrainData
{
    private:
        const int m_index;///< Index du terrain sur le plateau.
        QString m_titre;///< Titre du terrain.
        Terrain* m_pointeur;///< Pointeur vers l'objet terrain.
        
        
        
    public:
        /**
         * Construit une structure de données à partir d'un terrain.
         * @param terrain Terrain fournissant les informations.
         */
        TerrainData(Terrain* terrain);
        
        
        
        /**
         * Retourne l'index du terrain sur le plateau.
         * @return Index du terrain.
         */
        int getIndex() const;
        
        
        
        /**
         * Retourne le titre du terrain.
         * @return Titre du terrain.
         */
        const QString& getTitre() const;
        
        
        
        /**
         * Retourne un pointeur vers le terrain original.
         * @return Terrain original.
         */
        Terrain* getTerrain() const;
};

#endif // TERRAINDATA_HPP
