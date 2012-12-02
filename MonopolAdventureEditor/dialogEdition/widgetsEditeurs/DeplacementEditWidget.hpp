#ifndef DEPLACEMENTEDITWIDGET_HPP
#define DEPLACEMENTEDITWIDGET_HPP

#include <QComboBox>
#include <QFormLayout>
#include <QSpinBox>

#include "dialogEdition/widgetsEditeurs/SauvegardeInterface.hpp"
#include "dialogEdition/modeles/EmplacementListModel.hpp"
#include "donnees/emplacements/Deplacement.hpp"





/**
 * @class DeplacementEditWidget DeplacementEditWidget.hpp dialogEdition/widgetsEditeurs/DeplacementEditWidget.hpp
 * Cette classe fournit une interface d'édition des informations caractéristiques d'un emplacement « Déplacement ».
 */
class DeplacementEditWidget : public SauvegardeInterface
{
        Q_OBJECT
        
        
    private:
        Deplacement* m_deplacement;///< Emplacement « Déplacement » en cours d'édition.
        QComboBox* m_champDestination;///< Champ d'édition de la destination.
        EmplacementListModel* m_modeleEmplacementSelectionnable;///< Modèle de données contenant la liste des emplacements sélectionnables.
        QSpinBox* m_champAmende;///< Champ d'édition de l'amende.
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition d'emplacement « Déplacement ».
         * @param deplacement Emplacement « Déplacement » à éditer.
         * @param emplacements Liste des emplacements du plateau.
         */
        DeplacementEditWidget(Deplacement* const deplacement,
                              const QList<Emplacement*>& emplacements);
        
        
        
        /**
         * Edite les informations de la prison en fonction de la configuration des champs.
         */
        void sauvegarde();
};

#endif // DEPLACEMENTEDITWIDGET_HPP
