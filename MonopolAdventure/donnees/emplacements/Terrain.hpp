#ifndef TERRAININFOS_HPP
#define TERRAININFOS_HPP

#include <QList>

#include "donnees/emplacements/Propriete.hpp"
class Regroupement;
#include "donnees/emplacements/Regroupement.hpp"





/**
 * @class Terrain Terrain.hpp donnees/emplacements/Terrain.hpp
 * Cette classe représente un terrain.
 * 
 * Les terrains sont des propriété. Ce sont les emplacements les plus présents sur un plateau. Ils sont rassemblés en regroupements et peuvent accueillir des constructions.
 */
class Terrain : public Propriete
{
        friend class Regroupement;
        
        
    private:
        Regroupement* m_regroupement;///< Regroupement auquel appartient le terrain.
        quint16 m_prixAchatMaison;///< Prix d'achat d'une maison.
        quint16 m_prixVenteMaison;///< Prix de vente d'une maison.
        quint16 m_prixAchatHotel;///< Prix d'achat d'un hôtel.
        quint16 m_prixVenteHotel;///< Prix de vente d'un hôtel.
        quint16 m_loyerNu;///< Loyer du terrain nu.
        quint16 m_loyerNuExtra;///< Loyer du terrain nu lorsque le propriétaire possède tous les terrains du regroupement.
        QList<quint16> m_loyersMaison;///< Liste des loyers en fonction du nombre de maisons construites.
        QList<quint16> m_loyersHotel;///< Liste des loyers en fonction du nombre d'hôtels construits.
        
        
        
    public:
        /**
         * Construit un terrain par défaut.
         * @param graphismeInfos Informations concernant le graphisme.
         * @param devise Référence vers la devise servant à l'affichage du prix sur le plateau.
         */
        Terrain(const GraphismeEmplacementInfos& graphismeInfos,
                const QString& devise);
        
        
        
        /**
         * Destructeur virtuel.
         * Enlève le terrain du regroupement avant la suppression.
         */
        virtual ~Terrain();
        
        
        
        /**
         * Renseigne le regroupement auquel appartient le terrain.
         * @return Regroupement auquel appartient le terrain.
         */
        const Regroupement* getRegroupement() const;
        
        
        
        /**
         * Renseigne le prix d'achat d'une maison.
         * @return Prix d'achat d'une maison.
         */
        quint16 getPrixAchatMaison() const;
        
        
        
        /**
         * Renseigne le prix de vente d'une maison.
         * @return Prix de vente d'une maison.
         */
        quint16 getPrixVenteMaison() const;
        
        
        
        /**
         * Renseigne le prix d'achat d'un hôtel.
         * @return Prix d'achat d'un hôtel.
         */
        quint16 getPrixAchatHotel() const;
        
        
        
        /**
         * Renseigne le prix de vente d'un hôtel.
         * @return Prix de vente d'un hôtel.
         */
        quint16 getPrixVenteHotel() const;
        
        
        
        /**
         * Renseigne le montant du loyer du terrain nu.
         * @return Montant du loyer du terrain nu.
         */
        quint16 getLoyerNu() const;
        
        
        
        /**
         * Renseigne le montant du loyer du terrain nu lorsque le propriétaire possède tous les terrains du regroupement.
         * @return Montant du loyer du terrain nu lorsque le propriétaire possède tous les terrains du regroupement.
         */
        quint16 getLoyerNuExtra() const;
        
        
        
        /**
         * Renseigne le nombre de maisons nécessaires pour la construction d'un hôtel.
         * @return Nombre de maisons nécessaires pour la construction d'un hôtel.
         */
        int getNombreMaisonsPourHotel() const;
        
        
        
        /**
         * Renseigne le montant du loyer du terrain en fonction du nombre de maisons construites.
         * @param nombreMaisonsConstruites Nombre de maisons construites.
         * @return Montant du loyer du terrain en fonction du nombre de maisons construites.
         */
        quint16 getLoyerMaison(const int nombreMaisonsConstruites) const;
        
        
        
        /**
         * Renseigne le nombre maximum d'hôtels constructibles sur le terrain.
         * @return Nombre maximum d'hôtels constructibles sur le terrain.
         */
        int getNombreMaxHotel() const;
        
        
        
        /**
         * Renseigne le montant du loyer du terrain en fonction du nombre d'hôtels construits.
         * @param nombreHotelsConstruits Nombre d'hôtels construits.
         * @return Montant du loyer du terrain en fonction du nombre d'hôtels construits.
         */
        quint16 getLoyerHotel(const int nombreHotelsConstruits) const;
        
        
        
        /**
         * Charge les informations concernant le terrains depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version);
        
        
        
    protected:
        virtual QColor helper_getCouleurRegroupement() const;
};

#endif // TERRAININFOS_HPP
