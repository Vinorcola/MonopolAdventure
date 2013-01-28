#ifndef SIMPLEVISITEINFOS_HPP
#define SIMPLEVISITEINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class SimpleVisite SimpleVisite.hpp donnees/emplacements/SimpleVisite.hpp
 * Cette classe représente un emplacement « Simple visite ».
 * 
 * Les joueurs ne font rien de spécial sur ce type d'emplacement. Une prison peut être associé à un tel emplacement.
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
         */
        void saveInFile(QDataStream& ecriture) const;
        
        
        
        /**
         * Charge les informations concernant l'emplacement « Simple visite » depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version);
};

#endif // SIMPLEVISITEINFOS_HPP
