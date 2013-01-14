#include "PiocheEditWidget.hpp"





PiocheEditWidget::PiocheEditWidget(Pioche* const pioche,
                                   const QList<PileCartes*>& pilesCartes) :
    SauvegardeInterface(),
    m_pioche(pioche),
    m_champPileCartes(new PointerComboBox<PileCartes>)
{
    // Configuration des champs.
    for (int i(0), iEnd(pilesCartes.count()); i < iEnd; i++)
    {
        PileCartes* pileCartes(pilesCartes.at(i));
        m_champPileCartes->addItem(QString::number(i) + ". " + pileCartes->getTitre(), pileCartes);
    }
    
    
    
    // Aménagement du widget.
    QFormLayout* layout(new QFormLayout);
    layout->addRow(tr("Pile de cartes"), m_champPileCartes);
    
    setLayout(layout);
}





void PiocheEditWidget::sauvegarde()
{
    m_pioche->editPileCartes(m_champPileCartes->getCurrentPointeur());
}

