#ifndef SELECTIONREGROUPEMENTLISTMODEL_HPP
#define SELECTIONREGROUPEMENTLISTMODEL_HPP

#include <QAbstractListModel>

#include "donnees/emplacements/Regroupement.hpp"





/**
 * @class SelectionRegroupementListModel SelectionRegroupementListModel.hpp dialogEdition/modeles/SelectionRegroupementListModel.hpp
 * Cette classe représente un modèle de données contenant une liste de regroupements sélectionnable. Un de ces regroupement peut-être désactivé à la sélection.
 * 
 * Ce modèle sert pour la configuration des terrains d'un regroupement. Le regroupement en cours d'édition est masqué, ainsi, l'utilisateur peut sélectionné un des autres regroupements existant et transférer des terrains d'un regroupement à un autre.
 * 
 * Cette classe ne devrait pas être manipulée directement. Elle fonctionne de pair avec la classe RegroupementListModel.
 */
class SelectionRegroupementListModel : public QAbstractListModel
{
        Q_OBJECT
        
        
        friend class RegroupementListModel;
        
        
    private:
        QList<Regroupement*>& m_regroupements;///< Référence vers la liste de regroupements.
        int m_rangRegroupementInactif;///< Indique l'éventuel regroupement inactif (-1 pour aucun).
        
        
        
    private:
        /**
         * Construit un nouveau modèle de données avec les regroupements contenus dans la liste @a regroupements.
         * @param regroupements Liste des regroupements.
         * @param parent QObject parent.
         */
        SelectionRegroupementListModel(QList<Regroupement*>& regroupements,
                                       QObject* parent);
        
        
        
    public:
        /**
         * Renseigne diverses informations nécessaires aux QWidgets vues.
         * @param index Index correspondant au Terrain concerné.
         * @param role Rôle de l'information.
         * @return Diverses informations nécessaires aux QWidgets vues.
         */
        QVariant data(const QModelIndex& index,
                      int role = Qt::DisplayRole) const;
        
        
        
        /**
         * Renseigne diverses informations nécessaires aux widgets vues.
         * @param index Index correspondant au Regroupement concerné.
         */
        Qt::ItemFlags flags(const QModelIndex& index) const;
        
        
        
        /**
         * Retourne le regroupement situé au rang @a row.
         * @param row Rang du regroupement à retourner.
         */
        Regroupement* getRegroupementAt(int row) const;
        
        
        
        /**
         * Indique si le regroupement au rang @a row est sélectionnable.
         * @return @b @c true si le regroupement est sélectionnable.
         */
        bool isSelectionnable(int row) const;
        
        
        
        /**
         * Renseigne le nombre de rangs contenus dans le modèle de données.
         * @param parent Paramètre inutilisé dans la réimplémentation.
         * @return Nombre de rangs contenus dans le modèle de données.
         */
        int rowCount(const QModelIndex& parent = QModelIndex()) const;
        
        
        
    public slots:
        /**
         * Notifie au modèle de données que le regroupement @a regroupement doit être désactivé à la sélection.
         * @param regroupement Regroupement à désactiver.
         */
        void notifyRegroupementInactif(Regroupement* regroupement);
        
        
        
        /**
         * Notifie au modèle de données que des données ont changées.
         * @param index Index du regroupement qui a été édité.
         */
        void notifyDataChanged(const QModelIndex& index);
};

#endif // SELECTIONREGROUPEMENTLISTMODEL_HPP
