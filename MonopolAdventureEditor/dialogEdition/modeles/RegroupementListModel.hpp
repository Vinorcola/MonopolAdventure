#ifndef REGROUPEMENTLISTMODEL_HPP
#define REGROUPEMENTLISTMODEL_HPP

#include <QAbstractListModel>

#include "donnees/emplacements/Regroupement.hpp"
#include "modeles/SelectionRegroupementListModel.hpp"





/**
 * @class RegroupementListModel RegroupementListModel.hpp modeles/RegroupementListModel.hpp
 * Cette classe représente un modèle de données contenant une liste de regroupements.
 */
class RegroupementListModel : public QAbstractListModel
{
        Q_OBJECT
        
        
    private:
        QList<Regroupement*>& m_regroupements;///< Référence vers la liste de Regroupements.
        SelectionRegroupementListModel* m_modeleSecondaire;///< Modèle de données secondaire permettant l'édition de terrains.
        
        
        
    public:
        /**
         * Construit un nouveau modèle de données avec les regroupements contenus dans la liste @a regroupements.
         * @param regroupements Liste des regroupements.
         * @param parent QObject parent.
         */
        RegroupementListModel(QList<Regroupement*>& regroupements,
                              QObject* parent);
        
        
        
        /**
         * Créé un nouveau regroupement et l'ajoute dans le modèle de données.
         */
        void createRegroupement();
        
        
        
        /**
         * Renseigne diverses informations nécessaires aux QWidgets vues.
         * @param index Index correspondant au Terrain concerné.
         * @param role Rôle de l'information.
         * @return Diverses informations nécessaires aux QWidgets vues.
         */
        QVariant data(const QModelIndex& index,
                      int role = Qt::DisplayRole) const;
        
        
        
        /**
         * Supprime le regroupement situé au rang @a row.
         * @param row Rang du regroupement à supprimer.
         */
        void deleteRegroupement(int row);
        
        
        
        /**
         * Retourne le modèle de données secondaire servant à éditer les terrains présents dans un regroupement en cours d'édition.
         * @return Modèle de données secondaire.
         */
        SelectionRegroupementListModel* getModeleSecondaire() const;
        
        
        
        /**
         * Retourne le regroupement au rang @a row.
         * @param row Rang du regroupement à retourner.
         * @return Regroupement au rang @a row.
         */
        Regroupement* getRegroupement(const int row) const;
        
        
        
        /**
         * Renseigne le nombre de rangs contenus dans le modèle de données.
         * @param parent Paramètre inutilisé dans la réimplémentation.
         * @return Nombre de rangs contenus dans le modèle de données.
         */
        int rowCount(const QModelIndex& parent = QModelIndex()) const;
        
        
        
    public slots:
        /**
         * Notifie au modèle de données le regroupement sélectionné dans la vue.
         * @param row Rang du regroupement sélectionné.
         */
        void notifyRegroupementSelectionne(int row);
};

#endif // REGROUPEMENTLISTMODEL_HPP
