#ifndef GRAPHISMEEMPLACEMENTINFOS_HPP
#define GRAPHISMEEMPLACEMENTINFOS_HPP

#include <QColor>
#include <QFont>
#include <QPen>
#include <QSize>





/**
 * @class GraphismeEmplacementInfos GraphismeEmplacementInfos.hpp donnees/graphismes/GraphismeEmplacementInfos.hpp
 * GraphismeEmplacementInfos contient les informations graphiques permettant l'affichage des emplacements.
 */
class GraphismeEmplacementInfos
{
    private:
        QSize m_tailleNormale;///< Taille des emplacements.
        /**
         * Taille des emplacements en coin du plateau.
         * @note Cette variable pourrais être calculée à chaque fois dans une méthode getter de Plateau. Cependant, rajouter cette variable permet de fournir une référence constante vers celle-ci.
         */
        QSize m_tailleEnCoin;
        quint16 m_hauteurRectangleCouleur;///< Taille de la bande de couleur des terrains.
        QPen m_crayonBordure;///< Crayon utilisé pour dessiner les bordures des emplacements.
        QColor m_couleurFond;///< Couleur de fond des emplacements du plateau.
        quint8 m_marge;///< Marge minimale entre le texte et la bordure de l'emplacement.
        QFont m_fontTitre;///< Fonte utilisée pour afficher le titre des emplacements.
        QFont m_fontSousTitre;///< Fonte utilisée pour afficher le sous-titre des emplacements.
        QFont m_fontDescription;///< Fonte utilisée pour afficher la description des emplacements.
        QFont m_fontPrix;///< Fonte utilisée pour afficher le prix des propriétés ou des emplacements taxes.
        
        
        
    public:
        /**
         * Construit la structure avec les informations par défaut.
         */
        GraphismeEmplacementInfos();
        
        
        
        /**
         * Renseigne la taille des emplacements.
         * @return Taille des emplacements.
         */
        const QSize& getTailleNormale() const;
        
        
        
        /**
         * Renseigne la taille des emplacements en coin du plateau.
         * @return Taille des emplacements en coin du plateau.
         */
        const QSize& getTailleEnCoin() const;
        
        
        
        /**
         * Renseigne la taille de la bande de couleur des terrains.
         * @return Taille de la bande de couleur des terrains.
         */
        quint16 getHauteurRectangleCouleur() const;
        
        
        
        /**
         * Renseigne le crayon utilisé pour dessiner les bordures des emplacements.
         * @return Crayon utilisé pour dessiner les bordures des emplacements.
         */
        const QPen& getCrayonBordure() const;
        
        
        
        /**
         * Renseigne la couleur de fond des emplacements du plateau.
         * @return Couleur de fond des emplacements du plateau.
         */
        const QColor& getCouleurFond() const;
        
        
        
        /**
         * Renseigne la marge minimale entre le texte et la bordure de l'emplacement.
         * @return Marge minimale entre le texte et la bordure de l'emplacement.
         */
        quint8 getMarge() const;
        
        
        
        /**
         * Renseigne la fonte utilisée pour afficher le titre des emplacements.
         * @return Fonte utilisée pour afficher le titre des emplacements.
         */
        const QFont& getFonteTitre() const;
        
        
        
        /**
         * Renseigne la fonte utilisée pour afficher le sous-titre des emplacements.
         * @return Fonte utilisée pour afficher le sous-titre des emplacements.
         */
        const QFont& getFonteSousTitre() const;
        
        
        
        /**
         * Renseigne la fonte utilisée pour afficher la description des emplacements.
         * @return Fonte utilisée pour afficher la description des emplacements.
         */
        const QFont& getFonteDescription() const;
        
        
        
        /**
         * Renseigne la fonte utilisée pour afficher le prix des emplacements.
         * @return Fonte utilisée pour afficher le prix des emplacements.
         */
        const QFont& getFontePrix() const;
        
        
        
        /**
         * Charge les informations concernant le graphisme des emplacements depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version);
};

#endif // GRAPHISMEEMPLACEMENTINFOS_HPP
