#ifndef PLATEAUDECORATIONEDITWIDGET_HPP
#define PLATEAUDECORATIONEDITWIDGET_HPP

#include <QFormLayout>
#include <QLineEdit>

class Plateau;
#include "widgetsSelecteurs/ColorSelectWidget.hpp"
#include "widgetsSelecteurs/ImageSelectWidget.hpp"





/**
 * @class PlateauDecorationEditWidget PlateauDecorationEditWidget.hpp dialogEdition/widgetsEditeurs/PlateauDecorationEditWidget.hpp
 * Ce widget permet l'édition des décorations du plateau.
 */
class PlateauDecorationEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        Plateau* m_plateau;///< Plateau en cours d'édition.
        QLineEdit* m_champTitre;///< Champ permettant de configurer le titre du plateau.
        ColorSelectWidget* m_champCouleur;///< Champ permettant de configurer la couleur de fond du plateau.
        ImageSelectWidget* m_champImage;///< Champ permettant de configurer l'image centrale du plateau.
        
        
        
    public:
        /**
         * Construit un widget d'édition par défaut.
         * @param plateau Plateau en cours d'édition.
         */
        PlateauDecorationEditWidget(Plateau* plateau);
        
        
        
        /**
         * Sauvegarde les nouvelles informations dans le plateau.
         */
        void sauvegarde();
};

#endif // PLATEAUDECORATIONEDITWIDGET_HPP
