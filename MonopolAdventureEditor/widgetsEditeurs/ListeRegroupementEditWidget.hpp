#ifndef LISTEREGROUPEMENTEDITWIDGET_HPP
#define LISTEREGROUPEMENTEDITWIDGET_HPP

#include <QComboBox>
#include <QMessageBox>
#include <QPushButton>

#include "modeles/RegroupementListModel.hpp"
#include "widgetsEditeurs/RegroupementEditWidget.hpp"





/**
 * @class ListeRegroupementEditWidget ListeRegroupementEditWidget.hpp widgetsEditeurs/ListeRegroupementEditWidget.hpp
 * Cette classe fournit une interface d'édition pour une liste de regroupements.
 */
class ListeRegroupementEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        RegroupementListModel* m_modelRegroupementChoix;///< Modèle de données contenant la liste des regroupements à choisir pour l'édition.
        QComboBox* m_champRegroupement;///< QComboBox permettant de sélectionner le regroupement à éditer.
        QPushButton* m_boutonCreer;///< Bouton permettant de créer un nouveau regroupement.
        QPushButton* m_boutonSupprimer;///< Bouton permettant de supprimer un regroupement.
        RegroupementEditWidget* m_editWidget;///< QWidget d'édition d'un regroupement.
        
        
        
    public:
        /**
         * Construit un nouveau QWidget d'édition d'une liste de Regroupements.
         * @param listeRegroupements Liste de Regroupements à éditer.
         */
        ListeRegroupementEditWidget(QList<Regroupement*>& regroupements);
        
        
        
    public slots:
        /**
         * Change le regroupement en cours d'édition.
         * @param index Nouvel index sélectionné dans la liste.
         */
        void champRegroupementChanged(int index);
        
        
        
        /**
         * Créer un nouveau regroupement et le sélectionne pour l'édition.
         */
        void createRegroupement();
        
        
        
        /**
         * Supprime le regroupement en cours d'édition.
         * 
         * Le regroupement suivant est sélectionné pour être édité. Si le regroupement supprimé était le dernier de la liste, alors le regroupement précédent sera sélectionné pour être édité.
         */
        void deleteRegroupement();
};

#endif // LISTEREGROUPEMENTEDITWIDGET_HPP
