#ifndef PAGEMENUCLASSIQUE_HPP
#define PAGEMENUCLASSIQUE_HPP

#include <QPushButton>
#include <QVBoxLayout>





/**
 * @class PageMenuClassique PageMenuClassique.hpp assistants/menu/PageMenuClassique.hpp
 * Cette classe représente la page du mode Classique du menu de MonopolAdventure.
 * 
 * L'utilisateur a plusieurs choix possibles :
 * @li Commencer une nouvelle partie
 * @li Charger une partie sauvegardée
 * @li Retourner au menu principal
 * 
 * Un signal est envoyé  lorsqu'un des bouton est cliqué.
 */
class PageMenuClassique : public QWidget
{
        Q_OBJECT
        
        
    private:
        QPushButton* m_nouvellePartie;///< Bouton permettant de lancer une nouvelle partie.
        QPushButton* m_chargerPartie;///< Bouton permettant de lancer une partie sauvegardée.
        QPushButton* m_retour;///< Bouton permettant de retourner au menu principal.
        
        
        
    public:
        /**
         * Construit une nouvelle page du mode Classique.
         */
        PageMenuClassique();
        
        
        
    signals:
        /**
         * Signal émit lorsque le bouton Nouvelle Partie est cliqué.
         */
        void nouvellePartieClicked();
        
        
        
        /**
         * Signal émit lorsque le bouton Charger Partie est cliqué.
         */
        void chargerPartieClicked();
        
        
        
        /**
         * Signal émit lorsque le bouton Retour est cliqué.
         */
        void retourClicked();
};

#endif // PAGEMENUCLASSIQUE_HPP
