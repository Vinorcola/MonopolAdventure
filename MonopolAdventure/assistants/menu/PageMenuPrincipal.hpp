#ifndef PAGEMENUPRINCIPAL_HPP
#define PAGEMENUPRINCIPAL_HPP

#include <QPushButton>
#include <QVBoxLayout>





/**
 * @class PageMenuPrincipal PageMenuPrincipal.hpp assistants/menu/PageMenuPrincipal.hpp
 * Cette classe représente la page principale du menu de MonopolAdventure.
 * 
 * L'utilisateur a plusieurs choix possibles :
 * @li Jouer en mode Classique
 * @li Jouer en mode Aventure
 * @li Jouer en mode En-Ligne
 * @li Quitter MonopolAdventure
 * 
 * Un signal est envoyé lorsque chacun des boutons est cliqué.
 */
class PageMenuPrincipal : public QWidget
{
        Q_OBJECT
        
        
    private:
        QPushButton* m_modeClassique;///< Bouton permettant de lancer une partie ne mode Classique.
        QPushButton* m_modeAventure;///< Bouton permettant de lancer une partie en mode Aventure.
        QPushButton* m_modeEnLigne;///< Bouton permettant de lancer une partie en mode En-Ligne.
        QPushButton* m_quitter;///< Bouton permettant de quitter MonopolAdventure.
        
        
        
    public:
        /**
         * Construit une nouvelle page principale.
         */
        PageMenuPrincipal();
        
        
        
    signals:
        /**
         * Signal émit lorsque le bouton Mode Classique est cliqué.
         */
        void modeClassiqueClicked();
        
        
        
        /**
         * Signal émit lorsque le bouton Mode Aventure est cliqué.
         */
        void modeAventureClicked();
        
        
        
        /**
         * Signal émit lorsque le bouton Mode En-Ligne est cliqué.
         */
        void modeEnLigneClicked();
        
        
        
        /**
         * Signal émit lorsque le bouton Quitter est cliqué.
         */
        void quitterClicked();
};

#endif // PAGEMENUPRINCIPAL_HPP
