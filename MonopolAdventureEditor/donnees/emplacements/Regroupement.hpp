#ifndef REGROUPEMENTINFOS_HPP
#define REGROUPEMENTINFOS_HPP

#include <QColor>
#include <QList>
#include <QString>

class Terrain;
#include "donnees/emplacements/Terrain.hpp"





/**
 * @class Regroupement Regroupement.hpp donnees/emplacements/Regroupement.hpp
 * Regroupement contient les informations éditables d'un regroupement de terrains.
 */
class Regroupement : private QList<Terrain*>
{
        friend class Terrain;
        
        
    private:
        QString m_titre;///< Titre du regroupement.
        QColor m_couleur;///< Couleur du regroupement.
        
        
        
    public:
        /**
         * Construit un regroupement par défaut.
         */
        Regroupement();
        
        
        
        /**
         * Construit une copie du regroupement @a regroupement pour l'édition.
         * @param regroupement Regroupement à copier.
         * 
         * La copie du regroupement ne pourra servir que pour l'édition temporaire. En effet, la liste des terrains est copiée (pas les terrains à l'intérieur). Aussi les terrains pointent toujours vers le regroupement à copier (@a regroupement). Par la suite, lorsque l'édition est validée par l'utilisateur, on utilise l'operateur d'affectation pour sauvegarder le regroupement initial (@a regroupement) à partir de l'instance copiée ici.
         */
        Regroupement(const Regroupement& regroupement);
        
        
        
        /**
         * Destructeur.
         * Enlève tous les terraisn contenus avant la suppression.
         */
        ~Regroupement();
        
        
        
        /**
         * Sauvegarde les informations édités par l'utilisateur dans la copie @a copieRegroupement.
         * @param copieRegroupement Copie du regroupement effectuée avant l'édition des informations par l'utilisateur.
         */
        Regroupement& operator =(const Regroupement& copieRegroupement);
        
        
        
        
        /**
         * Renseigne le titre du regroupement.
         * @return Titre du regroupement.
         */
        const QString& getTitre() const;
        
        
        
        /**
         * Remplace le titre du regroupement par @a titre.
         * @param titre Nouveau titre.
         */
        void editTitre(const QString& titre);
        
        
        
        /**
         * Renseigne la couleur du regroupement.
         * @return Couleur du regroupement.
         */
        const QColor& getCouleur() const;
        
        
        
        /**
         * Remplace la couleur du regroupement par @a couleur.
         * @param couleur Nouvelle couleur.
         */
        void editCouleur(const QColor& couleur);
        
        
        
        /**
         * Renseigne le nombre de terrains contenus dans le regroupement.
         * @return Nombre de terrains contenus dans le regroupement.
         */
        int getNombreTerrains() const;
        
        
        
        /**
         * Retourne le terrain situé à l'index @a index.
         * @return Terrain situé à l'index @a index.
         */
        Terrain* getTerrain(int index) const;
        
        
        
        /**
         * Retourne la liste des terrains contenus.
         * @return Liste des terrains contenus.
         */
        QList<Terrain*> getListeTerrains() const;
};

#endif // REGROUPEMENTINFOS_HPP
