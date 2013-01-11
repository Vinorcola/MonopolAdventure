#ifndef ACTIONEDITWIDGET_HPP
#define ACTIONEDITWIDGET_HPP

#include <QButtonGroup>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QRadioButton>
#include <QScrollArea>
#include <QScrollBar>
#include <QSpinBox>

#include "dialogEdition/donnees/PileCartesData.hpp"
#include "donnees/cartes/Action.hpp"
#include "widgetsSelecteurs/PointerComboBox.hpp"





/**
 * @class ActionEditWidget ActionEditWidget.hpp dialogEdition/widgetsEditeurs/ActionEditWidget.hpp
 * Cette classe fournit une interface d'édition pour des actions.
 */
class ActionEditWidget : public QScrollArea
{
        Q_OBJECT
        
        
    private:
        Action* m_action;///< Action en cours d'édition.
        bool m_slotsInactifs;///< Permet de désactiver temporairement l'effet des slots lors d'une modification des entrées par le programme.
        const QList<Emplacement*>& m_emplacements;///< Référence constante vers la liste des emplacements du plateau.
        const QList<PileCartesData*>& m_pilesCartes;///< Référence constante vers la liste des piles de cartes du plateau.
        
        
        
        QGroupBox* m_groupeDeplacement;///< Groupe sélectionnable permettant la configuration d'un déplacement absolu.
        QRadioButton* m_radioAvance;///< Indique si le joueur avance.
        QRadioButton* m_radioRecule;///< Indique si le joueur recule.
        QButtonGroup* m_groupeRadioDeplacement;///< Champ permettant de configurer le sens de déplacement du joueur.
        PointerComboBox<Emplacement>* m_emplacement;///< Champ permettant de configurer la case sur laquelle se déplacer.
        
        
        
        QGroupBox* m_groupeDeplacementRelatif;///< Groupe sélectionnable permettant la configuration d'un déplacement relatif.
        QRadioButton* m_radioAvanceRelatif;///< Indique si le joueur avance.
        QRadioButton* m_radioReculeRelatif;///< Indique si le joueur recule.
        QButtonGroup* m_groupeRadioDeplacementRelatif;///< Champ permettant de configurer le sens de déplacement du joueur.
        QSpinBox* m_nombreEmplacements;///< Champ permettant de configurer le nombre d'emplacements à se déplacer.
        
        
        
        QGroupBox* m_groupeDeplacementAuProchain;///< Groupe sélectionnable permettant la configuration d'un déplacement à un type d'emplacement.
        QRadioButton* m_radioAvanceAuProchain;///< Indique si le joueur avance.
        QRadioButton* m_radioReculeAuProchain;///< Indique si le joueur recule.
        QButtonGroup* m_groupeRadioDeplacementAuProchain;///< Champ permettant de configurer le sens de déplacement du joueur.
        QComboBox* m_typeEmplacement;///< Champ permettant de configurer le prochain type d'emplacement à se déplacer.
        
        
        
        QGroupBox* m_groupeTransaction;///< Groupe sélectionnable permettant la configuration d'une transaction.
        QRadioButton* m_radioGagne;///< Indique si le joueur gagne l'argent.
        QRadioButton* m_radioPerd;///< Indique si le joueur perd l'argent.
        QButtonGroup* m_groupeRadioArgent;///< Champ permettant de configurer le sens de la transaction.
        QSpinBox* m_montant;///< Champ permettant de configurer le montant de la transaction
        QComboBox* m_destinataire;///< Champ permettant de configurer le destinataire de la transaction.
        
        
        
        QGroupBox* m_groupeReparation;///< Groupe sélectionnable permettant la configuration d'une réparation de constructions.
        QSpinBox* m_montantParMaison;///< Champ permettant de configurer le montant des réparations pour une maison.
        QSpinBox* m_montantParHotel;///< Champ permettant de configurer le montant des réparations pour un hôtel.
        
        
        
        QGroupBox* m_groupePayeOuPioche;///< Groupe sélectionnable permettant la configuration d'une action de type "Paye ou Pioche".
        QSpinBox* m_amende;///< Champ permettant de configurer le montant de l'amende.
        PointerComboBox<PileCartesData>* m_pileCartesPayeOuPioche;///< Champ permettant de configurer la pile de cartes dans laquelle piocher la carte.
        
        
        
        QGroupBox* m_groupePioche;///< Groupe sélectionnable permettant la configuration de la carte à piocher.
        PointerComboBox<PileCartesData>* m_pileCartesPioche;///< Champ permettant de configurer la pile de cartes dans laquelle piocher la carte.
        
        
        
        QGroupBox* m_groupeLiberePrison;///< Groupe sélectionnable permettant la configuration d'une carte de type "Libéré de prison".
        
        
        
    public:
        /**
         * Construit un nouveau widget d'édition d'actions.
         * 
         * @param action Action à éditer.
         * @param emplacements Liste des emplacements du plateau.
         * @param pilesCartes Liste des piles de cartes du plateau.
         */
        ActionEditWidget(Action* action,
                         const QList<Emplacement*>& emplacements,
                         const QList<PileCartesData*>& pilesCartes);
        
        
        
        /**
         * Sauvegarde les changements dans l'action en cours d'édition.
         */
        void sauvegarde();
        
        
        
    private slots:
        /**
         * Réinitialise tous les autres groupes.
         */
        void groupeDeplacement_clicked(bool checked);
        
        
        
        /**
         * Réinitialise tous les autres groupes.
         */
        void groupeDeplacementRelatif_clicked(bool checked);
        
        
        
        /**
         * Réinitialise tous les autres groupes.
         */
        void groupeDeplacementAuProchain_clicked(bool checked);
        
        
        
        /**
         * Réinitialise tous les autres groupes.
         */
        void groupeTransaction_clicked(bool checked);
        
        
        
        /**
         * Réinitialise tous les autres groupes.
         */
        void groupeReparation_clicked(bool checked);
        
        
        
        /**
         * Réinitialise tous les autres groupes.
         */
        void groupePayeOuPioche_clicked(bool checked);
        
        
        
        /**
         * Réinitialise tous les autres groupes.
         */
        void groupePioche_clicked(bool checked);
        
        
        
        /**
         * Réinitialise tous les autres groupes.
         */
        void groupeLibereDePrison_clicked(bool checked);
        
        
        
    private:
        /**
         * Réinitialise les champs du groupe Déplacement absolu.
         */
        void helper_resetGroupeDeplacement();
        
        
        
        /**
         * Réinitialise les champs du groupe Déplacement relatif.
         */
        void helper_resetGroupeDeplacementRelatif();
        
        
        
        /**
         * Réinitialise les champs du groupe Déplacement au prochain.
         */
        void helper_resetGroupeDeplacementAuProchain();
        
        
        
        /**
         * Réinitialise les champs du groupe Mouvement d'argent.
         */
        void helper_resetGroupeTransaction();
        
        
        
        /**
         * Réinitialise les champs du groupe Réparation des constructions.
         */
        void helper_resetGroupeReparation();
        
        
        
        /**
         * Réinitialise les champs du groupe Payer ou piocher.
         */
        void helper_resetGroupePayeOuPioche();
        
        
        
        /**
         * Réinitialise les champs du groupe Piocher.
         */
        void helper_resetGroupePioche();
        
        
        
        /**
         * Réinitialise les champs du groupe Libéré de prison.
         */
        void helper_resetGroupeLibereDePrison();
};

#endif // ACTIONEDITWIDGET_HPP
