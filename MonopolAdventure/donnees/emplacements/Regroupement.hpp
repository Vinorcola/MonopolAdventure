#ifndef REGROUPEMENTINFOS_HPP
#define REGROUPEMENTINFOS_HPP

#include <QAbstractListModel>
#include <QColor>
#include <QList>
#include <QString>

class Terrain;
#include "donnees/emplacements/Terrain.hpp"
class Plateau;





/**
 * @class Regroupement Regroupement.hpp donnees/emplacements/Regroupement.hpp
 * Cette classe permet de rassembler plusieurs terrains dans un même groupe.
 * 
 * Les regroupements rassemblent plusieurs terrains dans un unique but : un joueur doit posséder tous les terrains d'un regroupement pour pouvoir construire sur ces terrains. Un regroupement est caractérisé par une couleur (qui est affichée sur les terrains). Les joueurs peuvent ainsi rapidement voir quels terrains font parti du même groupe.
 */
class Regroupement
{
    private:
        QString m_titre;///< Titre du regroupement.
        QColor m_couleur;///< Couleur du regroupement.
        QList<Terrain*> m_terrains;///< Liste des terrains regroupés dans ce regroupement.
        
        
        
    public:
    /* Constructeurs et destructeur. */
        /**
         * Construit un regroupement par défaut.
         */
        Regroupement();
        
        
        
    /* Méthodes d'accès aux informations. */
        /**
         * Renseigne le titre du regroupement.
         * @return Titre du regroupement.
         */
        const QString& getTitre() const;
        
        
        
        /**
         * Renseigne la couleur du regroupement.
         * @return Couleur du regroupement.
         */
        const QColor& getCouleur() const;
        
        
        
        /**
         * Renseigne le nombre de terrains contenus dans le regroupement.
         * @return Nombre de terrains contenus dans le regroupement.
         */
        int getNombreTerrains() const;
        
        
        
    /* Méthodes de sauvegarde et de chargement. */
        /**
         * Charge les informations concernant le regroupement depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         * @param plateau Plateau de jeu.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version,
                          const Plateau* plateau);
};

#endif // REGROUPEMENTINFOS_HPP
