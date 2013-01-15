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





void ParcGratuit::loadFromFile(QDataStream& lecture,
                               const quint16 version)
{
    switch (version)
    {
        default:
            Emplacement::loadFromFile(lecture, version);
    }
}

