#include "ListePilesCartesEditWidget.hpp"

#include "donnees/emplacements/Pioche.hpp"





ListePilesCartesEditWidget::ListePilesCartesEditWidget(QList<PileCartes*>& pilesCartes,
                                                       const QList<Emplacement*>& emplacements,
                                                       const QString& devise) :
    QWidget(),
    m_emplacements(emplacements),
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
    connect(m_vuePilesCartes, SIGNAL(currentIndexChanged(int)), this, SLOT(changePileCartesEditee(int)));
    connect(m_creerPileCartes, SIGNAL(clicked()), this, SLOT(createPileCartes()));
    connect(m_supprimerPileCartes, SIGNAL(clicked()), this, SLOT(deletePileCartes()));
    connect(m_champPileCartes, SIGNAL(titreChanged(PileCartes*,QString)), m_modelePilesCartes, SLOT(editTitrePileCartes(PileCartes*,QString)));
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
    
    
    
    /* On contrôle l'utilisation de la pile de cartes dans les autres pile de cartes.
     */
    bool trouve(false);
    int i(0), iEnd(m_pilesCartes.count());
    PileCartes* pileCartesASupprimer(m_modelePilesCartes->getPileCartesAt(rowSelectionne));
    
    while (!trouve && i < iEnd)
    {
        PileCartes* pileCartes(m_pilesCartes.at(i));
        if (pileCartes != pileCartesASupprimer)
        {
            trouve = pileCartes->utilise(pileCartesASupprimer);
        }
        
        i++;
    }
    
    if (trouve)
    {
        QMessageBox::warning(this, tr("Erreur lors de la suppression"), tr("Attention, cette pile de cartes est utilisée dans certaines cartes de la pile « ") + m_pilesCartes.at(i - 1)->getTitre() + tr(" ». Veuillez modifier ces cartes pour pouvoir supprimer cette pile de cartes."));
    }
    else
    {
        /* On contrôle l'utilisation de la pile de cartes dans les emplacements « Pioche ».
         */
        i = 0;
        iEnd = m_emplacements.count();
        
        while (!trouve && i < iEnd)
        {
            if (m_emplacements.at(i)->getType() == Type::Pioche)
            {
                trouve = (static_cast<Pioche*>(m_emplacements.at(i))->getPileCartes() == pileCartesASupprimer);
            }
            
            i++;
        }
        
        if (trouve)
        {
            QMessageBox::warning(this, tr("Erreur lors de la suppression"), tr("Attention, cette pile de cartes est utilisée par l'emplacements « ") + m_emplacements.at(i - 1)->getTitre() + tr(" ». Veuillez modifier ces emplacements pour pouvoir supprimer cette pile de cartes."));
        }
        else
        {
            /* Suppression de la pile de cartes.
             */
            m_modelePilesCartes->deletePileCartesAt(rowSelectionne);
            
            
            
            /* Sélection d'une nouvelle pile de cartes pour l'édition.
             * Si la pile de cartes à supprimer est la dernière de la liste, on sélectionne la précédente. Sinon, on
             * sélectionne la suivante.
             */
            if (rowSelectionne == m_modelePilesCartes->rowCount())
            {
                m_champPileCartes->editPileCartes(m_modelePilesCartes->getPileCartesAt(rowSelectionne - 1));
            }
            else
            {
                m_champPileCartes->editPileCartes(m_modelePilesCartes->getPileCartesAt(rowSelectionne));
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
    }
}

