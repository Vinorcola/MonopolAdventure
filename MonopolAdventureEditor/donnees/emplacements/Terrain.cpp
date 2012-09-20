#include "Terrain.hpp"





Terrain::Terrain() :
    Propriete(Type::Terrain),
    m_regroupement(0),
    m_loyerNu(0),
    m_loyerNuExtra(0),
    m_loyersMaison(),
    m_loyersHotel()
{
    
}





Terrain::~Terrain()
{
    /* Enlève le terrain du regroupement.
     */
    if (m_regroupement)
    {
        m_regroupement->removeOne(this);
    }
}





Regroupement* Terrain::getRegroupement() const
{
    return m_regroupement;
}





void Terrain::editRegroupement(Regroupement* const regroupement)
{
    if (regroupement != m_regroupement)
    {
        /* Enlève le terrain de l'ancien regroupement.
         */
        if (m_regroupement)
        {
            m_regroupement->removeOne(this);
        }
        
        
        m_regroupement = regroupement;
        
        
        /* Ajoute le terrain dans le nouveau regroupement.
         */
        if (m_regroupement)
        {
            m_regroupement->append(this);
        }
    }
}





quint16 Terrain::getLoyerNu() const
{
    return m_loyerNu;
}





void Terrain::editLoyerNu(const quint16 montant)
{
    if (montant > MONTANT_MAX_EDITEUR)
    {
        m_loyerNu = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_loyerNu = montant;
    }
}





quint16 Terrain::getLoyerNuExtra() const
{
    return m_loyerNuExtra;
}





void Terrain::editLoyerNuExtra(const quint16 montant)
{
    if (montant > MONTANT_MAX_EDITEUR)
    {
        m_loyerNuExtra = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_loyerNuExtra = montant;
    }
}





quint16 Terrain::getLoyerMaison(const int nombreMaisonsConstruites) const
{
    return m_loyersMaison.value(nombreMaisonsConstruites - 1, 0);
}





void Terrain::setupNombreMaxMaison(const int quantite)
{
    if (quantite > 0)
    {
        if (quantite > m_loyersMaison.count())
        {
            for (int i(0), iEnd(quantite - m_loyersMaison.count()); i < iEnd; ++i)
            {
                m_loyersMaison << 0;
            }
        }
        else if (quantite < m_loyersMaison.count())
        {
            for (int i(0), iEnd(m_loyersMaison.count() - quantite); i < iEnd; ++i)
            {
                m_loyersMaison.removeLast();
            }
        }
    }
}





void Terrain::editLoyerMaison(const int nombreMaisonsConstruites,
                                   const quint16 montant)
{
    if (nombreMaisonsConstruites >= 1 && nombreMaisonsConstruites <= m_loyersMaison.count())
    {
        if (montant > MONTANT_MAX_EDITEUR)
        {
            m_loyersMaison[nombreMaisonsConstruites - 1] = MONTANT_MAX_EDITEUR;
        }
        else
        {
            m_loyersMaison[nombreMaisonsConstruites - 1] = montant;
        }
    }
}





quint16 Terrain::getLoyerHotel(const int nombreHotelsConstruits) const
{
    return m_loyersHotel.value(nombreHotelsConstruits - 1, 0);
}





void Terrain::setupNombreMaxHotel(const int quantite)
{
    if (quantite > 0)
    {
        if (quantite > m_loyersHotel.count())
        {
            for (int i(0), iEnd(quantite - m_loyersHotel.count()); i < iEnd; ++i)
            {
                m_loyersHotel << 0;
            }
        }
        else if (quantite < m_loyersHotel.count())
        {
            for (int i(0), iEnd(m_loyersHotel.count() - quantite); i < iEnd; ++i)
            {
                m_loyersHotel.removeLast();
            }
        }
    }
}





void Terrain::editLoyerHotel(const int nombreHotelsConstruits,
                                  const quint16 montant)
{
    if (nombreHotelsConstruits >= 1 && nombreHotelsConstruits <= m_loyersHotel.count())
    {
        if (montant > MONTANT_MAX_EDITEUR)
        {
            m_loyersHotel[nombreHotelsConstruits - 1] = MONTANT_MAX_EDITEUR;
        }
        else
        {
            m_loyersHotel[nombreHotelsConstruits - 1] = montant;
        }
    }
}

