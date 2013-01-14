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
 * 
 * L'objet graphique est placé dans une classe à part. De cette manière, l'élément graphique n'est créé que si nécessaire. Par exemple, pour l'édition de la liste des regroupements, les regroupements et les terrains sont copiés. Mais les éléments graphiques ne sont pas créés dans les objets terrains copiés.
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
         */
        void setEmplacementEnCoin();
        
        
        
        /**
         * Notifie à l'emplacement qu'il ne se situe pas dans un coin du plateau.
         */
        void setEmplacementNormal();
        
        
        
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
         * Dessine l'emplacement sur la scène configurée dans le constructeur.
         * @return Élément graphique.
         */
        GraphismeEmplacement* dessiner();
        
        
        
        /**
         * Sauvegarde les informations concernant l'emplacement via le flux de données.
         * @param ecriture Flux de données vers le fichier à écrire.
         */
        void saveInFile(QDataStream& ecriture) const;
        
        
        
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
