#ifndef SIMPLEVISITEINFOS_HPP
#define SIMPLEVISITEINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class SimpleVisite SimpleVisite.hpp donnees/emplacements/SimpleVisite.hpp
 * SimpleVisite contient les informations éditables d'un emplacement « Simple visite » d'un plateau.
 */
class SimpleVisite : public Emplacement
{
    public:
        /**
         * Construit un emplacement « Simple visite » par défaut.
         * @param graphismeInfos Informations concernant le graphisme.
         */
        SimpleVisite(const GraphismeEmplacementInfos& graphismeInfos);
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~SimpleVisite();
};

#endif // SIMPLEVISITEINFOS_HPP
