#ifndef SELECTIONREGROUPEMENTLISTMODEL_HPP
#define SELECTIONREGROUPEMENTLISTMODEL_HPP

#include <QAbstractListModel>

#include "donnees/emplacements/Regroupement.hpp"





/**
 * @class SelectionRegroupementListModel SelectionRegroupementListModel.hpp modeles/SelectionRegroupementListModel.hpp
 * Cette classe représente un modèle de données contenant une liste de regroupements. Un de ces regroupement peut-être désactivé à la sélection.
 * 
 * Ce modèle sert pour la configuration des terrains d'un regroupement. Le regroupement en cours d'édition est masqué, ainsi, l'utilisateur peut sélectionné un des autres regroupements existant et transférer des terrains d'un regroupement à un autre.
 * 
 * Cette classe ne devrait pas être manipulée directement. Elle est utilisée par la classe RegroupementListModel.
 */
class SelectionRegroupementListModel : public QAbstractListModel
{
        Q_OBJECT
        
        
    private:
        QList<Regroupement*>& m_regroupements;///< Référence vers la liste de Regroupements.
        int m_rangRegroupementInactif;///< Indique l'éventuel Regroupement inactif (-1 pour aucun).
        
        
        
    public:
        /**
         * Construit un nouveau modèle de données avec les regroupements contenus dans la liste @a regroupements.
         * @param regroupements Liste des regroupements.
         * @param parent QObject parent.
         */
    public:
        SelectionRegroupementListModel(QList<Regroupement*>& regroupements,
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
         * Renseigne diverses informations nécessaires aux widgets vues.
         * @param index Index correspondant au Regroupement concerné.
         */
        Qt::ItemFlags flags(const QModelIndex& index) const;
        
        
        
        /**
         * Renseigne le nombre de rangs contenus dans le modèle de données.
         * @param parent Paramètre inutilisé dans la réimplémentation.
         * @return Nombre de rangs contenus dans le modèle de données.
         */
        int rowCount(const QModelIndex& parent = QModelIndex()) const;
        
        
        
    public slots:
        /**
         * Notifie au modèle de données que le regroupement situé au rang @a row doit être désactivé à la sélection.
         * @param row Rang du regroupement à désactiver.
         */
        void notifyRegroupementInactif(int row);
};

#endif // SELECTIONREGROUPEMENTLISTMODEL_HPP
