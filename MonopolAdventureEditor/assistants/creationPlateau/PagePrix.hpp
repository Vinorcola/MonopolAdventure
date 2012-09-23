#ifndef PAGEPRIX_HPP
#define PAGEPRIX_HPP

#include <QCheckBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWizardPage>





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
        QLineEdit* m_champDevise;///< Champ permettant de renseigner la devise utilisée sur le plateau.
        QLabel* m_explicationCoef;///< Texte d'explication du coefficient.
        QPushButton* m_coefPlus;///< Bouton qui augmente le coefficient.
        QPushButton* m_coefMoins;///< Bouton qui diminu le coefficient.
        QLabel* m_champCoef;///< Champ affichent le coefficient.
        QCheckBox* m_champAffichageCompletPrix;///< Champ permettant de configurer l'affichage des prix.
        QLabel* m_exempleAffichagePrix;///< Affichage des certain prix à titre d'exemple.
        
        
        
    public:
        /**
         * Construit une nouvelle page.
         */
        PagePrix();
        
        
        
        /**
         * Renvoie l'iddentifiant de la page suivante.
         */
        int nextId() const;
        
        
        
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

#endif // PAGEPRIX_HPP
