#ifndef PRISONINFOS_HPP
#define PRISONINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class Prison Prison.hpp donnees/emplacements/Prison.hpp
 * Prison contient les informations éditables d'une prison d'un plateau.
 */
class Prison : public Emplacement
{
    public:
        /**
         * Construit une prison par défaut.
         */
        Prison();
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~Prison();
};

#endif // PRISONINFOS_HPP
