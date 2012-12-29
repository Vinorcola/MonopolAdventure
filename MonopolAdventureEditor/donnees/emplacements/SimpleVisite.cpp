#include "SimpleVisite.hpp"





SimpleVisite::SimpleVisite(const GraphismeEmplacementInfos& graphismeInfos) :
    Emplacement(Type::SimpleVisite, graphismeInfos)
{
    
}





SimpleVisite::~SimpleVisite()
{
    
}





void SimpleVisite::saveInFile(QDataStream& ecriture,
                              const quint16 version) const
{
    if (version == 100)
    {
        Emplacement::saveInFile(ecriture, 100);
    }
}

