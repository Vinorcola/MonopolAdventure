#ifndef PAGEJOUEUR_HPP
#define PAGEJOUEUR_HPP

#include <QList>
#include <QSignalMapper>
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
        QVBoxLayout* m_layout;///< Layout permettant de mettre en forme les champs de la page.
        QSignalMapper* m_signalMapper;///< Mapper de signaux pour les QPushButton.
        QPushButton* m_boutonAjout;///< Bouton déclenchant l'ajout d'un nouveau widget.
        
        
        
    public:
        /**
         * Construit une nouvelle page.
         */
        PageJoueur();
        
        
        
    public slots:
        /**
         * Ajoute les champs nécessaires pour configurer un joueur supplémentaire.
         */
        void ajouterJoueur();
        
        
        
        /**
         * Enlève les champs permettant de configurer le joueur désigné.
         * 
         * @param index Index du joueur à supprimer.
         */
        void enleverJoueur(int index);
        
        
        
        /**
         * Configure les joueurs sur le plateau.
         * @param plateau Plateau de jeu.
         */
        void configureJoueurs(Plateau* plateau);
};

#endif // PAGEJOUEUR_HPP
