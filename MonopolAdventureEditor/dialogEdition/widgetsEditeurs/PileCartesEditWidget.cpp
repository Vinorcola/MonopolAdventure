#include "PileCartesEditWidget.hpp"





PileCartesEditWidget::PileCartesEditWidget(const QList<Emplacement*>& emplacements,
                                           const QList<PileCartes*>& pilesCartes,
                                           const QString& devise) :
    QWidget(),
    m_emplacements(emplacements),
    m_pilesCartes(pilesCartes),
    m_devise(devise),
    m_pileCartes(0),
    m_champTitre(new QLineEdit),
    m_champImage(new ImageSelectWidget(this)),
    m_vueCartes(new QListView),
    m_description(new QLabel),
    m_creerCarte(new QPushButton(tr("Ajouter une nouvelle carte"))),
    m_modifierCarte(new QPushButton(tr("Modifier cette carte"))),
    m_supprimerCarte(new QPushButton(tr("Supprimer cette carte")))
{
    // Configuration des champs
    m_vueCartes->setFixedWidth(500);
    
    m_description->setWordWrap(true);
    m_description->setAlignment(Qt::AlignJustify);
    m_description->setFixedWidth(250);
    
    
    
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
    layout->addRow(tr("Image"), m_champImage);
    layout->addRow(tr("Cartes"), layoutCartes);
    
    setLayout(layout);
    
    
    
    // Connexion des entrées à leur slot respectifs
    connect(m_champTitre, SIGNAL(textEdited(QString)), this, SLOT(changeTitre(QString)));
    connect(m_champImage, SIGNAL(imageChange()), this, SLOT(changeImage()));
    connect(m_creerCarte, SIGNAL(clicked()), this, SLOT(createCarte()));
    connect(m_modifierCarte, SIGNAL(clicked()), this, SLOT(editCarte()));
    connect(m_supprimerCarte, SIGNAL(clicked()), this, SLOT(deleteCarte()));
    connect(m_vueCartes, SIGNAL(activated(QModelIndex)), this, SLOT(editCarte(QModelIndex)));
}





void PileCartesEditWidget::editPileCartes(PileCartes* pileCartes)
{
    if (pileCartes)
    {
        m_pileCartes = pileCartes;
        m_champTitre->setText(pileCartes->getTitre());
        m_champImage->setImage(pileCartes->getImage());
        m_vueCartes->setModel(pileCartes);
        connect(m_vueCartes->selectionModel(), SIGNAL(currentChanged(QModelIndex,QModelIndex)), this, SLOT(selectedCarteChanged(QModelIndex)));
        
        if (pileCartes->getNombreCartes() >= 1)
        {
            m_vueCartes->setCurrentIndex(pileCartes->helper_createIndexFromRow(0));
            m_description->setText(pileCartes->getCarteAt(0)->getAction().getDescription(m_devise));
            m_creerCarte->setEnabled(true);
            m_modifierCarte->setEnabled(true);
            m_supprimerCarte->setEnabled(true);
        }
        else
        {
            m_description->setText("");
            m_creerCarte->setEnabled(true);
            m_modifierCarte->setDisabled(true);
            m_supprimerCarte->setDisabled(true);
        }
    }
    else
    {
        m_champTitre->setText("");
        m_champImage->resetImage();
        m_description->setText("");
        m_creerCarte->setDisabled(true);
        m_modifierCarte->setDisabled(true);
        m_supprimerCarte->setDisabled(true);
    }
}





void PileCartesEditWidget::changeTitre(QString titre)
{
    emit titreChanged(m_pileCartes, titre);
}





void PileCartesEditWidget::changeImage()
{
    if (m_pileCartes)
    {
        /* Pas besoin d'émettre un quelconque signal car on n'a pas besoin de notifier ce changement au modèle de
         * données.
         */
        m_pileCartes->editImage(m_champImage->getImage());
    }
}





void PileCartesEditWidget::createCarte()
{
    // Activation du bouton de suppression.
    m_modifierCarte->setEnabled(true);
    m_supprimerCarte->setEnabled(true);
    
    // Création et édition de la carte.
    editCarte(m_pileCartes->createCarte());
}





void PileCartesEditWidget::editCarte(int row)
{
    if (row == -1)
    {
        row = m_vueCartes->currentIndex().row();
    }
    
    
    
    if (row >=0 && row < m_pileCartes->rowCount())
    {
        EditionCarte fenetre(m_pileCartes->getCarteAt(row), m_emplacements, m_pilesCartes, this);
        fenetre.executer();
    }
}





void PileCartesEditWidget::editCarte(const QModelIndex& index)
{
    editCarte(index.row());
}





void PileCartesEditWidget::deleteCarte()
{
    // Suppression de la carte.
    int rang(m_vueCartes->currentIndex().row());
    m_pileCartes->deleteCarteAt(rang);
    
    
    
    // Désactivation du bouton de suppression.
    if (m_pileCartes->getNombreCartes() == 0)
    {
        m_modifierCarte->setDisabled(true);
        m_supprimerCarte->setDisabled(true);
    }
    // Sélection d'une nouvelle carte.
    else
    {
        QItemSelectionModel* selection(m_vueCartes->selectionModel());
        if (rang == m_pileCartes->getNombreCartes())
        {
            selection->select(m_pileCartes->helper_createIndexFromRow(rang - 1), QItemSelectionModel::Select);
        }
        else
        {
            selection->select(m_pileCartes->helper_createIndexFromRow(rang), QItemSelectionModel::Select);
        }
        
        m_vueCartes->setSelectionModel(selection);
    }
}





void PileCartesEditWidget::selectedCarteChanged(const QModelIndex& index)
{
    if (index.row() >=0 && index.row() < m_pileCartes->rowCount())
    {
        m_description->setText(m_pileCartes->getCarteAt(index.row())->getAction().getDescription(m_devise));
    }
}

