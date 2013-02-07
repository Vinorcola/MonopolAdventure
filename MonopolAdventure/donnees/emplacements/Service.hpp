#ifndef SERVICEINFOS_HPP
#define SERVICEINFOS_HPP

#include <QList>

#include "donnees/emplacements/Propriete.hpp"





/**
 * @class Service Service.hpp donnees/emplacements/Service.hpp
 * Cette classe représente un service public.
 * 
 * Un service public est une propriété dont le loyer varie en fonction du nombre de services que possède le joueur propriétaire et le montant obtenu aux dés.
 */
class Service : public Propriete
{
    private:
        QList<quint16> m_loyers;///< Liste des loyers en fonction du nombre de services possédés par le propriétaire.
        
        
        
    public:
        /**
         * Construit un service par défaut.
         * @param graphismeInfos Informations concernant le graphisme.
         * @param devise Référence vers la devise servant à l'affichage du prix sur le plateau.
         */
        Service(const GraphismeEmplacementInfos& graphismeInfos,
                const QString& devise);
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~Service();
        
        
        
        /**
         * Renseigne le montant du loyer du service en fonction du nombre de services possédés par le propriétaire.
         * @param nombreServicesPossedes Nombre de services possédés par le propriétaire.
         * @return Montant du loyer du service en fonction du nombre de services possédés par le propriétaire.
         */
        quint16 getLoyer(const int nombreServicesPossedes) const;
        
        
        
        /**
         * Charge les informations concernant le service depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version);
};

#endif // SERVICEINFOS_HPP
