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





SimpleVisite* Prison::getEmplacementAssocie() const
{
    return m_emplacementAssocie;
}





void Prison::editEmplacementAssocie(SimpleVisite* emplacement)
{
    if (emplacement && emplacement->getType() == Type::SimpleVisite)
    {
        m_emplacementAssocie = emplacement;
    }
}





quint16 Prison::getCaution() const
{
    return m_caution;
}





void Prison::editCaution(const quint16 montant)
{
    if (montant > MONTANT_MAX_EDITEUR)
    {
        m_caution = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_caution = montant;
    }
}





void Prison::saveInFile(QDataStream& ecriture,
                        const Plateau* plateau) const
{
    Emplacement::saveInFile(ecriture);
    
    ecriture << plateau->getIdentifiantEmplacement(m_emplacementAssocie)
             << m_caution;
}

