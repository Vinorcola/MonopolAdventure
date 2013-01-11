#include "PileCartesEditWidget.hpp"





PileCartesEditWidget::PileCartesEditWidget(const QList<Emplacement*>& emplacements,
                                           const QList<PileCartesData*>& pilesCartes,
                                           const QString& devise) :
    QWidget(),
    m_emplacements(emplacements),
    m_pilesCartes(pilesCartes),
    m_devise(devise),
    m_pileCartes(0),
    m_champTitre(new QLineEdit),
    m_modeleCartes(0),
    m_vueCartes(new QListView),
    m_description(new QLabel),
    m_creerCarte(new QPushButton(tr("Ajouter une nouvelle carte"))),
    m_modifierCarte(new QPushButton(tr("Modifier cette carte"))),
    m_supprimerCarte(new QPushButton(tr("Supprimer cette carte")))
{
    // Configuration des champs
    m_vueCartes->setMinimumWidth(500);
    
    m_description->setWordWrap(true);
    m_description->setAlignment(Qt::AlignJustify);
    
    
    
    // Mise en forme
    QVBoxLayout* layoutDroite(new QVBoxLayout);
    layoutDroite->addWidget(m_description);
    layoutDroite->addWidget(m_creerCarte);
    layoutDroite->addWidget(m_modifierCarte);
    layoutDroite->addWidget(m_supprimerCarte);
    
    QHBoxLayout* layoutCartes(new QHBoxLayout);
    layoutCartes->addWidget(m_vueCartes);
    layoutCartes->addLayout(layoutDroite);
    
    QFormLayout* layout(new QFormLayout);
    layout->addRow(tr("Titre"), m_champTitre);
    layout->addRow(tr("Cartes"), layoutCartes);
    
    setLayout(layout);
    
    
    
    // Connexion des entrées à leur slot respectifs
    connect(m_champTitre, SIGNAL(textEdited(QString)), this, SLOT(changeTitre(QString)));
    connect(m_creerCarte, SIGNAL(clicked()), this, SLOT(createCarte()));
    connect(m_modifierCarte, SIGNAL(clicked()), this, SLOT(editCarte()));
    connect(m_supprimerCarte, SIGNAL(clicked()), this, SLOT(deleteCarte()));
}





void PileCartesEditWidget::editPileCartes(PileCartesData* pileCartes)
{
    if (pileCartes)
    {
        m_pileCartes = pileCartes;
        m_champTitre->setText(pileCartes->getTitre());
        m_modeleCartes = pileCartes->getModeleCartes();
        m_vueCartes->setModel(m_modeleCartes);
        connect(m_vueCartes->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(selectedCarteChanged(QModelIndex)));
        
        if (m_modeleCartes->rowCount() >= 1)
        {
            m_vueCartes->setCurrentIndex(m_modeleCartes->helper_createIndexFromRow(0));
            m_description->setText(m_modeleCartes->getCarteAt(0)->getAction().getDescription(m_devise));
            m_modifierCarte->setEnabled(true);
            m_supprimerCarte->setEnabled(true);
        }
        else
        {
            m_modifierCarte->setDisabled(true);
            m_supprimerCarte->setDisabled(true);
        }
    }
    else
    {
        m_champTitre->setText("");
    }
}





void PileCartesEditWidget::changeTitre(QString titre)
{
    m_pileCartes->editTitre(titre);
}





void PileCartesEditWidget::createCarte()
{
    // Activation du bouton de suppression.
    m_modifierCarte->setEnabled(true);
    m_supprimerCarte->setEnabled(true);
    
    // Création et édition de la carte.
    editCarte(m_modeleCartes->createCarte());
}





void PileCartesEditWidget::editCarte(int row)
{
    if (row == -1)
    {
        row = m_vueCartes->currentIndex().row();
    }
    
    EditionCarte fenetre(m_modeleCartes->getCarteAt(row), m_emplacements, m_pilesCartes, this);
    fenetre.executer();
}





void PileCartesEditWidget::deleteCarte()
{
    // Suppression de la carte.
    m_modeleCartes->deleteCarteAt(m_vueCartes->currentIndex().row());
    
    // Désactivation du bouton de suppression.
    if (m_modeleCartes->rowCount() == 0)
    {
        m_modifierCarte->setDisabled(true);
        m_supprimerCarte->setDisabled(true);
    }
}





void PileCartesEditWidget::selectedCarteChanged(const QModelIndex& index)
{
    m_description->setText(m_modeleCartes->getCarteAt(index.row())->getAction().getDescription(m_devise));
}

