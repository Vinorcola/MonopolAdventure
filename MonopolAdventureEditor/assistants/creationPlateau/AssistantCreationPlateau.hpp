#ifndef ASSISTANTCREATIONPLATEAU_HPP
#define ASSISTANTCREATIONPLATEAU_HPP

#include <QWizard>

#include "donnees/Plateau.hpp"
class PagePrix;





/**
 * @class AssistantCreationPlateau AssistantCreationPlateau.hpp assistants/creationPlateau/AssistantCreationPlateau.hpp
 * Cette classe créer un assistant qui va acompagner l'utilisateur dans la création d'un plateau depuis zéro.
 * 
 * Cet assistant va utiliser d'autres classes widget afin de configurer le plateau.
 */
class AssistantCreationPlateau : public QWizard
{
    private:
        Plateau* m_plateau;///< Plateau à configurer.
        PagePrix* m_pagePrix;///< Page de l'assistant permettant de configurer les informations sur les prix.
        
        
        
    public:
        /**
         * Construit un nouvel assistant qui va configurer le plateau @a plateau.
         * @param plateau Plateau à configurer.
         */
        AssistantCreationPlateau(Plateau* plateau);
        
        
        
    public slots:
        void accept();
};

#endif // ASSISTANTCREATIONPLATEAU_HPP
