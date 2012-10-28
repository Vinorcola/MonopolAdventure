#include "Regroupement.hpp"





Regroupement::Regroupement() :
    QList(),
    m_titre(""),
    m_couleur(255, 255, 255)
{
    
}





Regroupement::Regroupement(const Regroupement& regroupement) :
    QList(regroupement),
    m_titre(regroupement.m_titre),
    m_couleur(regroupement.m_couleur)
{
    
}





Regroupement::~Regroupement()
{
    for (int i(0), iEnd(count()); i < iEnd; ++i)
    {
        last()->editRegroupement(0);
    }
}





Regroupement& Regroupement::operator =(const Regroupement& copieRegroupement)
{
    m_titre = copieRegroupement.m_titre;
    m_couleur = copieRegroupement.m_couleur;
    
    /* Recherche des terrains ajoutés.
     * On n'a pas besoin de rechercher les terrains supprimés, car on parcours tous les regroupements après l'édition.
     * Les terrains supprimés seront donc ajouté dans un autre regroupement et donc supprimé de celui-ci grâce à la
     * méthode Terrain::editRegroupement().
     */
    for (int i(0), iEnd(copieRegroupement.count()); i < iEnd; ++i)
    {
        if (!contains(copieRegroupement.at(i)))
        {
            copieRegroupement.getTerrain(i)->editRegroupement(this);
        }
    }
    
    return *this;
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





Terrain* Regroupement::getTerrain(int index) const
{
    return at(index);
}

