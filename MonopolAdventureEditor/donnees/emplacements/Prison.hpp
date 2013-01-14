#ifndef PRISONINFOS_HPP
#define PRISONINFOS_HPP

#include "donnees/emplacements/SimpleVisite.hpp"
class Plateau;





/**
 * @class Prison Prison.hpp donnees/emplacements/Prison.hpp
 * Prison contient les informations éditables d'une prison d'un plateau.
 */
class Prison : public Emplacement
{
    private:
        SimpleVisite* m_emplacementAssocie;///< Emplacement « Simple visite » associé à la prison.
        quint16 m_caution;///< Montant de la caution pour sortir de prison.
        
        
        
    public:
        /**
         * Construit une prison par défaut.
         * @param graphismeInfos Informations concernant le graphisme.
         * @param emplacementAssocie Emplacement « Simple visite » associé à la prison.
         */
        Prison(const GraphismeEmplacementInfos& graphismeInfos,
               SimpleVisite* const emplacementAssocie);
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~Prison();
        
        
        
        /**
         * Renseigne l'emplacement « Simple visite » associé à la prison.
         * @return Emplacement « Simple visite » associé à la prison.
         */
        SimpleVisite* getEmplacementAssocie() const;
        
        
        
        /**
         * Remplace l'emplacement « Simple visite » associé à la prison par @a emplacement
         * @param emplacement Nouvel emplacement.
         */
        void editEmplacementAssocie(SimpleVisite* emplacement);
        
        
        
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
        
        
        
        /**
         * Sauvegarde les informations concernant la prison via le flux de données.
         * @param ecriture Flux de données vers le fichier à écrire.
         * @param plateau Plateau auquel appartient l'emplacement.
         */
        void saveInFile(QDataStream& ecriture,
                        const Plateau* plateau) const;
};

#endif // PRISONINFOS_HPP
