#ifndef PAGEOUVRIR_HPP
#define PAGEOUVRIR_HPP

#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QWizardPage>

#include "global.hpp"
#include "widgetsSelecteurs/FileSelectWidget.hpp"





/**
 * @class PageOuvrir PageOuvrir.hpp assistants/creationPlateau/PageOuvrir.hpp
 * Cette classe représente une page de l'assistant de création de plateau.
 * 
 * Cette page permet de charger un plateau existant depuis un fichier .plt.
 */
class PageOuvrir : public QWizardPage
{
        Q_OBJECT
        
        
    private:
        FileSelectWidget* m_champOuvrir;///< Champ permettant de sélectionner un fichier .plt contenant un plateau.
        
        
        
    public:
        /**
         * Construit une nouvelle page.
         */
        PageOuvrir();
        
        
        
        /**
         * Renvoie l'iddentifiant de la page suivante.
         */
        int nextId() const;
};

#endif // PAGEOUVRIR_HPP
