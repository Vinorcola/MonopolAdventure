#ifndef TYPEEMPLACEMENTEDITWIDGET_HPP
#define TYPEEMPLACEMENTEDITWIDGET_HPP

#include <QComboBox>
#include <QFormLayout>
#include <QLabel>

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class TypeEmplacementEditWidget TypeEmplacementEditWidget.hpp dialogEdition/widgetsEditeurs/TypeEmplacementEditWidget.hpp
 * Cette classe fournit une interface graphique permettant de changer le type d'un emplacement.
 */
class TypeEmplacementEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        Emplacement* m_emplacement;///< Emplacement en cours d'édition.
        QComboBox* m_champTypes;///< Liste de tous les types d'emplacement disponibles.
        QLabel* m_description;///< Affiche la description du type sélectionné.
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition de type d'emplacement.
         * @param emplacement Emplacement à éditer.
         */
        TypeEmplacementEditWidget(Emplacement* emplacement);
        
        
        
        /**
         * Retourne le type d'emplacement actuellement sélectionné.
         * @return Type d'emplacement actuellement sélectionné.
         */
        Type::Emplacement getTypeEmplacement() const;
        
        
        
    private slots:
        /**
         * Change la description affichée.
         */
        void changeDescription(int index);
};

#endif // TYPEEMPLACEMENTEDITWIDGET_HPP
