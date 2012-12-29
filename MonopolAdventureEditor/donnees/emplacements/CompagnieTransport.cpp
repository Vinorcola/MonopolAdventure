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





void CompagnieTransport::setupNombreCompagnies(const int quantite)
{
    if (quantite > 0)
    {
        if (quantite > m_loyers.count())
        {
            for (int i(0), iEnd(quantite - m_loyers.count()); i < iEnd; ++i)
            {
                m_loyers << 0;
            }
        }
        else if (quantite < m_loyers.count())
        {
            for (int i(0), iEnd(m_loyers.count() - quantite); i < iEnd; ++i)
            {
                m_loyers.removeLast();
            }
        }
    }
}





void CompagnieTransport::editLoyer(const int nombreCompagniesPossedees,
                                       const quint16 montant)
{
    if (nombreCompagniesPossedees >= 1 && nombreCompagniesPossedees <= m_loyers.count())
    {
        if (montant > MONTANT_MAX_EDITEUR)
        {
            m_loyers[nombreCompagniesPossedees - 1] = MONTANT_MAX_EDITEUR;
        }
        else
        {
            m_loyers[nombreCompagniesPossedees - 1] = montant;
        }
    }
}





void CompagnieTransport::saveInFile(QDataStream& ecriture,
                                    const quint16 version) const
{
    if (version == 100)
    {
        Propriete::saveInFile(ecriture, 100);
        
        ecriture << (quint8) m_loyers.count();// Ecriture de la taille de la liste.
        for (int i(0), iEnd(m_loyers.count()); i < iEnd; i++)
        {
            ecriture << m_loyers.at(i);
        }
    }
}

