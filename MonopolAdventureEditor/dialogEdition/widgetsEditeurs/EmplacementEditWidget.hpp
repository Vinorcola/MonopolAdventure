#ifndef EMPLACEMENTEDITWIDGET_HPP
#define EMPLACEMENTEDITWIDGET_HPP

#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>

#include "dialogEdition/widgetsEditeurs/SauvegardeInterface.hpp"
#include "donnees/emplacements/Emplacement.hpp"
#include "widgetsSelecteurs/ImageSelectWidget.hpp"





/**
 * @class EmplacementEditWidget EmplacementEditWidget.hpp dialogEdition/widgetsEditeurs/EmplacementEditWidget.hpp
 * Cette classe fournit une interface d'édition des informations générales d'un emplacement.
 */
class EmplacementEditWidget : public SauvegardeInterface
{
        Q_OBJECT
        
        
    private:
        Emplacement* m_emplacement;///< Enplacement en cours d'édition.
        QLineEdit* m_champTitre;///< Champ d'édition du titre.
        QLineEdit* m_champSousTitre;///< Champ d'édition du sous-titre.
        QTextEdit* m_champDescription;///< Champ d'édition de la description.
        ImageSelectWidget* m_champImage;///< Champ d'édition de l'image.
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition d'emplacement.
         * @param emplacement Emplacement à éditer.
         */
        EmplacementEditWidget(Emplacement* const emplacement);
        
        
        
        /**
         * Edite les informations générales de l'emplacement en fonction de la configuration des champs.
         */
        void sauvegarde();
};

#endif // EMPLACEMENTEDITWIDGET_HPP
