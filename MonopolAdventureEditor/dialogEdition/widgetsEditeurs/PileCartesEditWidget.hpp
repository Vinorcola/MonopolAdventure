#ifndef PILECARTESEDITWIDGET_HPP
#define PILECARTESEDITWIDGET_HPP

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>

#include "dialogEdition/EditionCarte.hpp"
#include "donnees/cartes/PileCartes.hpp"





/**
 * @class PileCartesEditWidget PileCartesEditWidget.hpp dialogEdition/widgetsEditeurs/PileCartesEditWidget.hpp
 * Cette classe fournit une interface d'édition pour des piles de cartes.
 */
class PileCartesEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        const QList<Emplacement*>& m_emplacements;///< Liste des emplacements du plateau.
        const QList<PileCartes*>& m_pilesCartes;///< Liste des piles de cartes en cours d'édition.
        const QString& m_devise;///< Devise du plateau.
        
        PileCartes* m_pileCartes;///< Pile de cartes à éditer.
        QLineEdit* m_champTitre;///< Champ d'édition du titre de la pile de cartes.
        QListView* m_vueCartes;///< Vue de la liste des cartes.
        QLabel* m_description;///< Widget affichant la description de la carte.
        QPushButton* m_creerCarte;///< Bouton demandant la création d'une nouvelle carte.
        QPushButton* m_modifierCarte;///< Bouton demandant l'ouverture de la fenêtre d'édition de la carte sélectionnée.
        QPushButton* m_supprimerCarte;///< Bouton demandant la suppression de la carte sélectionnée.
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition de pile de cartes.
         * @param emplacements Liste des emplacements du plateau.
         * @param pilesCartes Liste des piles de cartes en cours d'édition.
         * @param devise Devise du plateau.
         */
        PileCartesEditWidget(const QList<Emplacement*>& emplacements,
                             const QList<PileCartes*>& pilesCartes,
                             const QString& devise);
        
        
        
        /**
         * Edite la pile de carte dans le fichier.
         * @param pileCartes
         */
        void editPileCartes(PileCartes* pileCartes);
        
        
        
    public slots:
        /**
         * Change le titre de la pile de cartes.
         * @param titre Nouveau titre.
         */
        void changeTitre(QString titre);
        
        
        
        /**
         * Créé une nouvelle pile de cartes et l'ajoute au modèle de données. Puis lance la fenêtre d'édition de cette carte.
         */
        void createCarte();
        
        
        
        /**
         * Lance la fenêtre d'édition de la carte sélectionnée.
         */
        void editCarte(int row = -1);
        
        
        
        /**
         * Supprime la carte sélectionnée du modèle de données.
         */
        void deleteCarte();
        
        
        
        /**
         * Indique qu'une autre carte a été sélectionnée dans la liste.
         * @param index Index de la carte.
         */
        void selectedCarteChanged(const QModelIndex& index);
};

#endif // PILECARTESEDITWIDGET_HPP
