#ifndef CONSTRUCTIONEDITWIDGET_HPP
#define CONSTRUCTIONEDITWIDGET_HPP

#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QSpinBox>

#include "donnees/emplacements/Terrain.hpp"





/**
 * @class ConstructionEditWidget ConstructionEditWidget.hpp dialogEdition/widgetsEditeurs/ConstructionEditWidget.hpp
 * Cette classe fournit une interface d'édition des informations de construction d'un terrain.
 */
class ConstructionEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        Terrain* m_terrain;///< Terrain en cours d'édition.
        QSpinBox* m_champPrixAchatMaison;///< Champ d'édition du prix d'achat d'une maison.
        QCheckBox* m_venteMaisonMoitie;///< Helper permettant l'aide à la décision du prix de vente d'une maison.
        QLabel* m_labelPrixVenteMaison;///< Étiquette associée à m_venteMaisonMoitie.
        QSpinBox* m_champPrixVenteMaison;///< Champ d'édition du prix de vente d'une maison.
        QSpinBox* m_champPrixAchatHotel;///< Champ d'édition du prix d'achat d'un hôtel.
        QCheckBox* m_venteHotelMoitie;///< Helper permettant l'aide à la décision du prix de vente d'un hôtel.
        QLabel* m_labelPrixVenteHotel;///< Étiquette associée à m_venteHotelMoitie.
        QSpinBox* m_champPrixVenteHotel;///< Champ d'édition du prix de vente d'un hôtel.
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition de terrain.
         * @param terrain Terrain à éditer.
         */
        ConstructionEditWidget(Terrain* const terrain);
        
        
        
        /**
         * Edite les informations du terrain en fonction de la configuration des champs.
         */
        void sauvegarde();
        
        
        
    private slots:
        /**
         * Met à jour le prix de vente d'une maison si l'option « prix vente = moitie prix achat » est cochée.
         * @param prix Nouveau prix d'achat.
         */
        void champPrixAchatMaisonChanged(int prix);
        
        
        
        /**
         * Active ou désactive les champs de configuration de la vente de maisons en fonction de si m_venteMaisonMoitie est cochée ou non.
         * @param state Statut du champ m_venteMaisonMoitie.
         */
        void venteMaisonMoitieChanged(int state);
        
        
        
        /**
         * Met à jour le prix de vente d'un hôtel si l'option « prix vente = moitie prix achat » est cochée.
         * @param prix Nouveau prix d'achat.
         */
        void champPrixAchatHotelChanged(int prix);
        
        
        
        /**
         * Active ou désactive les champs de configuration de la vente d'hôtels en fonction de si m_venteHotelMoitie est cochée ou non.
         * @param state Statut du champ m_venteHotelMoitie.
         */
        void venteHotelMoitieChanged(int state);
};

#endif // CONSTRUCTIONEDITWIDGET_HPP
