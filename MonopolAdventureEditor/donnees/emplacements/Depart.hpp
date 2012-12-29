#ifndef DEPARTINFOS_HPP
#define DEPARTINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class Depart Depart.hpp donnees/emplacements/Depart.hpp
 * Depart contient les informations éditables d'un emplacement « Départ » d'un plateau.
 */
class Depart : public Emplacement
{
    private:
        quint16 m_salaire;///< Salaire reçu au passage.
        
        
        
    protected:
        const QString& m_devise;///< Référence constante vers la devise du plateau.
        
        
        
    public:
        /**
         * Construit un emplacement « Départ » par défaut.
         * @param graphismeInfos Informations concernant le graphisme.
         * @param devise Référence vers la devise servant à l'affichage du prix sur le plateau.
         */
        Depart(const GraphismeEmplacementInfos& graphismeInfos,
               const QString& devise);
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~Depart();
        
        
        
        /**
         * Renseigne le montant du salaire perçu au passage.
         * @return Montant du salaire perçu au passage.
         */
        quint16 getSalaire() const;
        
        
        
        /**
         * Remplace le montant du salaire par @a montant.
         * @param montant Montant du nouveau salaire.
         */
        void editSalaire(const quint16 montant);
        
        
        
        /**
         * Sauvegarde les informations concernant l'emplacement « Départ » via le flux de données.
         * @param ecriture Flux de données vers le fichier à écrire.
         * @param version Numéro de la version à utiliser pour écrire les données.
         */
        void saveInFile(QDataStream& ecriture,
                        const quint16 version) const;
        
        
        
    protected:
        virtual QString helper_getPrix() const;
};

#endif // DEPARTINFOS_HPP
