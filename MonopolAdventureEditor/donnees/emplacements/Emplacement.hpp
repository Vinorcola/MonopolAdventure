#ifndef EMPLACEMENTINFOS_HPP
#define EMPLACEMENTINFOS_HPP

#include <QPixmap>
#include <QString>

#include "global.hpp"





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
        
        
        
    public:
        /**
         * Construit un emplacement par défaut.
         * @param type Précise le type d'emplacement.
         */
        Emplacement(Type::Emplacement type);
        
        
        
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
};

#endif // EMPLACEMENTINFOS_HPP
