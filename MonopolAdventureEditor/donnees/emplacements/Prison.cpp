#include "Prison.hpp"





Prison::Prison() :
    Emplacement(Type::Prison),
    m_caution(0)
{
    
}





Prison::~Prison()
{
    
}





quint16 Prison::getCaution() const
{
    reuturn m_caution;
}





void Prison::editCaution(const quint16 montant)
{
    if (montant > MONTANT_MAX_EDITEUR)
    {
        m_caution = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_caution = montant;
    }
}

