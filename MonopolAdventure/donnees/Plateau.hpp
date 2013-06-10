#ifndef PLATEAUINFOS_HPP
#define PLATEAUINFOS_HPP

#include <QDialog>
#include <QDialogButtonBox>
#include <QFile>
#include <QGraphicsScene>
#include <QMessageBox>
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
         * Renseigne le titre du plateau.
         * @return Titre du plateau.
         */
        const QString& getTitre() const;
        
        
        
        /**
         * Renseigne la taille du plateau (en nombre d'emplacements).
         * @return Taille du plateau (en nombre d'emplacements).
         */
        const QSize& getTaille() const;
        
        
        
        /**
         * Renseigne la devise utilisée sur le plateau.
         * @return Devise utilisée sur le plateau.
         */
        const QString& getDevise();
        
        
        
        /**
         * Renseigne le coefficient à appliquer sur les prix.
         * @return Coefficient à appliquer sur les prix.
         */
        quint32 getCoefficientPrix() const;
        
        
        
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
         * Renseigne la couleur de fond du plateau.
         * @return Couleur de fond du plateau.
         */
        const QColor& getCouleurFond() const;
        
        
        
        /**
         * Retourne l'image du centre du plateau.
         * @return Image du centre du plateau.
         */
        const QPixmap& getImage() const;
        
        
        
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
         * Renseigne la hauteur du rectangle de couleur des terrains (en pixel).
         * @return Hauteur du rectangle de couleur des terrains (en pixel).
         */
        quint16 getHauteurRectangleCouleur() const;
        
        
        
        /**
         * Retourne le crayon à utiliser pour dessiner les bordures des emplacements sur le plateau.
         * @return Crayon à utiliser pour dessiner les bordures des emplacements sur le plateau.
         */
        const QPen& getCrayonBordureEmplacement() const;
        
        
        
        /**
         * Renseigne la marge minimale entre le texte et la bordure de l'emplacement (en pixel).
         * @return Marge minimale entre le texte et la bordure de l'emplacement (en pixel).
         */
        quint8 getMarge() const;
        
        
        
        /**
         * Renseigne la couleur de fond des emplacements.
         * @return Couleur de fond des emplacements.
         */
        const QColor& getCouleurFondEmplacement() const;
        
        
        
        
        /**
         * Retourne la fonte à utiliser pour afficher le titre des emplacements sur le plateau.
         * @return Fonte à utiliser pour afficher le titre des emplacements sur le plateau.
         */
        const QFont& getFonteTitreEmplacement() const;
        
        
        
        /**
         * Retourne la fonte à utiliser pour afficher le sous-titre des emplacements sur le plateau.
         * @return Fonte à utiliser pour afficher le sous-titre des emplacements sur le plateau.
         */
        const QFont& getFonteSousTitreEmplacement() const;
        
        
        
        /**
         * Retourne la fonte à utiliser pour afficher la descripiton des emplacements sur le plateau.
         * @return Fonte à utiliser pour afficher la descripiton des emplacements sur le plateau.
         */
        const QFont& getFonteDescriptionEmplacement() const;
        
        
        
        /**
         * Retourne la fonte à utiliser pour afficher le prix des propriétés ou des emplacements taxes sur le plateau.
         * @return Fonte à utiliser pour afficher le prix des propriétés ou des emplacements taxes sur le plateau.
         */
        const QFont& getFontePrixEmplacement() const;
        
        
        
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
         * Renseigne l'emplacement identifié par @a id.
         * @param id Identifiant de l'emplacement (dans la liste du plateau).
         * @return Emplacement.
         */
        const Emplacement* getEmplacement(quint8 id) const;
        
        
        
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
         * Charge le plateau depuis un fichier.
         * @param cheminFichier Chemin vers le fichier à enregistrer.
         * @return @b @c true si le plateau a été chargé correctement, @b @c false sinon.
         * 
         * Détruit tout ce qui était dans le plateau auparavant.
         */
        bool loadFromFile(QString cheminFichier = QString("save") + EXTENSION_FICHIER);
        
        
        
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
