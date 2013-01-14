#ifndef LISTEPILESCARTESEDITWIDGET_HPP
#define LISTEPILESCARTESEDITWIDGET_HPP

#include <QComboBox>
#include <QPushButton>

#include "dialogEdition/modeles/PileCartesListModel.hpp"
#include "dialogEdition/widgetsEditeurs/PileCartesEditWidget.hpp"




/**
 * @class ListePilesCartesEditWidget ListePilesCartesEditWidget.hpp dialogEdition/widgetsEditeurs/ListePilesCartesEditWidget.hpp
 * Cette classe fournit une interface d'édition pour une liste de piles de cartes.
 */
class ListePilesCartesEditWidget : public QWidget
{
        Q_OBJECT
        
        
    private:
        const QList<Emplacement*>& m_emplacements;///< Liste des emplacements du plateau.
        
        QList<PileCartes*>& m_pilesCartes;///< Liste de piles de cartes éditables.
        PileCartesListModel* m_modelePilesCartes;///< Modèle de données contenant la liste des piles de cartes éditable.
        QComboBox* m_vuePilesCartes;///< Vue permettant de sélectionner la pile de cartes à éditer.
        QPushButton* m_creerPileCartes;///< Bouton demandant la création d'une nouvelle pile de cartes.
        QPushButton* m_supprimerPileCartes;///< Bouton demandant la suppression de la pile de cartes.
        PileCartesEditWidget* m_champPileCartes;///< Champ d'édition d'une pile de cartes.
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition d'une liste de piles de cartes.
         * @param pilesCartes Liste des piles de cartes à éditer.
         * @param emplacements Liste des emplacements du plateau.
         * @param devise Devise du plateau.
         */
        ListePilesCartesEditWidget(QList<PileCartes*>& pilesCartes,
                                   const QList<Emplacement*>& emplacements,
                                   const QString& devise);
        
        
        
    public slots:
        /**
         * Change la pile de cartes en cours d'édition.
         * @param index Index de la pile de cartes à éditer dans le modèle de données.
         */
        void changePileCartesEditee(int index);
        
        
        
        /**
         * Créé une nouvelle pile de cartes et l'ajoute au modèle de données. Puis lance l'édition de cette dernière.
         */
        void createPileCartes();
        
        
        
        /**
         * Supprime une pile de cartes (et toutes les cartes qu'elle contient) du modèle de données. Change la pile de cartes en cours d'édition.
         */
        void deletePileCartes();
};

#endif // LISTEPILESCARTESEDITWIDGET_HPP
