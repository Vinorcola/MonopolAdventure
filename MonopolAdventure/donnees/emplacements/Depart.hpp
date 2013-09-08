#ifndef DEPARTINFOS_HPP
#define DEPARTINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class Depart Depart.hpp donnees/emplacements/Depart.hpp
 * Cette classe représente la case de départ du plateau.
 * 
 * Cet emplacement est unique : il n'y en a qu'un seul sur le plateau (et il est obligatoire). C'est l'emplacement à partir duquel les joueurs vont débuter la partie. Par la suite, ils vont recevoir un salaire à chaque fois qu'il passeront par cet emplacement.
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
         * Configure le salaire de l'emplacement.
         * @param salaire Nouveau salaire.
         */
        void setSalaire(quint16 salaire);
        
        
        
        /**
         * Charge les informations concernant l'emplacement « Départ » depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version);
        
        
        
    protected:
        virtual QString helper_getPrix() const;
};

#endif // DEPARTINFOS_HPP
