#include "Depart.hpp"





Depart::Depart() :
    Emplacement(Type::Depart),
    m_salaire(0)
{
    
}





Depart::~Depart()
{
    
}





quint16 Depart::getSalaire() const
{
    return m_salaire;
}





void Depart::editSalaire(const quint16 montant)
{
    if (montant > MONTANT_MAX_EDITEUR)
    {
        m_salaire = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_salaire = montant;
    }
}

