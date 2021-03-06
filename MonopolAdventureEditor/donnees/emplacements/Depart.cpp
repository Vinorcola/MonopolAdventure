#include "Depart.hpp"





Depart::Depart(const GraphismeEmplacementInfos& graphismeInfos,
               const QString& devise) :
    Emplacement(Type::Depart, graphismeInfos),
    m_salaire(0),
    m_devise(devise)
{
    
}





Depart::~Depart()
{
    
}





quint16 Depart::getSalaire() const
{
    return m_salaire;
}





void Depart::editSalaire(const quint16 montant)
{
    if (montant > MONTANT_MAX_EDITEUR)
    {
        m_salaire = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_salaire = montant;
    }
}





void Depart::saveInFile(QDataStream& ecriture) const
{
    Emplacement::saveInFile(ecriture);
    
    ecriture << m_salaire;
}





void Depart::loadFromFile(QDataStream&lecture,
                          const quint16 version)
{
    switch (version)
    {
        default:
            Emplacement::loadFromFile(lecture, version);
            
            lecture >> m_salaire;
    }
}





QString Depart::helper_getPrix() const
{
    return QString::number(m_salaire) + m_devise;
}

