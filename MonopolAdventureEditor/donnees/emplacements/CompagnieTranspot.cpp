#include "CompagnieTranspot.hpp"





CompagnieTranspot::CompagnieTranspot() :
    Propriete(Type::CompagnieTransport)
{
    
}





CompagnieTranspot::~CompagnieTranspot()
{
    
}





quint16 CompagnieTranspot::getLoyer(const int nombreCompagniesPossedees) const
{
    return m_loyers.value(nombreCompagniesPossedees - 1, 0);
}





void CompagnieTranspot::setupNombreCompagnies(const int quantite)
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





void CompagnieTranspot::editLoyer(const int nombreCompagniesPossedees,
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

