#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QAction>
#include <QApplication>
#include <QFileDialog>
#include <QGraphicsView>
#include <QMainWindow>
#include <QMenuBar>
#include <QMessageBox>
#include <QTimer>
#include <QToolBar>

#include "donnees/Plateau.hpp"





/**
 * @class MainWindow MainWindow.hpp MainWindow.hpp
 * MainWindow représente la fenêtre principale de l'éditeur de plateau MonopolAdventure.
 * 
 * Cette fenêtre est la fenêtre principale du programme. Elle accueille en son centre la vue sur le plateau en cours d'édition. Elle apporte aussi une barre d'outils, liée au plateau, permettant de lancer diverses fenêtres de dialogue pour éditer différentes composantes du plateau.
 */
class MainWindow : public QMainWindow
{
        Q_OBJECT
        
        
    private:
        Plateau* m_plateau;///< Plateau en cours d'édition.
        QGraphicsView* m_vueCentrale;///< Vue sur le plateau.
        QToolBar* m_barreOutils;///< Barre d'outils d'édition.
        QAction* m_actionQuitter;///< Action permettant de quitter MonopolAdventureEditor.
        QAction* m_actionAssistantCreation;///< Action permettant de lancer l'assistant d'ouverture/création de plateau.
        QAction* m_actionSauvegarder;///< Action permettant de sauvegarder le plateau dans un fichier.
        QAction* m_actionFermerPlateau;///< Action permettent de fermer un plateau en cours d'édition.
        
        QAction* m_actionZoomPlus;///< Action permettant de zoomer la vue sur le plateau.
        QAction* m_actionZoomMoins;///< Action permettant de dézoomer la vue du plateau.
        
        QAction* m_actionInfosGeneralesPlateau;///< Action permettant d'éditer les informations générales du plateau.
        QAction* m_actionPrix;///< Action permettant d'éditer les informations concernant les prix.
        QAction* m_actionRegroupements;///< Action permettant d'éditer les regroupements du plateau.
        QAction* m_actionPilesCartes;///< Action permettant d'éditer les piles de cartes du plateau.
        QAction* m_actionEditionTypeEmplacement;///< Action permettant d'activer ou de désactiver l'édition du type des emplacements.
        QAction* m_actionGraphismeEmplacement;///< Action permettant d'éditer les graphismes des emplacements.
        
        
        
    public:
        /**
         * Construit la fenêtre principale du programme.
         * 
         * Construit les différentes actions, menus, barres d'outils, etc. Agence le contenu avec des layouts et connecte les diverses signaux et slots.
         */
        MainWindow();
        
        
        
        /**
         * Indique si le bouton d'édition du type des emplacements est activé ou non.
         * @return @b @c true si le bouton est activé, @b @c false sinon.
         */
        bool editionTypeActive() const;
        
        
        
    public slots:
        /**
         * Quitte MonopolAdventureEditor.
         * 
         * Vérifie que le plateau en cours d'édition est enregistré. Si ce n'est pas le cas, on demande l'avis de l'utilisateur et, en fonction de sa réponse, on enregistre ou non le plateau avant de fermer l'application.
         */
        void quitter();
        
        
        
        /**
         * Ferme le plateau en cours d'édition.
         * 
         * Vérifie que le plateau en cours d'édition est enregistré. Si ce n'est pas le cas, on demande l'avis de l'utilisateur et, en fonction de sa réponse, on enregistre ou non le plateau avant de le fermer.
         */
        void fermerPlateau();
        
        
        
       /**
        * Lance l'assistant de création de plateau.
        * 
        * Invite l'utilisateur à ouvrir un plateau existant, ou a un créer un nouveau.
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
