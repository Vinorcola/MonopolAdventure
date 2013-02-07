#include "PileCartes.hpp"

#include "donnees/cartes/Carte.hpp"
#include "donnees/Plateau.hpp"





PileCartes::PileCartes() :
    m_titre(QObject::tr("Nouvelle pile de cartes")),
    m_image(),
    m_cartes()
{
    
}





PileCartes::~PileCartes()
{
    for (int i(0), iEnd(m_cartes.count()); i < iEnd; i++)
    {
        delete m_cartes.takeLast();
    }
}





const QString& PileCartes::getTitre() const
{
    return m_titre;
}





const QPixmap& PileCartes::getImage() const
{
    return m_image;
}





int PileCartes::getNombreCartes() const
{
    return m_cartes.count();
}





void PileCartes::loadFromFile(QDataStream& lecture,
                              const quint16 version,
                              const Plateau* plateau)
{
    switch (version)
    {
        default:
            quint8 nbCartes;
            
            lecture >> m_titre
                    >> m_image
                    >> nbCartes;
            
            for (int i(0); i < nbCartes; i++)
            {
                Carte* carte = new Carte(this);
                carte->loadFromFile(lecture, version, plateau);
                m_cartes.append(carte);
            }
    }
}

