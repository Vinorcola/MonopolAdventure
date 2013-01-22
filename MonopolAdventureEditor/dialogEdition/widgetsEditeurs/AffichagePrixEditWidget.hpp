#ifndef AFFICHAGEPRIXEDITWIDGET_HPP
#define AFFICHAGEPRIXEDITWIDGET_HPP

#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Plateau;





/**
 * @class AffichagePrixEditWidget AffichagePrixEditWidget.hpp dialogEdition/widgetsEditeurs/AffichagePrixEditWidget.hpp
 * Ce widget permet l'édition des informations concernant les prix : la devise, le coefficient et l'affichage des chiffres.
 */
class AffichagePrixEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        Plateau* m_plateau;///< Plateau en cours d'édition.
        QLineEdit* m_champDevise;///< Champ permettant de renseigner la devise utilisée sur le plateau.
        QLabel* m_explicationCoef;///< Texte d'explication du coefficient.
        QPushButton* m_coefPlus;///< Bouton qui augmente le coefficient.
        QPushButton* m_coefMoins;///< Bouton qui diminu le coefficient.
        QLabel* m_champCoef;///< Champ affichent le coefficient.
        QCheckBox* m_champAffichageCompletPrix;///< Champ permettant de configurer l'affichage des prix.
        QLabel* m_exempleAffichagePrix;///< Affichage des certain prix à titre d'exemple.
        
        
        
    public:
        /**
         * Construit un widget d'édition par défaut.
         * @param plateau Plateau en cours d'édition.
         */
        AffichagePrixEditWidget(Plateau* plateau);
        
        
        
        /**
         * Sauvegarde les nouvelles informations dans le plateau.
         */
        void sauvegarde();
        
        
        
        
    public slots:
        /**
         * Slot appelé lorsque le bouton « plus » est cliqué.
         */
        void coefPlusClicked();
        
        
        
        /**
         * Slot appelé lorsque le bouton « moins » est cliqué.
         */
        void coefMoinsClicked();
        
        
        
        /**
         * Met à jour les exemples d'affichage de prix.
         */
        void affichageChanged(int state);
};

#endif // AFFICHAGEPRIXEDITWIDGET_HPP
