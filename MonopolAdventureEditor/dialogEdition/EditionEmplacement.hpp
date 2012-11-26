#ifndef EDITIONEMPLACEMENT_HPP
#define EDITIONEMPLACEMENT_HPP

#include <QDialog>
#include <QDialogButtonBox>
#include <QTabWidget>
#include <QVBoxLayout>

class EmplacementEditWidget;
class Emplacement;
#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class EditionEmplacement EditionEmplacement.hpp dialogEdition/EditionEmplacement.hpp
 * Cette classe contrôle l'édition d'un emplacement.
 */
class EditionEmplacement
{
    private:
        QDialog* m_dialog;///< Boîte de dialogue affichant le widget d'édition.
        Emplacement* m_emplacement;///< Emplacement en cours d'édition.
        QTabWidget* m_onglets;///< Onglets d'édition.
        EmplacementEditWidget* m_onglet1;///< 1er onglet (informations générales).
        QWidget* m_onglet2;///< 2ème onglet (dépend du type d'emplacement).
        QWidget* m_onglet3;///< 3ème onglet (dépend du type d'emplacement).
        QWidget* m_onglet4;///< 4ème onglet (dépend du type d'emplacement).
        
        
        
    public:
        /**
         * Construit un contrôleur d'édition d'emplacement.
         * @param emplacement Emplacement à éditer.
         * @param parent QWidget parent de la QDialog.
         */
        EditionEmplacement(Emplacement* emplacement,
                           QWidget* parent = 0);
        
        
        
        /**
         * Lance la fenêtre d'édition de l'emplacement.
         */
        bool executer();
};

#endif // EDITIONEMPLACEMENT_HPP
