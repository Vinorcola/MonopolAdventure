#include "CompagnieTransport.hpp"





CompagnieTransport::CompagnieTransport(const GraphismeEmplacementInfos& graphismeInfos,
                                     const QString& devise) :
    Propriete(Type::CompagnieTransport, graphismeInfos, devise),
    m_loyers()
{
    
}





CompagnieTransport::CompagnieTransport(const CompagnieTransport& compagnieTransport) :
    Propriete(compagnieTransport),
    m_loyers(compagnieTransport.m_loyers)
{
    
}





CompagnieTransport::~CompagnieTransport()
{
    
}





CompagnieTransport &CompagnieTransport::operator =(const CompagnieTransport& compagnieTransport)
{
    Propriete::operator =(compagnieTransport);
    m_loyers = compagnieTransport.m_loyers;
    
    return *this;
}





quint16 CompagnieTransport::getLoyer(const int nombreCompagniesPossedees) const
{
    return m_loyers.value(nombreCompagniesPossedees - 1, 0);
}





void CompagnieTransport::setupNombreCompagnies(const int quantite)
{
    if (quantite > 0)
    {
        if (quantite > m_loyers.count())
        {
            for (int i(0), iEnd(quantite - m_loyers.count()); i < iEnd; ++i)
            {
                m_loyers << 0;
            }
        }
        else if (quantite < m_loyers.count())
        {
            for (int i(0), iEnd(m_loyers.count() - quantite); i < iEnd; ++i)
            {
                m_loyers.removeLast();
            }
        }
    }
}





void CompagnieTransport::editLoyer(const int nombreCompagniesPossedees,
                                       const quint16 montant)
{
    if (nombreCompagniesPossedees >= 1 && nombreCompagniesPossedees <= m_loyers.count())
    {
        if (montant > MONTANT_MAX_EDITEUR)
        {
            m_loyers[nombreCompagniesPossedees - 1] = MONTANT_MAX_EDITEUR;
        }
        else
        {
            m_loyers[nombreCompagniesPossedees - 1] = montant;
        }
    }
}
