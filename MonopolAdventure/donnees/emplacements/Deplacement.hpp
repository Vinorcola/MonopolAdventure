#ifndef DEPLACEMENTINFOS_HPP
#define DEPLACEMENTINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"
class Plateau;





/**
 * @class Deplacement Deplacement.hpp donnees/emplacements/Deplacement.hpp
 * Cette classe représente un emplacement qui oblige les joueurs à se déplacer vers un autre emplacement précis.
 * 
 * Il est possible de configurer une amende que le joueur devra payer avant de se déplacer.
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
         * @param devise Référence vers la devise servant à l'affichage du prix sur le plateau.
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
         * Renseigne le montant de l'amende.
         * @return montant de l'amende.
         */
        quint16 getMontantAmende() const;
        
        
        
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
