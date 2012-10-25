#ifndef DEPARTINFOS_HPP
#define DEPARTINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class Depart Depart.hpp donnees/emplacements/Depart.hpp
 * Depart contient les informations éditables d'un emplacement « Départ » d'un plateau.
 */
class Depart : public Emplacement
{
    private:
        quint16 m_salaire;///< Salaire reçu au passage.
        
        
        
    public:
        /**
         * Construit un emplacement « Départ » par défaut.
         * @param graphismeInfos Informations concernant le graphisme.
         */
        Depart(const GraphismeEmplacementInfos& graphismeInfos);
        
        
        
        /**
         * Construit une copie de l'emplacement @a depart.
         * @param depart Emplacement « Départ » à copier.
         */
        Depart(const Depart& depart);
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~Depart();
        
        
        
        /**
         * Copie les informations de l'emplacement @a depart.
         * @param depart Emplacement « Départ » à copier.
         */
        Depart& operator =(const Depart& depart);
        
        
        
        /**
         * Renseigne le montant du salaire perçu au passage.
         * @return Montant du salaire perçu au passage.
         */
        quint16 getSalaire() const;
        
        
        
        /**
         * Remplace le montant du salaire par @a montant.
         * @param montant Montant du nouveau salaire.
         */
        void editSalaire(const quint16 montant);
};

#endif // DEPARTINFOS_HPP
