#ifndef TERRAINLISTMODEL_HPP
#define TERRAINLISTMODEL_HPP

#include <QAbstractListModel>

#include "donnees/emplacements/Regroupement.hpp"





/**
 * @class TerrainListModel TerrainListModel.hpp modeles/TerrainListModel.hpp
 * Cette classe représente un modèle de données contenant une liste de terrains.
 */
class TerrainListModel : public QAbstractListModel
{
        Q_OBJECT
        
        
    private:
        Regroupement* m_regroupement;///< Regroupement de terrains.
        
        
        
    public:
        /**
         * Construit un nouveau modèle de données avec les terrains contenus dans le regroupement @a regroupement.
         * @param regroupement Regroupement.
         * @param parent QObject parent.
         */
        TerrainListModel(Regroupement* regroupement,
                         QObject* parent = 0);
        
        
        
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
         * Transfère un Terrain vers un autre modèle de données.
         * @param row Rang du Terrain à transférer.
         * @param autreModele Modèle de données vers lequel transférer le Terrain.
         */
        void transfererTerrain(int row,
                               TerrainListModel* autreModele);
};

#endif // TERRAINLISTMODEL_HPP
