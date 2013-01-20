#include "LoyerTerrainEditWidget.hpp"





LoyerTerrainEditWidget::LoyerTerrainEditWidget(Terrain* const terrain) :
    SauvegardeInterface(),
    m_terrain(terrain),
    m_champLoyerNu(new QSpinBox),
    m_champLoyerNuExtra(new QSpinBox),
    m_champsLoyersMaison(),
    m_champsLoyersHotel()
{
    /* Configuration des champs.
     */
    m_champLoyerNu->setMaximum(MONTANT_MAX_EDITEUR);
    m_champLoyerNu->setValue(terrain->getLoyerNu());
    
    m_champLoyerNuExtra->setMaximum(MONTANT_MAX_EDITEUR);
    m_champLoyerNuExtra->setValue(terrain->getLoyerNuExtra());
    
    for (int i(1), iEnd(terrain->getNombreMaisonsPourHotel()); i <= iEnd; ++i)
    {
        QSpinBox* champ(new QSpinBox);
        champ->setSingleStep(10);
        champ->setMaximum(MONTANT_MAX_EDITEUR);
        champ->setValue(terrain->getLoyerMaison(i));
        
        m_champsLoyersMaison.append(champ);
    }
    
    for (int i(1), iEnd(terrain->getNombreMaxHotel()); i <= iEnd; ++i)
    {
        QSpinBox* champ(new QSpinBox);
        champ->setSingleStep(50);
        champ->setMaximum(MONTANT_MAX_EDITEUR);
        champ->setValue(terrain->getLoyerHotel(i));
        
        m_champsLoyersHotel.append(champ);
    }
    
    
    
    /* Mise en forme du widget.
     */
    /** @todo Séparer les champs dans des groupes. */
    QFormLayout* layout = new QFormLayout;
    layout->addRow(tr("Loyer du terrain nu"), m_champLoyerNu);
    layout->addRow(tr("Loyer du terrain nu lorsque le propriétaire possède tous les terrains du regroupement"), m_champLoyerNuExtra);
    
    layout->addRow(tr("Loyer avec une maison"), m_champsLoyersMaison.first());
    for (int i(1), iEnd(terrain->getNombreMaisonsPourHotel()); i < iEnd; ++i)
    {
        layout->addRow(tr("Loyer avec") + " " + QString::number(i + 1) + " " + tr("maisons"), m_champsLoyersMaison.at(i));
    }
    
    layout->addRow(tr("Loyer avec un hôtel"), m_champsLoyersHotel.first());
    for (int i(1), iEnd(terrain->getNombreMaxHotel()); i < iEnd; ++i)
    {
        layout->addRow(tr("Loyer avec") + " " + QString::number(i + 1) + " " + tr("hôtels"), m_champsLoyersHotel.at(i));
    }
    
    setLayout(layout);
}





void LoyerTerrainEditWidget::sauvegarde()
{
    m_terrain->editLoyerNu(m_champLoyerNu->value());
    m_terrain->editLoyerNuExtra(m_champLoyerNuExtra->value());
    
    for (int i(0), iEnd(m_champsLoyersMaison.count()); i < iEnd; ++i)
    {
        m_terrain->editLoyerMaison(i + 1, m_champsLoyersMaison.at(i)->value());
    }
    
    for (int i(0), iEnd(m_champsLoyersHotel.count()); i < iEnd; ++i)
    {
        m_terrain->editLoyerHotel(i + 1, m_champsLoyersHotel.at(i)->value());
    }
}

