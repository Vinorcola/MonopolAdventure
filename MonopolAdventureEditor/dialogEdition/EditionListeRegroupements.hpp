#ifndef EDITIONLISTEREGROUPEMENTS_HPP
#define EDITIONLISTEREGROUPEMENTS_HPP

#include "dialogEdition/modeles/RegroupementListModel.hpp"
#include "dialogEdition/modeles/SelectionRegroupementListModel.hpp"
#include "dialogEdition/StructuresEditionListeRegroupements.hpp"
#include "donnees/emplacements/Regroupement.hpp"





/**
 * @class EditionListeRegroupements EditionListeRegroupements.hpp dialogEdition/EditionListeRegroupements.hpp
 * Cette classe contrôle l'édition de la liste des regroupements.
 */
class EditionListeRegroupements
{
    private:
        QList<Regroupement*>& m_listeOriginale;///< Référence vers la liste originale des regroupements.
        QList<RegroupementData*> m_listeEditable;///< Liste de structures de données contenant les informations éditable des regroupements.
        RegroupementListModel* m_modeleRegroupementsEditables;///< Modèle de données contenant une liste affichable des regroupements éditables.
        SelectionRegroupementListModel* m_modeleRegroupementsSelectionnables;///< Modèle de données contenant une liste affichable des regroupements sélectionnable pour la configuration des terrains.
        
        
        
    public:
        /**
         * Construit un controleur d'édition de liste de regroupements.
         * @param regroupements Liste originale des regroupements à éditer.
         */
        EditionListeRegroupements(QList<Regroupement*>& regroupements);
};

#endif // EDITIONLISTEREGROUPEMENTS_HPP
