#include "Service.hpp"





Service::Service() :
    Propriete(Type::Service),
    m_loyers()
{
    
}





Service::~Service()
{
    
}





quint16 Service::getLoyer(const int nombreServicesPossedes) const
{
    return m_loyers.value(nombreServicesPossedes - 1, 0);
}





void Service::setupNombreServices(const int quantite)
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





void Service::editLoyer(const int nombreServicesPossedes,
                             const quint16 montant)
{
    if (nombreServicesPossedes >= 1 && nombreServicesPossedes <= m_loyers.count())
    {
        if (montant > MONTANT_MAX_EDITEUR)
        {
            m_loyers[nombreServicesPossedes - 1] = MONTANT_MAX_EDITEUR;
        }
        else
        {
            m_loyers[nombreServicesPossedes - 1] = montant;
        }
    }
}

