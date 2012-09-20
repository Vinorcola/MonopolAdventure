#ifndef SERVICEINFOS_HPP
#define SERVICEINFOS_HPP

#include <QList>

#include "donnees/emplacements/Propriete.hpp"





/**
 * @class Service Service.hpp donnees/emplacements/Service.hpp
 * Service contient les information éditables d'un service d'un plateau.
 */
class Service : public Propriete
{
    private:
        QList<quint16> m_loyers;///< Liste des loyers en fonction du nombre de services possédés par le propriétaire.
        
        
        
    public:
        /**
         * Construit un service par défaut.
         */
        Service();
        
        
        
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
         * Informe du nombre de services sur le plateau.
         * @param quantite Nombre de services sur le plateau.
         */
        void setupNombreServices(const int quantite);
        
        
        
        /**
         * Remplace le montant du loyer du service lorsque le propriétaire possède @a nombreServicesPossedes services par @a montant.
         * @param nombreServicesPossedes Nombre de services possédés par le propriétaire.
         * @param montant Montant du nouveau loyer.
         */
        void editLoyer(const int nombreServicesPossedes,
                       const quint16 montant);
};

#endif // SERVICEINFOS_HPP
