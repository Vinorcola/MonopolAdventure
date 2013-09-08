#ifndef REGLECONFIGWIDGET_HPP
#define REGLECONFIGWIDGET_HPP

#include <QCheckBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QSpinBox>

#include "global.hpp"
#include "donnees/Regle.hpp"





/**
 * @class RegleConfigWidget RegleConfigWidget.hpp config/RegleConfigWidget.hpp
 * Cette classe représente un widget permettant de configurer les règles de jeu lors du lancement d'une partie.
 */
class RegleConfigWidget : public QScrollArea
{
        Q_OBJECT
        
        
    private:
        const Regle* m_regleDefaut;///< Règle par défaut du plateau.
        quint16 m_salaireDefaut;///< Salaire par défaut.
        QPushButton* m_parDefaut;///< Bouton permettant de réinitialisé tous les widgets.
        
        // Groupe Constructions
        QGroupBox* m_groupeConstruction;///< Groupe des options concernant les constructions.
        QSpinBox* m_nombreTotalMaison;///< Champ permettant de modifier le nombre total de maisons.
        QSpinBox* m_nombreTotalHotel;///< Champ permettant de modifier le nombre total d'hôtels.
        QCheckBox* m_possessionRegroupement;///< Champ permettant d'imposer la possession du regroupement pour pouvoir construire.
        QCheckBox* m_constructionsUniformes;///< Champ permettant d'imposer des constructions uniformes sur un regroupement.
        QCheckBox* m_joueurPresentPourConstruire;///< Champ permettant d'imposer que le joueur soit présent pour pouvoir construire.
        QCheckBox* m_tousTerrainsVendus;///< Champ permettant d'obliger les joueurs à attendre que tous les terrains soient vendus pour pouvoir construire.
        QCheckBox* m_toutesPprtVendues;///< Champ permettant d'obliger les joueurs à attendre que toutes les propriétés soient vendus pour pouvoir construire.
        
        // Groupe Case Départ
        QGroupBox* m_groupeDepart;///< Groupe des options concernant la case Départ.
        QSpinBox* m_salaire;///< Champ permettant de changer le salaire reçu à la case Départ.
        QCheckBox* m_doubleSalaire;///< Champ permettant d'activer le double salaire si le joueur s'arrête sur la cae Départ.
        
        // Groupe Début de la partie
        QGroupBox* m_groupeDebut;///< Groupe des options concernant le début de la partie.
        QSpinBox* m_nbPprtAuDebut;///< Champ permettant de déterminer un nombre de propriétés par joueur à distribuer au début de la partie.
        QCheckBox* m_toutesPprtAuDebut;///< Champ permettant de distribuer toutes les propriétés aux joueurs au début de la partie.
        QCheckBox* m_encheresDepart;///< Champ permettant de démarrer une enchère pour savoir quel joueur part le premier.
        QCheckBox* m_premierTourSansAchat;///< Champ permettant de désactiver les achats de propriétés durant le premier tour.
        
        // Groupe Parc gratuit
        QGroupBox* m_groupeParcGratuit;///< Groupe des options concernant le Parc gratuit.
        QCheckBox* m_taxeAuParcGratuit;///< Champ permettant d'envoyer les taxes récoltés au Parc gratuit.
        QCheckBox* m_amendeCarteAuParcGratuit;///< Champ permettant d'envoyer les amendes des cartes au Parc gratuit.
        QCheckBox* m_cagnotteFixe;///< Champ permettant d'activité la distribution d'une cagnotte au Parc gratuit.
        QSpinBox* m_montantCagnotte;///< Champ permettant de déterminer le montant de la cagnotte à distribuer au Parc gratuit.
        
        // Groupe Prison
        QGroupBox* m_groupePrison;///< Groupe des options concernant la prison.
        QSpinBox* m_maxTourEnPrison;///< Champ permettant de configurer le nombre maximum de tours en prison.
        QCheckBox* m_percevoirLoyerEnPrison;
        QCheckBox* m_participerEnchereEnPrison;
        QCheckBox* m_echangerEnPrison;
        QCheckBox* m_construireEnPrison;
        QPushButton* m_tousLesDroitsEnPrison;
        QPushButton* m_aucunDroitEnPrison;
        
        // Groupe Enchères
        QGroupBox* m_groupeEncheres;///< Groupe des options concernant les enchères.
        QCheckBox* m_encheresSurBiensPerdus;///< Champ permettant d'imposer des enchères sur les biens perdus de retour à la banque.
        QCheckBox* m_encheresSurNonAchete;///< Champ permettant d'imposer des enchères sur les biens non-achetés.
        
        // Groupe Autres
        QGroupBox* m_groupeAutres;///< Groupe de toutes les options non-classés
        QCheckBox* m_deRapide;///< Champ permettant d'autoriser l'utilisation du dé rapide.
        QCheckBox* m_nbMaxTours;///< Champ permettant d'imposer un nombre maximum de tours.
        QSpinBox* m_nbTours;///< Champ permettant de configurer le nombre de tours maximum.
        
        
        
    public:
        /**
         * Construit un widget de configuration de règles.
         * @param defaut Règle utilisée par défaut.
         * @param salaire Salaire perçu en passant par l'emplacement Départ.
         */
        RegleConfigWidget(const Regle* defaut = 0,
                          const quint16 salaire = 200);
        
        
        
        /**
         * Configure tous les champs avec la règle passée en argument.
         * @param regle Règle permettant d'initialiser les champs.
         * @param salaire Salaire perçu en passant à l'emplacement Départ.
         */
        void setRegle(const Regle* regle,
                      const quint16 salaire);
        
        
        
    private slots:
        /**
         * Active ou non l'option « Constructions uniformes » en fonction de l'état de l'option « Possession regroupement pour construire ».
         * @param state État de l'option « Possession regroupement pour construire ».
         */
        void possessionRegroupementChanged(int state);
        
        
        
        /**
         * Active ou non l'option « Toutes propriétés vendues pour construire » en fonction de l'état de l'option « Tous terrains vendus pour construire ».
         * @param state État de l'option « Tous terrains vendus pour construire ».
         */
        void tousTerrainsVendusChanged(int state);
        
        
        
        /**
         * Active ou non l'option « Tous terrains vendus pour construire » en fonction de l'état de l'option « Toutes propriétés vendues pour construire ».
         * @param state État de l'option « Toutes propriétés vendues pour construire ».
         */
        void toutesPprtVenduesChanged(int state);
        
        
        
        /**
         * Coche toutes les checkbox nécessaires afin d'avoir tous les droits en prison.
         */
        void tousLesDroitsEnPrison();
        
        
        
        /**
         * Décoche toutes les checkbox nécessaires pour n'avoir aucun droit en prison.
         */
        void aucunDroitEnPrison();
        
        
        
        /**
         * Active ou non le champ « Nombre de propriété au début » en fonction de l'état de l'option « Toutes les propriété au début ».
         * @param state État de l'option « Toutes les propriétés au début ».
         */
        void toutesPprtAuDebut(int state);
        
        
        
        /**
         * 
         * @param state 
         */
        void taxeAuParcGratuitChanged(int state);
        
        
        
        /**
         * 
         * @param state 
         */
        void amendeCarteAuParcGratuitChanged(int state);
        
        
        
        /**
         * 
         * @param state 
         */
        void cagnotteFixeChanged(int state);
        
        
        
        /**
         *
         * @param state
         */
        void nbMaxToursChanged(int state);
        
        
        
        /**
         * Reconfigure tous les widgets avec la règle et le salaire par défaut.
         */
        void setParDefaut();
};

#endif // REGLECONFIGWIDGET_HPP
