#ifndef PAGEGRAPHISME_HPP
#define PAGEGRAPHISME_HPP

#include <QWizardPage>

#include "dialogEdition/widgetsEditeurs/GraphismeEmplacementEditWidget.hpp"
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
        GraphismeEmplacementEditWidget* m_champ;///< Champ d'édition des graphismes des emplacements.
        
        
        
    public:
        /**
         * Construit une nouvelle page.
         * @param plateau Plateau à éditer.
         */
        PageGraphisme(Plateau* plateau);
        
        
        
        /**
         * Renvoie l'iddentifiant de la page suivante.
         */
        int nextId() const;
        
        
        
        /**
         * Permet au widget de sauvegarder les informations sur les prix dans le plateau.
         */
        void sauvegarde();
};

#endif // PAGEGRAPHISME_HPP
