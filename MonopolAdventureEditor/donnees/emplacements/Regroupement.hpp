#ifndef REGROUPEMENTINFOS_HPP
#define REGROUPEMENTINFOS_HPP

#include <QAbstractListModel>
#include <QColor>
#include <QList>
#include <QString>

class Terrain;
#include "donnees/emplacements/Terrain.hpp"
class Plateau;





/**
 * @class Regroupement Regroupement.hpp donnees/emplacements/Regroupement.hpp
 * Cette classe permet de rassembler plusieurs terrains dans un même groupe.
 * 
 * Les regroupements rassemblent plusieurs terrains dans un unique but : un joueur doit posséder tous les terrains d'un regroupement pour pouvoir construire sur ces terrains. Un regroupement est caractérisé par une couleur (qui est affichée sur les terrains). Les joueurs peuvent ainsi rapidement voir quels terrains font parti du même groupe.
 * 
 * Cette classe hérite de QAbstractListModel. Elle permet donc d'afficher la liste des terrains qu'elle contient dans un widget de vue. Cette fonctionnalité est utilisée lors de l'édition des regroupements via une fenêtre de dialogue (cf RegroupementEditWidget). Lors de l'ouverture d'une fenêtre d'édition, tous les regroupements du plateau sont copiés, et ces copies sont mises en « mode édition ». Si l'utilisateur annule l'édition, ces copies sont simplement supprimées. En revanche, si l'utilisateur valide les changements, alors les regroupements originaux sont supprimés, et les copies les remplacent.
 * 
 * Le mode édition permet de gérer les terrains différemment. En effet, chaque terrain possède un pointeur vers le regroupement auquel il appartient (pour plus de simplicité). Lorsque l'on transfère un terrain d'un regroupement à un autre, ce pointeur change de valeur pour pointer vers le nouveau regroupement. Mais en mode édition, cette mise à jour du pointeur ne se fait pas : cela permet de garder les regroupements originaux intact, et de travailler avec les copies uniquements, sans modifier les terrains. Ainsi, si l'utilisateur annule tous les changements, la suppression des regroupements copiés et suffisante.
 * En revanche, si l'utilisateur valide les changements, alors, la méthode Regroupement::termineEdition() doit être appelée pour mettre a jour les pointeur de tous terrains contenus dans le (nouveau) regroupement.
 */
class Regroupement : public QAbstractListModel
{
    private:
        QString m_titre;///< Titre du regroupement.
        QColor m_couleur;///< Couleur du regroupement.
        QList<Terrain*> m_terrains;///< Liste des terrains regroupés dans ce regroupement.
        bool m_modeEdition;///< Indique si le regroupement est en édition ou non.
        
        
        
    public:
    /* Constructeurs et destructeur. */
        /**
         * Construit un regroupement par défaut.
         */
        Regroupement(const bool modeEdition = false);
        
        
        
        /**
         * Construit un regroupement identique à @a regroupement.
         * @param regroupement Regroupement à copier.
         */
        Regroupement(const Regroupement* regroupement);
        
        
        
    /* Méthodes d'accès aux informations. */
        /**
         * Renseigne le titre du regroupement.
         * @return Titre du regroupement.
         */
        const QString& getTitre() const;
        
        
        
        /**
         * Remplace le titre du regroupement par @a titre.
         * @param titre Nouveau titre.
         */
        void editTitre(const QString& titre);
        
        
        
        /**
         * Renseigne la couleur du regroupement.
         * @return Couleur du regroupement.
         */
        const QColor& getCouleur() const;
        
        
        
        /**
         * Remplace la couleur du regroupement par @a couleur.
         * @param couleur Nouvelle couleur.
         */
        void editCouleur(const QColor& couleur);
        
        
        
        /**
         * Renseigne le nombre de terrains contenus dans le regroupement.
         * @return Nombre de terrains contenus dans le regroupement.
         */
        int getNombreTerrains() const;
        
        
        
        /**
         * Retourne le terrain situé à l'index @a index.
         * @return Terrain situé à l'index @a index.
         */
        Terrain* getTerrainAt(int index) const;
        
        
        
        /**
         * Transfère un terrain vers un autre regroupement.
         * @param regroupement Regroupement récupérant le terrain.
         * @param rowTerrain Rang désignant le terrains à transférer.
         */
        void transfereTerrainA(Regroupement* regroupement,
                               int rowTerrain);
        
        
        
        /**
         * Insert un terrain dans le regroupement.
         * @param terrain Terrain à insérer.
         */
        void insertTerrain(Terrain* terrain);
        
        
        
        /**
         * Enlève un terrain du regroupement.
         * @param terrain Terrain à enlever.
         */
        void enleveTerrain(Terrain* terrain);
        
        
        
        /**
         * Configure tous les terrains contenus dans la liste pour qu'ils appartiennent à ce regroupement.
         */
        void termineEdition();
        
        
        
    /* Méthodes de sauvegarde et de chargement. */
        /**
         * Sauvegarde les informations concernant le regroupement via le flux de données.
         * @param ecriture Flux de données vers le fichier à écrire.
         * @param plateau Plateau auquel appartient le regroupement.
         */
        void saveInFile(QDataStream& ecriture,
                        const Plateau* plateau) const;
        
        
        
        /**
         * Charge les informations concernant le regroupement depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         * @param plateau Plateau de jeu.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version,
                          const Plateau* plateau);
        
        
        
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

#endif // REGROUPEMENTINFOS_HPP
