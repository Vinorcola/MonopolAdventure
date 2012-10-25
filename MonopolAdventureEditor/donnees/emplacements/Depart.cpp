#include "Depart.hpp"





Depart::Depart(const GraphismeEmplacementInfos& graphismeInfos,
               const QString& devise) :
    Emplacement(Type::Depart, graphismeInfos),
    m_salaire(0),
    m_devise(devise)
{
    
}





Depart::Depart(const Depart& depart) :
    Emplacement(depart),
    m_salaire(depart.m_salaire),
    m_devise(depart.m_devise)
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





QString Depart::helper_getPrix() const
{
    return QString::number(m_salaire) + m_devise;
}

