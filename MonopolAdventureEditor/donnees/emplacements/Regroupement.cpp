#include "Regroupement.hpp"





Regroupement::Regroupement() :
    QList(),
    m_titre(""),
    m_couleur(255, 255, 255)
{
    
}





Regroupement::Regroupement(const Regroupement& regroupement) :
    QList(),
    m_titre(regroupement.m_titre),
    m_couleur(regroupement.m_couleur)
{
    for (int i(0), iEnd(regroupement.count()); i < iEnd; ++i)
    {
        Terrain* terrain(regroupement.at(i));
        append(new Terrain(*terrain));
    }
}





Regroupement::~Regroupement()
{
    for (int i(0), iEnd(count()); i < iEnd; ++i)
    {
        last()->editRegroupement(0);
    }
}





const QString& Regroupement::getTitre() const
{
    return m_titre;
}





void Regroupement::editTitre(const QString& titre)
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





const QColor& Regroupement::getCouleur() const
{
    return m_couleur;
}





void Regroupement::editCouleur(const QColor& couleur)
{
    if (couleur.isValid())
    {
        m_couleur = couleur;
    }
    else
    {
        m_couleur.setRgb(255, 255, 255);
    }
}





int Regroupement::getNombreTerrains() const
{
    return count();
}





Terrain* Regroupement::getTerrain(int index)
{
    return at(index);
}

