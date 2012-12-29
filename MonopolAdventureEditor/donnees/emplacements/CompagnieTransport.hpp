#ifndef COMPAGNIETRANSPOTINFOS_HPP
#define COMPAGNIETRANSPOTINFOS_HPP

#include <QList>

#include "donnees/emplacements/Propriete.hpp"





/**
 * @class CompagnieTransport CompagnieTransport.hpp donnees/emplacements/CompagnieTransport.hpp
 * CompagnieTransport contient les informations éditables d'une compagnie de transport d'un plateau.
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
         * Informe du nombre de compagnies de transport sur le plateau.
         * @param quantite Nombre de compagnies de transport sur le plateau.
         */
        void setupNombreCompagnies(const int quantite);
        
        
        
        /**
         * Remplace le montant du loyer de la compagnie de transport lorsque le propriétaire possède @a nombreCompagniesPossedees compagnies par @a montant.
         * @param nombreCompagniesPossedees Nombre de compagnies de transport possédées par le propriétaire.
         * @param montant Montant du nouveau loyer.
         */
        void editLoyer(const int nombreCompagniesPossedees,
                       const quint16 montant);
        
        
        
        /**
         * Sauvegarde les informations concernant la compagnie de transport via le flux de données.
         * @param ecriture Flux de données vers le fichier à écrire.
         * @param version Numéro de la version à utiliser pour écrire les données.
         */
        void saveInFile(QDataStream& ecriture,
                        const quint16 version) const;
};

#endif // COMPAGNIETRANSPOTINFOS_HPP
