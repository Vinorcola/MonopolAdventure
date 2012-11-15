#include "ProprieteEditWidget.hpp"





ProprieteEditWidget::ProprieteEditWidget(Propriete* const propriete) :
    QWidget(),
    m_propriete(propriete),
    m_champPrixAchat(new QSpinBox),
    m_hypothequeMoitiePrix(new QCheckBox(tr("La valeur hypothécaire est égale à la moitié du prix d'achat"))),
    m_labelValeurHypotheque(new QLabel(tr("Valeur hypothécaire de la propriété"))),
    m_champValeurHypotheque(new QSpinBox)
{
    /* Configuration des champs.
     */
    bool hypothequeMoitiePrix(m_propriete->getValeurHypotheque() * 2 == m_propriete->getPrixAchat());
    
    m_champPrixAchat->setSingleStep(10);
    m_champPrixAchat->setMaximum(MONTANT_MAX_EDITEUR);
    m_champPrixAchat->setValue(m_propriete->getPrixAchat());
    
    m_hypothequeMoitiePrix->setChecked(hypothequeMoitiePrix);
    
    m_labelValeurHypotheque->setEnabled(!hypothequeMoitiePrix);
    
    m_champValeurHypotheque->setSingleStep(10);
    m_champValeurHypotheque->setMaximum(MONTANT_MAX_EDITEUR);
    m_champValeurHypotheque->setEnabled(!hypothequeMoitiePrix);
    m_champValeurHypotheque->setValue(m_propriete->getValeurHypotheque());
    
    
    
    /* Mise en forme du widget.
     */
    QFormLayout* layout = new QFormLayout;
    layout->addRow(tr("Prix d'achat de la propriété"), m_champPrixAchat);
    layout->addRow(m_hypothequeMoitiePrix);
    layout->addRow(m_labelValeurHypotheque, m_champValeurHypotheque);
    
    setLayout(layout);
    
    
    
    /* Connexion des champs aux slots.
     */
    connect(m_champPrixAchat, SIGNAL(valueChanged(int)), this, SLOT(champPrixAchatChanged(int)));
    connect(m_hypothequeMoitiePrix, SIGNAL(stateChanged(int)), this, SLOT(hypothequeMoitiePrixChanged(int)));
}





void ProprieteEditWidget::sauvegarde()
{
    m_propriete->editPrixAchat(m_champPrixAchat->value());
    m_propriete->editValeurHypotheque(m_champValeurHypotheque->value());
}





void ProprieteEditWidget::champPrixAchatChanged(int prix)
{
    if (m_hypothequeMoitiePrix->isChecked())
    {
        m_champValeurHypotheque->setValue(prix / 2);
    }
}





void ProprieteEditWidget::hypothequeMoitiePrixChanged(int state)
{
    if (state == Qt::Unchecked)
    {
        m_labelValeurHypotheque->setEnabled(true);
        m_champValeurHypotheque->setEnabled(true);
    }
    else
    {
        m_labelValeurHypotheque->setEnabled(false);
        m_champValeurHypotheque->setEnabled(false);
        m_champValeurHypotheque->setValue(m_champPrixAchat->value() / 2);
    }
}

