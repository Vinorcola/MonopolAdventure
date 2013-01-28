#ifndef PIOCHEEDITWIDGET_HPP
#define PIOCHEEDITWIDGET_HPP

#include <QFormLayout>

#include "dialogEdition/widgetsEditeurs/SauvegardeInterface.hpp"
#include "donnees/emplacements/Pioche.hpp"
#include "widgetsSelecteurs/PointerComboBox.hpp"





/**
 * @class PiocheEditWidget PiocheEditWidget.hpp dialogEdition/widgetsEditeurs/PiocheEditWidget.hpp
 * Cette classe fournit une interface d'édition des informations caractéristique d'un emplacement « Pioche ».
 */
class PiocheEditWidget : public SauvegardeInterface
{
        Q_OBJECT
        
        
    private:
        Pioche* m_pioche;///< Emplacement « Pioche » en cours d'édition.
        PointerComboBox<PileCartes>* m_champPileCartes;///< Champ d'édition de la pile de cartes dans laquelle piocher.
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition d'emplacement « Pioche ».
         * @param pioche Emplacement « Pioche » à éditer.
         * @param pilesCartes Liste des piles de cartes.
         */
        PiocheEditWidget(Pioche* const pioche,
                         const QList<PileCartes*>& pilesCartes);
        
        
        
        /**
         * Edite les informations de l'emplacement « Taxe » en fonction de la configuration des champs.
         */
        void sauvegarde();
};

#endif // PIOCHEEDITWIDGET_HPP
