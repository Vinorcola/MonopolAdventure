#ifndef LOYERSERVICEEDITWIDGET_HPP
#define LOYERSERVICEEDITWIDGET_HPP

#include <QFormLayout>
#include <QSpinBox>

#include "dialogEdition/widgetsEditeurs/SauvegardeInterface.hpp"
#include "donnees/emplacements/Service.hpp"





/**
 * @class LoyerServiceEditWidget LoyerServiceEditWidget.hpp dialogEdition/widgetsEditeurs/LoyerServiceEditWidget.hpp
 * Cette classe fournit une interface d'édition des loyers d'un service.
 */
class LoyerServiceEditWidget : public SauvegardeInterface
{
        Q_OBJECT
        
        
    private:
        Service* m_service;///< Service en cours d'édition.
        QList<QSpinBox*> m_champsLoyer;///< Liste des champs d'édition des loyers.
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition de loyers d'un service.
         * @param service Service à éditer.
         * @param nombreServices Nombre total de services sur le plateau.
         */
        LoyerServiceEditWidget(Service* const service,
                               const int nombreServices);
        
        
        
        /**
         * Edite les informations de la compagnie de transport en fonction de la configuration des champs.
         */
        void sauvegarde();
};

#endif // LOYERSERVICEEDITWIDGET_HPP
