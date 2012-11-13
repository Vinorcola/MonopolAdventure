#include "TaxeEditWidget.hpp"





TaxeEditWidget::TaxeEditWidget(Taxe *const taxe) :
    QWidget(),
    m_taxe(taxe),
    m_champPayeMontantFixe(new QCheckBox(tr("Le joueur verse un montant fixe"))),
    m_labelMontantFixe(new QLabel(tr("Montant fixe à verser"))),
    m_champMontantFixe(new QSpinBox),
    m_champPayePourcentage(new QCheckBox(tr("Le joueur verse un pourcentage de sa fortune"))),
    m_labelPourcentage(new QLabel(tr("Pourcentage de la fortune à verser"))),
    m_champPourcentage(new QSpinBox)
{
    /* Configuration des champs.
     */
    m_champPayeMontantFixe->setChecked(m_taxe->isMontantFixe());
    
    m_labelMontantFixe->setEnabled(m_taxe->isMontantFixe());
    
    m_champMontantFixe->setSingleStep(10);
    m_champMontantFixe->setMaximum(MONTANT_MAX_EDITEUR);
    m_champMontantFixe->setEnabled(m_taxe->isMontantFixe());
    m_champMontantFixe->setValue(m_taxe->isMontantFixe() ? m_taxe->getMontantFixe() : 0);
    
    m_champPayePourcentage->setChecked(m_taxe->isPourcentageFortune());
    
    m_labelPourcentage->setEnabled(m_taxe->isPourcentageFortune());
    
    m_champPourcentage->setMaximum(100);
    m_champPourcentage->setEnabled(m_taxe->isPourcentageFortune());
    m_champPourcentage->setValue(m_taxe->isPourcentageFortune() ? m_taxe->getPourcentageFortune() : 0);
    
    
    
    /* Mise en forme du widget.
     */
    QFormLayout* layout = new QFormLayout;
    layout->addRow(m_champPayeMontantFixe);
    layout->addRow(m_labelMontantFixe, m_champMontantFixe);
    layout->addRow(m_champPayePourcentage);
    layout->addRow(m_labelPourcentage, m_champPourcentage);
    
    setLayout(layout);
}





void TaxeEditWidget::sauvegarde()
{
    if (m_champPayeMontantFixe->isChecked())
    {
        m_taxe->enableMontantFixe(m_champMontantFixe->value());
    }
    else
    {
        m_taxe->disableMontantFixe();
    }
    
    if (m_champPayePourcentage->isChecked())
    {
        m_taxe->enablePourcentageFortune(m_champPourcentage->value());
    }
    else
    {
        m_taxe->disablePourcentageFortune();
    }
}

