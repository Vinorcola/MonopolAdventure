#ifndef EMPLACEMENTINFOS_HPP
#define EMPLACEMENTINFOS_HPP

#include <QGraphicsScene>
#include <QHash>
#include <QPixmap>
#include <QPoint>
#include <QString>

#include "global.hpp"

#include "donnees/graphismes/GraphismeEmplacement.hpp"
#include "donnees/graphismes/GraphismeEmplacementInfos.hpp"





/**
 * @class Emplacement Emplacement.hpp donnees/emplacements/Emplacement.hpp
 * Emplacement contient les informations éditables communes à tous les emplacements d'un plateau.
 */
class Emplacement
{
    private:
        const Type::Emplacement m_type;///< Indique le type d'emplacement.
        QString m_titre;///< Titre de l'emplacement.
        QString m_sousTitre;///< Sous-titre de l'emplacement.
        QString m_description;///< Description de l'emplacement.
        QPixmap m_image;///< Image de l'emplacement.
        
        
        
    protected:
        /**
         * Structure de données servant à la déclaration des scène sur lesquelles est affiché l'emplacement.
         */
        class ElementGraphique
        {
            public:
                GraphismeEmplacement* elementGraphique;///< Élement graphique.
                QPoint coordonnees;///< Coordonnées de l'élément dans la scène.
                int rotation;///< Rotation de l'élément dans la scène.
        };
        
        
        
        const GraphismeEmplacementInfos& m_graphismeInfos;///< Informations concernant le graphisme.
        bool m_enCoin;///< Indique si l'emplacement se situe dans un coin du plateau.
        QHash<QGraphicsScene*, ElementGraphique> m_scenes;///< Table des éléments graphiques et de leur scène.
        
        
        
    public:
        /**
         * Construit un emplacement par défaut.
         * @param type Précise le type d'emplacement.
         * @param graphismeInfos Informations concernant le graphisme.
         */
        Emplacement(Type::Emplacement type,
                    const GraphismeEmplacementInfos& graphismeInfos);
        
        
        
        /**
         * Destructeur virtuel.
         */
        virtual ~Emplacement();
        
        
        
        /**
         * Renseigne le type d'emplacement.
         * @return Type d'emplacement.
         */
        Type::Emplacement getType() const;
        
        
        
        /**
         * Renseigne le titre de l'emplacement.
         * @return Titre de l'emplacement.
         */
        const QString& getTitre() const;
        
        
        
        /**
         * Remplace le titre de l'emplacement par @a titre.
         * @param titre Nouveau titre.
         */
        void editTitre(const QString& titre);
        
        
        
        /**
         * Renseigne le sous-titre de l'emplacement.
         * @return Sous-titre de l'emplacement.
         */
        const QString& getSousTitre() const;
        
        
        
        /**
         * Remplace le sous-titre de l'emplacement par @a sousTitre.
         * @param sousTitre Nouveau sous-titre.
         */
        void editSousTitre(const QString& sousTitre);
        
        
        
        /**
         * Renseigne la description de l'emplacement.
         * @return Description de l'emplacement.
         */
        const QString& getDescription() const;
        
        
        
        /**
         * Remplace la description de l'emplacement par @a description.
         * @param description Nouvelle description.
         */
        void editDescription(const QString& description);
        
        
        
        /**
         * Retourne l'image de l'emplacement.
         * @return Image de l'emplacement.
         */
        const QPixmap& getImage() const;
        
        
        
        /**
         * Remplace l'image de l'emplacement par @a image.
         * @param image Nouvelle image.
         */
        void editImage(const QPixmap& image);
        
        
        
        /**
         * Notifie à l'emplacement qu'il se situe dans un coin du plateau.
         */
        void setEmplacementEnCoin();
        
        
        
        /**
         * Notifie à l'emplacement qu'il ne se situe pas dans un coin du plateau.
         */
        void setEmplacementNormal();
        
        
        
        /**
         * Déclare l'emplacement sur une scène.
         * @param scene Scène sur laquelle afficher l'emplacement.
         * @param coordonnees Coordonnées de la position de l'emplacement sur la scène.
         * @param rotation Rotation de l'emplacement sur la scène.
         */
        void registerScene(QGraphicsScene* scene,
                           const QPoint& coordonnees = QPoint(),
                           const int rotation = 0);
        
        
        
        /**
         * Dessine l'emplacement sur la scène passée en argument.
         * @param scene Scène sur laquelle mettre à jour l'affichage (0 pour toutes).
         * 
         * L'emplacement va garder en mémoire les scènes sur lesquelles il est affiché. Il va créer un nouveau QGraphicsItem à chaque fois qu'il doit être affiché sur une nouvelle scène. Pour déclarer une scène, il faut appeler au préalale la méthode Emplacement::registerScene() afin de renseigner les coordonnées et la rotation de l'emplacement sur la scène.
         * Pour actualiser l'affichage graphique de l'emplacement sur une scène précise, il suffit d'appeler cette méthode avec la scène en paramètre. Si aucune scène n'est passée en argument, toutes les scènes sont mises à jour.
         */
        void dessiner(QGraphicsScene* scene = 0);
        
        
        
    protected:
        /**
         * Méthode virtuelle permettant à chaque classe héritant de renvoyer un prix personnalisé.
         * 
         * Cette méthode est réimplémentée dans les emplacements Propriete et Taxe. Pour plus de facilité, elle renvoie un QString directement utilisable.
         */
        virtual QString helper_getPrix() const;
        
        
        
        /**
         * Méthode virtuelle permettant à chaque classe héritant de renvoyer une couleur personnalisée.
         * 
         * Cette méthode est réimplémentée dans les emplacements Terrain.
         */
        virtual QColor helper_getCouleurRegroupement() const;
};

#endif // EMPLACEMENTINFOS_HPP
