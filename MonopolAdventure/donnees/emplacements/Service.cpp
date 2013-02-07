#include "Service.hpp"





Service::Service(const GraphismeEmplacementInfos& graphismeInfos,
                 const QString& devise) :
    Propriete(Type::Service, graphismeInfos, devise),
    m_loyers()
{
    
}





Service::~Service()
{
    
}





quint16 Service::getLoyer(const int nombreServicesPossedes) const
{
    return m_loyers.value(nombreServicesPossedes - 1, 0);
}





void Service::loadFromFile(QDataStream& lecture,
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

