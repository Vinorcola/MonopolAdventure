#include "Deplacement.hpp"





Deplacement::Deplacement(const GraphismeEmplacementInfos& graphismeInfos) :
    Emplacement(Type::Deplacement, graphismeInfos),
    m_destination(0),
    m_amende(0)
{
    
}





Deplacement::Deplacement(const Deplacement& deplacement) :
    Emplacement(deplacement),
    m_destination(deplacement.m_destination),
    m_amende(deplacement.m_amende)
{
    
}





Deplacement::~Deplacement()
{
    
}





Deplacement& Deplacement::operator =(const Deplacement& deplacement)
{
    Emplacement::operator =(deplacement);
    m_destination = deplacement.m_destination;
    m_amende = deplacement.m_amende;
    
    return *this;
}





Emplacement* Deplacement::getDestination() const
{
    return m_destination;
}





void Deplacement::editDestination(Emplacement* const destination)
{
    m_destination = destination;
}





quint16 Deplacement::getMontantAmende() const
{
    return m_amende;
}





void Deplacement::editMontantAmende(const quint16 montant)
{
    if (montant > MONTANT_MAX_EDITEUR)
    {
        m_amende = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_amende = montant;
    }
}

