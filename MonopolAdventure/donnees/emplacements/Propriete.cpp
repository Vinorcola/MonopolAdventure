#include "Propriete.hpp"





Propriete::Propriete(const Type::Emplacement type,
                     const GraphismeEmplacementInfos& graphismeInfos,
                     const QString& devise) :
    Emplacement(type, graphismeInfos),
    m_prixAchat(0),
    m_valeurHypotheque(0),
    m_devise(devise)
{
    
}





Propriete::~Propriete()
{
    
}





quint16 Propriete::getPrixAchat() const
{
    return m_prixAchat;
}





quint16 Propriete::getValeurHypotheque() const
{
    return m_valeurHypotheque;
}





void Propriete::loadFromFile(QDataStream& lecture,
                             const quint16 version)
{
    switch (version)
    {
        default:
            Emplacement::loadFromFile(lecture, version);
            
            lecture >> m_prixAchat
                    >> m_valeurHypotheque;
    }
}





QString Propriete::helper_getPrix() const
{
    return QString::number(m_prixAchat) + m_devise;
}

