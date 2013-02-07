#include "SimpleVisite.hpp"





SimpleVisite::SimpleVisite(const GraphismeEmplacementInfos& graphismeInfos) :
    Emplacement(Type::SimpleVisite, graphismeInfos)
{
    
}





SimpleVisite::~SimpleVisite()
{
    
}





void SimpleVisite::loadFromFile(QDataStream& lecture,
                                const quint16 version)
{
    switch (version)
    {
        default:
            Emplacement::loadFromFile(lecture, version);
    }
}

