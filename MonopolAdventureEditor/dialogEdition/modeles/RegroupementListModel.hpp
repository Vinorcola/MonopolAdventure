#ifndef REGROUPEMENTLISTMODEL_HPP
#define REGROUPEMENTLISTMODEL_HPP

#include <QAbstractListModel>

#include "dialogEdition/modeles/SelectionRegroupementListModel.hpp"





/**
 * @class RegroupementListModel RegroupementListModel.hpp dialogEdition/modeles/RegroupementListModel.hpp
 * Cette classe représente un modèle de données contenant une liste de regroupements.
 */
class RegroupementListModel : public QAbstractListModel
{
        Q_OBJECT
        
        
    private:
        QList<Regroupement*>& m_regroupements;///< Référence vers la liste de regroupements.
        SelectionRegroupementListModel* m_modeleRegroupementsSelectionnables;///< Modèle de données secondaire contenant une liste des regroupements sélectionnables.
        
        
        
    public:
        /**
         * Construit un nouveau modèle de données avec les regroupements contenus dans la liste @a regroupements.
         * @param regroupements Liste des regroupements.
         */
        RegroupementListModel(QList<Regroupement*>& regroupements);
        
        
        
        /**
         * Renseigne diverses informations nécessaires aux QWidgets vues.
         * @param index Index correspondant au Terrain concerné.
         * @param role Rôle de l'information.
         * @return Diverses informations nécessaires aux QWidgets vues.
         */
        QVariant data(const QModelIndex& index,
                      int role = Qt::DisplayRole) const;
        
        
        
        /**
         * Retourne le modèle de données des regroupements sélectionnables.
         * @return Modèle de données des regroupements sélectionnables.
         */
        SelectionRegroupementListModel* getModeleRegroupementsSelectionnables() const;
        
        
        
        /**
         * Retourne le regroupement situé au rang @a row.
         * @param row Rang du regroupement à retourner.
         * @return Regroupement situé au rang @a row.
         */
        Regroupement* getRegroupementAt(int row) const;
        
        
        
        /**
         * Renseigne le nombre de rangs contenus dans le modèle de données.
         * @param parent Paramètre inutilisé dans la réimplémentation.
         * @return Nombre de rangs contenus dans le modèle de données.
         */
        int rowCount(const QModelIndex& parent = QModelIndex()) const;
        
        
        
        /**
         * Créé un nouveau regroupement et l'insert dans le modèle de données.
         */
        int createRegroupement();
        
        
        
        /**
         * Enlève un regroupement du modèle de données (seulement si le regroupement ne possède plus aucun terrain) et le supprime.
         * @param row Rang du regroupement à supprimer dans le modèle de données.
         */
        void deleteRegroupementAt(int row);
};

#endif // REGROUPEMENTLISTMODEL_HPP
