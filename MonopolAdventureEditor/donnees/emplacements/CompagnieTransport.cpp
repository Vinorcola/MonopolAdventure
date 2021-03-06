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





void CompagnieTransport::saveInFile(QDataStream& ecriture) const
{
    Propriete::saveInFile(ecriture);
    
    ecriture << (quint8) m_loyers.count();// Ecriture de la taille de la liste.
    for (int i(0), iEnd(m_loyers.count()); i < iEnd; i++)
    {
        ecriture << m_loyers.at(i);
    }
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

