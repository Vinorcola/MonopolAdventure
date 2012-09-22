#ifndef TAXEINFOS_HPP
#define TAXEINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class Taxe Taxe.hpp donnees/emplacements/Taxe.hpp
 * Taxe contient les informations éditables d'un emplacement « Taxe » d'un plateau.
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
         * Autorise le joueur à verser un montant fixe.
         * @param montant Montant fixe de la taxe à verser.
         */
        void enableMontantFixe(const quint16 montant);
        
        
        
        /**
         * Supprime l'autorisation pour le joueur de verser un montant fixe.
         */
        void disableMontantFixe();
        
        
        
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
         * Autorise le joueur à verser un pourcentage de sa fortune.
         * @param pourcentage Pourcentage de la fortune à verser.
         */
        void enablePourcentageFortune(const quint8 pourcentage);
        
        
        
        /**
         * Supprime l'autorisation pour le joueur de verser un pourcentage de sa fortune.
         */
        void disablePourcentageFortune();
        
        
        
    protected:
        virtual QString helper_getPrix() const;
};

#endif // TAXEINFOS_HPP
