#ifndef ASSISTANTCREATIONPLATEAU_HPP
#define ASSISTANTCREATIONPLATEAU_HPP

#include <QWizard>

#include "assistants/creationPlateau/PageGraphisme.hpp"
#include "assistants/creationPlateau/PageImage.hpp"
#include "assistants/creationPlateau/PageIntro.hpp"
#include "assistants/creationPlateau/PageOuvrir.hpp"
#include "assistants/creationPlateau/PagePrix.hpp"
#include "assistants/creationPlateau/PageTaille.hpp"
#include "donnees/Plateau.hpp"





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
