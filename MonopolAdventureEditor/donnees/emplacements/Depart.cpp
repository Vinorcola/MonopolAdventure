#include "Depart.hpp"





Depart::Depart(const GraphismeEmplacementInfos& graphismeInfos) :
    Emplacement(Type::Depart, graphismeInfos),
    m_salaire(0)
{
    
}





Depart::Depart(const Depart& depart) :
    Emplacement(depart),
    m_salaire(depart.m_salaire)
{
    
}





Depart::~Depart()
{
    
}





Depart& Depart::operator =(const Depart& depart)
{
    Emplacement::operator =(depart);
    m_salaire = depart.m_salaire;
    
    return *this;
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

