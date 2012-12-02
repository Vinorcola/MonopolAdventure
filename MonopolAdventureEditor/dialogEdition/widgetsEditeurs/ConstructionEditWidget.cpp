#include "ConstructionEditWidget.hpp"





ConstructionEditWidget::ConstructionEditWidget(Terrain* const terrain) :
    QWidget(),
    m_terrain(terrain),
    m_champPrixAchatMaison(new QSpinBox),
    m_venteMaisonMoitie(new QCheckBox(tr("La subvention de destruction d'une maison vaut la moitié de son prix de construction"))),
    m_labelPrixVenteMaison(new QLabel(tr("Subvention pour la destruction d'une maison"))),
    m_champPrixVenteMaison(new QSpinBox),
    m_champPrixAchatHotel(new QSpinBox),
    m_venteHotelMoitie(new QCheckBox(tr("La subvention de destruction d'un hotel vaut la moitié de son prix de construction"))),
    m_labelPrixVenteHotel(new QLabel(tr("Subvention pour la destruction d'un hotel"))),
    m_champPrixVenteHotel(new QSpinBox)
{
    /* Configuration des champs.
     */
    bool venteMaisonMoitie(m_terrain->getPrixVenteMaison() * 2 == m_terrain->getPrixAchatMaison());
    bool venteHotelMoitie(m_terrain->getPrixVenteHotel() * 2 == m_terrain->getPrixAchatHotel());
    
    m_champPrixAchatMaison->setSingleStep(10);
    m_champPrixAchatMaison->setMaximum(MONTANT_MAX_EDITEUR);
    m_champPrixAchatMaison->setValue(m_terrain->getPrixAchatMaison());
    
    m_venteMaisonMoitie->setChecked(venteMaisonMoitie);
    
    m_labelPrixVenteMaison->setEnabled(!venteMaisonMoitie);
    
    m_champPrixVenteMaison->setSingleStep(10);
    m_champPrixVenteMaison->setMaximum(MONTANT_MAX_EDITEUR);
    m_champPrixVenteMaison->setEnabled(!venteMaisonMoitie);
    m_champPrixVenteMaison->setValue(m_terrain->getPrixVenteMaison());
    
    m_champPrixAchatHotel->setSingleStep(10);
    m_champPrixAchatHotel->setMaximum(MONTANT_MAX_EDITEUR);
    m_champPrixAchatHotel->setValue(m_terrain->getPrixAchatHotel());
    
    m_venteHotelMoitie->setChecked(venteHotelMoitie);
    
    m_labelPrixVenteHotel->setEnabled(!venteHotelMoitie);
    
    m_champPrixVenteHotel->setSingleStep(10);
    m_champPrixVenteHotel->setMaximum(MONTANT_MAX_EDITEUR);
    m_champPrixVenteHotel->setEnabled(!venteHotelMoitie);
    m_champPrixVenteHotel->setValue(m_terrain->getPrixVenteHotel());
    
    
    
    /* Mise en forme du widget.
     */
    QFormLayout* layout = new QFormLayout;
    layout->addRow(tr("Prix de construction d'une maison"), m_champPrixAchatMaison);
    layout->addRow(m_venteMaisonMoitie);
    layout->addRow(m_labelPrixVenteMaison, m_champPrixVenteMaison);
    layout->addRow(new QLabel());
    layout->addRow(tr("Prix de construction d'un hôtel"), m_champPrixAchatHotel);
    layout->addRow(m_venteHotelMoitie);
    layout->addRow(m_labelPrixVenteHotel, m_champPrixVenteHotel);
    
    setLayout(layout);
    
    
    
    /* Connexion des champs aux slots.
     */
    connect(m_champPrixAchatMaison, SIGNAL(valueChanged(int)), this, SLOT(champPrixAchatMaisonChanged(int)));
    connect(m_venteMaisonMoitie, SIGNAL(stateChanged(int)), this, SLOT(venteMaisonMoitieChanged(int)));
    connect(m_champPrixAchatHotel, SIGNAL(valueChanged(int)), this, SLOT(champPrixAchatHotelChanged(int)));
    connect(m_venteHotelMoitie, SIGNAL(stateChanged(int)), this, SLOT(venteHotelMoitieChanged(int)));
}





void ConstructionEditWidget::sauvegarde()
{
    m_terrain->editPrixAchatMaison(m_champPrixAchatMaison->value());
    m_terrain->editPrixVenteMaison(m_champPrixVenteMaison->value());
    m_terrain->editPrixAchatHotel(m_champPrixAchatHotel->value());
    m_terrain->editPrixVenteHotel(m_champPrixVenteHotel->value());
}





void ConstructionEditWidget::champPrixAchatMaisonChanged(int prix)
{
    if (m_venteMaisonMoitie->isChecked())
    {
        m_champPrixVenteMaison->setValue(prix / 2);
    }
}





void ConstructionEditWidget::venteMaisonMoitieChanged(int state)
{
    if (state == Qt::Unchecked)
    {
        m_labelPrixVenteMaison->setEnabled(true);
        m_champPrixVenteMaison->setEnabled(true);
    }
    else
    {
        m_labelPrixVenteMaison->setEnabled(false);
        m_champPrixVenteMaison->setEnabled(false);
        m_champPrixVenteMaison->setValue(m_champPrixAchatMaison->value() / 2);
    }
}





void ConstructionEditWidget::champPrixAchatHotelChanged(int prix)
{
    if (m_venteHotelMoitie->isChecked())
    {
        m_champPrixVenteHotel->setValue(prix / 2);
    }
}





void ConstructionEditWidget::venteHotelMoitieChanged(int state)
{
    if (state == Qt::Unchecked)
    {
        m_labelPrixVenteHotel->setEnabled(true);
        m_champPrixVenteHotel->setEnabled(true);
    }
    else
    {
        m_labelPrixVenteHotel->setEnabled(false);
        m_champPrixVenteHotel->setEnabled(false);
        m_champPrixVenteHotel->setValue(m_champPrixAchatHotel->value() / 2);
    }
}

