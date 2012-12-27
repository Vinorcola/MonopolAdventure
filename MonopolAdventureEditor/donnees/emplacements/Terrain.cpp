#include "Terrain.hpp"





Terrain::Terrain(const GraphismeEmplacementInfos& graphismeInfos,
                 const QString& devise) :
    Propriete(Type::Terrain, graphismeInfos, devise),
    m_regroupement(0),
    m_prixAchatMaison(0),
    m_prixVenteMaison(0),
    m_prixAchatHotel(0),
    m_prixVenteHotel(0),
    m_loyerNu(0),
    m_loyerNuExtra(0),
    m_loyersMaison(),
    m_loyersHotel()
{
    m_loyersMaison << 0 << 0 << 0 << 0;
    m_loyersHotel << 0;
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
            
            
            /* Met à jour l'affichage de l'emplacement.
             * NOTE : On ne met à jour l'affichage que s'il y a un nouveau regroupement. S'il n'y a pas de nouveau
             * regroupement, c'est que le terrain va être supprimé. Il n'est donc pas nécessaire d'actualiser
             * l'affichage graphique.
             */
            if (m_elementGraphique)
            {
                m_elementGraphique->updateCouleurRegroupement(helper_getCouleurRegroupement());
            }
        }
    }
}





quint16 Terrain::getPrixAchatMaison() const
{
    return m_prixAchatMaison;
}





void Terrain::editPrixAchatMaison(const quint16 prix)
{
    if (prix > MONTANT_MAX_EDITEUR)
    {
        m_prixAchatMaison = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_prixAchatMaison = prix;
    }
}





quint16 Terrain::getPrixVenteMaison() const
{
    return m_prixVenteMaison;
}





void Terrain::editPrixVenteMaison(const quint16 prix)
{
    if (prix > MONTANT_MAX_EDITEUR)
    {
        m_prixAchatMaison = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_prixAchatMaison = prix;
    }
}





quint16 Terrain::getPrixAchatHotel() const
{
    return m_prixAchatHotel;
}





void Terrain::editPrixAchatHotel(const quint16 prix)
{
    if (prix > MONTANT_MAX_EDITEUR)
    {
        m_prixAchatHotel = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_prixAchatHotel = prix;
    }
}





quint16 Terrain::getPrixVenteHotel() const
{
    return m_prixVenteHotel;
}





void Terrain::editPrixVenteHotel(const quint16 prix)
{
    if (prix > MONTANT_MAX_EDITEUR)
    {
        m_prixVenteHotel = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_prixVenteHotel = prix;
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





int Terrain::getNombreMaisonsPourHotel() const
{
    return m_loyersMaison.count();
}





void Terrain::editNombreMaisonsPourHotel(const int quantite)
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





quint16 Terrain::getLoyerMaison(const int nombreMaisonsConstruites) const
{
    return m_loyersMaison.value(nombreMaisonsConstruites - 1, 0);
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





int Terrain::getNombreMaxHotel() const
{
    return m_loyersHotel.count();
}





void Terrain::editNombreMaxHotel(const int quantite)
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





quint16 Terrain::getLoyerHotel(const int nombreHotelsConstruits) const
{
    return m_loyersHotel.value(nombreHotelsConstruits - 1, 0);
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





QColor Terrain::helper_getCouleurRegroupement() const
{
    if (m_regroupement)
    {
        return m_regroupement->getCouleur();
    }
    
    /* Couleur blanche par défaut, si le terrain n'appartient à aucun regroupement.
     */
    return QColor(255, 255, 255);
}

