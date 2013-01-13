#include "ListeRegroupementEditWidget.hpp"





ListeRegroupementEditWidget::ListeRegroupementEditWidget(QList<Regroupement*>& regroupements) :
    QWidget(),
    m_regroupements(regroupements),
    m_modeleRegroupement(new RegroupementListModel(m_regroupements)),
    m_vueRegroupements(new QComboBox),
    m_boutonCreer(new QPushButton(tr("Ajouter un nouveau regroupement"))),
    m_boutonSupprimer(new QPushButton(tr("Supprimer ce regroupement"))),
    m_widgetEditionRegroupement(new RegroupementEditWidget(m_regroupements.first(), m_modeleRegroupement->getModeleRegroupementsSelectionnables()))
{
    /* Configuration des champs.
     */
    m_vueRegroupements->setModel(m_modeleRegroupement);
    connect(m_vueRegroupements, SIGNAL(currentIndexChanged(int)), this, SLOT(changeRegroupementEdite(int)));
    connect(m_boutonCreer, SIGNAL(clicked()), this, SLOT(createRegroupement()));
    connect(m_boutonSupprimer, SIGNAL(clicked()), this, SLOT(deleteRegroupement()));
    
    if (m_modeleRegroupement->rowCount() <= 1)
    {
        m_boutonSupprimer->setEnabled(false);// On ne peut pas supprimer le dernier regroupement.
    }
    
    
    
    /* Mise en forme.
     */
    QHBoxLayout* layoutHaut(new QHBoxLayout);
    layoutHaut->addWidget(m_vueRegroupements);
    layoutHaut->addWidget(m_boutonSupprimer);
    layoutHaut->addWidget(m_boutonCreer);
    
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addLayout(layoutHaut);
    layout->addWidget(m_widgetEditionRegroupement);
    
    setLayout(layout);
    
    
    
    connect(m_widgetEditionRegroupement, SIGNAL(titreChanged(Regroupement*,QString)), m_modeleRegroupement, SLOT(editTitreRegroupement(Regroupement*,QString)));
    connect(m_widgetEditionRegroupement, SIGNAL(couleurChanged(Regroupement*,QColor)), m_modeleRegroupement, SLOT(editCouleurRegroupement(Regroupement*,QColor)));
}





void ListeRegroupementEditWidget::selectionneRegroupement(int row)
{
    m_vueRegroupements->setCurrentIndex(row);
}





void ListeRegroupementEditWidget::changeRegroupementEdite(int index)
{
    // Récupère le regroupement associé à l'index sélectionné.
    m_widgetEditionRegroupement->changeRegroupement(m_modeleRegroupement->getRegroupementAt(index));
}





void ListeRegroupementEditWidget::createRegroupement()
{
    m_vueRegroupements->setCurrentIndex(m_modeleRegroupement->createRegroupement());
    m_boutonSupprimer->setEnabled(true);
}





void ListeRegroupementEditWidget::deleteRegroupement()
{
    /* NOTE : Le modèle de données contient ici au moins deux regroupements. S'il n'en restait qu'un, le bouton
     * « Supprimer » aurait été désactivé.
     */
    int rowSelectionne(m_vueRegroupements->currentIndex());
    if (m_modeleRegroupement->getRegroupementAt(rowSelectionne)->rowCount() != 0)
    {
        QMessageBox::information(this, tr("Suppression de regroupement"), tr("Attention ! Vous ne pouvez pas supprimer un regroupement qui contient encore des terrains. Veuillez déplacer tous les terrains vers un autre regroupement pour pouvoir le supprimer."));
    }
    else
    {
        /* Suppression du regroupement.
         */
        m_modeleRegroupement->deleteRegroupementAt(rowSelectionne);
        
        
        /* Sélection d'un nouveau regroupement pour l'édition.
         * Si le regroupement à supprimer est le dernier de la liste, on sélectionne le précédent. Sinon, on sélectionne
         * le suivant.
         */
        if (rowSelectionne == m_modeleRegroupement->rowCount() - 1)
        {
            m_widgetEditionRegroupement->changeRegroupement(m_modeleRegroupement->getRegroupementAt(rowSelectionne - 1));
        }
        else
        {
            m_widgetEditionRegroupement->changeRegroupement(m_modeleRegroupement->getRegroupementAt(rowSelectionne + 1));
        }
    }
    
    
    
    /* S'il n'y a plus qu'un seul regroupement, on désactive la suppression.
     */
    if (m_modeleRegroupement->rowCount() == 1)
    {
        m_boutonSupprimer->setEnabled(false);
    }
}

