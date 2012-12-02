#include "LoyerServiceEditWidget.hpp"





LoyerServiceEditWidget::LoyerServiceEditWidget(Service* const service,
                                               const int nombreServices) :
    SauvegardeInterface(),
    m_service(service),
    m_champsLoyer()
{
    /* Configuration des champs.
     */
    for (int i(1); i <= nombreServices; ++i)
    {
        QSpinBox* champ(new QSpinBox);
        champ->setSingleStep(10);
        champ->setMaximum(MONTANT_MAX_EDITEUR);
        champ->setValue(m_service->getLoyer(i));
        
        m_champsLoyer.append(champ);
    }
    
    
    
    /* Mise en forme du widget.
     */
    QFormLayout* layout = new QFormLayout;
    layout->addRow(tr("Loyer si le propriétaire ne possède que cette compagnie de transport"), m_champsLoyer.first());
    for (int i(1); i < nombreServices; ++i)
    {
        layout->addRow(tr("Loyer si le propriétaire possède") + " " + QString::number(i + 1) + " " + tr("compagnies de transport"), m_champsLoyer.at(i));
    }
    
    setLayout(layout);
}





void LoyerServiceEditWidget::sauvegarde()
{
    for (int i(0), iEnd(m_champsLoyer.count()); i < iEnd; ++i)
    {
        m_service->editLoyer(i + 1, m_champsLoyer.at(i)->value());
    }
}

