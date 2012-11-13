#ifndef TAXEEDITWIDGET_HPP
#define TAXEEDITWIDGET_HPP

#include <QCheckBox>
#include <QFormLayout>
#include <QSpinBox>

#include "donnees/emplacements/Taxe.hpp"





/**
 * @class TaxeEditWidget TaxeEditWidget.hpp dialogEdition/widgetsEditeurs/TaxeEditWidget.hpp
 * Cette classe fournit une interface d'édition des informations caractéristiques d'un emplacement « Taxe ».
 */
class TaxeEditWidget : public QWidget
{
        Q_OBJECT
        
        
    protected:
        Taxe* m_taxe;
        QCheckBox* m_champPayeMontant;
        QLabel* m_labelMontant;
        QSpinBox* m_champMontant;
        QCheckBox* m_champPayePourcentage;
        QLabel* m_labelPourcentage;
        QSpinBox* m_champPourcentage;
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition d'emplacement « Taxe ».
         * @param taxe Empalcement à éditer.
         */
        TaxeEditWidget(Taxe* const taxe);
        
        
        
        /**
         * Edite les informations de l'emplacement « Taxe » en fonction de la configuration des champs.
         */
        void sauvegarde();
};

#endif // TAXEEDITWIDGET_HPP
