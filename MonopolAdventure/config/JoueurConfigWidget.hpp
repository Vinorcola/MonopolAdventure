#ifndef JOUEURCONFIGWIDGET_HPP
#define JOUEURCONFIGWIDGET_HPP

#include <QLineEdit>
#include <QVBoxLayout>





/**
 * @class JoueurConfigWidget JoueurConfigWidget.hpp config/JoueurConfigWidget.hpp
 * Cette classe représente un widget permettant de créer et de configurer un joueur pour une partie.
 */
class JoueurConfigWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        QLineEdit* m_pseudo;///< Champ permettant de saisir le pseudo du joueur.
        
        
        
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
};

#endif // JOUEURCONFIGWIDGET_HPP
