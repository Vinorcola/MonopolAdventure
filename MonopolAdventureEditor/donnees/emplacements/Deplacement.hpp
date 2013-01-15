#ifndef DEPLACEMENTINFOS_HPP
#define DEPLACEMENTINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"
class Plateau;





/**
 * @class Deplacement Deplacement.hpp donnees/emplacements/Deplacement.hpp
 * Deplacement contient les informations éditables d'un emplacement « Déplacement » d'un plateau.
 * @todo Ajouter une option permetant de terminer le tour du joueur ou non (si non, il peut rejouer de suite s'il avait fait un double aux dés).
 */
class Deplacement : public Emplacement
{
    private:
        const Emplacement* m_destination;///< Emplacement de destination.
        quint16 m_amende;///< Amende à payer avant de se déplacer.
        
        
        
    protected:
        const QString& m_devise;///< Référence constante vers la devise du plateau.
        
        
        
    public:
        /**
         * Construit un emplacement « Déplacement » par défaut.
         * @param graphismeInfos Informations concernant le graphisme.
         */
        Deplacement(const GraphismeEmplacementInfos& graphismeInfos,
                    const QString& devise);
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~Deplacement();
        
        
        
        /**
         * Renseigne l'emplacement de destination.
         * @return Emplacement de destination.
         */
        const Emplacement* getDestination() const;
        
        
        
        /**
         * Remplace l'emplacement de destination par @a destination.
         * @param destination Nouvel emplacement de destination.
         */
        void editDestination(const Emplacement* destination);
        
        
        
        /**
         * Renseigne le montant de l'amende.
         * @return montant de l'amende.
         */
        quint16 getMontantAmende() const;
        
        
        
        /**
         * Remplace le montant de l'amende par @a montant.
         * @param montant Montant de la nouvelle amende.
         */
        void editMontantAmende(const quint16 montant);
        
        
        
        /**
         * Sauvegarde les informations concernant l'emplacement « Déplacement » via le flux de données.
         * @param ecriture Flux de données vers le fichier à écrire.
         * @param plateau Plateau auquel appartient l'emplacement.
         */
        void saveInFile(QDataStream& ecriture,
                        const Plateau* plateau) const;
        
        
        
        /**
         * Charge les informations concernant l'emplacement « Déplacement » depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         * @param plateau Plateau de jeu.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version,
                          const Plateau* plateau);
        
        
        
    protected:
        virtual QString helper_getPrix() const;
};

#endif // DEPLACEMENTINFOS_HPP
