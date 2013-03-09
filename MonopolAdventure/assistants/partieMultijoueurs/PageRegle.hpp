#ifndef PAGEREGLE_HPP
#define PAGEREGLE_HPP

#include <QWizardPage>

#include "config/RegleConfigWidget.hpp"





/**
 * @class PageRegle PageRegle.hpp assistants/partieMultijoueurs/PageRegle.hpp
 * Cette classe représente une page de l'assistant de chargement d'une partie multijoueurs.
 * 
 * Cette page permet de personnaliser les règles de jeu.
 */
class PageRegle : public QWizardPage
{
        Q_OBJECT
        
        
    private:
        Plateau* m_plateau;///< Plateau chargé précédemment.
        RegleConfigWidget* m_widgetCentral;///< Widget de configuration de la règle.
        
        
        
    public:
        /**
         * Construit une nouvelle page.
         * @param plateau Plateau chargé précédemment.
         */
        PageRegle(Plateau* plateau);
        
        
        
        /**
         * Initialise le widget avec la règle du plateau chargé.
         */
        void initializePage();
};

#endif // PAGEREGLE_HPP
