#ifndef PAGEOUVRIR_HPP
#define PAGEOUVRIR_HPP

#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QWizardPage>

#include "widgetsSelecteurs/FileSelectWidget.hpp"





/**
 * @class PageOuvrir PageOuvrir.hpp assistants/creationPlateau/PageOuvrir.hpp
 * Cette classe représente une page de l'assistant de création de plateau.
 * 
 * Cette page permet de charger un plateau existant depuis un fichier .map.
 */
class PageOuvrir : public QWizardPage
{
        Q_OBJECT
        
        
    private:
        FileSelectWidget* m_champOuvrir;///< Champ permettant de sélectionner un fichier .map contenant un plateau.
        QCheckBox* m_champCopier;///< Indique si le plateau doit être enregistré dans un autre fichier.
        QLabel* m_labelEnregistrerSous;///< QLabel associé au champ @c m_champEnregistrerSous.
        FileSelectWidget* m_champEnregistrerSous;///< Champ permettant de sélectionner un fichier .map pour enregistrer le plateau modifié.
        
        
        
    public:
        /**
         * Construit une nouvelle page.
         */
        PageOuvrir();
        
        
        
        /**
         * Renvoie l'iddentifiant de la page suivante.
         */
        int nextId() const;
        
        
        
    public slots:
        /**
         * Ce slot est appelé à chaque fois que la QCheckBox est cochée ou décochée.
         * 
         * Il active ou désactive le widget @c m_champEnregistrerSous.
         */
        void checkBoxStateChanged(int state);
        
        
        
    private slots:
        /**
         * Vérifie que le chemin du fichier à enregistrer contient bien « .map » à la fin.
         * 
         * Dans le cas contraire, on le rajoute.
         */
        void checkSavePath(QString file);
};

#endif // PAGEOUVRIR_HPP
