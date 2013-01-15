#ifndef PIOCHEINFOS_HPP
#define PIOCHEINFOS_HPP

#include "donnees/cartes/PileCartes.hpp"
#include "donnees/emplacements/Emplacement.hpp"
class Plateau;





/**
 * @class Pioche Pioche.hpp donnees/emplacements/Pioche.hpp
 * Pioche contient les informations éditables d'un emplacement « Pioche » d'un plateau.
 */
class Pioche : public Emplacement
{
    private:
        const PileCartes* m_pileCartes;///< Pile de cartes associée à l'emplacement.
        
        
        
    public:
        /**
         * Construit un emplacement « Pioche » par défaut.
         * @param graphismeInfos Informations concernant le graphisme.
         */
        Pioche(const GraphismeEmplacementInfos& graphismeInfos);
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~Pioche();
        
        
        
        /**
         * Renseigne la pile de cartes associée à l'emplacement.
         * @return Pile de cartes associée à l'emplacement.
         */
        const PileCartes* getPileCartes() const;
        
        
        
        /**
         * Remplace la pile de cartes associée à l'emplacement par @a pileCartes.
         * @param pileCartes Nouvelle pile de cartes associée à l'emplacement.
         */
        void editPileCartes(const PileCartes* pileCartes);
        
        
        
        /**
         * Sauvegarde les informations concernant l'emplacement « Pioche » via le flux de données.
         * @param ecriture Flux de données vers le fichier à écrire.
         * @param plateau Plateau auquel appartient l'emplacement.
         */
        void saveInFile(QDataStream& ecriture,
                        const Plateau* plateau) const;
        
        
        
        /**
         * Charge les informations concernant l'emplacement « Pioche » depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         * @param plateau Plateau de jeu.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version,
                          const Plateau* plateau);
};

#endif // PIOCHEINFOS_HPP
