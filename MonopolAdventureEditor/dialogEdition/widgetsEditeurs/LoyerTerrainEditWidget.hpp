#ifndef LOYERTERRAINEDITWIDGET_HPP
#define LOYERTERRAINEDITWIDGET_HPP

#include <QFormLayout>
#include <QSpinBox>

#include "dialogEdition/widgetsEditeurs/SauvegardeInterface.hpp"
#include "donnees/emplacements/Terrain.hpp"





/**
 * @class LoyerTerrainEditWidget LoyerTerrainEditWidget.hpp dialogEdition/widgetsEditeurs/LoyerTerrainEditWidget.hpp
 * Cette classe fournit une interface d'édition des loyers d'un terrain.
 */
class LoyerTerrainEditWidget : public SauvegardeInterface
{
        Q_OBJECT
        
        
    private:
        Terrain* m_terrain;///< Terrain en cours d'édition.
        QSpinBox* m_champLoyerNu;///< Champ d'édition du loyer du terrain nu.
        QSpinBox* m_champLoyerNuExtra;///< Champ d'édition du loyer extra du terrain nu.
        QList<QSpinBox*> m_champsLoyersMaison;///< Liste des champs d'édition des loyers des maisons.
        QList<QSpinBox*> m_champsLoyersHotel;///< Liste des champs d'édition des loyers des hôtels.
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition de loyers d'un terrain.
         * @param terrain Terrain à éditer.
         * @param nombreMaisonsPourHotel Nombre de maisons nécessaires pour la construction d'un hôtel.
         */
        LoyerTerrainEditWidget(Terrain* const terrain);
        
        
        
        /**
         * Edite les informations du terrain en fonction de la configuration des champs.
         */
        void sauvegarde();
};

#endif // LOYERTERRAINEDITWIDGET_HPP
