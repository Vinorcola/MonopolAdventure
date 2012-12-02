#include "PrisonEditWidget.hpp"





PrisonEditWidget::PrisonEditWidget(Prison* const prison) :
    SauvegardeInterface(),
    m_prison(prison),
    m_champCaution(new QSpinBox)
{
    /* Configuration des champs.
     */
    m_champCaution->setSingleStep(5);
    m_champCaution->setMaximum(MONTANT_MAX_EDITEUR);
    m_champCaution->setValue(m_prison->getCaution());
    
    
    
    /* Mise en forme du widget.
     */
    QFormLayout* layout = new QFormLayout;
    layout->addRow(tr("Montant de la caution que doit payer le joueur pour sortir de prison"), m_champCaution);
    
    setLayout(layout);
}





void PrisonEditWidget::sauvegarde()
{
    m_prison->editCaution(m_champCaution->value());
}

