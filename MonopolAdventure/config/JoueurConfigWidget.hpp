#ifndef JOUEURCONFIGWIDGET_HPP
#define JOUEURCONFIGWIDGET_HPP

#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>





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
        
        
        
    public:
        /**
         * Construit un widget de configuration d'un joueur.
         */
        JoueurConfigWidget();
        
        
        
        /**
         * Indique le pseudo du joueur
         * @return Le pseudo du joueur.
         */
        QString pseudo();
        
        
        
    signals:
        /**
         * Signal envoyé lorsque le bouton « Supprimer » a été cliqué.
         */
        void supprimer();
};

#endif // JOUEURCONFIGWIDGET_HPP
