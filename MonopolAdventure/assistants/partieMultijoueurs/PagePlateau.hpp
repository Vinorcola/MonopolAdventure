#ifndef PAGEPLATEAU_HPP
#define PAGEPLATEAU_HPP

#include <QLabel>
#include <QWizardPage>

#include "donnees/Plateau.hpp"
#include "widgetsSelecteurs/FileSelectWidget.hpp"





/**
 * @class PagePlateau PagePlateau.hpp assistants/partieMultijoueurs/PagePlateau.hpp
 * Cette classe représente une page de l'assistant de chargement d'une partie multijoueurs.
 * 
 * Cette page permet de sélectionner un plateau.
 */
class PagePlateau : public QWizardPage
{
        Q_OBJECT
        
        
    private:
        Plateau* m_plateau;///< Plateau a charger.
        FileSelectWidget* m_fichier;///< Fichier à partir duquel charger le plateau.
        QLabel* m_msgConfirmation;///< Label affichant un message de confirmation du chargement du plateau.
        bool m_plateauCharge;///< Indique si le plateau est bien chargé.
        
        
        
    public:
        /**
         * Construit une nouvelle page.
         * @param plateau Plateau a charger.
         */
        PagePlateau(Plateau* plateau);
        
        
        
        /**
         * Indique si le plateau est bien charger.
         * @return @b @c true si le plateau est bien chargé à partir du fichier.
         */
        bool isComplete() const;
        
        
        
    public slots:
        /**
         * Charge le plateau demandé par l'utilisateur.
         */
        void chargePlateau(const QString& chemin);
};

#endif // PAGEPLATEAU_HPP
