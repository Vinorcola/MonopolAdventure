#include "Pioche.hpp"





Pioche::Pioche(const GraphismeEmplacementInfos& graphismeInfos) :
    Emplacement(Type::Pioche, graphismeInfos),
    m_pileCartes(0)
{
    
}





Pioche::Pioche(const Pioche& pioche) :
    Emplacement(pioche),
    m_pileCartes(pioche.m_pileCartes)
{
    
}





Pioche::~Pioche()
{
    
}





Pioche& Pioche::operator =(const Pioche& pioche)
{
    Emplacement::operator =(pioche);
    m_pileCartes = pioche.m_pileCartes;
    
    return *this;
}





PileCartes* Pioche::getPileCartes() const
{
    return m_pileCartes;
}





void Pioche::editPileCartes(PileCartes* const pileCartes)
{
    m_pileCartes = pileCartes;
}

