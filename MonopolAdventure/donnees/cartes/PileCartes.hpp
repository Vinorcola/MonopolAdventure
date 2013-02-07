#ifndef PILECARTESINFOS_HPP
#define PILECARTESINFOS_HPP

#include <QAbstractListModel>
#include <QPixmap>

class Carte;
class Emplacement;
class Plateau;





/**
 * @class PileCartes PileCartes.hpp donnees/cartes/PileCartes.hpp
 * PileCartes est une pile de cartes du plateau contenant un certain nombre de cartes.
 * 
 * Une pile de cartes est avant tout une liste de cartes. Les plus communes sont les piles Chance et Caisse de communauté. Les piles de cartes se mélangent automatiquement après leur chargement depuis un fichier.
 * @todo Mélanger la pile après le chargement depuis un fichier.
 * @todo Penser à gérer la carte Libérer de prison (la sortie de la pile quant un joueur l'a).
 */
class PileCartes
{
    private:
        QString m_titre;///< Titre de la pile de cartes.
        QPixmap m_image;///< Image du verso des cartes de la pile.
        QList<Carte*> m_cartes;///< Liste des cartes contenues dans la pile de cartes.
        
        
        
    public:
    /* Constructeurs et destructeur. */
        /**
         * Construit une pile de cartes vide par défaut.
         */
        PileCartes();
        
        
        
        /**
         * Supprime toutes les cartes que la pile de cartes contient.
         */
        ~PileCartes();
        
        
        
    /* Méthodes d'accès aux informations.*/
        /**
         * Renseigne le titre de la pile de cartes.
         * @return Titre de la pile de cartes.
         */
        const QString& getTitre() const;
        
        
        
        /**
         * Renseigne l'image du verso des cartes de la pile.
         * @return Image du verso des cartes de la pile.
         */
        const QPixmap& getImage() const;
        
        
        
        /**
         * Renseigne le nombre de cartes contenus dans la pile de cartes.
         * @return Nombre de cartes contenus dans la pile de cartes.
         */
        int getNombreCartes() const;
        
        
        
    /* Méthodes de sauvegarde et de chargement. */
        /**
         * Charge les informations concernant la pile de cartes depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         * @param plateau Plateau de jeu.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version,
                          const Plateau* plateau);
};

#endif // PILECARTESINFOS_HPP
