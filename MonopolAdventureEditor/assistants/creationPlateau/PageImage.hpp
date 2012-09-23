#ifndef PAGEIMAGE_HPP
#define PAGEIMAGE_HPP

#include <QFormLayout>
#include <QWizardPage>

#include "widgetsSelecteurs/ColorSelectWidget.hpp"
#include "widgetsSelecteurs/ImageSelectWidget.hpp"





/**
 * @class PageImage PageImage.hpp assistants/creationPlateau/PageImage.hpp
 * Cette classe représente une page de l'assistant de création de plateau.
 * 
 * Cette page permet de sélectionner une image pour le centre du plateau.
 * 
 * @todo Rajouter la sélection de la couleur de fond du plateau.
 */
class PageImage : public QWizardPage
{
        Q_OBJECT
        
        
        
    private:
        ColorSelectWidget* m_champCouleur;///< Champ permettant de configurer la couleur de fond du plateau.
        ImageSelectWidget* m_champImage;///< Champ permettant de configurer l'image centrale du plateau.
        
        
        
    public:
        /**
         * Construit une nouvelle page.
         */
        PageImage();
        
        
        
        /**
         * Renvoie l'iddentifiant de la page suivante.
         */
        int nextId() const;
};

#endif // PAGEIMAGE_HPP
