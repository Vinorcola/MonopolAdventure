#ifndef PILECARTESDATA_HPP
#define PILECARTESDATA_HPP

#include "dialogEdition/modeles/CarteListModel.hpp"





/**
 * @class PileCartesData PileCartesData.hpp dialogEdition/donnees/PileCartesData.hpp
 * Structure de données contenant les informations d'une pile de cartes à éditer.
 */
class PileCartesData
{
    private:
        QString m_titre;///< Titre de la pile de cartes.
        QList<Carte*> m_cartes;///< Liste des cartes.
        CarteListModel* m_modeleCartes;///< Modèle de données permettant d'aficher la liste des cartes.
        
        
        
    public:
        /**
         * Initialise tous les attributs par défaut.
         */
        PileCartesData();
        
        
        
        /**
         * Construit une structure de données à partir d'une pile de cartes.
         * @param pileCartes Pile de cartes fournissant les informations.
         */
        PileCartesData(PileCartes* pileCartes);
        
        
        
        /**
         * Détruit le modèle de donnnées des terains.
         */
        ~PileCartesData();
        
        
        
        /**
         * Retourne le titre de la pile de cartes.
         * @return Titre de la pile de cartes.
         */
        const QString& getTitre() const;
        
        
        
        /**
         * Configure le titre de la pile de cartes.
         * @param titre Nouveau titre.
         */
        void editTitre(const QString& titre);
        
        
        
        /**
         * Retourne le modèle de données contenant la liste des cartes.
         * @return Modèle de données contenant la liste des cartes.
         */
        CarteListModel* getModeleCartes() const;
        
        
        
        /**
         * Retourne la liste des cates contenus dans la pile de cartes.
         * @return Liste des cartes contenus dans la pile de cartes.
         */
        QList<Carte*>& getListeCartes();
        
        
        
        /**
         * Créer une carte et l'ajoute au modèle de donées.
         */
        void createCarte();
        
        
        
        /**
         * Enlève la carte située au rang @a row du modèle de données, puis la supprime.
         * @param row Rang auquel se situe la carte.
         */
        void deleteCarte(int row);
        
        
        
        /**
         * Transfère toutes les cartes à la pile de cartes passée en paramètre.
         * @param pileCartes Pile de cartes recevant les cartes.
         */
        void transfereCartes(PileCartes* pileCartes);
};

#endif // PILECARTESDATA_HPP
