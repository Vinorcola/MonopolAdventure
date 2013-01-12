#include "ListePilesCartesEditWidget.hpp"





ListePilesCartesEditWidget::ListePilesCartesEditWidget(QList<PileCartes*>& pilesCartes,
                                                       const QList<Emplacement*>& emplacements,
                                                       const QString& devise) :
    QWidget(),
    m_pilesCartes(pilesCartes),
    m_modelePilesCartes(new PileCartesListModel(pilesCartes)),
    m_vuePilesCartes(new QComboBox),
    m_creerPileCartes(new QPushButton(tr("Créer une nouvelle pile de cartes"))),
    m_supprimerPileCartes(new QPushButton(tr("Supprimer cette pile de cartes"))),
    m_champPileCartes(new PileCartesEditWidget(emplacements, pilesCartes, devise))
{
    // Configuration des champs.
    m_vuePilesCartes->setModel(m_modelePilesCartes);
    
    if (pilesCartes.isEmpty())
    {
        m_vuePilesCartes->setDisabled(true);
        m_supprimerPileCartes->setDisabled(true);
        m_champPileCartes->setDisabled(true);
    }
    else
    {
        m_vuePilesCartes->setCurrentIndex(0);
        m_champPileCartes->editPileCartes(pilesCartes.first());
    }
    
    
    
    // Mise en forme.
    QHBoxLayout* layoutHaut(new QHBoxLayout);
    layoutHaut->addWidget(m_vuePilesCartes);
    layoutHaut->addWidget(m_creerPileCartes);
    layoutHaut->addWidget(m_supprimerPileCartes);
    
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addLayout(layoutHaut);
    layout->addWidget(m_champPileCartes);
    
    setLayout(layout);
    
    
    
    // Connexion des slots.
    QObject::connect(m_vuePilesCartes, SIGNAL(currentIndexChanged(int)), this, SLOT(changePileCartesEditee(int)));
    QObject::connect(m_creerPileCartes, SIGNAL(clicked()), this, SLOT(createPileCartes()));
    QObject::connect(m_supprimerPileCartes, SIGNAL(clicked()), this, SLOT(deletePileCartes()));
}





void ListePilesCartesEditWidget::changePileCartesEditee(int index)
{
    m_champPileCartes->editPileCartes(m_modelePilesCartes->getPileCartesAt(index));
}





void ListePilesCartesEditWidget::createPileCartes()
{
    m_vuePilesCartes->setCurrentIndex(m_modelePilesCartes->createPileCartes());
    m_vuePilesCartes->setEnabled(true);
    m_supprimerPileCartes->setEnabled(true);
    m_champPileCartes->setEnabled(true);
}





void ListePilesCartesEditWidget::deletePileCartes()
{
    int rowSelectionne(m_vuePilesCartes->currentIndex());
    
    
    
    /* Suppression de la pile de cartes.
     */
    m_modelePilesCartes->deletePileCartesAt(rowSelectionne);
    
    
    
    /* Sélection d'une nouvelle pile de cartes pour l'édition.
     * Si la pile de cartes à supprimer est la dernière de la liste, on sélectionne la précédente. Sinon, on sélectionne
     * la suivante.
     */
    if (rowSelectionne == m_modelePilesCartes->rowCount() - 1)
    {
        m_champPileCartes->editPileCartes(m_modelePilesCartes->getPileCartesAt(rowSelectionne - 1));
    }
    else
    {
        m_champPileCartes->editPileCartes(m_modelePilesCartes->getPileCartesAt(rowSelectionne + 1));
    }
    
    
    
    /* S'il n'y a plus de piles de cartes, on désactive la suppression et le widget éditeur.
     */
    if (m_modelePilesCartes->rowCount() == 0)
    {
        m_vuePilesCartes->setDisabled(true);
        m_supprimerPileCartes->setDisabled(true);
        m_champPileCartes->setDisabled(true);
    }
}

