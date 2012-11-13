#ifndef PRISONEDITWIDGET_HPP
#define PRISONEDITWIDGET_HPP

#include <QFormLayout>
#include <QSpinBox>

#include "donnees/emplacements/Prison.hpp"





/**
 * @class PrisonEditWidget PrisonEditWidget.hpp dialogEdition/widgetsEditeurs/PrisonEditWidget.hpp
 * Cette classe fournit une interface d'édition des informations caractéristiques d'une prison.
 */
class PrisonEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        Prison* m_prison;///< Prison en cours d'édition.
        QSpinBox* m_champCaution;///< Champ d'édition de la caution.
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition de prison.
         * @param prison Prison à éditer.
         */
        PrisonEditWidget(Prison* const prison);
        
        
        
        /**
         * Edite les informations de la prison en fonction de la configuration des champs.
         */
        void sauvegarde();
};

#endif // PRISONEDITWIDGET_HPP
