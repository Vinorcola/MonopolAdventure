#include "CompagnieTransport.hpp"





CompagnieTransport::CompagnieTransport(const GraphismeEmplacementInfos& graphismeInfos,
                                     const QString& devise) :
    Propriete(Type::CompagnieTransport, graphismeInfos, devise),
    m_loyers()
{
    
}





CompagnieTransport::~CompagnieTransport()
{
    
}





quint16 CompagnieTransport::getLoyer(const int nombreCompagniesPossedees) const
{
    return m_loyers.value(nombreCompagniesPossedees - 1, 0);
}





void CompagnieTransport::loadFromFile(QDataStream& lecture,
                                      const quint16 version)
{
    switch (version)
    {
        default:
            Propriete::loadFromFile(lecture, version);
            
            quint8 nbLoyers;
            lecture >> nbLoyers;
            for (int i(0); i < nbLoyers; i++)
            {
                quint16 loyer;
                lecture >> loyer;
                m_loyers.append(loyer);
            }
    }
}

