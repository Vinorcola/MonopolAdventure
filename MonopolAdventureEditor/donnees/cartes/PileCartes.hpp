#ifndef PILECARTESINFOS_HPP
#define PILECARTESINFOS_HPP

#include <QList>
#include <QString>

class Carte;
#include "donnees/cartes/Carte.hpp"





/**
 * @class PileCartes PileCartes.hpp donnees/cartes/PileCartes.hpp
 * PileCartes contient les informations éditables d'une pile de cartes.
 */
class PileCartes : private QList<Carte*>
{
        friend class Carte;
        
        
    private:
        QString m_titre;///< Titre de la pile de cartes.
        
        
        
    public:
        /**
         * Construit une pile de cartes par défaut.
         */
        PileCartes();
        
        
        
        /**
         * Supprime toutes les cartes que la pile de cartes contient.
         */
        ~PileCartes();
        
        
        
        /**
         * Renseigne le titre de la pile de cartes.
         * @return Titre de la pile de cartes.
         */
        const QString& getTitre() const;
        
        
        
        /**
         * Remplace le titre de la pile de cartes par @a titre.
         * @param titre Nouveau titre.
         */
        void editTitre(const QString& titre);
        
        
        
        /**
         * Renseigne le nombre de cartes contenus dans la pile de cartes.
         * @return Nombre de cartes contenus dans la pile de cartes.
         */
        int getNombreCartes() const;
        
        
        
        /**
         * Retourne la carte situé à l'index @a index.
         * @return Carte situé à l'index @a index.
         */
        Carte* getCarte(int index) const;
        
        
        
        /**
         * Retourne la liste des cartes contenus.
         * @return Liste des cartes contenus.
         */
        QList<Carte*> getListeCartes() const;
        
        
        
        /**
         * Supprime toutes les cartes que contient la pile de cartes.
         */
        void vider();
};

#endif // PILECARTESINFOS_HPP
