#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QAction>
#include <QApplication>
#include <QFileDialog>
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
        QAction* m_actionSauvegarder;///< Action permettant de sauvegarder le plateau.
        QAction* m_actionFermerPlateau;///< Action permettent de fermer un plateau en cours d'édition.
        
        QAction* m_actionZoomPlus;///< Action permettant de zoomer la vue sur le plateau.
        QAction* m_actionZoomMoins;///< Action permettant de dézoomer la vue du plateau.
        
        QAction* m_actionDecoration;///< Action permettant d'éditer les décorations du plateau.
        QAction* m_actionPrix;///< Action permettant d'éditer les informations concernant les prix.
        QAction* m_actionRegroupements;///< Action permettant d'éditer la liste des regroupements du plateau.
        QAction* m_actionPilesCartes;///< Action permettant d'éditer la liste des piles de cartes du plateau.
        QAction* m_actionEditionTypeEmplacement;///< Action permettant d'activer ou de désactiver l'édition du type des emplacements.
        QAction* m_actionGraphismeEmplacement;///< Action permettant d'éditer les graphismes des emplacements.
        
        
        
    public:
        /**
         * Construit le fenêtre principale du programme.
         */
        MainWindow();
        
        
        
        /**
         * Indique si le bouton d'édition du type des emplacements est activé ou non.
         * @return @b @c true si le bouton est activé.
         */
        bool editionTypeActive() const;
        
        
        
    public slots:
        /**
         * Ferme l'application.
         */
        void quitter();
        
        
        
        /**
         * Ferme le plateau en cours d'édition.
         */
        void fermerPlateau();
        
        
        
       /**
        * Lance l'assistant de création de plateau.
        */
        void startAssistant();
        
        
        
        /**
         * Dessine le plateau et le connecte à différents slots.
         * @param plateau Plateau à afficher et éditer.
         */
        void dessinePlateau(Plateau* plateau);
        
        
        
        /**
         * Enclenche la procédure de sauvegarde du plateau.
         * @return @b @c true si l'utilisateur a bien sauvegarder, @b @c false s'il a annulé la procédure.
         */
        bool enregistrer();
        
        
        
        /**
         * Zoom la vue sur le plateau.
         */
        void zoomPlus();
        
        
        
        /**
         * Dézoom la vue du le plateau.
         */
        void zoomMoins();
};

#endif // MAINWINDOW_HPP
