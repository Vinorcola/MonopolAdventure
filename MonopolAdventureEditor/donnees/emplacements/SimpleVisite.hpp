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
        
        
        
        /**
         * Sauvegarde les informations concernant l'emplacement « Simple visite » via le flux de données.
         * @param ecriture Flux de données vers le fichier à écrire.
         * @param version Numéro de la version à utiliser pour écrire les données.
         */
        void saveInFile(QDataStream& ecriture,
                        const quint16 version) const;
};

#endif // SIMPLEVISITEINFOS_HPP
