#ifndef PLATEAUINFOS_HPP
#define PLATEAUINFOS_HPP

#include <QDialog>
#include <QDialogButtonBox>
#include <QFile>
#include <QGraphicsScene>
#include <QPixmap>
#include <QSize>
#include <QString>
#include <QtCore/qmath.h>

class MainWindow;
#include "donnees/cartes/PileCartes.hpp"
#include "donnees/emplacements/CompagnieTransport.hpp"
#include "donnees/emplacements/Regroupement.hpp"
#include "donnees/emplacements/Service.hpp"
#include "donnees/graphismes/GraphismeEmplacementInfos.hpp"
#include "donnees/Regle.hpp"





/**
 * @class Plateau Plateau.hpp donnees/Plateau.hpp
 * Cette classe représente un plateau de jeu dans MonopolAdventure.
 * 
 * Le plateau est la base de tout dans MonopolAdventure : il contient les emplacements, les cartes et toutes les autres informations nécessaires. De plus, il hérite de QGraphicsScene. Il va donc pouvoir être affiché à l'écran, et va s'occuper de rendre les différents emplacements qu'il contient en les aménageant lui-même.
 * 
 * Un plateau peut être enregistré dans un fichier.
 */
class Plateau : public QGraphicsScene
{
        Q_OBJECT
        
        
    private:
        MainWindow* m_parent;///< Fenêtre parent, nécessaire pour apparenter les diverses fenêtre de dialogue.
        bool m_sauvegarde;///< Indique si le plateau est sauvegardé ou non.
        
        QString m_titre;///< Titre du plateau.
        QSize m_taille;///< Taille du plateau (en nombre d'emplacements).
        QString m_devise;///< Devise utilisée sur le plateau.
        /**
         * Coefficient utilisé pour les prix.
         * 
         * Peut aller de 0 à 8. Le coefficient réel vaut 10^m_nombreCoefficient. Par exemple, si m_prixCoefficient vaut 2, le coefficient est de 100, si m_prixCoefficient vaut 5, le coefficient est de 100 000.
         * 
         * En interne, les prix sont enregistrés dans des quint16 et doivent être compris entre 0 et 50 000. Il est donc possible d'appliquer un coefficient à l'affichage de tous les prix afin d'obtenir 20M € (au lieu de 200 €) en passant par la case Départ par exemple.
         */
        quint8 m_prixCoefficient;
        /**
         * Affichage complet des prix.
         * 
         * Si cet attribut vaut @b @c true, les prix sont affichés intégralement. Par exemple, avec un coefficient très gros :
         * @li 1 500 000 000;
         * @li 20 000 000 ;
         * @li 14 500 000 ;
         * @li 500 000.
         * 
         * Si cet attribut vaut @b @c false, les prix sont affichés avec des lettres. Par exemple, avec les prix ci-dessus :
         * @li 1 500M ;
         * @li 20M ;
         * @li 14,5M;
         * @li 500k.
         */
        bool m_prixAffichageComplet;
        QColor m_couleurFond;///< Couleur de fond du plateau.
        QPixmap m_image;///< Image au centre du plateau.
        GraphismeEmplacementInfos m_graphismeEmplacement;///< Informations sur les graphismes des emplacements.
        Regle m_regle;///< Règle de jeu associée au plateau.
        
        QList<PileCartes*> m_pilesCartes;///< Liste des piles de cartes du plateau.
        QList<Emplacement*> m_emplacements;///< Liste des emplacements du plateau.
        QList<Regroupement*> m_regroupements;///< Liste des regroupements de terrains.
        
        // Les attributs suivant sont des raccourcis vers certains emplacements. Ils sont tous déjà présent dans m_emplacements.
        QList<CompagnieTransport*> m_compagniesTransport;///< Liste des compagnies de transport du plateau (raccourcis).
        QList<Service*> m_services;///< Liste des services du plateau (raccourcis).
        
        
        
    public:
        /**
         * Construit un nouveau plateau vide et non initialisé.
         * @param parent Fenêtre parent (utilisé pour apparenter les diverses fenêtres dialogue).
         */
        Plateau(MainWindow* parent);
        
        
        
        /**
         * Destructeur.
         * 
         * Détruit tous les emplacements, les piles de cartes et les regroupements.
         */
        ~Plateau();
        
        
        
        /**
         * Dessine tous les emplacements sur le plateau.
         * 
         * Configure pour chaque emplacement sa position et sa rototion en fonction de sa place sur le plateau. Puis récupère l'élément graphique de l'emplacement.
         */
        void dessiner();
        
        
        
        /**
         * Indique si le plateau est sauvegardé.
         * @return @b @c true si le plateau est sauvegardé, @b @c false sinon.
         */
        bool isSave();
        
        
        
        /**
         * Renseigne le titre du plateau.
         * @return Titre du plateau.
         */
        const QString& getTitre() const;
        
        
        
        /**
         * Change le titre du plateau.
         * @param titre Nouveau titre.
         */
        void editTitre(const QString& titre);
        
        
        
        /**
         * Renseigne la taille du plateau (en nombre d'emplacements).
         * @return Taille du plateau (en nombre d'emplacements).
         */
        const QSize& getTaille() const;
        
        
        
        /**
         * Change la taille du plateau.
         * @param taille Nouvelle taille (en nombre d'emplacements).
         * @note La taille doit être comprise entre 3x3 et 50x50 inclus, pour éviter la création de plateau inutilement trop grand.
         */
        void editTaille(const QSize& taille);
        
        
        
        /**
         * Renseigne la devise utilisée sur le plateau.
         * @return Devise utilisée sur le plateau.
         */
        const QString& getDevise();
        
        
        
        /**
         * Change la devise utilisée sur le plateau.
         * @param devise Nouvelle devise.
         */
        void editDevise(const QString& devise);
        
        
        
        /**
         * Renseigne le coefficient à appliquer sur les prix.
         * @return Coefficient à appliquer sur les prix.
         */
        quint32 getCoefficientPrix() const;
        
        
        
        /**
         * Change le coefficient à appliquer sur les prix.
         * @param coefficient Nouveau coefficient.
         * @note Coefficients acceptés : 1, 10, 100, 1 000, 10 000, 100 000, 1 000 000, 10 000 000, 100 000 000.
         */
        void editCoefficientPrix(const quint32 coefficient);
        
        
        
        /**
         * Indique si les prix sont à afficher en intégralité, ou en forme compressée.
         * 
         * Si cette méthode retourne @b @c true, les prix sont à afficher intégralement. Par exemple, avec un coefficient très gros :
         * @li 1 500 000 000;
         * @li 20 000 000 ;
         * @li 14 500 000 ;
         * @li 500 000.
         * 
         * Si cette méthode retourne @b @c false, les prix sont à afficher avec des lettres. Par exemple, avec les prix ci-dessus :
         * @li 1 500M ;
         * @li 20M ;
         * @li 14,5M;
         * @li 500k.
         * 
         * @return @b @c true si les nombres sont à afficher en intégralité.
         */
        bool affichageIntegraleActif() const;
        
        
        
        /**
         * Active ou désactive l'affichage intégrale des prix.
         * 
         * Si l'affichage intégrale est activé, les prix sont affichés intégralement. Par exemple, avec un coefficient très gros :
         * @li 1 500 000 000;
         * @li 20 000 000 ;
         * @li 14 500 000 ;
         * @li 500 000.
         * 
         * Si l'affichage intégrale est désactivé, les nombres sont affichés avec des lettres. Par exemple, avec les prix ci-dessus :
         * @li 1 500M ;
         * @li 20M ;
         * @li 14,5M;
         * @li 500k.
         * 
         * @param actif Indique si l'affichage intégrale des prix doit être activé ou désactivé.
         */
        void editAffichageIntegrale(const bool actif);
        
        
        
        /**
         * Renseigne la couleur de fond du plateau.
         * @return Couleur de fond du plateau.
         */
        const QColor& getCouleurFond() const;
        
        
        
        /**
         * Change la couleur de fond du plateau.
         * @param couleur Nouvelle couleur.
         */
        void editCouleurFond(const QColor& couleur);
        
        
        
        /**
         * Retourne l'image du centre du plateau.
         * @return Image du centre du plateau.
         */
        const QPixmap& getImage() const;
        
        
        
        /**
         * Change l'image du centre du plateau.
         * @param image Nouvelle image.
         */
        void editImage(const QPixmap& image);
        
        
        
        /**
         * Renseigne la taille des emplacements normaux sur le plateau (en pixel).
         * @return Taille des emplacements normaux sur le plateau (en pixel).
         */
        const QSize& getTailleEmplacementsNormaux() const;
        
        
        
        /**
         * Retourne la taille des emplacements en coin de plateau (en pixel).
         * @return Taille des emplacements en coin de plateau (en pixel).
         */
        const QSize& getTailleEmplacementsEnCoin() const;
        
        
        
        /**
         * Change la taille des emplacements sur le plateau.
         * @param taille Nouvelle taile (en pixel).
         * @note La taille d'un emplacement doit être suppérieur à 50x50.
         */
        void editTailleEmplacements(const QSize& taille);
        
        
        
        /**
         * Renseigne la hauteur du rectangle de couleur des terrains (en pixel).
         * @return Hauteur du rectangle de couleur des terrains (en pixel).
         */
        quint16 getHauteurRectangleCouleur() const;
        
        
        
        /**
         * Change la hauteur du rectangle de couleur des terrains.
         * @param hauteur Nouvelle hauteur (en pixel).
         */
        void editHauteurRectangleCouleur(const quint16 hauteur);
        
        
        
        /**
         * Retourne le crayon à utiliser pour dessiner les bordures des emplacements sur le plateau.
         * @return Crayon à utiliser pour dessiner les bordures des emplacements sur le plateau.
         */
        const QPen& getCrayonBordureEmplacement() const;
        
        
        
        /**
         * Change le crayon utilisé pour dessiner les bordures des emplacements sur le plateau.
         * @param crayon Nouveau crayon.
         */
        void editCrayonBordureEmplacement(const QPen& crayon);
        
        
        
        /**
         * Renseigne la marge minimale entre le texte et la bordure de l'emplacement (en pixel).
         * @return Marge minimale entre le texte et la bordure de l'emplacement (en pixel).
         */
        quint8 getMarge() const;
        
        
        
        /**
         * Change la marge minimale entre le texte et la bordure de la case (en pixel).
         * @param marge Nouvelle marge.
         */
        void editMarge(quint8 marge);
        
        
        
        /**
         * Renseigne la couleur de fond des emplacements.
         * @return Couleur de fond des emplacements.
         */
        const QColor& getCouleurFondEmplacement() const;
        
        
        
        /**
         * Change la couleur de fond des emplacements.
         * @param couleur Nouvelle couleur.
         */
        void editCouleurFondEmplacement(const QColor& couleur);
        
        
        
        
        /**
         * Retourne la fonte à utiliser pour afficher le titre des emplacements sur le plateau.
         * @return Fonte à utiliser pour afficher le titre des emplacements sur le plateau.
         */
        const QFont& getFonteTitreEmplacement() const;
        
        
        
        /**
         * Change la fonte utilisée pour afficher le titre des emplacements sur le plateau.
         * @param fonte Nouvelle fonte.
         */
        void editFonteTitreEmplacement(const QFont& fonte);
        
        
        
        /**
         * Retourne la fonte à utiliser pour afficher le sous-titre des emplacements sur le plateau.
         * @return Fonte à utiliser pour afficher le sous-titre des emplacements sur le plateau.
         */
        const QFont& getFonteSousTitreEmplacement() const;
        
        
        
        /**
         * Change la fonte utilisée pour afficher le sous-titre des emplacements sur le plateau.
         * @param fonte Nouvelle fonte.
         */
        void editFonteSousTitreEmplacement(const QFont& fonte);
        
        
        
        /**
         * Retourne la fonte à utiliser pour afficher la descripiton des emplacements sur le plateau.
         * @return Fonte à utiliser pour afficher la descripiton des emplacements sur le plateau.
         */
        const QFont& getFonteDescriptionEmplacement() const;
        
        
        
        /**
         * Change la fonte utilisée pour afficher la description des emplacements sur le plateau.
         * @param fonte Nouvelle fonte.
         */
        void editFonteDescriptionEmplacement(const QFont& fonte);
        
        
        
        /**
         * Retourne la fonte à utiliser pour afficher le prix des propriétés ou des emplacements taxes sur le plateau.
         * @return Fonte à utiliser pour afficher le prix des propriétés ou des emplacements taxes sur le plateau.
         */
        const QFont& getFontePrixEmplacement() const;
        
        
        
        /**
         * Change la fonte utilisée pour afficher le prix des propriétés ou des emplacements taxes sur le plateau.
         * @param fonte Nouvelle fonte.
         */
        void editFontePrixEmplacement(const QFont& fonte);
        
        
        
        /**
         * Retourne les règles de jeu associées au plateau.
         * @return Règles de jeu associées au plateau.
         */
        const Regle& getRegle() const;
        
        
        
        /**
         * Fourni la liste des regroupements du plateau.
         * @return Liste des regroupements du plateau.
         */
        const QList<Regroupement*>& getListeRegroupement();
        
        
        
        /**
         * Renseigne un identifiant de l'emplacement par rapport à sa position sur le plateau (identifiant de l'emplacement dans la liste du plateau).
         * @param emplacement Emplacement à identifier.
         * @return Identifiant de l'emplacement.
         * 
         * Cette méthode est utilisée pour identifier un emplacement dans la sauvegarde de certaines données dans un fichier.
         */
        quint8 getIdentifiantEmplacement(const Emplacement* emplacement) const;
        
        
        
        /**
         * Renseigne l'emplacement identifié par @a id.
         * @param id Identifiant de l'emplacement (dans la liste du plateau).
         * @return Emplacement.
         */
        const Emplacement* getEmplacement(quint8 id) const;
        
        
        
        /**
         * Renseigne un identifiant de la pile de cartes (identifiant de la pile de cartes dans la liste du plateau).
         * @param pileCartes Pile de cartes à identifier.
         * @return Identifiant de la pile de cartes.
         * 
         * Cette méthode est utiliser pour identifier une pile de cartes dans la sauvegarde de certaines données dans un fichier.
         */
        quint8 getIdentifiantPileCartes(const PileCartes* pileCartes) const;
        
        
        
        /**
         * Renseigne la pile de cartes identifiée par @a id.
         * @param id Identifiant de la pile de cartes (dans la liste du plateau).
         * @return Pile de cartes.
         */
        const PileCartes* getPileCartes(quint8 id) const;
        
        
        
        /**
         * Renseigne le nombre de propriété sur le plateau.
         * @return Nombre de propriété du plateau.
         */
        int getNombrePropriete() const;
        
        
        
        /**
         * Sauvegarde le plateau dans le fichier désigné.
         * @param cheminFichier Chemin vers le fichier à enregistrer.
         */
        void saveInFile(QString cheminFichier = "save.plt");
        
        
        
        /**
         * Charge le plateau depuis un fichier.
         * @param cheminFichier Chemin vers le fichier à enregistrer.
         * 
         * Détruit tout ce qui était dans le plateau auparavant.
         */
        void loadFromFile(QString cheminFichier = "save.plt");
        
        
        
    public slots:
        /**
         * Ouvre une fenêtre de dialogue pour l'édition des informations générales du plateau.
         */
        void editInfosGenerales();
        
        
        
        /**
         * Ouvre une fenêtre de dialogue pour l'édition des informations concernant les prix.
         */
        void editAffichagePrix();
        
        
        
        /**
         * Ouvre une fenêtre de dialogue pour l'édition des regroupements.
         */
        void editListeRegroupements();
        
        
        
        /**
         * Ouvre une fenêtre de dialogue pour l'édition des cartes et des piles de cartes.
         */
        void editListePilesCartes();
        
        
        
        /**
         * Ouvre une fenêtre de dialogue pour l'édition des graphismes des emplacements.
         */
        void editGraphismeEmplacement();
        
        
        
        /**
         * Ouvre une fenêtre de changement de type ou une fenêtre d'édition des informations de l'emplacement.
         * @param emplacement Emplacement concerné.
         * 
         * Cette méthode contrôle l'état du bouton d'édition de type (cf MainWindow::m_actionEditionTypeEmplacement). Si celui-ci est activé, alors on lance une fenêtre d'édition du type d'emplacement. Sinon, on lance une fenêtre d'édition des informations de l'emplacement.
         */
        void editEmplacement(Emplacement* emplacement);
        
        
        
    private:
        /**
         * Ouvre une fenêtre de dialogue pour l'édition de l'emplacement @a emplacement.
         * @param emplacement Emplacement à éditer.
         */
        void editEmplacementInformations(Emplacement* emplacement);
        
        
        
        /**
         * Affiche la fenêtre de dialogue permettant de changer le type d'emplacement.
         * @param emplacement Emplacement concerné.
         * 
         * Cette méthode contrôle si le changement de type est possible. Certain emplacement ne peuvent par exemple pas être changés : l'emplacement « Départ », la prison, etc.
         * 
         * Si le changement de type est possible, alors, on ouvre la fenêtre de dialogue, puis, si l'utilisateur valide le changement, on appels Plateau::changeTypeEmplacement().
         */
        void editEmplacementType(Emplacement* emplacement);
        
        
        
        /**
         * Change le type d'un emplacement.
         * @param emplacement Emplacement concerné.
         * @param nouveauType Nouveau type d'emplacement demandé.
         * 
         * Cette méthode n'effectue aucune vérification sur l'emplacement concerné. Toutes ces vérifications doivent être faite au préalable.
         */
        void changeTypeEmplacement(Emplacement* emplacement,
                                   Type::Emplacement nouveauType);
        
        
        
        /**
         * Configure un emplacement avant de pouvoir le dessiner sur le plateau.
         * @param emplacement Emplacement a dessiner.
         * 
         * Configure la position de l'emplacement, sa rotation, et s'il doit être dessiner en tant qu'emplacement « normal » ou emplacement « en coin ».
         */
        void helper_dessineEmplacement(Emplacement* emplacement);
        
        
        
        /**
         * Indique si l'emplacement est situé dans un coin du plateau.
         * @param id Numéro d'identification de l'emplacement.
         * @return @b @c true si l'emplacement est situé en coin de plateau, @b @c false sinon.
         */
        bool helper_isEmplacementEnCoin(int id) const;
        
        
        
        /**
         * Retourne les coordonnées de l'emplacement sur le plateau.
         * @param id Numéro d'identification de l'emplacement.
         * @return Coordonnées de l'emplacement sur le plateau.
         */
        QPoint helper_getPositionEmplacement(int id) const;
        
        
        
        /**
         * Retourne l'angle de rotation (en °) de l'emplacement sur le plateau.
         * @param id Numéro d'identification de l'emplacement.
         * @return Angle de rotation (en °) de l'emplacement sur le plateau.
         */
        int helper_getRotationEmplacement(int id) const;
};

#endif // PLATEAUINFOS_HPP
