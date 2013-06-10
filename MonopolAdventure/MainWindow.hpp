#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QAction>
#include <QApplication>
#include <QGraphicsView>
#include <QMainWindow>
#include <QMenuBar>
#include <QTimer>

#include "assistants/partieMultijoueurs/AssistantPartieMultijoueurs.hpp"





/**
 * @class MainWindow MainWindow.hpp MainWindow.hpp
 * MainWindow représente la fenêtre principale du porgramme MonopolAdventure.
 */
class MainWindow : public QMainWindow
{
        Q_OBJECT
        
        
    private:
        Plateau* m_plateau;///< Plateau sur lequel se déroule la partie.
        QGraphicsView* m_vueCentrale;///< Vue sur le plateau.
        QAction* m_actionQuitter;///< Action permettant de quitter MonopolAdventureEditor.
        QAction* m_actionLancerNouvellePartie;///< Action permettant de lancer une nouvelle partie.
        
        QAction* m_actionZoomPlus;///< Action permettant de zoomer la vue sur le plateau.
        QAction* m_actionZoomMoins;///< Action permettant de dézoomer la vue du plateau.
        
        
        
    public:
        /**
         * Construit la fenêtre principale du programme.
         * 
         * Construit les différentes actions, menus, barres d'outils, etc. Agence le contenu avec des layouts et connecte les diverses signaux et slots.
         */
        MainWindow();
        
        
        
    public slots:
        /**
         * Quitte MonopolAdventure.
         */
        void quitter();
        
        
        
        /**
         * Lance l'assistant de chargement d'une nouvelle partie.
         * @note Pour l'instant, on lance l'assistant de parties multijoueurs.
         */
        void startAssistantPartieMultijoueurs();
        
        
        
        /**
         * Dessine le plateau et le connecte à différents slots.
         * @param plateau Plateau à afficher pour la partie.
         */
        void dessinePlateau(Plateau* plateau);
        
        
        
        /**
         * Zoom la vue sur le plateau.
         * 
         * Applique un zoom plus important sur le plateau.
         */
        void zoomPlus();
        
        
        
        /**
         * Dézoom la vue du le plateau.
         * 
         * Applique un zoom moins important sur le plateau.
         */
        void zoomMoins();
};

#endif // MAINWINDOW_HPP
