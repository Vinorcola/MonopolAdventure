#ifndef EDITIONGRAPHISMEEMPLACEMENT_HPP
#define EDITIONGRAPHISMEEMPLACEMENT_HPP

#include <QDialog>
#include <QDialogButtonBox>

#include "dialogEdition/widgetsEditeurs/GraphismeEmplacementEditWidget.hpp"





/**
 * @class EditionGraphismeEmplacement EditionGraphismeEmplacement.hpp dialogEdition/EditionGraphismeEmplacement.hpp
 * Cette classe contrôle l'édition des graphismes des emplacements.
 */
class EditionGraphismeEmplacement
{
    private:
        QDialog* m_dialog;///< Boîte de dialogue affichant le widget d'édition.
        GraphismeEmplacementEditWidget* m_champ;///< Champ d'édition des graphismes des emplacements.
        
        
        
    public:
        /**
         * Construit un contrôleur d'édition des graphismes des emplacements.
         * @param plateau Plateau a éditer.
         * @param parent Widget parent de la fenêtre de dialogue.
         */
        EditionGraphismeEmplacement(Plateau* plateau,
                                    QWidget* parent);
        
        
        
        /**
         * Détruit la fenêtre de dialogue.
         */
        ~EditionGraphismeEmplacement();
        
        
        
        /**
         * Lance la fenêtre d'édition de la carte.
         */
        bool executer();
};

#endif // EDITIONGRAPHISMEEMPLACEMENT_HPP
