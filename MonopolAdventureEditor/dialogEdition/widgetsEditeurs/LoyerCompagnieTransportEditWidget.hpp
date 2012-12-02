#ifndef LOYERCOMPAGNIETRANSPORTEDITWIDGET_HPP
#define LOYERCOMPAGNIETRANSPORTEDITWIDGET_HPP

#include <QFormLayout>
#include <QSpinBox>

#include "donnees/emplacements/CompagnieTransport.hpp"





/**
 * @class LoyerCompagnieTransportEditWidget LoyerCompagnieTransportEditWidget.hpp dialogEdition/widgetsEditeurs/LoyerCompagnieTransportEditWidget.hpp
 * Cette classe fournit une interface d'édition des loyers d'une compagnie de transport.
 */
class LoyerCompagnieTransportEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        CompagnieTransport* m_compagnieTransport;///< Compagnie de transport en cours d'édition.
        QList<QSpinBox*> m_champsLoyer;///< Liste des champs d'édition du loyer.
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition de compagnie de transport.
         * @param compagnieTransport Compagnie de transport à éditer.
         * @param nombreCompagnies Nombre total de compagnies de transport sur le plateau.
         */
        LoyerCompagnieTransportEditWidget(CompagnieTransport* const compagnieTransport,
                                          const int nombreCompagnies);
        
        
        
        /**
         * Edite les informations de la compagnie de transport en fonction de la configuration des champs.
         */
        void sauvegarde();
};

#endif // LOYERCOMPAGNIETRANSPORTEDITWIDGET_HPP
