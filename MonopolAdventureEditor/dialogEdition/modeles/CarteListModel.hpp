#ifndef CARTELISTMODEL_HPP
#define CARTELISTMODEL_HPP

#include <QAbstractListModel>

#include "donnees/cartes/Carte.hpp"





/**
 * @class CarteListModel CarteListModel.hpp dialogEdition/modeles/CarteListModel.hpp
 *Cette classe représente un modèle de données contenant une liste affichable de cartes contenu dans une pile de cartes.
 */
class CarteListModel : public QAbstractListModel
{
        Q_OBJECT
        
        
    private:
        QList<Carte*>& m_cartes;///< Données éditables d'une carte.
        
        
        
    public:
        /**
         * Construit un nouveau modèle de données avec les cartes @a cartes.
         * @param cates Liste des cartes.
         */
        CarteListModel(QList<Carte*>& cartes);
        
        
        
        /**
         * Renseigne diverses informations nécessaires aux QWidgets vues.
         * @param index Index correspondant au Terrain concerné.
         * @param role Rôle de l'information.
         * @return Diverses informations nécessaires aux QWidgets vues.
         */
        QVariant data(const QModelIndex& index,
                      int role = Qt::DisplayRole) const;
        
        
        
        /**
         * Retourne la carte situé au rang @a row dans le modèle de données.
         * @param row Rang auquel est situé la carte dans le modèle de données.
         * @return Carte au rang @a row.
         */
        Carte* getCarteAt(int row);
        
        
        
        /**
         * Créé une nouvelle carte et l'insert dans le modèle de données.
         * @return Le rang de la nouvelle carte dans le modèle de données.
         */
        int createCarte();
        
        
        
        /**
         * Enlève une carte du modèle de données et la supprime.
         * @param row Rang de la carte à supprimer dans le modèle de données.
         */
        void deleteCarteAt(int row);
        
        
        
        /**
         * Renseigne le nombre de rangs contenus dans le modèle de données.
         * @param parent Paramètre inutilisé dans la réimplémentation.
         * @return Nombre de rangs contenus dans le modèle de données.
         */
        int rowCount(const QModelIndex& parent = QModelIndex()) const;
        
        
        
        /**
         * Helper créant un index à partir d'un rang.
         */
        QModelIndex helper_createIndexFromRow(int row);
};

#endif // CARTELISTMODEL_HPP
