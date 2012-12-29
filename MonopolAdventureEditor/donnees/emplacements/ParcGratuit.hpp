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
         * Destructeur virtuel.
         */
        virtual ~ParcGratuit();
        
        
        
        /**
         * Sauvegarde les informations concernant le parc gratuit via le flux de données.
         * @param ecriture Flux de données vers le fichier à écrire.
         * @param version Numéro de la version à utiliser pour écrire les données.
         */
        void saveInFile(QDataStream& ecriture,
                        const quint16 version) const;
};

#endif // PARCGRATUITINFOS_HPP
