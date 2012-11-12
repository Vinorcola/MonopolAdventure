#ifndef LISTEREGROUPEMENTEDITWIDGET_HPP
#define LISTEREGROUPEMENTEDITWIDGET_HPP

#include <QComboBox>
#include <QMessageBox>
#include <QPushButton>

#include "dialogEdition/modeles/RegroupementListModel.hpp"
#include "dialogEdition/widgetsEditeurs/RegroupementEditWidget.hpp"





/**
 * @class ListeRegroupementEditWidget ListeRegroupementEditWidget.hpp widgetsEditeurs/ListeRegroupementEditWidget.hpp
 * Cette classe fournit une interface d'édition pour une liste de regroupements.
 */
class ListeRegroupementEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        QList<RegroupementData*>& m_regroupements;///< Liste de regroupements éditables.
        RegroupementListModel* m_modeleRegroupement;///< Modèle de données contenant la liste des regroupements éditable.
        QComboBox* m_vueRegroupements;///< Vue permettant d'afficher le modèle de données @a m_modeleRegroupements.
        QPushButton* m_boutonCreer;///< Bouton permettant de créer un nouveau regroupement.
        QPushButton* m_boutonSupprimer;///< Bouton permettant de supprimer un regroupement.
        RegroupementEditWidget* m_widgetEditionRegroupement;///< QWidget d'édition d'un regroupement.
        
        
        
    public:
        /**
         * Construit un nouveau QWidget d'édition d'une liste de Regroupements.
         * @param regroupements Liste de regroupements éditables.
         */
        ListeRegroupementEditWidget(QList<RegroupementData*>& regroupements);
        
        
        
        /**
         * Sélectionne un regroupement précis pour l'édition.
         * @param row Rang du regroupement dans le modèle de données.
         */
        void selectionneRegroupement(int row);
        
        
        
    private slots:
        /**
         * Change le regroupement en cours d'édition.
         * @param index Index du regroupement à éditer dans le modèle de données.
         */
        void changeRegroupementEdite(int index);
        
        
        
        /**
         * Créé un nouveau regroupement et l'ajoute au modèle de données. Puis lance l'édition de se dernier.
         */
        void createRegroupement();
        
        
        
        /**
         * Supprime un regroupement (s'il ne contient plus de terrains) du modèle de données. Change le regroupement en cours d'édition.
         */
        void deleteRegroupement();
};

#endif // LISTEREGROUPEMENTEDITWIDGET_HPP
