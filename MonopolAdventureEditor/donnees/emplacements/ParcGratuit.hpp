#ifndef PARCGRATUITINFOS_HPP
#define PARCGRATUITINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class ParcGratuit ParcGratuit.hpp donnees/emplacements/ParcGratuit.hpp
 * ParcGratuit contient les informations éditables d'un parc gratuit d'un plateau.
 */
class ParcGratuit : public Emplacement
{
    public:
        /**
         * Construit un parc gratuit par défaut.
         * @param graphismeInfos Informations concernant le graphisme.
         */
        ParcGratuit(const GraphismeEmplacementInfos& graphismeInfos);
        
        
        
        /**
         * Construit une copie du parc gratuit @a parcGratuit.
         * @param parcGratuit Parc gratuit à copier.
         */
        ParcGratuit(const ParcGratuit& parcGratuit);
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~ParcGratuit();
        
        
        
        /**
         * Copie les informations du parc gratuit @a parcGratuit.
         * @param parcGratuit Parc gratuit à copier.
         */
        ParcGratuit& operator =(const ParcGratuit& parcGratuit);
};

#endif // PARCGRATUITINFOS_HPP
