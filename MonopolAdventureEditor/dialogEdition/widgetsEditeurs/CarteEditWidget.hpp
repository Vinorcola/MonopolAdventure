#ifndef CARTEEDITWIDGET_HPP
#define CARTEEDITWIDGET_HPP

#include <QTabWidget>
#include <QTextEdit>

#include "dialogEdition/widgetsEditeurs/ActionEditWidget.hpp"
#include "widgetsSelecteurs/ImageSelectWidget.hpp"





/**
 * @class CarteEditWidget CarteEditWidget.hpp dialogEdition/widgetsEditeurs/CarteEditWidget.hpp
 * Cette classe fournit une interface d'édition pour des cartes.
 */
class CarteEditWidget : public QTabWidget
{
        Q_OBJECT
        
        
    private:
        Carte* m_carte;///< Carte à éditer.
        QTextEdit* m_consigne;///< Champ d'édition de la consigne.
        ImageSelectWidget* m_image;///< Champ d'édition de l'image.
        QRadioButton* m_gauche;///< Indique si l'image est positionné à gauche.
        QRadioButton* m_droite;///< Indique si l'image est positionné à droite.
        QRadioButton* m_haut;///< Indique si l'image est positionné en haut.
        QRadioButton* m_bas;///< Indique si l'image est positionné en bas.
        QButtonGroup* m_positionImage;///< Champ de positionnement de l'image par rapport à la consigne.
        ActionEditWidget* m_action;///< Champ d'édition de l'action.
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition de cartes.
         * 
         * @param carte Carte à éditer.
         * @param emplacements Liste des emplacements du plateau.
         * @param pilesCartes Liste des piles de cartes du plateau.
         */
        CarteEditWidget(Carte* carte,
                        const QList<Emplacement*>& emplacements,
                        const QList<PileCartesData*>& pilesCartes);
        
        
        
        /**
         * Sauvegarde les changements dans la carte en cours d'édition.
         */
        void sauvegarde();
};

#endif // CARTEEDITWIDGET_HPP
