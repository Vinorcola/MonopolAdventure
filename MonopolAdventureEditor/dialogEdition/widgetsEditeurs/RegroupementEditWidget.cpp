#include "RegroupementEditWidget.hpp"





RegroupementEditWidget::RegroupementEditWidget(Regroupement* regroupement,
                                               SelectionRegroupementListModel* modeleRegroupementsSelectionnables) :
    QWidget(),
    m_regroupement(regroupement),
    m_champTitre(new QLineEdit(regroupement ? regroupement->getTitre() : "")),
    m_champCouleur(new ColorSelectWidget(this, regroupement ? regroupement->getCouleur() : QColor(255, 255, 255))),
    m_modeleRegroupementsSelectionnables(modeleRegroupementsSelectionnables),
    m_vueRegroupementsSelectionnables(new QComboBox),
    m_vueTerrainsInternes(new QListView),
    m_vueTerrainsExternes(new QListView),
    m_boutonAjouter(new QPushButton("< " + tr("Ajouter") + " <")),
    m_boutonEnlever(new QPushButton("> " + tr("Enlever") + " >"))
{
    /* Détermination du regroupement sélectionné (pour l'importation des terrains dans le regroupement en cours 
     * d'édition).
     */
    int rowSelectionne(0);
    if (m_modeleRegroupementsSelectionnables->rowCount() > 1)
    {
        if (regroupement == m_modeleRegroupementsSelectionnables->getRegroupementAt(rowSelectionne))
        {
            /* Si le regroupement en cours d'édition est le premier de la liste, alors on sélectionne le deuxième.
             */
            rowSelectionne = 1;
        }
    }
    else
    {
        /* On désactive les champs car il n'y a qu'un seul regroupement dans le modèle de données.
         */
        m_vueRegroupementsSelectionnables->setEnabled(false);
        m_vueTerrainsExternes->setEnabled(false);
        m_boutonAjouter->setEnabled(false);
        m_boutonEnlever->setEnabled(false);
    }
    
    
    
    /* Associations modèles/vues.
     */
    m_vueRegroupementsSelectionnables->setModel(m_modeleRegroupementsSelectionnables);
    m_vueRegroupementsSelectionnables->setCurrentIndex(rowSelectionne);
    m_vueTerrainsInternes->setModel(regroupement);
    m_vueTerrainsExternes->setModel(m_modeleRegroupementsSelectionnables->getRegroupementAt(rowSelectionne));
    
    
    
    /* Configuration des champs.
     */
    connect(m_champTitre, SIGNAL(textChanged(QString)), this, SLOT(changeTitre(QString)));
    connect(m_champCouleur, SIGNAL(colorChange(QColor)), this, SLOT(changeCouleur(QColor)));
    connect(m_vueRegroupementsSelectionnables, SIGNAL(currentIndexChanged(int)), this, SLOT(changeModeleTerrainsExterne(int)));
    connect(m_boutonAjouter, SIGNAL(clicked()), this, SLOT(ajouterTerrain()));
    connect(m_boutonEnlever, SIGNAL(clicked()), this, SLOT(enleverTerrain()));
    
    
    
    /* Mise en forme.
     */
    QVBoxLayout* layoutBouton(new QVBoxLayout);
    layoutBouton->addWidget(m_boutonAjouter);
    layoutBouton->addWidget(m_boutonEnlever);
    
    QVBoxLayout* layoutTerrainsExternes(new QVBoxLayout);
    layoutTerrainsExternes->addWidget(m_vueRegroupementsSelectionnables);
    layoutTerrainsExternes->addWidget(m_vueTerrainsExternes);
    
    QHBoxLayout* layoutTerrains(new QHBoxLayout);
    layoutTerrains->addWidget(m_vueTerrainsInternes);
    layoutTerrains->addLayout(layoutBouton);
    layoutTerrains->addLayout(layoutTerrainsExternes);
    
    QFormLayout* layout(new QFormLayout);
    layout->addRow(tr("Titre"), m_champTitre);
    layout->addRow(tr("Couleur"), m_champCouleur);
    layout->addRow(tr("Terrains"), layoutTerrains);
    
    setLayout(layout);
}





void RegroupementEditWidget::changeRegroupement(Regroupement* regroupement)
{
    if (regroupement)
    {
        /* Mise à jour des champs d'édition.
         */
        m_regroupement = regroupement;
        m_champTitre->setText(m_regroupement->getTitre());
        m_champCouleur->setColor(m_regroupement->getCouleur());
        m_vueTerrainsInternes->setModel(m_regroupement);
        
        
        
        /* Configuration de la liste des regroupements sélectionnables.
         */
        m_modeleRegroupementsSelectionnables->notifyRegroupementInactif(m_regroupement);
        int indexCourant(m_vueRegroupementsSelectionnables->currentIndex());
        if (m_modeleRegroupementsSelectionnables->rowCount() == 1)
        {
            /* Dans le cas où il ne reste plus qu'un regroupement dans le modèle de données, alors on le sélectionne,
             * puis on désactive les champs associés.
             */
            indexCourant = 0;
            m_vueRegroupementsSelectionnables->setCurrentIndex(indexCourant);
            m_vueRegroupementsSelectionnables->setEnabled(false);
            m_vueTerrainsExternes->setEnabled(false);
            m_boutonAjouter->setEnabled(false);
            m_boutonEnlever->setEnabled(false);
        }
        else
        {
            /* Dans le cas où il y a plusieurs regroupements dans le modèle de données, alors on active les champs. Si
             * le regroupement en cours d'édition était celui sélectionné au préalable, alors on sélectionne le suivant
             * (ou le précédent s'il était le dernier de la liste).
             */
            if (!m_modeleRegroupementsSelectionnables->isSelectionnable(indexCourant))
            {
                if (indexCourant == m_modeleRegroupementsSelectionnables->rowCount() - 1)
                {
                    indexCourant--;
                }
                else
                {
                    indexCourant++;
                }
                
                m_vueRegroupementsSelectionnables->setCurrentIndex(indexCourant);
            }
            
            m_vueRegroupementsSelectionnables->setEnabled(true);
            m_vueTerrainsExternes->setEnabled(true);
            m_boutonAjouter->setEnabled(true);
            m_boutonEnlever->setEnabled(true);
        }
        
        /* Mise à jour de la liste des terrains importable.
         */
        m_vueTerrainsExternes->setModel(m_modeleRegroupementsSelectionnables->getRegroupementAt(indexCourant));
    }
}





void RegroupementEditWidget::changeModeleTerrainsExterne(int rowRegroupementSelectionne)
{
    m_vueTerrainsExternes->setModel(m_modeleRegroupementsSelectionnables->getRegroupementAt(rowRegroupementSelectionne));
}





void RegroupementEditWidget::ajouterTerrain()
{
    m_modeleRegroupementsSelectionnables->getRegroupementAt(m_vueRegroupementsSelectionnables->currentIndex())
        ->transfereTerrainA(m_regroupement, m_vueTerrainsExternes->currentIndex().row());
}





void RegroupementEditWidget::enleverTerrain()
{
    m_regroupement->transfereTerrainA(
        m_modeleRegroupementsSelectionnables->getRegroupementAt(m_vueRegroupementsSelectionnables->currentIndex()),
        m_vueTerrainsInternes->currentIndex().row());
}





void RegroupementEditWidget::changeTitre(QString titre)
{
    emit titreChanged(m_regroupement, titre);
}





void RegroupementEditWidget::changeCouleur(QColor couleur)
{
    emit couleurChanged(m_regroupement, couleur);
}

