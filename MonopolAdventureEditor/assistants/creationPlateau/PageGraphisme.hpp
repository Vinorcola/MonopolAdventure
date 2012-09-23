#ifndef PAGEGRAPHISME_HPP
#define PAGEGRAPHISME_HPP

#include <QFormLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSpinBox>
#include <QWizardPage>

#include "widgetsSelecteurs/ColorSelectWidget.hpp"
#include "widgetsSelecteurs/FontSelectWidget.hpp"





/**
 * @class PageGraphisme PageGraphisme.hpp assistants/creationPlateau/PageGraphisme.hpp
 * Cette classe représente une page de l'assistant de création de plateau.
 * 
 * Cette page permet de configurer les détails graphiques des emplacements du plateau.
 */
class PageGraphisme : public QWizardPage
{
        Q_OBJECT
        
        
        
    private:
        QGraphicsScene* m_scene;///< Scène contenant les exemples.
        QGraphicsView* m_vue;///< Vue affichant la scène.
        
        QSpinBox* m_champLargeur;///< Champ permettant de configurer la largeur en pixel d'un emplacement.
        QSpinBox* m_champHauteur;///< Champ permettant de configurer la hauteur en pixel d'un emplacement.
        QSpinBox* m_champHauteurCouleurGroupement;///< Champ permettant de configurer la hauteur de la bande de couleur du groupement.
        ColorSelectWidget* m_champCouleurFond;///< Champ permettant de configurer la couleur de fond des emplacements.
        ColorSelectWidget* m_champCouleurBordure;///< Champ permettant de configurer la couleur des bordures des emplacements.
        QSpinBox* m_champEpaisseurBordure;///< Champ permettant de configurer l'épaisseur du trait des bordures des emplacements.
        FontSelectWidget* m_champPoliceTitre;///< Champ permettant de configurer la fonte de caractères du titre des emplacements.
        FontSelectWidget* m_champPoliceSousTitre;///< Champ permettant de configurer la fonte de caractères du sous-titre des emplacements.
        FontSelectWidget* m_champPoliceDescription;///< Champ permettant de configurer la fonte de caractères de la description des emplacements.
        FontSelectWidget* m_champPolicePrix;///< Champ permettant de configurer la fonte de caractères du prix des emplacements.
        QSpinBox* m_champMarge;///< Champ permettant de configurer la marge minimale entre le texte des les bordures des emplacements.
        
        
        
    public:
        /**
         * Construit une nouvelle page.
         */
        PageGraphisme();
        
        
        
        /**
         * Renvoie l'iddentifiant de la page suivante.
         */
        int nextId() const;
};

#endif // PAGEGRAPHISME_HPP
