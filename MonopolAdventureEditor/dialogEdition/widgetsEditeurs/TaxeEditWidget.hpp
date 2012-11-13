#ifndef TAXEEDITWIDGET_HPP
#define TAXEEDITWIDGET_HPP

#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QSpinBox>

#include "donnees/emplacements/Taxe.hpp"





/**
 * @class TaxeEditWidget TaxeEditWidget.hpp dialogEdition/widgetsEditeurs/TaxeEditWidget.hpp
 * Cette classe fournit une interface d'édition des informations caractéristiques d'un emplacement « Taxe ».
 */
class TaxeEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        Taxe* m_taxe;///< Emplacement « Taxe » en cour d'édition.
        QCheckBox* m_champPayeMontantFixe;///< Champ d'édition du moyen de paiement (1/2).
        QLabel* m_labelMontantFixe;///< Étiquette associée à m_champMontant.
        QSpinBox* m_champMontantFixe;///< Champ d'édition du montant fixe de la taxe.
        QCheckBox* m_champPayePourcentage;///< Champ d'édition du moyen de paiement (2/2).
        QLabel* m_labelPourcentage;///< Étiquette asociée à m_champPourcentage.
        QSpinBox* m_champPourcentage;///< Champ d'édition du pourcentage sur la fortune de la taxe.
        
        
        
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
        
        
        
    public slots:
        /**
         * Active ou désactive les champs de configuration du montant fixe en fonction de si m_champPayeMontantFixe est coché ou non.
         */
        void champPayeMontantFixeChanged(int state);
        
        
        
        /**
         * Active ou désactive les champs de configuration du pourcentage sur la fortune en fonction de si m_champPayePourcentage est coché ou non.
         */
        void champPayePourcentageChanged(int state);
};

#endif // TAXEEDITWIDGET_HPP
