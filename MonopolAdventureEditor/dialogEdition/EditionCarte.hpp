#ifndef EDITIONCARTE_HPP
#define EDITIONCARTE_HPP

#include <QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>

#include "dialogEdition/widgetsEditeurs/CarteEditWidget.hpp"





/**
 * @class EditionCarte EditionCarte.hpp dialogEdition/EditionCarte.hpp
 * Cette classe contrôle l'édition d'une carte.
 */
class EditionCarte
{
    private:
        QDialog* m_dialog;///< Boîte de dialogue affichant le widget d'édition.
        CarteEditWidget* m_champ;///< Champ d'édition de la carte.
        
        
        
    public:
        /**
         * Construit un contrôleur d'édition de cartes.
         * @param carte Carte à éditer.
         * @param emplacements Liste des emplacements du plateau.
         * @param pilesCartes Liste des piles de cartes en cours d'édition.
         * @param parent Widget parent de la fenêtre de dialogue.
         */
        EditionCarte(Carte* carte,
                     const QList<Emplacement*>& emplacements,
                     const QList<PileCartes*>& pilesCartes,
                     QWidget* parent);
        
        
        
        /**
         * Détruit la fenêtre de dialogue.
         */
        ~EditionCarte();
        
        
        
        /**
         * Lance la fenêtre d'édition de la carte.
         */
        bool executer();
};

#endif // EDITIONCARTE_HPP
