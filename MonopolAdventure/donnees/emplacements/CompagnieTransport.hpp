#ifndef COMPAGNIETRANSPOTINFOS_HPP
#define COMPAGNIETRANSPOTINFOS_HPP

#include <QList>

#include "donnees/emplacements/Propriete.hpp"





/**
 * @class CompagnieTransport CompagnieTransport.hpp donnees/emplacements/CompagnieTransport.hpp
 * Cette classe représente une compagnie de transport.
 * 
 * Une compagnie de transport est une propriété dont le loyer varie en fonction du nombre de compagnies que possède le joueur propriétaire.
 */
class CompagnieTransport : public Propriete
{
    private:
        QList<quint16> m_loyers;///< Liste des loyers en fonction du nombre de compagnies de transport possédées par le propriétaire.
        
        
        
    public:
        /**
         * Construit une compagnie de transport par défaut.
         * @param graphismeInfos Informations concernant le graphisme.
         * @param devise Référence vers la devise servant à l'affichage du prix sur le plateau.
         */
        CompagnieTransport(const GraphismeEmplacementInfos& graphismeInfos,
                          const QString& devise);
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~CompagnieTransport();
        
        
        
        /**
         * Renseigne le montant du loyer de la compagnie de transport en fonction du nombre de compagnies de transport possédées par le propriétaire.
         * @param nombreCompagniesPossedees Nombre de compagnies de transport possédées par le propriétaire.
         * @return Montant du loyer de la compagnie de transport en fonction du nombre de compagnies de transport possédées par le propriétaire.
         */
        quint16 getLoyer(const int nombreCompagniesPossedees) const;
        
        
        
        /**
         * Charge les informations concernant la compagnie de transport depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version);
};

#endif // COMPAGNIETRANSPOTINFOS_HPP
