#ifndef EDITIONEMPLACEMENT_HPP
#define EDITIONEMPLACEMENT_HPP

#include <QDialog>
#include <QDialogButtonBox>
#include <QTabWidget>
#include <QVBoxLayout>

class EmplacementEditWidget;
class CompagnieTransport;
class Deplacement;
class Emplacement;





/**
 * @class EditionEmplacement EditionEmplacement.hpp dialogEdition/EditionEmplacement.hpp
 * Cette classe contrôle l'édition d'un emplacement.
 */
class EditionEmplacement
{
    private:
        QDialog* m_dialog;///< Boîte de dialogue affichant le widget d'édition.
        Emplacement* m_emplacement;///< Emplacement en cours d'édition.
        QTabWidget* m_onglets;///< Onglets d'édition.
        EmplacementEditWidget* m_onglet1;///< 1er onglet (informations générales).
        QWidget* m_onglet2;///< 2ème onglet (dépend du type d'emplacement).
        QWidget* m_onglet3;///< 3ème onglet (dépend du type d'emplacement).
        QWidget* m_onglet4;///< 4ème onglet (dépend du type d'emplacement).
        
        
        
    public:
        /**
         * Construit un contrôleur d'édition d'emplacement.
         * @param emplacement Emplacement à éditer.
         * @param parent QWidget parent de la QDialog.
         */
        EditionEmplacement(Emplacement* emplacement,
                           QWidget* parent);
        
        
        
        /**
         * Construit un contrôleur d'édition spécialisé pour un emplacement « Déplacement ».
         * @param deplacement Emplacement « Déplacement » à éditer.
         * @param emplacements Liste des autres emplacements du plateau.
         * @param parent QWidget parent de la QDialog.
         */
        EditionEmplacement(Deplacement* deplacement,
                           const QList<Emplacement*>& emplacements,
                           QWidget* parent);
        
        
        
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
