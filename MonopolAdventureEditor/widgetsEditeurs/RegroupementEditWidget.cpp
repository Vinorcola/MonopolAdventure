#include "RegroupementEditWidget.hpp"





RegroupementEditWidget::RegroupementEditWidget(SelectionRegroupementListModel* regroupementModel,
                                               Regroupement* regroupement) :
    QWidget(),
    m_regroupementModel(regroupementModel),
    m_regroupement(0),
    m_champTitre(new QLineEdit),
    m_champCouleur(new ColorSelectWidget(this)),
    m_champListeTerrains(new QListView),
    m_boutonAdd(new QPushButton(tr("< Ajouter <"))),
    m_boutonRemove(new QPushButton(tr("> Enlever >"))),
    m_selectAutreRegroupement(new QComboBox),
    m_listeTerrainsDisponibles(new QListView)
    
{
    /* Configuration des champs.
     */
    connect(m_champTitre, SIGNAL(textChanged(QString)), this, SLOT(champTitreChanged(QString)));
    connect(m_champCouleur, SIGNAL(colorChange(QColor)), this, SLOT(champCouleurChanged(QColor)));
    connect(m_selectAutreRegroupement, SIGNAL(currentIndexChanged(int)), this, SLOT(selectAutreRegroupementChanged(int)));
    connect(m_boutonAdd, SIGNAL(clicked()), this, SLOT(boutonAddClicked()));
    connect(m_boutonRemove, SIGNAL(clicked()), this, SLOT(boutonRemoveClicked()));
    
    // Les slots doivent être connectés avant les deux configurations suivantes :
    m_selectAutreRegroupement->setModel(m_regroupementModel);
    changeRegroupement(regroupement);
    
    
    
    /* Mise en forme.
     */
    QVBoxLayout* layoutBouton(new QVBoxLayout);
    layoutBouton->addWidget(m_boutonAdd);
    layoutBouton->addWidget(m_boutonRemove);
    
    QVBoxLayout* layoutTerrainDispo(new QVBoxLayout);
    layoutTerrainDispo->addWidget(m_selectAutreRegroupement);
    layoutTerrainDispo->addWidget(m_listeTerrainsDisponibles);
    
    QHBoxLayout* layoutListe(new QHBoxLayout);
    layoutListe->addWidget(m_champListeTerrains);
    layoutListe->addLayout(layoutBouton);
    layoutListe->addLayout(layoutTerrainDispo);
    
    QFormLayout* layout(new QFormLayout);
    layout->addRow(tr("Titre"), m_champTitre);
    layout->addRow(tr("Couleur"), m_champCouleur);
    layout->addRow(tr("Terrains"), layoutListe);
    
    setLayout(layout);
}





void RegroupementEditWidget::changeRegroupement(Regroupement* regroupement)
{
    if (regroupement)
    {
        m_regroupement = regroupement;
        updateRegroupement();
        
        if (m_regroupementModel->rowCount() <= 1)
        {
            m_boutonAdd->setEnabled(false);
            m_boutonRemove->setEnabled(false);
            m_selectAutreRegroupement->setEnabled(false);
            m_listeTerrainsDisponibles->setEnabled(false);
        }
        else
        {
            m_boutonAdd->setEnabled(true);
            m_boutonRemove->setEnabled(true);
            m_selectAutreRegroupement->setEnabled(true);
            m_listeTerrainsDisponibles->setEnabled(true);
        }
    }
}





void RegroupementEditWidget::champTitreChanged(const QString& titre)
{
    m_regroupement->editTitre(titre);
}





void RegroupementEditWidget::champCouleurChanged(const QColor& couleur)
{
    m_regroupement->editCouleur(couleur);
}





void RegroupementEditWidget::boutonAddClicked()
{
    static_cast<TerrainListModel*>(m_listeTerrainsDisponibles->model())->transfererTerrain(m_listeTerrainsDisponibles->currentIndex().row(), static_cast<TerrainListModel*>(m_champListeTerrains->model()));
}





void RegroupementEditWidget::boutonRemoveClicked()
{
    static_cast<TerrainListModel*>(m_champListeTerrains->model())->transfererTerrain(m_champListeTerrains->currentIndex().row(), static_cast<TerrainListModel*>(m_listeTerrainsDisponibles->model()));
}





void RegroupementEditWidget::selectAutreRegroupementChanged(int row)
{
    // Met à jour la liste des terrains disponibles dans un autre regroupement.
    m_listeTerrainsDisponibles->setModel(m_regroupementModel->getTerrainListModel(row));
}





void RegroupementEditWidget::updateRegroupement()
{
    int index(m_regroupementModel->getRow(m_regroupement));
    
    // Mise à jour de la liste des terrains contenus dans le regroupement.
    m_champListeTerrains->setModel(m_regroupementModel->getTerrainListModel(index));
    
    // Met à jour les champs titre et couleur.
    m_champTitre->setText(m_regroupement->getTitre());
    m_champCouleur->setColor(m_regroupement->getCouleur());
    
    // Met à jour la liste de regroupements
    m_regroupementModel->notifyRegroupementInactif(m_regroupement);
    
    
    // Si il ne reste plus qu'un regroupement, on le sélectionne (les listes seront désactivés)
    if (m_regroupementModel->rowCount() == 1)
    {
        m_selectAutreRegroupement->setCurrentIndex(0);
    }
    // Si le regroupement rendu inactif était déjà sélectionné :
    else if (m_selectAutreRegroupement->currentIndex() == index)
    {
        if (m_regroupementModel->rowCount() - 1 == index)
        // Si le regroupement sélectionné est le dernier, on sélectionne le précédent.
        {
            m_selectAutreRegroupement->setCurrentIndex(index - 1);
        }
        else
        // Sinon, on prend le suivant.
        {
            m_selectAutreRegroupement->setCurrentIndex(index + 1);
        }
    }
}

