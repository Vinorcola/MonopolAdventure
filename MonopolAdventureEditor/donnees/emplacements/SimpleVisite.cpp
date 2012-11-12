#include "SimpleVisite.hpp"





SimpleVisite::SimpleVisite(const GraphismeEmplacementInfos& graphismeInfos) :
    Emplacement(Type::SimpleVisite, graphismeInfos)
{
    
}





SimpleVisite::SimpleVisite(const SimpleVisite& simpleVisite) :
    Emplacement(simpleVisite)
{
    
}





SimpleVisite::~SimpleVisite()
{
    
}





SimpleVisite& SimpleVisite::operator =(const SimpleVisite& simpleVisite)
{
    Emplacement::operator =(simpleVisite);
    
    return *this;
}

