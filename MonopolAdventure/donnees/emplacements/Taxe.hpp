#ifndef TAXEINFOS_HPP
#define TAXEINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class Taxe Taxe.hpp donnees/emplacements/Taxe.hpp
 * Cette classe représente un emplacement « Taxe », où les joueurs vont devoir verser des taxes à la banque.
 * 
 * Le montant de la taxe peut être un montant fixe, ou bien un pourcentage de la fortune du joueur (la fortune représente toutes les liquidités, les valeurs d'achat des terrains et des constructions possédés par le joueur). Ils est posible de configurer un montant fixe et un pourcentage de la fortune en même temps. Le joueur pourra alors choisir son mode d'imposition.
 */
class Taxe : public Emplacement
{
    private:
        bool m_payeMontantFixe;///< Indique si le joueur peut verser un montant fixe.
        quint16 m_montantFixe;///< Montant fixe à verser.
        bool m_payePourcentageFortune;///< Indique si le joueur peut verser un montant correspondant à un pourcentage de sa fortune.
        quint8 m_pourcentageFortune;///< Pourcentage de la fortune à verser.
        
        
        
    protected:
        const QString& m_devise;///< Référence constante vers la devise du plateau.
        
        
        
    public:
        /**
         * Construit un emplacement « Taxe » par défaut.
         * @param graphismeInfos Informations concernant le graphisme.
         * @param devise Référence vers la devise servant à l'affichage du prix sur le plateau.
         */
        Taxe(const GraphismeEmplacementInfos& graphismeInfos,
             const QString& devise);
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~Taxe();
        
        
        
        /**
         * Indique si la taxe est un montant fixe.
         * return @b @c true si la taxe est un montant fixe.
         */
        bool isMontantFixe() const;
        
        
        
        /**
         * Renseigne le montant fixe de la taxe.
         * @return Montant fixe de la taxe.
         */
        quint16 getMontantFixe() const;
        
        
        
        /**
         * Indique si la taxe est un pourcentage de la fortune.
         * @return @b @c true si la taxe est un pourcentage de la fortune.
         */
        bool isPourcentageFortune() const;
        
        
        
        /**
         * Renseigne le pourcentage de la fortune à verser.
         * @return Pourcentage de la fortune à verser.
         */
        quint16 getPourcentageFortune() const;
        
        
        
        /**
         * Charge les informations concernant l'emplacement « Taxe » depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version);
        
        
        
    protected:
        virtual QString helper_getPrix() const;
};

#endif // TAXEINFOS_HPP
