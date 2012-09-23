#ifndef PAGEINTRO_HPP
#define PAGEINTRO_HPP

#include <QFormLayout>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QWizardPage>





/**
 * @class PageIntro PageIntro.hpp assistants/creationPlateau/PageIntro.hpp
 * Cette classe représente une page de l'assistant de création de plateau.
 * 
 * Cette page affiche une introduction.
 */
class PageIntro : public QWizardPage
{
        Q_OBJECT
        
        
        
    private:
        QLabel* m_introduction;///< Texte d'introduction.
        QLabel* m_choix;///< Texte indiquant que l'utilisateur à le choix entre ouvrir un plateau existant ou créer un nouveau plateau.
        QRadioButton* m_radioCreer;///< Choix créer un nouveau plateau.
        QRadioButton* m_radioOuvrir;///< Choix ouvrir un plateau existant.
        
        
        
    public:
        /**
         * Construit une nouvelle page.
         */
        PageIntro();
        
        
        
        /**
         * Renvoie l'iddentifiant de la page suivante.
         */
        int nextId() const;
};

#endif // PAGEINTRO_HPP
