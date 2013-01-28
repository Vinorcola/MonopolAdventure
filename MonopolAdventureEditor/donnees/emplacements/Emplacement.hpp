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
 * Cette classe virtuelle représente un emplacement sur le plateau.
 * 
 * Cette classe est la base de tous les types d'emplacements que l'utilisateur peut créer. Elle embarque les fonctionnalité communes, tels que le titre, le sous-titre, une image, etc.
 * 
 * Pour plus de souplesse, Emplacement n'hérite pas directement de QGraphicsRectItem. On a préféré dédier une classe entière à cet élément graphique, puis l'intégrer en tant qu'attribut dans la classe. De cette manière, l'élément graphique n'est créé que si nécessaire (bien que jusqu'à présent, il ai toujours été nécessaire). Mais cela permet quand même de bien séparer les méthodes liées à l'affichage graphique de l'emplacement de celles contrôlant les informations.
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
        const GraphismeEmplacementInfos& m_graphismeInfos;///< Informations concernant le graphisme.
        QGraphicsScene* m_scene;///< Scène sur laquelle sera affiché l'élément graphique.
        GraphismeEmplacement* m_elementGraphique;///< Élement graphique.
        QPoint m_coordonnees;///< Coordonnées de l'élément dans la scène.
        int m_rotation;///< Rotation de l'élément dans la scène.
        bool m_enCoin;///< Indique si l'emplacement se situe dans un coin du plateau.
        
        
        
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
         * 
         * L'élément graphique généré n'est pas le même si l'emplacement est situé sur un côté ou en coin du plateau.
         */
        void setEmplacementEnCoin();
        
        
        
        /**
         * Notifie à l'emplacement qu'il ne se situe pas dans un coin du plateau.
         * 
         * L'élément graphique généré n'est pas le même si l'emplacement est situé sur un côté ou en coin du plateau.
         */
        void setEmplacementNormal();
        
        
        
        /**
         * Notifie à l'élément graphique que la devise a changé.
         * 
         * Met à jour l'élément graphique en actualisant les prix.
         */
        void deviseChanged();
        
        
        
        /**
         * Renseigne les informations concernant le graphisme des emplacements.
         * @return Informations concernant le graphisme des emplacements.
         */
        const GraphismeEmplacementInfos& getGraphismeInfos() const;
        
        
        
        /**
         * Met à jour les informations concernant la disposition de l'emplacement sur la scène.
         * @param position Position de l'emplacement sur la scène.
         * @param rotation Angle de rotation de l'emplacement sur la scène.
         * @param scene Scène sur laquelle est afficher l'emplacement.
         * @note Il faut appeler la méthode Emplacement::dessiner() pour mettre à jour l'affichage avec la nouvelle configuration.
         */
        void setupElementGraphique(const QPoint& position,
                                   const int rotation,
                                   QGraphicsScene* scene = 0);
        
        
        
        /**
         * Dessine l'élément graphique en fonction de toutes les informations connues puis intègre ce dernier sur la scène configurée.
         * @return Élément graphique.
         */
        GraphismeEmplacement* dessiner();
        
        
        
        /**
         * Sauvegarde les informations concernant l'emplacement via le flux de données.
         * @param ecriture Flux de données vers le fichier à écrire.
         */
        void saveInFile(QDataStream& ecriture) const;
        
        
        
        /**
         * Charge les informations concernant l'emplacement depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version);
        
        
        
    protected:
        /**
         * Méthode virtuelle permettant à chaque classe héritant de renvoyer un prix personnalisé.
         * 
         * Cette méthode est réimplémentée dans les propriete, les emplacement « Taxe » et les emplacements « Deplacement ». Pour plus de facilité, elle renvoie un QString directement utilisable.
         */
        virtual QString helper_getPrix() const;
        
        
        
        /**
         * Méthode virtuelle permettant à chaque classe héritant de renvoyer une couleur personnalisée.
         * 
         * Cette méthode est réimplémentée dans les terrains.
         */
        virtual QColor helper_getCouleurRegroupement() const;
};

#endif // EMPLACEMENTINFOS_HPP
