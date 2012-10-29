#ifndef TERRAINLISTMODEL_HPP
#define TERRAINLISTMODEL_HPP

#include <QAbstractListModel>

#include "dialogEdition/StructuresEditionListeRegroupements.hpp"





/**
 * @class TerrainListModel TerrainListModel.hpp modeles/TerrainListModel.hpp
 * Cette classe représente un modèle de données contenant une liste affichable de terrains contenu dans un regroupement.
 */
class TerrainListModel : public QAbstractListModel
{
        Q_OBJECT
        
        
    private:
        const QList<TerrainData*>& m_TerrainsData;///< Données éditables d'un regroupement.
        
        
        
    public:
        /**
         * Construit un nouveau modèle de données avec les terrains @a terrains.
         * @param terrains Liste des terrains.
         */
        TerrainListModel(const QList<TerrainData*>& terrains);
        
        
        
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
};

#endif // TERRAINLISTMODEL_HPP
