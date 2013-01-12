#ifndef EDITIONLISTEPILESCARTES_HPP
#define EDITIONLISTEPILESCARTES_HPP

#include <QDialog>
#include <QDialogButtonBox>

#include "dialogEdition/widgetsEditeurs/ListePilesCartesEditWidget.hpp"





/**
 * @class EditionListePilesCartes EditionListePilesCartes.hpp dialogEdition/EditionListePilesCartes.hpp
 * Cette classe contrôle l'édition de la liste des piles de cartes.
 */
class EditionListePilesCartes
{
    private:
        QDialog* m_dialog;///< Boîte de dialogue affichant le widget d'édition.
        QList<PileCartes*>& m_listeOriginale;///< Référence vers la liste originale des piles de cartes.
        QList<PileCartes*> m_listeEditable;///< Liste de structures de données contenant les informations éditables des piles de cartes.
        ListePilesCartesEditWidget* m_widgetEdition;///< Widget d'édition de la liste de piles de cartes.
        
        
        
    public:
        /**
         * Construit un controleur d'édition de liste de piles de cartes.
         * @param pilesCartes Liste des piles de cartes à éditer.
         * @param emplacements Liste des emplacements du plateau.
         * @param devise Devise du plateau.
         * @param parent QWidget parent à la fenêtre d'édition.
         */
        EditionListePilesCartes(QList<PileCartes*>& pilesCartes,
                                const QList<Emplacement*>& emplacements,
                                const QString& devise,
                                QWidget* parent);
        
        
        
        /**
         * Destructeur.
         */
        ~EditionListePilesCartes();
        
        
        
        /**
         * Lance la fenêtre d'édition des piles de cartes.
         */
        bool executer();
};

#endif // EDITIONLISTEPILESCARTES_HPP
