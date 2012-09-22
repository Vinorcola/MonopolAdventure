#include "Pioche.hpp"





Pioche::Pioche(const GraphismeEmplacementInfos& graphismeInfos) :
    Emplacement(Type::Pioche, graphismeInfos)
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

