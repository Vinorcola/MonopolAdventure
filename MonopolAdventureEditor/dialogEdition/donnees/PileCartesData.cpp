#include "PileCartesData.hpp"





PileCartesData::PileCartesData() :
    m_titre(QObject::tr("Nouvelle pile de cartes")),
    m_cartes(),
    m_modeleCartes(new CarteListModel(m_cartes))
{
    
}





PileCartesData::PileCartesData(PileCartes* pileCartes) :
    m_titre(pileCartes->getTitre()),
    m_cartes(),
    m_modeleCartes(0)
{
    // Création des structures de données pour les cartes.
    for (int i(0), iEnd(pileCartes->getNombreCartes()); i < iEnd; ++i)
    {
        m_cartes << new Carte(pileCartes->getCarte(i));
    }
    
    // Création du modèle de données.
    m_modeleCartes = new CarteListModel(m_cartes);
}





PileCartesData::~PileCartesData()
{
    for (int i(0), iEnd(m_cartes.count()); i < iEnd; i++)
    {
        delete m_cartes.at(i);
    }
    
    delete m_modeleCartes;
}





const QString& PileCartesData::getTitre() const
{
    return m_titre;
}





void PileCartesData::editTitre(const QString& titre)
{
    if (titre.isNull())
    {
        m_titre = "";
    }
    else
    {
        m_titre = titre;
    }
}





CarteListModel* PileCartesData::getModeleCartes() const
{
    return m_modeleCartes;
}





QList<Carte*>& PileCartesData::getListeCartes()
{
    return m_cartes;
}





void PileCartesData::createCarte()
{
    m_modeleCartes->createCarte();
}





void PileCartesData::deleteCarte(int row)
{
    m_modeleCartes->deleteCarteAt(row);
}





void PileCartesData::transfereCartes(PileCartes *pileCartes)
{
    for (int i(0), iEnd(m_cartes.count()); i < iEnd; i++)
    {
        m_cartes.at(i)->editPileCartes(pileCartes);
    }
    
    m_cartes.clear();
}

