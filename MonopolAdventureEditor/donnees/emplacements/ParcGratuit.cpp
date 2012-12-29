#include "ParcGratuit.hpp"





ParcGratuit::ParcGratuit(const GraphismeEmplacementInfos& graphismeInfos) :
    Emplacement(Type::ParcGratuit, graphismeInfos)
{
    
}





ParcGratuit::~ParcGratuit()
{
    
}





void ParcGratuit::saveInFile(QDataStream& ecriture,
                             const quint16 version) const
{
    if (version == 100)
    {
        Emplacement::saveInFile(ecriture, 100);
    }
}

