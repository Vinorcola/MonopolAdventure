#ifndef DEPARTEDITWIDGET_HPP
#define DEPARTEDITWIDGET_HPP

#include <QFormLayout>
#include <QSpinBox>

#include "donnees/emplacements/Depart.hpp"





/**
 * @class DepartEditWidget DepartEditWidget.hpp dialogEdition/widgetsEditeurs/DepartEditWidget.hpp
 * Cette classe fournit une interface d'édition des informations caractéristiques d'un emplacement « Départ ».
 */
class DepartEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        Depart* m_depart;///< Emplacement « Départ » en cour d'édition.
        QSpinBox* m_champSalaire;///< Champ d'édition du salaire.
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition d'emplacement « Départ ».
         * @param depart Emplacement « Départ » à éditer.
         */
        DepartEditWidget(Depart* const depart);
        
        
        
        /**
         * Edite les informations de la prison en fonction de la configuration des champs.
         */
        void sauvegarde();
};

#endif // DEPARTEDITWIDGET_HPP
