#ifndef EDITIONEMPLACEMENT_HPP
#define EDITIONEMPLACEMENT_HPP

#include <QDialog>
#include <QDialogButtonBox>
#include <QTabWidget>
#include <QVBoxLayout>

#include "dialogEdition/widgetsEditeurs/EmplacementEditWidget.hpp"
#include "donnees/cartes/PileCartes.hpp"
#include "donnees/emplacements/Emplacements.hpp"





/**
 * @class EditionEmplacement EditionEmplacement.hpp dialogEdition/EditionEmplacement.hpp
 * Cette classe contrôle l'édition d'un emplacement.
 */
class EditionEmplacement
{
    private:
        QDialog* m_dialog;///< Boîte de dialogue affichant le widget d'édition.
        QTabWidget* m_onglets;///< Onglets d'édition.
        EmplacementEditWidget* m_onglet1;///< 1er onglet (informations générales).
        QWidget* m_onglet2;///< 2ème onglet (dépend du type d'emplacement).
        QWidget* m_onglet3;///< 3ème onglet (dépend du type d'emplacement).
        QWidget* m_onglet4;///< 4ème onglet (dépend du type d'emplacement).
        
        
        
    public:
        /**
         * Construit un contrôleur d'édition spécialisé pour une compagnie de transport.
         * @param compagnieTransport Compagnie de transport à éditer.
         * @param nombreCompagnies Nombre total de compagnies de transport sur le plateau.
         * @param parent QWidget parent de la QDialog.
         */
        EditionEmplacement(CompagnieTransport* compagnieTransport,
                           const int nombreCompagnies,
                           QWidget* parent);
        
        
        
        /**
         * Construit un contrôleur d'édition spécialisé pour un emplacement « Départ ».
         * @param depart Emplacement « Départ » à éditer.
         * @param parent QWidget parent de la QDialog.
         */
        EditionEmplacement(Depart* depart,
                           QWidget* parent);
        
        
        
        /**
         * Construit un contrôleur d'édition spécialisé pour un emplacement « Déplacement ».
         * @param deplacement Emplacement « Déplacement » à éditer.
         * @param emplacements Liste des emplacements du plateau.
         * @param parent QWidget parent de la QDialog.
         */
        EditionEmplacement(Deplacement* deplacement,
                           const QList<Emplacement*>& emplacements,
                           QWidget* parent);
        
        
        
        /**
         * Construit un contrôleur d'édition spécialisé pour un parc gratuit.
         * @param parcGratuit Parc gratuit à éditer.
         * @param parent QWidget parent de la QDialog.
         */
        EditionEmplacement(ParcGratuit* parcGratuit,
                           QWidget* parent);
        
        
        
        /**
         * Construit un contrôleur d'édition spécialisé pour un emplacement « Pioche ».
         * @param pioche Emplacement « Pioche » à éditer.
         * @param pilesCartes Liste des piles de cartes du plateau.
         * @param parent QWidget parent de la QDialog.
         */
        EditionEmplacement(Pioche* pioche,
                           const QList<PileCartes*>& pilesCartes,
                           QWidget* parent);
        
        
        
        /**
         * Construit un contrôleur d'édition spécialisé pour une prison.
         * @param priosn Prison à éditer.
         * @param parent QWidget parent de la QDialog.
         */
        EditionEmplacement(Prison* prison,
                           QWidget* parent);
        
        
        
        /**
         * Construit un contrôleur d'édition spécialisé pour un service.
         * @param service Service à éditer.
         * @param nombreServices Nombre total de services sur le plateau.
         * @param parent QWidget parent de la QDialog.
         */
        EditionEmplacement(Service* service,
                           const int nombreServices,
                           QWidget* parent);
        
        
        
        /**
         * Construit un contrôleur d'édition spécialisé pour un emplacement « Simple visite ».
         * @param simpleVisite Emplacement « Simple visite » à éditer.
         * @param parent QWidget parent de la QDialog.
         */
        EditionEmplacement(SimpleVisite* simpleVisite,
                           QWidget* parent);
        
        
        
        /**
         * Construit un contrôleur d'édition spécialisé pour un emplacement « Taxe ».
         * @param taxe Emplacement « Taxe » à éditer.
         * @param parent QWidget parent de la QDialog.
         */
        EditionEmplacement(Taxe* taxe,
                           QWidget* parent);
        
        
        
        /**
         * Construit un contrôleur d'édition spécialisé pour un terrain.
         * @param terrain Terrain à éditer.
         * @param parent QWidget parent de la QDialog.
         */
        EditionEmplacement(Terrain* terrain,
                           QWidget* parent);
        
        
        
        /**
         * Destructeur.
         */
        ~EditionEmplacement();
        
        
        
        /**
         * Lance la fenêtre d'édition de l'emplacement.
         */
        bool executer();
        
        
        
    private:
        /**
         * Helper aménageant les widgets dans la fenêtre d'édition.
         */
        void amenageFenetre();
};

#endif // EDITIONEMPLACEMENT_HPP
