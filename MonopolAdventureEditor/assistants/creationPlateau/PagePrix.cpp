#include "PagePrix.hpp"





PagePrix::PagePrix() :
    QWizardPage(),
    m_champDevise(new QLineEdit("€")),
    m_explicationCoef(new QLabel(tr("Dans l'éditeur, <strong>tous les prix doivent être compris entre 0 et 50&nbsp;000</strong>. Cependant, certaines version du Monopoly se jouent avec des montant bien plus élevés&nbsp;: par exemple, le joueur reçoit 2 milions lorsqu'il passe par la case Départ. Pour cela, on peut configurer un coefficient qui sera appliqué sur tous les prix. De manière général, il est conseillé d'appliquer des prix assez bas dans l'éditeur (par exemple : 200 pour le salaire de la case Départ), puis d'appliquer un coefficient pour changer la valeur des montants."))),
    m_coefPlus(new QPushButton("+")),
    m_coefMoins(new QPushButton("-")),
    m_champCoef(new QLabel("1")),
    m_champAffichageCompletPrix(new QCheckBox(tr("Affichage complet des prix"))),
    m_exempleAffichagePrix(new QLabel("<ul><li>1 500 000 000</li><li>20 000 000</li><li>14 500 000</li><li>500 000</li><li>200</li></ul>"))
{
    /* Configuration de la page
     */
    setTitle(tr("Devise et prix"));
    setSubTitle(tr("Dans cette page, vous allez configurer la devise et l'affichage des prix."));
    
    
    
    /* Configuration du contenu
     */
    m_explicationCoef->setWordWrap(true);
    m_explicationCoef->setAlignment(Qt::AlignJustify);
    
    m_coefPlus->setMaximumWidth(m_coefPlus->sizeHint().height());
    m_coefMoins->setMaximumWidth(m_coefMoins->sizeHint().height());
    m_champCoef->setMinimumWidth(90);
    m_champCoef->setAlignment(Qt::AlignCenter);
    
    m_champAffichageCompletPrix->setChecked(true);
    
    m_exempleAffichagePrix->setWordWrap(true);
    m_exempleAffichagePrix->setAlignment(Qt::AlignJustify);
    
    connect(m_coefPlus, SIGNAL(clicked()), this, SLOT(coefPlusClicked()));
    connect(m_coefMoins, SIGNAL(clicked()), this, SLOT(coefMoinsClicked()));
    connect(m_champAffichageCompletPrix, SIGNAL(stateChanged(int)), this, SLOT(affichageChanged(int)));
    
    
    
    /* Mise en forme du contenu
     */
    QHBoxLayout* layoutChampCoef(new QHBoxLayout);
    layoutChampCoef->addWidget(m_coefMoins);
    layoutChampCoef->addWidget(m_champCoef);
    layoutChampCoef->addWidget(m_coefPlus);
    layoutChampCoef->addStretch(1);
    
    QVBoxLayout* layoutCoef(new QVBoxLayout);
    layoutCoef->addWidget(m_explicationCoef);
    layoutCoef->addLayout(layoutChampCoef);
    
    QVBoxLayout* layoutAffichage(new QVBoxLayout);
    layoutAffichage->addWidget(m_champAffichageCompletPrix);
    layoutAffichage->addWidget(m_exempleAffichagePrix);
    
    
    QFormLayout* layout(new QFormLayout);
    layout->addRow(tr("Devise"), m_champDevise);
    layout->addRow(tr("Coefficient"), layoutCoef);
    layout->addRow(tr("Affichage"), layoutAffichage);
    
    setLayout(layout);
    
    
    
    /* Enregistrement des champs
     */
    registerField("devise_plateau", m_champDevise);
    registerField("coefficient_prix", m_champCoef, "text");
    registerField("affichage_complet_prix", m_champAffichageCompletPrix);
}





int PagePrix::nextId() const
{
    return 4;
}





void PagePrix::coefPlusClicked()
{
    switch (m_champCoef->text().toInt())
    {
        case 1:
            m_champCoef->setText("10");
            break;
        case 10:
            m_champCoef->setText("100");
            break;
        case 100:
            m_champCoef->setText("1 000");
            break;
        case 1000:
            m_champCoef->setText("10 000");
            break;
        case 10000:
            m_champCoef->setText("100 000");
            break;
        case 100000:
            m_champCoef->setText("1 000 000");
            break;
        case 1000000:
            m_champCoef->setText("10 000 000");
            break;
        case 10000000:
            m_champCoef->setText("100 000 000");
            break;
    }
}





void PagePrix::coefMoinsClicked()
{
    switch (m_champCoef->text().toInt())
    {
        case 10:
            m_champCoef->setText("1");
            break;
        case 100:
            m_champCoef->setText("10");
            break;
        case 1000:
            m_champCoef->setText("100");
            break;
        case 10000:
            m_champCoef->setText("1 000");
            break;
        case 100000:
            m_champCoef->setText("10 000");
            break;
        case 1000000:
            m_champCoef->setText("100 000");
            break;
        case 10000000:
            m_champCoef->setText("1 000 000");
            break;
        case 100000000:
            m_champCoef->setText("10 000 000");
            break;
    }
}





void PagePrix::affichageChanged(int state)
{
    if (state == Qt::Checked)
    {
        m_exempleAffichagePrix->setText("<ul><li>1 500 000 000</li><li>20 000 000</li><li>14 500 000</li><li>500 000</li><li>200</li></ul>");
    }
    else if (state == Qt::Unchecked)
    {
        m_exempleAffichagePrix->setText("<ul><li>1 500M</li><li>20M</li><li>14,5M</li><li>500k</li><li>200</li></ul>");
    }
}

