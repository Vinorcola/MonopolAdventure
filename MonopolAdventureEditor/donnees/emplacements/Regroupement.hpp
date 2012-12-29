#ifndef REGROUPEMENTINFOS_HPP
#define REGROUPEMENTINFOS_HPP

#include <QColor>
#include <QList>
#include <QString>

class Terrain;
#include "donnees/emplacements/Terrain.hpp"
class Plateau;





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
         * Destructeur.
         * Enlève tous les terrains contenus avant la suppression.
         */
        ~Regroupement();
        
        
        
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
        
        
        
        /**
         * Sauvegarde les informations concernant le regroupement via le flux de données.
         * @param ecriture Flux de données vers le fichier à écrire.
         * @param version Numéro de la version à utiliser pour écrire les données.
         * @param plateau Plateau auquel appartient le regroupement.
         */
        void saveInFile(QDataStream& ecriture,
                        const quint16 version,
                        const Plateau* plateau) const;
};

#endif // REGROUPEMENTINFOS_HPP
