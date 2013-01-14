#include "Pioche.hpp"

#include "donnees/Plateau.hpp"





Pioche::Pioche(const GraphismeEmplacementInfos& graphismeInfos) :
    Emplacement(Type::Pioche, graphismeInfos),
    m_pileCartes(0)
{
    
}





Pioche::~Pioche()
{
    
}





PileCartes* Pioche::getPileCartes() const
{
    return m_pileCartes;
}





void Pioche::editPileCartes(PileCartes* const pileCartes)
{
    m_pileCartes = pileCartes;
}





void Pioche::saveInFile(QDataStream& ecriture,
                        const Plateau* plateau) const
{
    Emplacement::saveInFile(ecriture);
    
    ecriture << plateau->getIdentifiantPileCartes(m_pileCartes);
}

