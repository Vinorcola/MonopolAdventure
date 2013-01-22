#ifndef PAGETAILLE_HPP
#define PAGETAILLE_HPP

#include <QButtonGroup>
#include <QFormLayout>
#include <QLabel>
#include <QRadioButton>
#include <QSpinBox>
#include <QWizardPage>





/**
 * @class PageTaille PageTaille.hpp assistants/creationPlateau/PageTaille.hpp
 * Cette classe représente une page de l'assistant de création de plateau.
 * 
 * Cette page permet de préciser la taille du plateau.
 */
class PageTaille : public QWizardPage
{
        Q_OBJECT
        
        
        
    private:
        QRadioButton* m_champPetit;///< Champ sélectionnable indiquant une petite taille de plateau (11x7).
        QRadioButton* m_champNormal;///< Champ sélectionnable indiquant une taille normale de plateau (11x11).
        QRadioButton* m_champGrand;///< Champ sélectionnable indiquant une grande taille de plateau (14x14).
        QRadioButton* m_champPerso;///< Champ sélectionnable indiquant une taille personnalisée.
        QSpinBox* m_champLargeur;///< Champ permettant de configurer la largeur du plateau.
        QLabel* m_labelX;///< QLabel indiquant une croix entre le champ largeur et le champ hauteur du plateau.
        QSpinBox* m_champHauteur;///< Champ permettant de configurer la hauteur du plateu.
        
        
        
    public:
        /**
         * Construit une nouvelle page.
         */
        PageTaille();
        
        
        
        /**
         * Renvoie l'iddentifiant de la page suivante.
         */
        int nextId() const;
        
        
        
    public slots:
        /**
         * Ce slot est appelé à chaque changement sur les radios.
         * 
         * Il met a jour les champs de largeur et de hauteur du plateau.
         */
        void buttonClicked(QAbstractButton* bouton);
};

#endif // PAGETAILLE_HPP
