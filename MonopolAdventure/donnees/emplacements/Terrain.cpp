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
    
}





const Regroupement* Terrain::getRegroupement() const
{
    return m_regroupement;
}





quint16 Terrain::getPrixAchatMaison() const
{
    return m_prixAchatMaison;
}





quint16 Terrain::getPrixVenteMaison() const
{
    return m_prixVenteMaison;
}





quint16 Terrain::getPrixAchatHotel() const
{
    return m_prixAchatHotel;
}





quint16 Terrain::getPrixVenteHotel() const
{
    return m_prixVenteHotel;
}





quint16 Terrain::getLoyerNu() const
{
    return m_loyerNu;
}





quint16 Terrain::getLoyerNuExtra() const
{
    return m_loyerNuExtra;
}





int Terrain::getNombreMaisonsPourHotel() const
{
    return m_loyersMaison.count();
}





quint16 Terrain::getLoyerMaison(const int nombreMaisonsConstruites) const
{
    return m_loyersMaison.value(nombreMaisonsConstruites - 1, 0);
}





int Terrain::getNombreMaxHotel() const
{
    return m_loyersHotel.count();
}





quint16 Terrain::getLoyerHotel(const int nombreHotelsConstruits) const
{
    return m_loyersHotel.value(nombreHotelsConstruits - 1, 0);
}





void Terrain::loadFromFile(QDataStream& lecture,
                           const quint16 version)
{
    switch (version)
    {
        default:
            Propriete::loadFromFile(lecture, version);
            
            lecture >> m_prixAchatMaison
                    >> m_prixVenteMaison
                    >> m_prixAchatHotel
                    >> m_prixVenteHotel
                    >> m_loyerNu
                    >> m_loyerNuExtra;
            
            quint8 nbLoyers;
            lecture >> nbLoyers;
            for (int i(0); i < nbLoyers; i++)
            {
                quint16 loyer;
                lecture >> loyer;
                m_loyersMaison[i] = loyer;
            }
            
            lecture >> nbLoyers;
            for (int i(0); i < nbLoyers; i++)
            {
                quint16 loyer;
                lecture >> loyer;
                m_loyersHotel[i] = loyer;
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

