#include "PageTaille.hpp"





PageTaille::PageTaille() :
    QWizardPage(),
    m_champTitre(new QLineEdit("Nouveau plateau")),
    m_champPetit(new QRadioButton("Junior")),
    m_champNormal(new QRadioButton("Classique")),
    m_champGrand(new QRadioButton("Mega")),
    m_champPerso(new QRadioButton("Personnalisée :")),
    m_champLargeur(new QSpinBox),
    m_labelX(new QLabel("<center>x</center>")),
    m_champHauteur(new QSpinBox)
{
    /* Configuration de la page
     */
    setTitle(tr("Titre et taille du plateau"));
    setSubTitle(tr("Veuillez nommer votre plateau et configurer sa taille."));
    
    
    
    /* Configuration du contenu
     */
    m_champNormal->setChecked(true);
    
    m_champLargeur->setMinimum(3);
    m_champLargeur->setMaximum(50);
    m_champLargeur->setValue(11);
    m_champLargeur->setEnabled(false);
    
    m_labelX->setEnabled(false);
    
    m_champHauteur->setMinimum(3);
    m_champHauteur->setMaximum(50);
    m_champHauteur->setValue(11);
    m_champHauteur->setEnabled(false);
    
    QButtonGroup* radioGroupe(new QButtonGroup);
    radioGroupe->addButton(m_champPetit, 1);
    radioGroupe->addButton(m_champNormal, 2);
    radioGroupe->addButton(m_champGrand, 3);
    radioGroupe->addButton(m_champPerso, 4);
    
    connect(radioGroupe, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(buttonClicked(QAbstractButton*)));
    
    
    
    /* Mise en forme du contenu
     */
    QHBoxLayout* layoutPerso(new QHBoxLayout);
    layoutPerso->addWidget(m_champPerso);
    layoutPerso->addWidget(m_champLargeur);
    layoutPerso->addWidget(m_labelX);
    layoutPerso->addWidget(m_champHauteur);
    layoutPerso->addStretch(1);
    
    QVBoxLayout* layoutRadio(new QVBoxLayout);
    layoutRadio->addWidget(m_champPetit);
    layoutRadio->addWidget(m_champNormal);
    layoutRadio->addWidget(m_champGrand);
    layoutRadio->addLayout(layoutPerso);
    
    QFormLayout* layout(new QFormLayout);
    layout->addRow(tr("Titre"), m_champTitre);
    layout->addRow(tr("Taille"), layoutRadio);
    
    setLayout(layout);
    
    
    
    /* Enregistrement des champs
     */
    registerField("titre_plateau", m_champTitre);
    registerField("largeur_plateau", m_champLargeur);
    registerField("hauteur_plateau", m_champHauteur);
}





int PageTaille::nextId() const
{
    return 3;
}





void PageTaille::buttonClicked(QAbstractButton* bouton)
{
    if (bouton == m_champPetit)
    {
        m_champLargeur->setValue(11);
        m_champHauteur->setValue(7);
        
        m_champLargeur->setEnabled(false);
        m_labelX->setEnabled(false);
        m_champHauteur->setEnabled(false);
    }
    else if (bouton ==  m_champNormal)
    {
        m_champLargeur->setValue(11);
        m_champHauteur->setValue(11);
        
        m_champLargeur->setEnabled(false);
        m_labelX->setEnabled(false);
        m_champHauteur->setEnabled(false);
    }
    else if (bouton ==  m_champGrand)
    {
        m_champLargeur->setValue(14);
        m_champHauteur->setValue(14);
        
        m_champLargeur->setEnabled(false);
        m_labelX->setEnabled(false);
        m_champHauteur->setEnabled(false);
    }
    else if (bouton == m_champPerso)
    {
        m_champLargeur->setEnabled(true);
        m_labelX->setEnabled(true);
        m_champHauteur->setEnabled(true);
    }
}

