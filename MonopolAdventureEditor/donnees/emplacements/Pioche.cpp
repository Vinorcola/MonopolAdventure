#include "Pioche.hpp"





Pioche::Pioche() :
    Emplacement(Type::Pioche)
{
    
}





Pioche::~Pioche()
{
    
}





PileCartes* Pioche::getPileCartes() const
{
    return m_pileCartes;
}





void Pioche::editPileCartes(PileCartes* const pileCartes)
{
    m_pileCartes = pileCartes;
}

