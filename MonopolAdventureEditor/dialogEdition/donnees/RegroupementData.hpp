#ifndef REGROUPEMENTDATA_HPP
#define REGROUPEMENTDATA_HPP

#include "dialogEdition/modeles/TerrainListModel.hpp"





/**
 * @class RegroupementData RegroupementData.hpp dialogEdition/donnees/RegroupementData.hpp
 * Structure de données contenant les informations d'un regroupement à éditer.
 */
class RegroupementData
{
    public:
        QString m_titre;///< Titre du regroupement.
        QColor m_couleur;///< Couleur du regroupement.
        QList<TerrainData*> m_terrains;///< Liste des terrains (avec leur index général et leur nom).
        TerrainListModel* m_modeleTerrains;///< Modèle de données permettant d'afficher la liste des terrains.
        
        
        
    public:
        /**
         * Initialise tous les attributs par défaut.
         */
        RegroupementData();
        
        
        
        /**
         * Construit une structure de données à partir d'un regroupement.
         * @param regroupement Regroupement fournissant les informations.
         */
        RegroupementData(Regroupement* regroupement);
        
        
        
        /**
         * Détruit le modèle de donnnées des terains.
         */
        ~RegroupementData();
        
        
        
        /**
         * Retourne le titre du regroupement.
         * @return Titre du regroupement.
         */
        const QString& getTitre() const;
        
        
        
        /**
         * Configure le titre du regroupement.
         * @param titre Nouveau titre.
         */
        void editTitre(const QString& titre);
        
        
        
        /**
         * Retourne la couleur du regroupement.
         * @return Couleur du regroupement.
         */
        const QColor& getCouleur() const;
        
        
        
        /**
         * Configure la couleur du regroupement.
         * @param couleur Nouvelle couleur.
         */
        void editCouleur(const QColor& couleur);
        
        
        
        /**
         * Retourne le modèle de données contenant la liste des terrains.
         * @return Modèle de données contenant la liste des terrains.
         */
        TerrainListModel* getModeleTerrains() const;
        
        
        
        /**
         * Transfère un terrain vers un autre regroupement.
         * @param regroupement Regroupement récupérant le terrain.
         * @param rowTerrain Rang désignant le terrains à transférer.
         */
        void transfereTerrainA(RegroupementData* regroupement,
                               int rowTerrain);
};

#endif // REGROUPEMENTDATA_HPP
