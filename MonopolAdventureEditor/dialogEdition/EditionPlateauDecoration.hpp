#ifndef EDITIONPLATEAUDECORATION_HPP
#define EDITIONPLATEAUDECORATION_HPP

#include <QDialog>
#include <QDialogButtonBox>

#include "dialogEdition/widgetsEditeurs/PlateauDecorationEditWidget.hpp"





/**
 * @class EditionPlateauDecoration EditionPlateauDecoration.hpp dialogEdition/EditionPlateauDecoration.hpp
 * Cette classe contrôle l'édition de la décoration du plateau.
 */
class EditionPlateauDecoration
{
    private:
        QDialog* m_dialog;///< Boîte de dialogue affichant le widget d'édition.
        PlateauDecorationEditWidget* m_champ;///< Champ d'édition de la décoration du plateau.
        
        
        
    public:
        /**
         * Construit un contrôleur d'édition de la décoration de plateau.
         * @param plateau Plateau a éditer.
         * @param parent Widget parent de la fenêtre de dialogue.
         */
        EditionPlateauDecoration(Plateau* plateau,
                                 QWidget* parent);
        
        
        
        /**
         * Détruit la fenêtre de dialogue.
         */
        ~EditionPlateauDecoration();
        
        
        
        /**
         * Lance la fenêtre d'édition de la carte.
         */
        bool executer();
};

#endif // EDITIONPLATEAUDECORATION_HPP
