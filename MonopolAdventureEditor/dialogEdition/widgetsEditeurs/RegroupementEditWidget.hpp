#ifndef REGROUPEMENTEDITWIDGET_HPP
#define REGROUPEMENTEDITWIDGET_HPP

#include <QComboBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>

#include "dialogEdition/modeles/SelectionRegroupementListModel.hpp"
#include "widgetsSelecteurs/ColorSelectWidget.hpp"





/**
 * @class RegroupementEditWidget RegroupementEditWidget.hpp widgetsEditeurs/RegroupementEditWidget.hpp
 * Cette classe fournit une interface d'édition pour des regroupements.
 * 
 * Tout d'abord, la création d'un RegroupementEditWidget nécessite un pointeur vers le regroupementData à éditer. Le RegroupementEditWidget possède des champs permettant l'édition du titre et de la couleur du regroupement. Enfin, le dernier champs, le plus complexe permet de configurer les terrains appartenant au regroupement édité (deux listes et deux boutons « Ajouter » et « Enlever »).
 * 
 * Comme un terrain doit toujours appartenir à un regroupement, nous sommes obligé de transférer un terrain d'un regroupement à un autre pour modifier la liste des terrains contenus dans un regroupement. Ainsi, nous modifions deux regroupements en même temps lors d'un clic sur les boutons « Ajouter » ou « Enlever ». Donc finalement, la liste des terrains disponibles contient la liste des terrains d'un autre regroupement (déterminé via la liste de sélection de regroupement), d'où la nécessité de passer un modèle de données contenant une liste des regroupements sélectionnables en paramètre du constructeur.
 */
class RegroupementEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        Regroupement* m_regroupement;///< Regroupement en cours d'édition.
        QLineEdit* m_champTitre;///< Champ d'édition du titre du regroupement.
        ColorSelectWidget* m_champCouleur;///< Champ d'édition de la couleur du regroupement.
        SelectionRegroupementListModel* m_modeleRegroupementsSelectionnables;///< Modèle de données contenant la liste des regroupements sélectionnables.
        QComboBox* m_vueRegroupementsSelectionnables;///< Vue affichant le modèle de données @a m_modeleRegroupementsSelectionnables.
        QListView* m_vueTerrainsInternes;///< Vue affichant le modèle de données @a m_modelTerrainsInternes.
        QListView* m_vueTerrainsExternes;///< Vue affichant le modèle de données @a m_modelTerrainsExternes.
        QPushButton* m_boutonAjouter;///< Bouton émettant le signal ajouterClicked().
        QPushButton* m_boutonEnlever;///< Boutonémettant le signal enleverClicked().
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition de regroupement.
         * @param regroupement Regroupement à éditer.
         * @param regroupementModel Modèle contenant la liste des regroupements permettant de sélectionner des terrains.
         */
        RegroupementEditWidget(Regroupement* regroupement,
                               SelectionRegroupementListModel* regroupementModel);
        
        
        
        /**
         * Change le regroupement à éditer.
         * @param regroupement Regroupement à éditer.
         */
        void changeRegroupement(Regroupement* regroupement);
        
        
        
    private slots:
        /**
         * Change le modèle de données des terrains externes.
         * @param rowRegroupementSelectionne Rang du nouveau regroupement sélectionné.
         */
        void changeModeleTerrainsExterne(int rowRegroupementSelectionne);
        
        
        
        /**
         * Transmets un terrain du regroupement sélectionné au regroupement en cours d'édition.
         */
        void ajouterTerrain();
        
        
        
        /**
         * Transmet un terrain du regroupement en cours d'édition au regroupement sélectionné.
         */
        void enleverTerrain();
        
        
        
        /**
         * Change le titre du regroupement.
         * @param titre Nouveau titre.
         */
        void changeTitre(QString titre);
        
        
        
        /**
         * Change la couleur du regroupement.
         * @param couleur Nouvelle couleur.
         */
        void changeCouleur(QColor couleur);
};

#endif // REGROUPEMENTEDITWIDGET_HPP
