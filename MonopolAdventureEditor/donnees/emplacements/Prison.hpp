#ifndef PRISONINFOS_HPP
#define PRISONINFOS_HPP

#include "donnees/emplacements/SimpleVisite.hpp"
class Plateau;





/**
 * @class Prison Prison.hpp donnees/emplacements/Prison.hpp
 * Cette classe représente la prison du plateau.
 * 
 * Il ne peut y avoir qu'une et une seule prison sur le plateau. Elle doit alors être associée à un emplacement « Simple visite ». Les joueurs peuvent être envoyé en prison pour diverses raisons :
 * @li Ils ont fait trois doubles consécutifs aux dés ;
 * @li Ils sont tombés sur un emplacement les envoyant en prison ;
 * @li Ils ont pioché une carte les envoyant en prison.
 * 
 * Pour sortir de prison, ils doivent faire un double aux dés, payer une caution ou bien utiliser une carte permettant de sortir de prison. Le nombre de tours consécutifs en prison est limité.
 */
class Prison : public Emplacement
{
    private:
        const SimpleVisite* m_emplacementAssocie;///< Emplacement « Simple visite » associé à la prison.
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
        const SimpleVisite* getEmplacementAssocie() const;
        
        
        
        /**
         * Remplace l'emplacement « Simple visite » associé à la prison par @a emplacement
         * @param emplacement Nouvel emplacement.
         */
        void editEmplacementAssocie(const SimpleVisite* emplacement);
        
        
        
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
        
        
        
        /**
         * Charge les informations concernant la prison depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         * @param plateau Plateau de jeu.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version,
                          const Plateau* plateau);
};

#endif // PRISONINFOS_HPP
