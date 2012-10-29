#include "ListeRegroupementEditWidget.hpp"





ListeRegroupementEditWidget::ListeRegroupementEditWidget(QList<Regroupement*>& regroupements) :
    QWidget(),
    m_modelRegroupementChoix(new RegroupementListModel(regroupements, this)),
    m_champRegroupement(new QComboBox),
    m_boutonCreer(new QPushButton(tr("Ajouter un nouveau regroupement"))),
    m_boutonSupprimer(new QPushButton(tr("Supprimer ce regroupement"))),
    m_editWidget(new RegroupementEditWidget(m_modelRegroupementChoix->getModeleSecondaire(), regroupements.first()))
{
    /* Configuration des champs.
     */
    m_champRegroupement->setModel(m_modelRegroupementChoix);
    connect(m_champRegroupement, SIGNAL(currentIndexChanged(int)), this, SLOT(champRegroupementChanged(int)));
    connect(m_boutonCreer, SIGNAL(clicked()), this, SLOT(createRegroupement()));
    connect(m_boutonSupprimer, SIGNAL(clicked()), this, SLOT(deleteRegroupement()));
    
    if (m_modelRegroupementChoix->rowCount() <= 1)
    {
        m_boutonSupprimer->setEnabled(false);// On ne peut pas supprimer le dernier regroupement.
    }
    
    
    
    /* Mise en forme.
     */
    QHBoxLayout* layoutHaut(new QHBoxLayout);
    layoutHaut->addWidget(m_champRegroupement);
    layoutHaut->addWidget(m_boutonSupprimer);
    layoutHaut->addWidget(m_boutonCreer);
    
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addLayout(layoutHaut);
    layout->addWidget(m_editWidget);
    
    setLayout(layout);
}





void ListeRegroupementEditWidget::champRegroupementChanged(int index)
{
    // Récupère le regroupement associé à l'index sélectionné.
    m_editWidget->changeRegroupement(m_modelRegroupementChoix->getRegroupement(index));
}





void ListeRegroupementEditWidget::createRegroupement()
{
    // Création du nouveau regroupement.
    m_modelRegroupementChoix->createRegroupement();
    
    // Sélection du regroupement dernièrement créé.
    m_champRegroupement->setCurrentIndex(m_modelRegroupementChoix->rowCount() - 1);
    
    // Activation du bouton supprimé (ce bouton est désactivé dans le cas où il ne restait plus qu'un seul regroupement).
    m_boutonSupprimer->setEnabled(true);
}





void ListeRegroupementEditWidget::deleteRegroupement()
{
    // On récupère le regroupement à sélectionné et on vérifie qu'il ne contient plus aucun terrains.
    int index(m_champRegroupement->currentIndex());
    Regroupement* regroupement(m_modelRegroupementChoix->getRegroupement(index));
    
    if (regroupement->getNombreTerrains() != 0)
    {
        QMessageBox::information(this, tr("Suppression de regroupement"), tr("Vous ne pouvez pas supprimer un regroupement qui contient encore des terrains. Vous devez déplacer au préalable tous les terrains vers un autre regroupement."));
    }
    else
    {
        m_modelRegroupementChoix->deleteRegroupement(index);
        
        // Si après la suppression il ne reste plus qu'un regroupement dans la liste, on désactive le bouton Supprimer.
        if (m_modelRegroupementChoix->rowCount() <= 1)
        {
            m_boutonSupprimer->setEnabled(false);// On ne peut pas supprimer le dernier regroupement.
        }
    }
}

