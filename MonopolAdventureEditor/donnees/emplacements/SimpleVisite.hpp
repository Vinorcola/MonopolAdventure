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
         * Construit une copie de l'emplacement @a simpleVisite.
         * @param simpleVisite Emplacement « Simple visite » à copier.
         */
        SimpleVisite(const SimpleVisite& simpleVisite);
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~SimpleVisite();
        
        
        
        /**
         * Copie les informations de l'emplacement @a simpleVisite.
         * @param simpleVisite Emplacement « Simple visite » à copier.
         */
        SimpleVisite& operator =(const SimpleVisite& simpleVisite);
};

#endif // SIMPLEVISITEINFOS_HPP
