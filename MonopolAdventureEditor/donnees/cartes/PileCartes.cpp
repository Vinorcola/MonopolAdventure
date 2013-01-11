#include "PileCartes.hpp"





PileCartes::PileCartes() :
    QList(),
    m_titre("")
{
    
}





PileCartes::~PileCartes()
{
    for (int i(0), iEnd(count()); i < iEnd; i++)
    {
        delete takeLast();
    }
}





const QString& PileCartes::getTitre() const
{
    return m_titre;
}





void PileCartes::editTitre(const QString& titre)
{
    if (titre.isNull())
    {
        m_titre = "";
    }
    else
    {
        m_titre = titre;
    }
}





int PileCartes::getNombreCartes() const
{
    return count();
}





Carte* PileCartes::getCarte(int index) const
{
    return at(index);
}





QList<Carte*> PileCartes::getListeCartes() const
{
    return *this;
}





void PileCartes::vider()
{
    for (int i(0), iEnd(count()); i < iEnd; i++)
    {
        delete takeLast();
    }
}

