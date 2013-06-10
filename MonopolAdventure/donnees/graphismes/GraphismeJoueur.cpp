#include "GraphismeJoueur.hpp"





GraphismeJoueur::GraphismeJoueur(QString couleur) :
    QGraphicsPixmapItem(),
    m_imageH(new QPixmap("data/joueurs/" + couleur + "H.bmp")),
    m_imageB(new QPixmap("data/joueurs/" + couleur + "B.bmp")),
    m_imageG(new QPixmap("data/joueurs/" + couleur + "G.bmp")),
    m_imageD(new QPixmap("data/joueurs/" + couleur + "D.bmp"))
{
    setPixmap(*m_imageB);
}





void GraphismeJoueur::changeOrientation(GraphismeJoueur::Orientation orientation)
{
    switch (orientation)
    {
        case Haut:
            setPixmap(*m_imageH);
            break;
            
        case Bas:
            setPixmap(*m_imageB);
            break;
            
        case Gauche:
            setPixmap(*m_imageG);
            break;
            
        case Droite:
            setPixmap(*m_imageD);
            break;
    }
}

