#ifndef DEPLACEMENTEDITWIDGET_HPP
#define DEPLACEMENTEDITWIDGET_HPP

#include <QComboBox>
#include <QFormLayout>
#include <QSpinBox>

#include "dialogEdition/modeles/EmplacementListModel.hpp"
#include "donnees/emplacements/Deplacement.hpp"





/**
 * @class DeplacementEditWidget DeplacementEditWidget.hpp dialogEdition/widgetsEditeurs/DeplacementEditWidget.hpp
 * Cette classe fournit une interface d'édition des informations caractéristiques d'un emplacement « Déplacement ».
 */
class DeplacementEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        Deplacement* m_deplacement;///< Emplacement « Déplacement » en cours d'édition.
        QComboBox* m_champDestination;///< Champ d'édition de la destination.
        EmplacementListModel* m_modeleEmplacementSelectionnable;///< Modèle de données contenant la liste des emplacements sélectionnables.
        QSpinBox* m_champAmende;///< Champ d'édition de l'amende.
        
        
        
    public:
        DeplacementEditWidget(Deplacement* const deplacement,
                              const QList<Emplacement*>& emplacements,
                              Emplacement* emplacementParDefaut);
};

#endif // DEPLACEMENTEDITWIDGET_HPP
