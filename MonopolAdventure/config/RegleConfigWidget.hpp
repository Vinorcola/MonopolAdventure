#ifndef REGLECONFIGWIDGET_HPP
#define REGLECONFIGWIDGET_HPP

#include <QCheckBox>
#include <QSpinBox>

#include "donnees/Regle.hpp"




/**
 * @class RegleConfigWidget RegleConfigWidget.hpp config/RegleConfigWidget.hpp
 * Cette classe représente un widget permettant de configurer les règles de jeu lors du lancement d'une partie.
 */
class RegleConfigWidget : public QWidget
{
    private:
        QSpinBox* m_nombreTotalMaison;
        QSpinBox* m_nombreTotalHotel;
        QCheckBox* m_constructionsUniformes;
        
        QCheckBox* m_doubleSalaire;
        QCheckBox* m_enchereDepart;
        QCheckBox* m_premierTourSansAchat;
        
        QCheckBox* m_taxeAuParcGratuit;
        QCheckBox* m_amendeCarteAuParcGratuit;
        QCheckBox* m_cagnotteFixe;
        QSpinBox* m_montantCagnotte;
        
        QSpinBox* m_maxTourEnPrison;
        
        
        
    public:
        /**
         * Construit un widget de configuration de règles.
         * @param defaut Règle utilisée par défaut.
         */
        RegleConfigWidget(const Regle* defaut);
};

#endif // REGLECONFIGWIDGET_HPP
