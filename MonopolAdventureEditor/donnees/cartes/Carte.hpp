#ifndef CARTEINFOS_HPP
#define CARTEINFOS_HPP

#include <QPixmap>
#include <QString>

#include "donnees/cartes/Action.hpp"
class PileCartes;





/**
 * @class Carte Carte.hpp donnees/cartes/Carte.hpp
 * Carte est une carte que les joueurs peuvent piocher durant une partie.
 * 
 * Une carte possède une consigne, une action à effetuer et éventuellement, une image. Les cartes sont gérées directement par les piles de cartes. Il n'est donc pas possible de créer une carte seule.
 */
class Carte
{
        friend class PileCartes;
        
        
    public:
        /**
         * Cette énumération permet de déterminer la position de l'image par rapport à la consigne à l'affichage de la carte.
         */
        enum ImageDisposition
        {
            GAUCHE, DROITE, HAUT, BAS
        };
        
        
        
    private:
        const PileCartes* m_pileCartes;///< Pile de cartes à laquelle appartient la carte.
        QString m_consigne;///< Consigne à afficher au joueur.
        QPixmap m_image;///< Image à afficher sur la carte.
        ImageDisposition m_dispositionImage;///< Disposition de l'image par rapport à la consigne.
        Action m_action;///< Action associée à la carte.
        
        
        
    private:
    /* Constructeurs et destructeurs. */
        /**
         * Construit une carte par défaut.
         * @param pileCartes Pile de cartes dans laquelle est rangée la carte.
         */
        Carte(const PileCartes* pileCartes);
        
        
        
        /**
         * Construit une carte identique rattachée à une autre pile de cartes.
         * @param autre Carte à copier.
         * @param pileCartes Pile de cartes dans laquelle est rangée la carte.
         */
        Carte(const Carte* autre,
              const PileCartes* pileCartes);
        
        
        
    public:
    /* Méthodes d'accès aux informations. */
        /**
         * Retourne l'action associée à la carte.
         */
        Action& getAction();
        
        
        
        /**
         * Renseigne la pile de cartes à laquelle appartient la carte.
         * @return Pile de cartes à laquelle appartient la carte.
         */
        const PileCartes* getPileCartes() const;
        
        
        
        /**
         * Renseigne la consigne de la carte.
         * @return Consigne de la carte.
         */
        const QString& getConsigne() const;
        
        
        
        /**
         * Remplace la consigne de la carte par @a consigne.
         * @param consigne Nouvelle consigne.
         */
        void editConsigne(const QString& consigne);
        
        
        
        /**
         * Renseigne l'image de la carte.
         * @return Image de la carte.
         */
        const QPixmap& getImage() const;
        
        
        
        /**
         * Remplace l'image de la carte par @a image.
         * @param image Nouvelle image.
         */
        void editImage(const QPixmap& image);
        
        
        
        /**
         * Renseigne la disposition de l'image sur la carte.
         * @return Disposition de l'image sur la carte.
         */
        ImageDisposition getDispositionImage() const;
        
        
        
        /**
         * Modifie la disposition de l'image sur la carte.
         * @param disposition Nouvelle disposition.
         */
        void editDispositionImage(const ImageDisposition disposition);
        
        
        
        /**
         * Sauvegarde les informations concernant la carte via le flux de données.
         * @param ecriture Flux de données vers le fichier à écrire.
         * @param plateau Plateau de jeu.
         */
        void saveInFile(QDataStream& ecriture,
                        const Plateau* plateau) const;
        
        
        
        /**
         * Charge les informations concernant la carte depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         * @param plateau Plateau de jeu.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version,
                          const Plateau* plateau);
};

#endif // CARTEINFOS_HPP
