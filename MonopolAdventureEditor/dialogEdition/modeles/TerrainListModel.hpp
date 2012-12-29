#ifndef TERRAINLISTMODEL_HPP
#define TERRAINLISTMODEL_HPP

#include <QAbstractListModel>

#include "dialogEdition/donnees/TerrainData.hpp"





/**
 * @class TerrainListModel TerrainListModel.hpp dialogEdition/modeles/TerrainListModel.hpp
 * Cette classe représente un modèle de données contenant une liste affichable de terrains contenu dans un regroupement.
 */
class TerrainListModel : public QAbstractListModel
{
        Q_OBJECT
        
        
    private:
        QList<TerrainData*>& m_terrainsData;///< Données affichables d'un terrain.
        
        
        
    public:
        /**
         * Construit un nouveau modèle de données avec les terrains @a terrains.
         * @param terrains Liste des terrains.
         */
        TerrainListModel(QList<TerrainData*>& terrains);
        
        
        
        /**
         * Renseigne diverses informations nécessaires aux QWidgets vues.
         * @param index Index correspondant au Terrain concerné.
         * @param role Rôle de l'information.
         * @return Diverses informations nécessaires aux QWidgets vues.
         */
        QVariant data(const QModelIndex& index,
                      int role = Qt::DisplayRole) const;
        
        
        
        /**
         * Renseigne le nombre de rangs contenus dans le modèle de données.
         * @param parent Paramètre inutilisé dans la réimplémentation.
         * @return Nombre de rangs contenus dans le modèle de données.
         */
        int rowCount(const QModelIndex& parent = QModelIndex()) const;
        
        
        
        /**
         * Insère le terrain @a terrain dans le modèle de données.
         * @param terrain Terrain à insérer.
         */
        void insertTerrain(TerrainData* terrain);
        
        
        
        /**
         * Enlève, du modèle de données, le terrain situé au rang @a row, puis retourne son pointeur.
         * @param row Rang auquel se situe le terrain.
         * @return Pointeur du terrain enlevé.
         */
        TerrainData* enleveTerrain(int row);
};

#endif // TERRAINLISTMODEL_HPP
