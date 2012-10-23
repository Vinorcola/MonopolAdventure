#ifndef REGROUPEMENTEDITWIDGET_HPP
#define REGROUPEMENTEDITWIDGET_HPP

#include <QComboBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>

#include "modeles/SelectionRegroupementListModel.hpp"
#include "widgetsSelecteurs/ColorSelectWidget.hpp"





/**
 * @class RegroupementEditWidget RegroupementEditWidget.hpp widgetsEditeurs/RegroupementEditWidget.hpp
 * Cette classe fournit une interface d'édition pour des regroupements.
 * 
 * Tout d'abord, la création d'un RegroupementEditWidget nécessite un pointeur vers le regroupement à éditer. Le RegroupementEditWidget possède des champs permettant l'édition du titre et de la couleur du regroupement. Enfin, le dernier champs, le plus complexe permet de configurer les terrains appartenant au regroupement édité (deux listes et deux boutons « Ajouter » et « Enlever »).
 * 
 * Comme un terrain doit toujours appartenir à un regroupement, nous sommes obligé de transférer un terrain d'un regroupement à un autre pour modifier la liste des terrains contenus dans un regroupement. Ainsi, nous modifions deux regroupements en même temps lors d'un clic sur les boutons « Ajouter » ou « Enlever ». Donc finalement, la liste des terrains disponibles contient la liste des terrains d'un autre regroupement (déterminé via la liste de sélection de regroupement), d'où la nécessité de passer un modèle de données contenant une liste des Regroupements en paramètre du constructeur.
 */
class RegroupementEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        SelectionRegroupementListModel* m_regroupementModel;///< Modèle de données contenant une liste de regroupements.
        Regroupement* m_regroupement;///< Indique le regroupement en cours d'édition dans le modèle de données.
        QLineEdit* m_champTitre;///< Champ d'édition du titre du regroupement.
        ColorSelectWidget* m_champCouleur;///< Champ d'édition de la couleur du regroupement.
        QListView* m_champListeTerrains;///< Champ d'édition de la liste des terrains du regroupement.
        QPushButton* m_boutonAdd;///< Bouton ajoutant un terrain dans la liste des terrains du regroupement.
        QPushButton* m_boutonRemove;///< Bouton enlevant un terrain dans la liste des terrains du regroupement.
        QComboBox* m_selectAutreRegroupement;///< QComboBox permettant de sélectionner un autre regroupement à partir duquel ajouter/enlever des terrains.
        QListView* m_listeTerrainsDisponibles;///< Liste des terrains d'un autre regroupement.
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition de regroupement.
         * @param regroupement Regroupement à éditer.
         * @param regroupementModel Modèle contenant la liste des regroupements permettant de sélectionner des terrains.
         */
        RegroupementEditWidget(SelectionRegroupementListModel* regroupementModel,
                               Regroupement* regroupement);
        
        
        
    public slots:
        /**
         * Change le regroupement à éditer.
         * @param regroupement Regroupement à éditer.
         */
        void changeRegroupement(Regroupement* regroupement);
        
        
        
        /**
         * Remplace le titre du regroupement par @a titre.
         * @param titre Nouveau titre.
         */
        void champTitreChanged(const QString& titre);
        
        
        
        /**
         * Remplace la couleur du regroupement par @a couleur.
         * @param couleur Nouvelle couleur.
         */
        void champCouleurChanged(const QColor& couleur);
        
        
        
        /**
         * Déplace un terrain d'un autre regroupemen dans le regroupement en cours d'édition.
         */
        void boutonAddClicked();
        
        
        
        /**
         * Déplace un terrain du regroupement en cours d'édition dans un autre terrain.
         */
        void boutonRemoveClicked();
        
        
        
        /**
         * Change la liste des terrains disponibles.
         * @param row Nouveau rang du regroupement sélectionné.
         */
        void selectAutreRegroupementChanged(int row);
        
        
        
    private:
        /**
         * Met à jour tous les champs en fonction du Regroupement en cours d'édition.
         */
        void updateRegroupement();
};

#endif // REGROUPEMENTEDITWIDGET_HPP
