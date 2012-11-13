#ifndef PROPRIETEEDITWIDGET_HPP
#define PROPRIETEEDITWIDGET_HPP

#include <QCheckBox>
#include <QFormLayout>
#include <QLabel>
#include <QSpinBox>

#include "donnees/emplacements/Propriete.hpp"





/**
 * @class ProprieteEditWidget ProprieteEditWidget.hpp dialogEdition/widgetsEditeurs/ProprieteEditWidget.hpp
 * Cette classe fournit une interface d'édition des informations caractéristiques d'achat et d'hypothèque d'une propriété.
 */
class ProprieteEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        Propriete* m_propriete;///< Propriété en cours d'édition.
        QSpinBox* m_champPrixAchat;///< Champ d'édition du prix d'achat.
        QCheckBox* m_hypothequeMoitiePrix;///< Champ qui indique que la valeur de l'hypothèque est égale à la moitié du prix d'achat.
        QLabel* m_labelValeurHypotheque;///< Étiquette associé à m_champValeurHypotheque.
        QSpinBox* m_champValeurHypotheque;///< Champ d'édition de la valeur d'hypothèque.
        
                
    public:
        /**
         * Construit un nouveau widget d'édition de propriété.
         * @param propriete Propriété à éditer.
         */
        ProprieteEditWidget(Propriete* const propriete);
        
        
        
        /**
         * Edite les informations de la propriété en fonction de la configuration des champs.
         */
        void sauvegarde();
        
        
        
    public slots:
        /**
         * Met à jour le prix de l'hypotheque si l'option « hypothèque = moitie prix » est cochée.
         * @param prix Nouveau prix d'achat.
         */
        void champPrixAchatChanged(int prix);
        
        
        
        /**
         * Active ou désactive les champs de configuration de l'hypothèque en fonction de si m_hypothequeMoitiePrix est cochée ou non.
         * @param state Statut du champ m_hypothequeMoitiePrix.
         */
        void hypothequeMoitiePrixChanged(int state);
};

#endif // PROPRIETEEDITWIDGET_HPP
