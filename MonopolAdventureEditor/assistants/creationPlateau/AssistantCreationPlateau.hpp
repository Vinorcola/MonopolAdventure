#ifndef ASSISTANTCREATIONPLATEAU_HPP
#define ASSISTANTCREATIONPLATEAU_HPP

#include <QWizard>

class MainWindow;
class PageGeneral;
class PageGraphisme;
class PagePrix;
#include "donnees/Plateau.hpp"





/**
 * @class AssistantCreationPlateau AssistantCreationPlateau.hpp assistants/creationPlateau/AssistantCreationPlateau.hpp
 * Cette classe créer un assistant qui va acompagner l'utilisateur dans la création d'un plateau depuis zéro.
 * 
 * Cet assistant va utiliser d'autres classes widget afin de configurer le plateau.
 */
class AssistantCreationPlateau : public QWizard
{
        Q_OBJECT
        
        
    private:
        Plateau* m_plateau;///< Plateau créé.
        PageGeneral* m_pageGeneral;///< Page de l'assistant permettant de configurer les informations générales du plateau.
        PageGraphisme* m_pageGraphisme;///< Page de l'assistant permettant de configurer les graphismes des emplacements.
        PagePrix* m_pagePrix;///< Page de l'assistant permettant de configurer les informations sur les prix.
        
        
        
    public:
        /**
         * Construit un nouvel assistant qui va créer un plateau.
         * @param parent Fenêtre principale du programme.
         */
        AssistantCreationPlateau(MainWindow* parent);
        
        
        
    signals:
        /**
         * Indique que le plateau à été créé et configuré.
         * 
         * Un plateau configuré a pu, soit être chargé depuis un fichier, soit être configuré depuis zéro.
         */
        void plateauCreated(Plateau* plateau);
        
        
        
    public slots:
        void accept();
        
        
        
        /**
         * Détruit le plateau créé.
         */
        void reject();
};

#endif // ASSISTANTCREATIONPLATEAU_HPP
