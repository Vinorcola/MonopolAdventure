#ifndef PAGEGENERAL_HPP
#define PAGEGENERAL_HPP

#include <QWizardPage>

#include "dialogEdition/widgetsEditeurs/PlateauDecorationEditWidget.hpp"




/**
 * @class PageGeneral PageGeneral.hpp assistants/creatationPlateau/PageGeneral.hpp
 * Cette classe représente une page de l'assistant de création de plateau.
 * 
 * Cette page permet nommer le plateau, et de sélectionner une couleur de fond ainsi qu'une image pour le centre du plateau.
 */
class PageGeneral : public QWizardPage
{
        Q_OBJECT
        
        
    private:
        PlateauDecorationEditWidget* m_champ;///< Champ d'édition des informations générales du plateau.
        
        
        
    public:
        /**
         * Construit une nouvelle page.
         * @param plateau Plateau de jeu.
         */
        PageGeneral(Plateau* plateau);
        
        
        
        /**
         * Renvoie l'iddentifiant de la page suivante.
         */
        int nextId() const;
        
        
        
        /**
         * Permet au widget de sauvegarder les informations sur les prix dans le plateau.
         */
        void sauvegarde();
};

#endif // PAGEGENERAL_HPP
