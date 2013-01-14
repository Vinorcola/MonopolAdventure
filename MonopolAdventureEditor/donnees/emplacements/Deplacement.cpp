#include "Deplacement.hpp"

#include "donnees/Plateau.hpp"





Deplacement::Deplacement(const GraphismeEmplacementInfos& graphismeInfos,
                         const QString& devise) :
    Emplacement(Type::Deplacement, graphismeInfos),
    m_destination(0),
    m_amende(0),
    m_devise(devise)
{
    
}





Deplacement::~Deplacement()
{
    
}





Emplacement* Deplacement::getDestination() const
{
    return m_destination;
}





void Deplacement::editDestination(Emplacement* const destination)
{
    m_destination = destination;
}





quint16 Deplacement::getMontantAmende() const
{
    return m_amende;
}





void Deplacement::editMontantAmende(const quint16 montant)
{
    if (montant > MONTANT_MAX_EDITEUR)
    {
        m_amende = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_amende = montant;
    }
}





void Deplacement::saveInFile(QDataStream& ecriture,
                             const Plateau* plateau) const
{
    Emplacement::saveInFile(ecriture);
    
    ecriture << plateau->getIdentifiantEmplacement(m_destination)
             << m_amende;
}





QString Deplacement::helper_getPrix() const
{
    if (m_amende == 0)
    {
        return QString("");
    }
    else
    {
        return QString::number(m_amende) + m_devise;
    }
}

