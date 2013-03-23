#ifndef PAGEJOUEUR_HPP
#define PAGEJOUEUR_HPP

#include <QList>
#include <QWizardPage>

#include "config/JoueurConfigWidget.hpp"





/**
 * @class PageJoueur PageJoueur.hpp assistants/partieMultijoueurs/PageJoueur.hpp
 * Cette classe représente une page de l'assistant de chargement d'une partie multijoueurs.
 * 
 * Cette page permet de configurer le nombre de joueurs ainsi que leur pseudo.
 */
class PageJoueur : public QWizardPage
{
        Q_OBJECT
        
        
    private:
        QList<JoueurConfigWidget*> m_joueurs;///< Liste des joueurs participants à la partie.
        
        
        
    public:
        /**
         * Construit une nouvelle page.
         */
        PageJoueur();
};

#endif // PAGEJOUEUR_HPP
