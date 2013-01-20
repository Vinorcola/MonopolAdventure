#include "DepartEditWidget.hpp"





DepartEditWidget::DepartEditWidget(Depart* const depart) :
    SauvegardeInterface(),
    m_depart(depart),
    m_champSalaire(new QSpinBox)
{
    /* Configuration des champs.
     */
    m_champSalaire->setSingleStep(10);
    m_champSalaire->setMaximum(MONTANT_MAX_EDITEUR);
    m_champSalaire->setValue(depart->getSalaire());
    
    
    
    /* Mise en forme du widget.
     */
    QFormLayout* layout = new QFormLayout;
    layout->addRow(tr("Montant du salaire que reçoit le joueur à chaque fois qu'il passe par cet emplacement"), m_champSalaire);
    
    setLayout(layout);
}





void DepartEditWidget::sauvegarde()
{
    m_depart->editSalaire(m_champSalaire->value());
}

