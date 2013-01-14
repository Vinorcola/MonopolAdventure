#include "SimpleVisite.hpp"





SimpleVisite::SimpleVisite(const GraphismeEmplacementInfos& graphismeInfos) :
    Emplacement(Type::SimpleVisite, graphismeInfos)
{
    
}





SimpleVisite::~SimpleVisite()
{
    
}





void SimpleVisite::saveInFile(QDataStream& ecriture) const
{
    Emplacement::saveInFile(ecriture);
}

