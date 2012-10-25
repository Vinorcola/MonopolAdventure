#include "ParcGratuit.hpp"





ParcGratuit::ParcGratuit(const GraphismeEmplacementInfos& graphismeInfos) :
    Emplacement(Type::ParcGratuit, graphismeInfos)
{
    
}





ParcGratuit::ParcGratuit(const ParcGratuit& parcGratuit) :
    Emplacement(parcGratuit)
{
    
}





ParcGratuit::~ParcGratuit()
{
    
}





ParcGratuit& ParcGratuit::operator =(const ParcGratuit& parcGratuit)
{
    Emplacement::operator =(parcGratuit);
    
    return *this;
}

