#ifndef TERRAININFOS_HPP
#define TERRAININFOS_HPP

#include <QList>

#include "donnees/emplacements/Propriete.hpp"
class Regroupement;
#include "donnees/emplacements/Regroupement.hpp"





/**
 * @class Terrain Terrain.hpp donnees/emplacements/Terrain.hpp
 * Terrain contient les informations éditables d'un terrain d'un plateau.
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
         * Remplace le prix d'achat d'une maison.
         * @param prix Nouveau prix.
         */
        void editPrixAchatMaison(const quint16 prix);
        
        
        
        /**
         * Renseigne le prix de vente d'une maison.
         * @return Prix de vente d'une maison.
         */
        quint16 getPrixVenteMaison() const;
        
        
        
        /**
         * Remplace le prix de vente d'une maison.
         * @param prix Nouveau prix.
         */
        void editPrixVenteMaison(const quint16 prix);
        
        
        
        /**
         * Renseigne le prix d'achat d'un hôtel.
         * @return Prix d'achat d'un hôtel.
         */
        quint16 getPrixAchatHotel() const;
        
        
        
        /**
         * Remplace le prix d'achat d'un hotel.
         * @param prix Nouveau prix.
         */
        void editPrixAchatHotel(const quint16 prix);
        
        
        
        /**
         * Renseigne le prix de vente d'un hôtel.
         * @return Prix de vente d'un hôtel.
         */
        quint16 getPrixVenteHotel() const;
        
        
        
        /**
         * Remplace le prix de vente d'un hôtel.
         * @param prix Nouveau prix.
         */
        void editPrixVenteHotel(const quint16 prix);
        
        
        
        /**
         * Renseigne le montant du loyer du terrain nu.
         * @return Montant du loyer du terrain nu.
         */
        quint16 getLoyerNu() const;
        
        
        
        /**
         * Remplace le montant du loyer du terrain nu par @a montant.
         * @param montant Montant du nouveau loyer.
         */
        void editLoyerNu(const quint16 montant);
        
        
        
        /**
         * Renseigne le montant du loyer du terrain nu lorsque le propriétaire possède tous les terrains du regroupement.
         * @return Montant du loyer du terrain nu lorsque le propriétaire possède tous les terrains du regroupement.
         */
        quint16 getLoyerNuExtra() const;
        
        
        
        /**
         * Remplace le montant du loyer du terrain nu lorsque le propriétaire possède tous les terrains du regroupement par @a montant.
         * @param montant Montant du nouveau loyer.
         */
        void editLoyerNuExtra(const quint16 montant);
        
        
        
        /**
         * Renseigne le nombre de maisons nécessaires pour la construction d'un hôtel.
         * @return Nombre de maisons nécessaires pour la construction d'un hôtel.
         */
        int getNombreMaisonsPourHotel() const;
        
        
        
        /**
         * Configure le nombre de maisons nécessaires pour la construction d'un hôtel.
         * @param quantite Nombre de maisons nécessaires pour la construction d'un hôtel.
         */
        void editNombreMaisonsPourHotel(const int quantite);
        
        
        
        /**
         * Renseigne le montant du loyer du terrain en fonction du nombre de maisons construites.
         * @param nombreMaisonsConstruites Nombre de maisons construites.
         * @return Montant du loyer du terrain en fonction du nombre de maisons construites.
         */
        quint16 getLoyerMaison(const int nombreMaisonsConstruites) const;
        
        
        
        /**
         * Remplace le montant du loyer du terrain aménagé avec @a nombreMaisonsConstruites maisons par @a montant.
         * @param nombreMaisonsConstruites Nombre de maisons construites.
         * @param montant Montant du nouveau loyer.
         */
        void editLoyerMaison(const int nombreMaisonsConstruites,
                             const quint16 montant);
        
        
        
        /**
         * Renseigne le nombre maximum d'hôtels constructibles sur le terrain.
         * @return Nombre maximum d'hôtels constructibles sur le terrain.
         */
        int getNombreMaxHotel() const;
        
        
        
        /**
         * Configure le nombre maximum d'hôtels constructibles sur le terrain.
         * @param quantite Nombre maximum d'hôtels constructibles sur le terrain.
         */
        void editNombreMaxHotel(const int quantite);
        
        
        
        /**
         * Renseigne le montant du loyer du terrain en fonction du nombre d'hôtels construits.
         * @param nombreHotelsConstruits Nombre d'hôtels construits.
         * @return Montant du loyer du terrain en fonction du nombre d'hôtels construits.
         */
        quint16 getLoyerHotel(const int nombreHotelsConstruits) const;
        
        
        
        /**
         * Remplace le montant du loyer du terrain aménagé avec @a nombreHotelsConstruits hôtels par @a montant.
         * @param nombreHotelsConstruits Nombre d'hôtels construits.
         * @param montant Montant du nouveau loyer.
         */
        void editLoyerHotel(const int nombreHotelsConstruits,
                            const quint16 montant);
        
        
        
        /**
         * Sauvegarde les informations concernant le terrain via le flux de données.
         * @param ecriture Flux de données vers le fichier à écrire.
         * @param version Numéro de la version à utiliser pour écrire les données.
         */
        void saveInFile(QDataStream& ecriture,
                        const quint16 version) const;
        
        
        
    protected:
        virtual QColor helper_getCouleurRegroupement() const;
};

#endif // TERRAININFOS_HPP
