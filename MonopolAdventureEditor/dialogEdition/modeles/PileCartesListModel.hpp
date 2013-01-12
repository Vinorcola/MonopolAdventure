#ifndef PILECARTESLISTMODEL_HPP
#define PILECARTESLISTMODEL_HPP

#include <QAbstractListModel>

#include "donnees/cartes/PileCartes.hpp"





/**
 * @class PileCartesListModel PileCartesListModel.hpp dialogEdition/modeles/PileCartesListModel.hpp
 * Cette classe représente un modèle de données contenant une liste de piles de cartes.
 */
class PileCartesListModel : public QAbstractListModel
{
        Q_OBJECT
        
        
    private:
        QList<PileCartes*>& m_pilesCartes;///< Référence vers la liste de piles de cartes.
        
        
        
    public:
        /**
         * Construit un nouveau modèle de données avec les piles de cartes contenues dans la liste @a pilesCartes.
         * @param regroupements Liste des regroupements.
         */
        PileCartesListModel(QList<PileCartes*>& pilesCartes);
        
        
        
        /**
         * Renseigne diverses informations nécessaires aux QWidgets vues.
         * @param index Index correspondant au Terrain concerné.
         * @param role Rôle de l'information.
         * @return Diverses informations nécessaires aux QWidgets vues.
         */
        QVariant data(const QModelIndex& index,
                      int role = Qt::DisplayRole) const;
        
        
        
        /**
         * Retourne la pile de cartes situé au rang @a row.
         * @param row Rang de la pile de cartes à retourner.
         * @return Pile de cartes situé au rang @a row.
         */
        PileCartes* getPileCartesAt(int row) const;
        
        
        
        /**
         * Renseigne le nombre de rangs contenus dans le modèle de données.
         * @param parent Paramètre inutilisé dans la réimplémentation.
         * @return Nombre de rangs contenus dans le modèle de données.
         */
        int rowCount(const QModelIndex& parent = QModelIndex()) const;
        
        
        
        /**
         * Créé une nouvelle pile de cartes et l'insert dans le modèle de données.
         * @return Le rang de la nouvelle pile de cartes dans le modèle de données.
         */
        int createPileCartes();
        
        
        
        /**
         * Enlève une pile de cartes du modèle de données et la supprime (ainsi que toutes ses cartes).
         * @param row Rang de la pile de cartes à supprimer dans le modèle de données.
         */
        void deletePileCartesAt(int row);
};

#endif // PILECARTESLISTMODEL_HPP
