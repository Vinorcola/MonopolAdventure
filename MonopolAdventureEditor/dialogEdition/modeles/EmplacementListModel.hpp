#ifndef EMPLACEMENTLISTMODEL_HPP
#define EMPLACEMENTLISTMODEL_HPP

#include <QAbstractListModel>

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class EmplacementListModel EmplacementListModel.hpp dialogEdition/modeles/EmplacementListModel.hpp
 * Cette classe représente un modèle de données contenant une liste d'emplacements sélectionnable. Un de ces emplacement peut-être désactivé à la sélection.
 * 
 * Ce modèle sert pour la sélection d'un emplacement dans un emplacement « déplacement ». L'emplacement en cours d'édition est masqué, ainsi, l'utilisateur ne peut sélectionné que les autres.
 */
class EmplacementListModel : public QAbstractListModel
{
        Q_OBJECT
        
        
    private:
        const QList<Emplacement*>& m_emplacements;///< Référence vers la liste d'emplacements.
        int m_rangEmplacementInactif;///< Indique l'éventuel emplacement inactif (-1 pour aucun).
        
        
        
    public:
        /**
         * Construit un nouveau modèle de données avec les emplacements contenus dans la liste @a emplacements.
         * @param emplacements Liste des emplacements.
         * @param emplacementInactif Emplacement inactif à la sélection.
         * @param parent QObject parent.
         */
        EmplacementListModel(const QList<Emplacement*>& emplacements,
                             Emplacement* emplacementInactif,
                             QObject* parent);
        
        
        
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
         * Retourne l'emplacement situé au rang @a row.
         * @param row Rang de l'emplacement à retourner.
         */
        Emplacement* getEmplacementAt(int row) const;
        
        
        
        /**
         * Renseigne le nombre de rangs contenus dans le modèle de données.
         * @param parent Paramètre inutilisé dans la réimplémentation.
         * @return Nombre de rangs contenus dans le modèle de données.
         */
        int rowCount(const QModelIndex& parent = QModelIndex()) const;
};

#endif // EMPLACEMENTLISTMODEL_HPP
