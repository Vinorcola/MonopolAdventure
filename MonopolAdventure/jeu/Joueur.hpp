#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <QString>
#include <QPixmap>

#include "donnees/emplacements/Propriete.hpp"





/**
 * @class Joueur Joueur.hpp jeu/Joueur.hpp
 * Cette classe représente un joueur.
 */
class Joueur
{
    private:
        QString m_pseudo;///< Pseudo du joueur.
        QPixmap m_image;///< Image associée au joueur.
        qint32 m_cagnotte;///< Cagnotte du joueur.
        quint8 m_nbTourEnPrisonRestant;///< Indique si le nombre de tour en prison restant au joueur.
        QList<Propriete*> m_proprietes;///< Liste des propriétés possédés par le joueur.
        
        
        
    public:
        /**
         * Créé un nouveau joueur.
         * @param pseudo Pseudo du joueur.
         * @param cagnotteDepart Cagnotte de départ du joueur.
         */
        Joueur(const QString& pseudo,
               const qint32 cagnotteDepart);
        
        
        
        /**
         * Renseigne le pseudo du joueur.
         * @return Pseudo du joueur.
         */
        const QString& getPseudo() const;
        
        
        
        /**
         * Indique la cagnotte du joueur.
         * @return La valeur de la cagnotte du joueur.
         */
        qint32 getCagnotte() const;
        
        
        
        /**
         * Indique le nombre de tour que joueur peut encore rester en prison.
         * @return Nombre de tour en prison restant au joueur.
         */
        bool getNbTourEnPrisonRestant() const;
};

#endif // JOUEUR_HPP
