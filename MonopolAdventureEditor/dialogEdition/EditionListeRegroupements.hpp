#ifndef EDITIONLISTEREGROUPEMENTS_HPP
#define EDITIONLISTEREGROUPEMENTS_HPP

#include <QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>

#include "dialogEdition/modeles/RegroupementListModel.hpp"
#include "dialogEdition/modeles/SelectionRegroupementListModel.hpp"
#include "dialogEdition/widgetsEditeurs/ListeRegroupementEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/RegroupementEditWidget.hpp"





/**
 * @class EditionListeRegroupements EditionListeRegroupements.hpp dialogEdition/EditionListeRegroupements.hpp
 * Cette classe contrôle l'édition de la liste des regroupements.
 */
class EditionListeRegroupements : private QDialog
{
        Q_OBJECT
        
        
    private:
        QList<Regroupement*>& m_listeOriginale;///< Référence vers la liste originale des regroupements.
        QList<RegroupementData*> m_listeEditable;///< Liste de structures de données contenant les informations éditable des regroupements.
        RegroupementListModel* m_modeleRegroupementsEditables;///< Modèle de données contenant une liste affichable des regroupements éditables.
        ListeRegroupementEditWidget* m_widgetEditionListeRegroupements;///< Widget d'édition de la liste de regroupements.
        
        
        
    public:
        /**
         * Construit un controleur d'édition de liste de regroupements.
         * @param regroupements Liste originale des regroupements à éditer.
         */
        EditionListeRegroupements(QList<Regroupement*>& regroupements,
                                  QWidget* parent);
        
        
        
        /**
         * Destructeur.
         */
        ~EditionListeRegroupements();
        
        
        
        /**
         * Lance la fenêtre d'édition des regroupements.
         */
        bool executer();
};

#endif // EDITIONLISTEREGROUPEMENTS_HPP
