#ifndef PRISONINFOS_HPP
#define PRISONINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class Prison Prison.hpp donnees/emplacements/Prison.hpp
 * Prison contient les informations éditables d'une prison d'un plateau.
 */
class Prison : public Emplacement
{
    private:
        quint16 m_caution;///< Montant de la caution pour sortir de prison.
        
        
        
    public:
        /**
         * Construit une prison par défaut.
         */
        Prison();
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~Prison();
        
        
        
        /**
         * Renseigne le montant de la caution pour sortir de prison.
         * @return Montant de la caution pour sortir de prison.
         */
        quint16 getCaution() const;
        
        
        
        /**
         * Remplace le montant de la caution par @a montant.
         * @param montant Montant de la nouvelle caution.
         */
        void editCaution(const quint16 montant);
};

#endif // PRISONINFOS_HPP
