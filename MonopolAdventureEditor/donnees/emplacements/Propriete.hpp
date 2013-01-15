#ifndef PROPRIETEINFOS_HPP
#define PROPRIETEINFOS_HPP

#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class Propriete Propriete.hpp donnees/emplacements/Propriete.hpp
 * Propriete contient les informations éditables communes à toutes les propriétés d'un plateau.
 */
class Propriete : public Emplacement
{
    private:
        quint16 m_prixAchat;///< Prix d'achat de la propriété.
        quint16 m_valeurHypotheque;///< Valeur de l'hypothèque.
        
        
        
    protected:
        const QString& m_devise;///< Référence constante vers la devise du plateau.
        
        
        
    public:
        /**
         * Construit une propriété par défaut.
         * @param type Précise le type de propriété.
         * @param graphismeInfos Informations concernant le graphisme.
         * @param devise Référence vers la devise servant à l'affichage du prix sur le plateau.
         */
        Propriete(const Type::Emplacement type,
                  const GraphismeEmplacementInfos& graphismeInfos,
                  const QString& devise);
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~Propriete();
        
        
        
        /**
         * Renseigne le montant du prix d'achat de la propriété.
         * @return Montant du prix d'achat de la propriété.
         */
        quint16 getPrixAchat() const;
        
        
        
        /**
         * Remplace le montant du prix d'achat de la propriété par @a montant.
         * @param montant Montant du nouveau prix.
         */
        void editPrixAchat(const quint16 montant);
        
        
        
        /**
         * Renseigne le montant de la valeur de l'hypothèque de la propriété.
         * @return Montant de la valeur de l'hypothèque de la propriété.
         */
        quint16 getValeurHypotheque() const;
        
        
        
        /**
         * Remplace le montant de la valeur de l'hypothèque de la propriété par @a montant.
         * @param montant Montant de la nouvelle valeur.
         */
        void editValeurHypotheque(const quint16 montant);
        
        
        
        /**
         * Sauvegarde les informations concernant la propriété via le flux de données.
         * @param ecriture Flux de données vers le fichier à écrire.
         */
        void saveInFile(QDataStream& ecriture) const;
        
        
        
        /**
         * Charge les informations concernant la propriété depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version);
        
        
        
    protected:
        virtual QString helper_getPrix() const;
};

#endif // PROPRIETEINFOS_HPP
