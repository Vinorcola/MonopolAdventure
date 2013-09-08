#ifndef JOUEURCONFIGWIDGET_HPP
#define JOUEURCONFIGWIDGET_HPP

#include <QComboBox>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>

#include "config/CouleurListModel.hpp"
#include "donnees/Plateau.hpp"





/**
 * @class JoueurConfigWidget JoueurConfigWidget.hpp config/JoueurConfigWidget.hpp
 * Cette classe représente un widget permettant de créer et de configurer un joueur pour une partie.
 */
class JoueurConfigWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        QLineEdit* m_pseudo;///< Champ permettant de saisir le pseudo du joueur.
        QPushButton* m_boutonSupprimer;///< Bouton permetant de demander la suppression du widget.
        QComboBox* m_listeCouleur;///< Liste permettant de sélectionner la couleur du personnage.
        CouleurListModel* m_modeleCouleur;///< Modèle de données contenant la liste des couleurs disponible.
        
        
        
    public:
        /**
         * Construit un widget de configuration d'un joueur.
         */
        JoueurConfigWidget();
        
        
        
        /**
         * Destructeur.
         * 
         * Libère la couleur du modèle de données.
         */
        ~JoueurConfigWidget();
        
        
        
        /**
         * Indique le pseudo du joueur
         * @return Le pseudo du joueur.
         */
        QString pseudo();
        
        
        
        /**
         * Configure un nouveau joueur sur le plateau avec les renseignements présents dans les différents widgets.
         * @param plateau Plateau de jeu.
         */
        void configureJoueur(Plateau* plateau) const;
        
        
        
    signals:
        /**
         * Signal envoyé lorsque le bouton « Supprimer » a été cliqué.
         */
        void supprimer();
};

#endif // JOUEURCONFIGWIDGET_HPP
