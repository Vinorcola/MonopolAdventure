#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QAction>
#include <QApplication>
#include <QGraphicsView>
#include <QMainWindow>
#include <QMenuBar>

#include "donnees/Plateau.hpp"





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
};

#endif // MAINWINDOW_HPP
