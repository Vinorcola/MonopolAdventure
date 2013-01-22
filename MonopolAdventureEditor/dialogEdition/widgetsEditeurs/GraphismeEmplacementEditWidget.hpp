#ifndef GRAPHISMEEMPLACEMENTEDITWIDGET_HPP
#define GRAPHISMEEMPLACEMENTEDITWIDGET_HPP

#include <QFormLayout>
#include <QSpinBox>

class Plateau;
#include "widgetsSelecteurs/ColorSelectWidget.hpp"
#include "widgetsSelecteurs/FontSelectWidget.hpp"




/**
 * @class GraphismeEmplacementEditWidget GraphismeEmplacementEditWidget.hpp dialogEdition/widgetsEditeurs/GraphismeEmplacementEditWidget.hpp
 * Ce widget permet l'édition des graphismes des emplacements.
 */
class GraphismeEmplacementEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        Plateau* m_plateau;///< Plateau en cours d'édition.
        QSpinBox* m_champLargeur;///< Champ permettant de configurer la largeur en pixel d'un emplacement.
        QSpinBox* m_champHauteur;///< Champ permettant de configurer la hauteur en pixel d'un emplacement.
        QSpinBox* m_champHauteurCouleurRegroupement;///< Champ permettant de configurer la hauteur de la bande de couleur du regroupement.
        ColorSelectWidget* m_champCouleurFond;///< Champ permettant de configurer la couleur de fond des emplacements.
        ColorSelectWidget* m_champCouleurBordure;///< Champ permettant de configurer la couleur des bordures des emplacements.
        QSpinBox* m_champEpaisseurBordure;///< Champ permettant de configurer l'épaisseur du trait des bordures des emplacements.
        FontSelectWidget* m_champFonteTitre;///< Champ permettant de configurer la fonte de caractères du titre des emplacements.
        FontSelectWidget* m_champFonteSousTitre;///< Champ permettant de configurer la fonte de caractères du sous-titre des emplacements.
        FontSelectWidget* m_champFonteDescription;///< Champ permettant de configurer la fonte de caractères de la description des emplacements.
        FontSelectWidget* m_champFontePrix;///< Champ permettant de configurer la fonte de caractères du prix des emplacements.
        QSpinBox* m_champMarge;///< Champ permettant de configurer la marge minimale entre le texte des les bordures des emplacements.
        
        
        
    public:
        /**
         * Construit un widget d'édition par défaut.
         * @param plateau Plateau en cours d'édition.
         */
        GraphismeEmplacementEditWidget(Plateau* plateau);
        
        
        
        /**
         * Sauvegarde les nouvelles informations dans le plateau.
         */
        void sauvegarde();
};

#endif // GRAPHISMEEMPLACEMENTEDITWIDGET_HPP
