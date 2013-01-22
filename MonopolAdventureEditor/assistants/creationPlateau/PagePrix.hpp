#ifndef PAGEPRIX_HPP
#define PAGEPRIX_HPP

#include <QWizardPage>

#include "dialogEdition/widgetsEditeurs/AffichagePrixEditWidget.hpp"





/**
 * @class PagePrix PagePrix.hpp assistants/creationPlateau/PagePrix.hpp
 * Cette classe représente une page de l'assistant de création de plateau.
 * 
 * Cette page permet de préciser les informations concernant tous les prix : la devise, le coefficient et l'affichage des chiffres.
 */
class PagePrix : public QWizardPage
{
        Q_OBJECT
        
        
        
    private:
        AffichagePrixEditWidget* m_champPrix;///< Champ d'édition des informations concernant les prix.
        
        
        
    public:
        /**
         * Construit une nouvelle page.
         * @param plateau Plateau de jeu.
         */
        PagePrix(Plateau* plateau);
        
        
        
        /**
         * Renvoie l'iddentifiant de la page suivante.
         */
        int nextId() const;
        
        
        
        /**
         * Permet au widget de sauvegarder les informations sur les prix dans le plateau.
         */
        void sauvegarde();
};

#endif // PAGEPRIX_HPP
