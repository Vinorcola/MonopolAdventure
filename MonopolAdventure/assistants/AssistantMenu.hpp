#ifndef ASSISTANTMENU_HPP
#define ASSISTANTMENU_HPP

#include <QDialog>

#include "assistants/menu/PageMenuAventure.hpp"
#include "assistants/menu/PageMenuClassique.hpp"
#include "assistants/menu/PageMenuPrincipal.hpp"





/**
 * @class AssistantMenu AssistantMenu.hpp assistants/menu/AssistantMenu.hpp
 * Cet assistant s'occupe de demander à l'utilisateur quel genre de partie il souhaite jouer.
 */
class AssistantMenu : public QDialog
{
        Q_OBJECT
        
        
    private:
        PageMenuPrincipal* m_pagePrincipale;///< Page principale du menu.
        PageMenuClassique* m_pageModeClassique;///< Page permettant de lancer une partie en mode Classique.
        PageMenuAventure* m_pageModeAventure;///< Page permettant de lancer une partie en mode Aventure.
        
        
        
    public:
        /**
         * Construit un nouvel assistant.
         */
        AssistantMenu();
        
        
        
   private slots:
        /**
         * Affiche la page principale dans le menu.
         */
        void setPagePrincipale();
        
        
        
        /**
         * Affiche la page du mode Classique dans le menu.
         */
        void setPageClassique();
        
        
        
        /**
         * Affiche la page du mode Aventure dans le menu.
         */
        void setPageAventure();
};

#endif // ASSISTANTMENU_HPP
