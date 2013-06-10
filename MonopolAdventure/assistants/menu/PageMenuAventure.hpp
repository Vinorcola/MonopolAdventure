#ifndef PAGEMENUAVENTURE_HPP
#define PAGEMENUAVENTURE_HPP

#include <QPushButton>
#include <QVBoxLayout>





/**
 * @class PageMenuAventure PageMenuAventure.hpp assistants/menu/PageMenuAventure.hpp
 * Cette classe représente la page du mode Aventure du menu de MonopolAdventure.
 * 
 * L'utilisateur a plusieurs choix possibles :
 * @li Commencer une nouvelle aventure
 * @li Charger une aventure sauvegardée
 * @li Retourner au menu principal
 * 
 * Un signal est envoyé  lorsqu'un des bouton est cliqué.
 */
class PageMenuAventure : public QWidget
{
        Q_OBJECT
        
        
    private:
        QPushButton* m_nouvelleAventure;///< Bouton permettant de lancer une nouvelle aventure.
        QPushButton* m_chargerAventure;///< Bouton permettant de lancer une aventure sauvegardée.
        QPushButton* m_retour;///< Bouton permettant de retourner au menu principal.
        
        
        
    public:
        /**
         * Construit une nouvelle page du mode Aventure.
         */
        PageMenuAventure();
        
        
        
    signals:
        /**
         * Signal émit lorsque le bouton Nouvelle Aventure est cliqué.
         */
        void nouvelleAventureClicked();
        
        
        
        /**
         * Signal émit lorsque le bouton Charger Aventure est cliqué.
         */
        void chargerAventureClicked();
        
        
        
        /**
         * Signal émit lorsque le bouton Retour est cliqué.
         */
        void retourClicked();
};

#endif // PAGEMENUAVENTURE_HPP
