#ifndef GRAPHISMEJOUEUR_HPP
#define GRAPHISMEJOUEUR_HPP

#include <QGraphicsPixmapItem>





/**
 * @class GraphismeJoueur GraphismeJoueur.hpp donnees/graphismes/GraphismeJoueur.hpp
 * Cette classe permet l'affichage graphique des joueurs sur le plateau.
 * 
 * Elle est directement liée à la classe Joueur (cf. documentation de Joueur pour plus de détails).
 * 
 * GraphismeJoueur hérite directement de QGraphicsPixmapItem et va ainsi pouvoir être dessinée sur le plateau afin de représenter les joueurs. La classe se charge en indiquant une couleur de joueur. Un joueur peut prendre différentes positions en fonction de la direction de son deplacement. Cette classe affiche alors la bonne image.
 */
class GraphismeJoueur : public QGraphicsPixmapItem
{
    public:
        enum Orientation
        {
            Haut, Bas, Gauche, Droite
        };
        
        
        
    private:
        QGraphicsScene* m_scene;///< Scene sur laquelle afficher l'image.
        QPixmap* m_imageH;///< Image du joueur se dirrigeant vers le haut.
        QPixmap* m_imageB;///< Image du joueur se dirrigeant vers le bas.
        QPixmap* m_imageG;///< Image du joueur se dirrigeant vers la gauche.
        QPixmap* m_imageD;///< Image du joueur se dirrigeant vers la droite.
        
        
        
    public:
        /**
         * Construit un nouvel objet graphique.
         * @param couleur Couleur du joueur.
         */
        GraphismeJoueur(QString couleur);
        
        
        
        /**
         * Change l'image en fonction de l'orientation du joueur.
         * @param orientation Orientation du joueur.
         */
        void changeOrientation(Orientation orientation);
};

#endif // GRAPHISMEJOUEUR_HPP
