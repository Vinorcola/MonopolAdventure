#ifndef CARTEINFOS_HPP
#define CARTEINFOS_HPP

#include <QPixmap>
#include <QString>

#include "donnees/cartes/Action.hpp"
class PileCartes;
#include "donnees/cartes/PileCartes.hpp"





/**
 * Enumération permettant de mémoriser la disposition de l'image de la carte.
 */
enum CarteImageDisposition
{
    GAUCHE, DROITE, HAUT, BAS
};





/**
 * @class Carte Carte.hpp donnees/cartes/Carte.hpp
 * Carte contient les informations éditables d'une carte.
 */
class Carte
{
    private:
        PileCartes* m_pileCartes;///< Pile de cartes à laquelle appartient la carte.
        QString m_consigne;///< Consigne à afficher au joueur.
        QPixmap m_image;///< Image à afficher sur la carte.
        CarteImageDisposition m_dispositionImage;///< Disposition de l'image par rapport à la consigne.
        Action m_action;///< Action associée à la carte.
        
        
        
    public:
        /**
         * Construit une carte par défaut.
         */
        Carte();
        
        
        
        /**
         * Construit une carte identique, mais rattachée à aucune pile de cartes.
         * @param autre Carte à copier.
         */
        Carte(const Carte* autre);
        
        
        
        /**
         * Destructeur.
         * Enlève la carte de la pile de carte associée avant la suppression.
         */
        ~Carte();
        
        
        
        /**
         * Retourne l'action associée à la carte.
         */
        Action& getAction();
        
        
        
        /**
         * Renseigne la pile de cartes à laquelle appartient la carte.
         * @return Pile de cartes à laquelle appartient la carte.
         */
        PileCartes* getPileCartes() const;
        
        
        
        /**
         * Remplace la pile de cartes à laquelle appartient la carte.
         * @param pileCartes Nouvelle pile de cartes.
         */
        void editPileCartes(PileCartes* const pileCartes);
        
        
        
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
        CarteImageDisposition getDispositionImage() const;
        
        
        
        /**
         * Modifie la disposition de l'image sur la carte.
         * @param disposition Nouvelle disposition.
         */
        void editDispositionImage(const CarteImageDisposition disposition);
};

#endif // CARTEINFOS_HPP
