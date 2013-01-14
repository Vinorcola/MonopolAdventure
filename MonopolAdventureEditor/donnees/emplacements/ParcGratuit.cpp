#include "ParcGratuit.hpp"





ParcGratuit::ParcGratuit(const GraphismeEmplacementInfos& graphismeInfos) :
    Emplacement(Type::ParcGratuit, graphismeInfos)
{
    
}





ParcGratuit::~ParcGratuit()
{
    
}





void ParcGratuit::saveInFile(QDataStream& ecriture) const
{
    Emplacement::saveInFile(ecriture);
}

