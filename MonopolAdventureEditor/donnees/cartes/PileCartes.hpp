#ifndef PILECARTESINFOS_HPP
#define PILECARTESINFOS_HPP

#include <QAbstractListModel>

class Carte;





/**
 * @class PileCartes PileCartes.hpp donnees/cartes/PileCartes.hpp
 * PileCartes est une pile de cartes du plateau contenant un certain nombre de cartes.
 * 
 * Une pile de cartes est avant tout une liste de cartes. L'utilisateur peut créer plusieurs piles de cartes pour un même plateau. Les plus communes sont les piles Chance et Caisse de communauté. Une fois qu'un pile de cartes est créée, on peut lui ajouter des cartes en appelant la méthode createCarte() ou en supprimer en appelant la méthode deleteCarte().
 * 
 * La classe PileCartes hérite de QAbstractListModel. Elle peut donc être utilisée avec des QComboBox ou QListView afin d'afficher une liste des cartes présentes dans la pile.
 */
class PileCartes : public QAbstractListModel
{
        Q_OBJECT
        
        
    private:
        QString m_titre;///< Titre de la pile de cartes.
        QList<Carte*> m_cartes;///< Liste des cartes contenues dans la pile de cartes.
        
        
        
    public:
    /* Constructeurs et destructeur. */
        /**
         * Construit une pile de cartes vide par défaut.
         */
        PileCartes();
        
        
        
        /**
         * Construit une pile de cartes identique à @a pileCartes
         * @param pileCartes Pile de cartes à copier.
         */
        PileCartes(const PileCartes* pileCartes);
        
        
        
        /**
         * Supprime toutes les cartes que la pile de cartes contient.
         */
        ~PileCartes();
        
        
        
    /* Méthodes d'accès aux informations.*/
        /**
         * Renseigne le titre de la pile de cartes.
         * @return Titre de la pile de cartes.
         */
        const QString& getTitre() const;
        
        
        
        /**
         * Remplace le titre de la pile de cartes par @a titre.
         * @param titre Nouveau titre.
         */
        void editTitre(const QString& titre);
        
        
        
        /**
         * Renseigne le nombre de cartes contenus dans la pile de cartes.
         * @return Nombre de cartes contenus dans la pile de cartes.
         */
        int getNombreCartes() const;
        
        
        
        /**
         * Retourne la carte situé à l'index @a index.
         * @return Carte situé à l'index @a index.
         */
        Carte* getCarteAt(int index) const;
        
        
        
        /**
         * Créé une nouvelle carte dans la pile de cartes.
         * @return Le rang de la nouvelle carte dans la pile.
         */
        int createCarte();
        
        
        
        /**
         * Supprime une carte de la pile de cartes.
         * @param row Rang de la carte à supprimer dans la pile.
         */
        void deleteCarteAt(int row);
        
        
        
    /* Méthodes d'aide. */
        /**
         * Helper créant un index à partir d'un rang.
         */
        QModelIndex helper_createIndexFromRow(int row);
        
        
        
    /* Méthodes nécessaires pour QAbstractListModel. */
        /**
         * Renseigne diverses informations nécessaires aux QWidgets vues.
         * @param index Index correspondant au Terrain concerné.
         * @param role Rôle de l'information.
         * @return Diverses informations nécessaires aux QWidgets vues.
         */
        QVariant data(const QModelIndex& index,
                      int role = Qt::DisplayRole) const;
        
        
        
        /**
         * Renseigne le nombre de rangs contenus dans le modèle de données.
         * @param parent Paramètre inutilisé dans la réimplémentation.
         * @return Nombre de rangs contenus dans le modèle de données.
         */
        int rowCount(const QModelIndex& parent = QModelIndex()) const;
};

#endif // PILECARTESINFOS_HPP
