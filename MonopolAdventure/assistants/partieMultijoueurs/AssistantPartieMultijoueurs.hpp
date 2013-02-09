#ifndef ASSISTANTPARTIEMULTIJOUEURS_HPP
#define ASSISTANTPARTIEMULTIJOUEURS_HPP

#include <QWizard>

class MainWindow;
#include "assistants/partieMultijoueurs/PagePlateau.hpp"
#include "assistants/partieMultijoueurs/PageRegle.hpp"





/**
 * @class AssistantPartieMultijoueurs AssistantPartieMultijoueurs.hpp assistants/partieMultijouers/AssistantPartieMultijoueurs.hpp
 */
class AssistantPartieMultijoueurs : public QWizard
{
        Q_OBJECT
        
        
    private:
        Plateau* m_plateau;///< Plateau chargé pour la partie multijoueur.
        
        
        
    public:
        /**
         * Construit un nouvel assistant qui charge un plateau et configure les règles de jeu avant de lancer la partie.
         * @param parent Fenêtre principale du programme.
         */
        AssistantPartieMultijoueurs(MainWindow* parent);
        
        
        
    signals:
        /**
         * Signale que le plateau a été chargé et est prêt à être utilisé.
         * @param plateau Plateau à utiliser.
         */
        void plateauLoaded(Plateau* plateau);
        
        
        
    public slots:
        /**
         * Configure le plateau puis modifie la règle associée.
         */
        void accept();
        
        
        
        /**
         * Détruit le plateau créé.
         */
        void reject();
};

#endif // ASSISTANTPARTIEMULTIJOUEURS_HPP
