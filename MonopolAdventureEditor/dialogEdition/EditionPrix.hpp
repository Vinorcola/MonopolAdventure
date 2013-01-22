#ifndef EDITIONPRIX_HPP
#define EDITIONPRIX_HPP

#include <QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>

#include "dialogEdition/widgetsEditeurs/AffichagePrixEditWidget.hpp"





/**
 * @class EditionPrix EditionPrix.hpp dialogEdition/EditionPrix.hpp
 * Cette classe contrôle l'édition des informations concernant les prix.
 */
class EditionPrix
{
    private:
        QDialog* m_dialog;///< Boîte de dialogue affichant le widget d'édition.
        AffichagePrixEditWidget* m_champ;///< Champ d'édition de la carte.
        
        
        
    public:
        /**
         * Construit un contrôleur d'édition de cartes.
         * @param plateau Plateau a éditer.
         * @param parent Widget parent de la fenêtre de dialogue.
         */
        EditionPrix(Plateau* plateau,
                    QWidget* parent);
        
        
        
        /**
         * Détruit la fenêtre de dialogue.
         */
        ~EditionPrix();
        
        
        
        /**
         * Lance la fenêtre d'édition de la carte.
         */
        bool executer();
};

#endif // EDITIONPRIX_HPP
