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
 * Cette classe affiche un assistant guidant l'utilisateur dans l'ouverture ou la création d'un plateau.
 * 
 * Il y a deux façon d'éditer un plateau dans MonopolAdventureEditor :
 * @li Ouvrir un plateau déjà existant depuis un fichier, puis le modifier ;
 * @li Créer un plateau à parti de zéro.
 * 
 * Cet assistant invite l'utilisateur à faire un choix entre ces deux possibilités. Si l'utilisateur choisi d'ouvrir un plateau, alors il doit renseigner le chemin du fichier. S'il préfère créer un nouveau plateau, l'assistant l'accompagne dans les configurations de bases du plateau.
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
        /**
         * Termine l'assistant et enregistre toutes les informations dans le plateau.
         */
        void accept();
        
        
        
        /**
         * Détruit le plateau créé.
         */
        void reject();
};

#endif // ASSISTANTCREATIONPLATEAU_HPP
