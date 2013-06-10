#ifndef GRAPHISMEEMPLACEMENT_HPP
#define GRAPHISMEEMPLACEMENT_HPP

#define MARGE_MIN_DIAGONALE 50  /* Cette marge représente une marge minimale entre le coin suppérieur et le haut du
                                 * titre (ou sous-titre) dans un emplacement en coin de plateau.
                                 */

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QString>
#include <QtCore/qmath.h>

class Emplacement;
#include "donnees/graphismes/GraphismeEmplacementInfos.hpp"





/**
 * @class GraphismeEmplacement GraphismeEmplacement.hpp donnees/graphismes/GraphismeEmplacement.hpp
 * Cette classe permet l'affichage graphique des emplacements sur le plateau.
 * 
 * Elle est directement liées à la classe Emplacement. Sa séparation est expliqué plus en détail sur la page de documentation de cette classe.
 * 
 * GraphismeEmplacement hérite directement de QGraphicsRectItem et va ainsi pouvoir être dessinée sur le plateau ou dans des fenêtres annexes afin de représenter les emplacements.
 * 
 * @todo Détailler le fonctionnement de cet élément.
 */
class GraphismeEmplacement : public QObject, public QGraphicsRectItem
{
        Q_OBJECT
        
        
    private:
        const GraphismeEmplacementInfos& m_infosGraphiques;///< Détails du graphisme des emplacements.
        Emplacement* const m_emplacement;///< Pointeur vers l'emplacement à dessiner.
        
        bool m_eventOn;///< Indique si les événement (clique sur l'emplacement) sont activés.
        QPoint m_position;///< Position à laquelle est dessiné l'élément sur la scène.
        int m_rotation;///< Angle de rotation à appliquer à l'élément avant de l'afficher sur la scène.
        QString m_titre;///< Titre à afficher sur l'emplacement.
        QString m_sousTitre;///< Sous-titre à afficher sur l'emplacement.
        QString m_description;///< Description à afficher sur l'emplacement.
        QString m_prix;///< Texte directement utilisable représentant le prix d'une propriété ou le montant d'une taxe.
        QPixmap m_image;///< Image à afficher sur l'emplacement.
        QColor m_couleurRegroupement;///< Couleur du regroupement auquel appartient le terrain.
        bool m_emplacementEnCoin;///< Indique si l'emplacement à représenter se situe dans un coin du plateau.
        
        QGraphicsRectItem* m_graphCouleur;///< Élément graphique représentant la couleur du regroupement.
        QGraphicsEllipseItem* m_graphCouleurEnCoin;///< Élément graphique représentant la couleur du regroupement pour un emplacement en coin.
        QGraphicsTextItem* m_graphTitre;///< Élément graphique représentant le titre.
        QGraphicsTextItem* m_graphSousTitre;///< Élément graphique représentant le sous-titre.
        QGraphicsTextItem* m_graphDescription;///< Élément graphique représentant la descripiton.
        QGraphicsTextItem* m_graphPrix;///< Élément graphique représentant le prix.
        QGraphicsPixmapItem* m_graphImage;///< Élément graphique représentant l'image.
        
        
        
    public:
        /**
         * Construit un nouvel objet graphique.
         * @param infosGraphiques Détails du graphisme des emplacements.
         * @param emplacement Pointeur vers l'emplacement à dessiner.
         * @param position Position à laquelle est dessiné l'élément sur la scène.
         * @param rotation Angle de rotation à appliquer à l'élément avant de l'afficher sur la scène.
         * @param titre Titre à afficher sur l'emplacement.
         * @param sousTitre Sous-titre à afficher sur l'emplacement.
         * @param description Description à afficher sur l'emplacement.
         * @param prix Texte directement utilisable représentant le prix d'une propriété ou le montant d'une taxe.
         * @param image Image à afficher sur l'emplacement.
         * @param couleurRegroupement Couleur du regroupement auquel appartient le terrain.
         * @param emplacementEnCoin Indique si l'emplacement à représenter se situe dans un coin du plateau.
         * @param eventOn Indique si les événement (clique sur l'emplacement) sont activés.
         * @note Le constructeur dessine automatiquement l'élément graphique. Veillez donc à renseigner le maximum d'attributs plutôt que de faire appel aux différentes méthodes @c updateXXX().
         */
        GraphismeEmplacement(const GraphismeEmplacementInfos& infosGraphiques,
                             Emplacement* const emplacement,
                             const QPoint& position,
                             const int rotation,
                             const QString& titre,
                             const QString& sousTitre = QString(),
                             const QString& description = QString(),
                             const QString& prix = QString(),
                             const QPixmap& image = QPixmap(),
                             const QColor& couleurRegroupement = QColor(),
                             const bool emplacementEnCoin = false,
                             const bool eventOn = false);
        
        
        
        /**
         * Met à jour la couleur du regroupement.
         * @param couleur Nouvelle couleur.
         */
        void updateCouleurRegroupement(const QColor& couleur);
        
        
        
        /**
         * Met à jour l'affichage du titre.
         * @param titre Nouveau titre.
         */
        void updateTitre(const QString& titre);
        
        
        
        /**
         * Met à jour l'affichage du sous-titre.
         * @param sousTitre Nouveau sous-titre.
         */
        void updateSousTitre(const QString& sousTitre);
        
        
        
        /**
         * Met à jour l'image.
         * @param image Nouvelle image.
         */
        void updateImage(const QPixmap& image);
        
        
        
        /**
         * Met à jour l'affichage de la description.
         * @param description Nouvelle description.
         */
        void updateDescription(const QString& description);
        
        
        
        /**
         * Met à jour l'affichage du prix.
         * @param prix Nouveau prix.
         */
        void updatePrix(const QString& prix);
        
        
        
        /**
         * Redessine tous les éléments graphiques.
         * 
         * Cette méthode doit être appelée lorsque GraphismeInfos est modifiée.
         */
        void updateAffichage();
        
        
        
    signals:
        /**
         * Ce signal est envoyé lorsque que l'utilisateur a demandé une fenêtre d'édition sur l'emplacement associé.
         * @param emplacement Emplacement à éditer.
         */
        void editEmplacement(Emplacement* emplacement);
        
        
        
    private:
        /**
         * Met à jour l'affichage de la couleur du regroupement.
         */
        void updateCouleurRegroupement();
        
        
        
        /**
         * Met à jour l'affichage du titre.
         */
        void updateTitre();
        
        
        
        /**
         * Met à jour l'affichage du sous-titre.
         */
        void updateSousTitre();
        
        
        
        /**
         * Met à jour l'affichage de l'image.
         */
        void updateImage();
        
        
        
        /**
         * Met à jour l'affichage de la description.
         */
        void updateDescription();
        
        
        
        /**
         * Met à jour l'affichage du prix.
         */
        void updatePrix();
        
        
        
        /**
         * Met à jour l'affichage de la couleur du regroupement pour un emplacement en coin de plateau.
         */
        void updateCouleurRegroupementEnCoin();
        
        
        
        /**
         * Met à jour l'affichage du titre pour un emplacement en coin de plateau.
         */
        void updateTitreEnCoin();
        
        
        
        /**
         * Met à jour l'affichage du sous-titre pour un emplacement en coin de plateau.
         */
        void updateSousTitreEnCoin();
        
        
        
        /**
         * Met à jour l'affichage de l'image pour un emplacement en coin de plateau.
         * 
         * @note Attention : contrairement à tous les textes, aucun angle de rotation n'est appliquée à l'image.
         */
        void updateImageEnCoin();
        
        
        
        /**
         * Met à jour l'affichage de la description pour un emplacement en coin de plateau.
         */
        void updateDescriptionEnCoin();
        
        
        
        /**
         * Met à jour l'affichage du prix pour un emplacement en coin de plateau.
         */
        void updatePrixEnCoin();
        
        
        
        /**
         * Met à jour l'affichage du titre pour un emplacement « Simple visite » en coin de plateau.
         */
        void updateTitreSimpleVisite();
        
        
        
        /**
         * Met à jour l'affichage du sous-titre pour un emplacement « Simple visite » en coin de plateau.
         */
        void updateSousTitreSimpleVisite();
        
        
        
        /**
         * Met à jour l'affichage de l'image pour un emplacement « Simple visite » en coin de plateau.
         */
        void updateImageSimpleVisite();
        
        
        
        /**
         * Configure l'affichage de la couleur du regroupement.
         * 
         * @note Cette méthode gère aussi le positionnement de l'élément graphique. Il n'y a donc pas de méthode GraphismeEmplacement::setupCouleurRegroupement().
         */
        void setupCouleurRegroupement();
        
        
        
        /**
         * Configure l'affichage du titre.
         */
        void setupTitre();
        
        
        
        /**
         * Configure l'affichage du sous-titre.
         */
        void setupSousTitre();
        
        
        
        /**
         * Configure l'affichage de l'image.
         */
        void setupImage();
        
        
        
        /**
         * Configure l'affichage du description.
         */
        void setupDescription();
        
        
        
        /**
         * Configure l'affichage du prix.
         */
        void setupPrix();
        
        
        
        /**
         * Positionne @c m_graphTitre.
         */
        void positionneTitre();
        
        
        
        /**
         * Positionne @c m_graphSousTitre.
         */
        void positionneSousTitre();
        
        
        
        /**
         * Positionne @c m_graphImage.
         */
        void positionneImage();
        
        
        
        /**
         * Positionne @c m_graphDescription.
         */
        void positionneDescription();
        
        
        
        /**
         * Positionne @c m_graphPrix.
         */
        void positionnePrix();
        
        
        
        /**
         * Modifie le QGraphicsTextItem pour qu'il affiche correctement le texte @a texte.
         * @param item Item à modifier.
         * @param texte Texte à afficher.
         * @param font Police utilisée.
         * @param couleur Couleur du texte.
         */
        void helper_setupGraphicsTextItem(QGraphicsTextItem* item,
                                          const QString& texte,
                                          const QFont& font,
                                          const QColor& couleur = QColor(0, 0, 0));
        
        
        
        /**
         * Active la boucle d'événement.
         * 
         * Cette méthode ne fait rien, mais elle est nécessaire pour activer la réception des événements sur l'emplacement.
         */
        void mousePressEvent(QGraphicsSceneMouseEvent* event);
        
        
        
        /**
         * Détecte un clic gauche de la souris (si m_eventOn est @b @c true).
         */
        void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};

#endif // GRAPHISMEEMPLACEMENT_HPP
