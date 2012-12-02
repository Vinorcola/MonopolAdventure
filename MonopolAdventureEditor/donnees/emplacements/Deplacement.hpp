#ifndef DEPLACEMENTINFOS_HPP
#define DEPLACEMENTINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class Deplacement Deplacement.hpp donnees/emplacements/Deplacement.hpp
 * Deplacement contient les informations éditables d'un emplacement « Déplacement » d'un plateau.
 * @todo Ajouter une option permetant de terminer le tour du joueur ou non (si non, il peut rejouer de suite s'il avait fait un double aux dés).
 */
class Deplacement : public Emplacement
{
    private:
        Emplacement* m_destination;///< Emplacement de destination.
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
        Emplacement* getDestination() const;
        
        
        
        /**
         * Remplace l'emplacement de destination par @a destination.
         * @param destination Nouvel emplacement de destination.
         */
        void editDestination(Emplacement* const destination);
        
        
        
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
        
        
        
    protected:
        virtual QString helper_getPrix() const;
};

#endif // DEPLACEMENTINFOS_HPP
