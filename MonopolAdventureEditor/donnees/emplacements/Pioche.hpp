#ifndef PIOCHEINFOS_HPP
#define PIOCHEINFOS_HPP

#include "donnees/cartes/PileCartes.hpp"
#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class Pioche Pioche.hpp donnees/emplacements/Pioche.hpp
 * Pioche contient les informations éditables d'un emplacement « Pioche » d'un plateau.
 */
class Pioche : public Emplacement
{
    private:
        PileCartes* m_pileCartes;///< Pile de cartes associée à l'emplacement.
        
        
        
    public:
        /**
         * Construit un emplacement « Pioche » par défaut.
         */
        Pioche();
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~Pioche();
        
        
        
        /**
         * Renseigne la pile de cartes associée à l'emplacement.
         * @return Pile de cartes associée à l'emplacement.
         */
        PileCartes* getPileCartes() const;
        
        
        
        /**
         * Remplace la pile de cartes associée à l'emplacement par @a pileCartes.
         * @param pileCartes Nouvelle pile de cartes associée à l'emplacement.
         */
        void editPileCartes(PileCartes* const pileCartes);
};

#endif // PIOCHEINFOS_HPP
