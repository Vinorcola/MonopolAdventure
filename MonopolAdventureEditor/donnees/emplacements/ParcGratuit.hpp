#ifndef PARCGRATUITINFOS_HPP
#define PARCGRATUITINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class ParcGratuit ParcGratuit.hpp donnees/emplacements/ParcGratuit.hpp
 * Cette classe représente un emplacement « Parc gratuit ».
 * 
 * Les joueurs peuvent se reposer ici : ils ne doivent rien payer et ne reçoivent rien.
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
         */
        void saveInFile(QDataStream& ecriture) const;
        
        
        
        /**
         * Charge les informations concernant le parc gratuit depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version);
};

#endif // PARCGRATUITINFOS_HPP
