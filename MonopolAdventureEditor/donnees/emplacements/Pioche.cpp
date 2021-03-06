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





const PileCartes* Pioche::getPileCartes() const
{
    return m_pileCartes;
}





void Pioche::editPileCartes(const PileCartes* pileCartes)
{
    m_pileCartes = pileCartes;
}





void Pioche::saveInFile(QDataStream& ecriture,
                        const Plateau* plateau) const
{
    Emplacement::saveInFile(ecriture);
    
    ecriture << plateau->getIdentifiantPileCartes(m_pileCartes);
}





void Pioche::loadFromFile(QDataStream& lecture,
                          const quint16 version,
                          const Plateau* plateau)
{
    switch (version)
    {
        default:
            Emplacement::loadFromFile(lecture, version);
            
            quint8 idPileCartes;
            lecture >> idPileCartes;
            
            m_pileCartes = plateau->getPileCartes(idPileCartes);
    }
}

