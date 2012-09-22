#ifndef GRAPHISMEEMPLACEMENTINFOS_HPP
#define GRAPHISMEEMPLACEMENTINFOS_HPP

#include <QColor>
#include <QFont>
#include <QPen>
#include <QSize>





/**
 * @class GraphismeEmplacementInfos GraphismeEmplacementInfos.hpp donnees/graphismes/GraphismeEmplacementInfos.hpp
 * GraphismeEmplacementInfos contient les informations éditables permettant l'affichage graphique des emplacements.
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
         * Remplace la taille des emplacements par @a taille.
         * @param taille Nouvelle taille.
         */
        void editTaille(const QSize taille);
        
        
        
        /**
         * Renseigne la taille de la bande de couleur des terrains.
         * @return Taille de la bande de couleur des terrains.
         */
        quint16 getHauteurRectangleCouleur() const;
        
        
        
        /**
         * Remplace la taille de la bande de couleur des terrains par @a hauteur.
         * @param hauteur Nouvelle hauteur.
         */
        void editHauteurRectangleCouleur(const quint16 hauteur);
        
        
        
        /**
         * Renseigne le crayon utilisé pour dessiner les bordures des emplacements.
         * @return Crayon utilisé pour dessiner les bordures des emplacements.
         */
        const QPen& getCrayonBordure() const;
        
        
        
        /**
         * Remplace le crayon utilisé pour dessiner les bordures des emplacements par @a crayon.
         * @param crayon Nouveau crayon.
         */
        void editCrayonBordure(const QPen& crayon);
        
        
        
        /**
         * Renseigne la couleur de fond des emplacements du plateau.
         * @return Couleur de fond des emplacements du plateau.
         */
        const QColor& getCouleurFond() const;
        
        
        
        /**
         * Remplace la couleur de fond des emplacements du plateau par @a couleur.
         * @param couleur Nouvelle couleur.
         */
        void editCouleurFond(const QColor& couleur);
        
        
        
        /**
         * Renseigne la marge minimale entre le texte et la bordure de l'emplacement.
         * @return Marge minimale entre le texte et la bordure de l'emplacement.
         */
        quint8 getMarge() const;
        
        
        
        /**
         * Remplace la marge minimale entre le texte et la bordure de l'emplacement par @a marge.
         * @param marge Nouvelle marge.
         */
        void editMarge(const quint8 marge);
        
        
        
        /**
         * Renseigne la fonte utilisée pour afficher le titre des emplacements.
         * @return Fonte utilisée pour afficher le titre des emplacements.
         */
        const QFont& getFonteTitre() const;
        
        
        
        /**
         * Remplace la fonte utilisée pour afficher le titre des emplacements par @a fonte.
         * @param fonte Nouvelle fonte.
         */
        void editFonteTitre(const QFont& fonte);
        
        
        
        /**
         * Renseigne la fonte utilisée pour afficher le sous-titre des emplacements.
         * @return Fonte utilisée pour afficher le sous-titre des emplacements.
         */
        const QFont& getFonteSousTitre() const;
        
        
        
        /**
         * Remplace la fonte utilisée pour afficher le sous-titre des emplacements par @a fonte.
         * @param fonte Nouvelle fonte.
         */
        void editFonteSousTitre(const QFont& fonte);
        
        
        
        /**
         * Renseigne la fonte utilisée pour afficher la description des emplacements.
         * @return Fonte utilisée pour afficher la description des emplacements.
         */
        const QFont& getFonteDescription() const;
        
        
        
        /**
         * Remplace la fonte utilisée pour afficher la description des emplacements par @a fonte.
         * @param fonte Nouvelle fonte.
         */
        void editFonteDescription(const QFont& fonte);
        
        
        
        /**
         * Renseigne la fonte utilisée pour afficher le prix des emplacements.
         * @return Fonte utilisée pour afficher le prix des emplacements.
         */
        const QFont& getFontePrix() const;
        
        
        
        /**
         * Remplace la fonte utilisée pour afficher le prix des emplacements par @a fonte.
         * @param fonte Nouvelle fonte.
         */
        void editFontePrix(const QFont& fonte);
};

#endif // GRAPHISMEEMPLACEMENTINFOS_HPP
