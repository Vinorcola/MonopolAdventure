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
    private:
        Regroupement* m_regroupement;///< Regroupement auquel appartient le terrain.
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
        Regroupement* getRegroupement() const;
        
        
        
        /**
         * Remplace le regroupement auquel appartient le terrain.
         * @param regroupement Nouveau regroupement.
         */
        void editRegroupement(Regroupement* const regroupement);
        
        
        
        /**
         * Met à jour l'affichage graphique de la couleur du regroupement.
         * @param scene Scène sur laquelle mettre à jour l'affichage (0 pour toutes).
         * 
         * Pour plus d'information concernant la mémorisation des scène, voir la méthode Emplacement::dessiner(). Pour actualiser l'affichage graphique de l'emplacement sur une scène précise, il suffit d'appeler cette méthode avec la scène en paramètre. Si aucune scène n'est passée en argument, toutes les scènes sont mises à jour.
         */
        void updateAffichageCouleurRegroupement(QGraphicsScene* scene = 0);
        
        
        
        /**
         * Renseigne le montant du loyer du terrain nu.
         * @return montant du loyer du terrain nu.
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
         * Renseigne le montant du loyer du terrain en fonction du nombre de maisons construites.
         * @param nombreMaisonsConstruites Nombre de maisons construites.
         * @return Montant du loyer du terrain en fonction du nombre de maisons construites.
         */
        quint16 getLoyerMaison(const int nombreMaisonsConstruites) const;
        
        
        
        /**
         * Confirgure le nombre maximum de maisons constructibles sur le terrain.
         * @param quantite Nombre maximum de maisons constructibles sur le terrain.
         */
        void setupNombreMaxMaison(const int quantite);
        
        
        
        /**
         * Remplace le montant du loyer du terrain aménagé avec @a nombreMaisonsConstruites maisons par @a montant.
         * @param nombreMaisonsConstruites Nombre de maisons construites.
         * @param montant Montant du nouveau loyer.
         */
        void editLoyerMaison(const int nombreMaisonsConstruites,
                             const quint16 montant);
        
        
        
        /**
         * Renseigne le montant du loyer du terrain en fonction du nombre d'hôtels construits.
         * @param nombreHotelsConstruits Nombre d'hôtels construits.
         * @return Montant du loyer du terrain en fonction du nombre d'hôtels construits.
         */
        quint16 getLoyerHotel(const int nombreHotelsConstruits) const;
        
        
        
        /**
         * Confirgure le nombre maximum d'hôtels constructibles sur le terrain.
         * @param quantite Nombre maximum d'hôtels constructibles sur le terrain.
         */
        void setupNombreMaxHotel(const int quantite);
        
        
        
        /**
         * Remplace le montant du loyer du terrain aménagé avec @a nombreHotelsConstruits hôtels par @a montant.
         * @param nombreHotelsConstruits Nombre d'hôtels construits.
         * @param montant Montant du nouveau loyer.
         */
        void editLoyerHotel(const int nombreHotelsConstruits,
                            const quint16 montant);
        
        
        
    protected:
        virtual QColor helper_getCouleurRegroupement() const;
};

#endif // TERRAININFOS_HPP
