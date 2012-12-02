#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QAction>
#include <QApplication>
#include <QGraphicsView>
#include <QMainWindow>
#include <QMenuBar>
#include <QTimer>
#include <QToolBar>

#include "donnees/Plateau.hpp"





/**
 * @class MainWindow MainWindow.hpp MainWindow.hpp
 * MainWindow représente la fenêtre principale de l'éditeur de plateau MonopolAdventure.
 */
class MainWindow : public QMainWindow
{
        Q_OBJECT
        
        
    private:
        Plateau* m_plateau;///< Plateau en cours d'édition.
        QGraphicsView* m_vueCentrale;///< Widget central de la fenêtre.
        QToolBar* m_barreOutils;///< Barre d'outils d'édition.
        QAction* m_actionQuitter;///< Action permettant de quitter l'éditeur.
        QAction* m_actionAssistantCreation;///< Action permettant de lancer l'assistant de création de plateau.
        QAction* m_actionRegroupement;///< Action permettant d'éditer la liste des regroupements du plateau.
        
        
        
    public:
        /**
         * Construit le fenêtre principale du programme.
         */
        MainWindow();
        
        
        
    public slots:
        /**
         * Ferme l'application.
         */
        void quitter();
        
        
        
       /**
        * Lance l'assistant de création de plateau.
        */
        void startAssistant();
};

#endif // MAINWINDOW_HPP
