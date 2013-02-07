#include "Prison.hpp"

#include "donnees/Plateau.hpp"





Prison::Prison(const GraphismeEmplacementInfos& graphismeInfos,
               SimpleVisite* const emplacementAssocie) :
    Emplacement(Type::Prison, graphismeInfos),
    m_emplacementAssocie(emplacementAssocie),
    m_caution(0)
{
    
}





Prison::~Prison()
{
    
}





const SimpleVisite* Prison::getEmplacementAssocie() const
{
    return m_emplacementAssocie;
}





quint16 Prison::getCaution() const
{
    return m_caution;
}





void Prison::loadFromFile(QDataStream& lecture,
                          const quint16 version,
                          const Plateau* plateau)
{
    switch (version)
    {
        default:
            Emplacement::loadFromFile(lecture, version);
            
            quint8 idEmplacement;
            lecture >> idEmplacement
                    >> m_caution;
            
            m_emplacementAssocie = static_cast<const SimpleVisite*>(plateau->getEmplacement(idEmplacement));
    }
}

