#ifndef SAUVEGARDEINTERFACE_HPP
#define SAUVEGARDEINTERFACE_HPP

#include <QWidget>





/**
 * @interface SauvegardeInterface SauvegardeInterface.hpp dialogEdition/WidgetsEdition/SauvegardeInterface.hpp
 * Cette interface sert de base au widget d'édition des emplacements.
 */
class SauvegardeInterface : public QWidget
{
        Q_OBJECT
        
        
    public:
        /**
         * Permet au widget de sauvegarder les informations changés dans l'emplacement.
         */
        virtual void sauvegarde() = 0;
};


#endif // SAUVEGARDEINTERFACE_HPP
