#include "PageGraphisme.hpp"





PageGraphisme::PageGraphisme() :
    QWizardPage(),
    m_champLargeur(new QSpinBox),
    m_champHauteur(new QSpinBox),
    m_champHauteurCouleurGroupement(new QSpinBox),
    m_champCouleurFond(new ColorSelectWidget(this, QColor(255, 255, 128))),
    m_champCouleurBordure(new ColorSelectWidget(this, QColor(0, 0, 0))),
    m_champEpaisseurBordure(new QSpinBox),
    m_champPoliceTitre(new FontSelectWidget(this, QFont("Comic Sans MS", 20, QFont::Bold))),
    m_champPoliceSousTitre(new FontSelectWidget(this, QFont("Arial", 16))),
    m_champPoliceDescription(new FontSelectWidget(this, QFont("Arial", 12))),
    m_champPolicePrix(new FontSelectWidget(this, QFont("DejaVu Sans Mono", 12))),
    m_champMarge(new QSpinBox)
{
    /* Configuration de la page
     */
    setTitle(tr("Graphisme des emplacements"));
    setSubTitle(tr("Sur cette page, vous allez configurer les graphismes des emplacements."));
    
    
    
    /* Configuration du contenu
     */
    m_champLargeur->setMinimum(0);
    m_champLargeur->setMaximum(500);
    m_champLargeur->setSingleStep(10);
    m_champLargeur->setValue(200);
    
    m_champHauteur->setMinimum(0);
    m_champHauteur->setMaximum(650);
    m_champHauteur->setSingleStep(10);
    m_champHauteur->setValue(250);
    
    m_champHauteurCouleurGroupement->setMinimum(0);
    m_champHauteurCouleurGroupement->setMaximum(150);
    m_champHauteurCouleurGroupement->setSingleStep(5);
    m_champHauteurCouleurGroupement->setValue(50);
    
    m_champEpaisseurBordure->setMinimum(0);
    m_champEpaisseurBordure->setMaximum(10);
    m_champEpaisseurBordure->setValue(1);
    
    m_champMarge->setMinimum(0);
    m_champMarge->setMaximum(20);
    m_champMarge->setValue(5);
    
    
    
    /* Mise en forme du contenu
     */
    QHBoxLayout* layoutTaille(new QHBoxLayout);
    layoutTaille->addWidget(m_champLargeur);
    layoutTaille->addWidget(new QLabel("X"));
    layoutTaille->addWidget(m_champHauteur);
    layoutTaille->addStretch(1);
    
    QFormLayout* layout(new QFormLayout);
    layout->addRow(tr("Taille des emplacements"), layoutTaille);
    layout->addRow(tr("Hauteur de la bande de couleur des terrains"), m_champHauteurCouleurGroupement);
    layout->addRow(tr("Couleur de fond des emplacements"), m_champCouleurFond);
    layout->addRow(tr("Couleur de la bordure des emplacements"), m_champCouleurBordure);
    layout->addRow(tr("Épaisseur de la bordure des emplacements"), m_champEpaisseurBordure);
    layout->addRow(tr("Fonte de caractère du titre"), m_champPoliceTitre);
    layout->addRow(tr("Fonte de caractère du sous-titre"), m_champPoliceSousTitre);
    layout->addRow(tr("Fonte de caractère de la description"), m_champPoliceDescription);
    layout->addRow(tr("Fonte de caractère du prix"), m_champPolicePrix);
    layout->addRow(tr("Marge minimale entre le texte et la bordure"), m_champMarge);
    
    setLayout(layout);
    
    
    
    /* Enregistrement des champs
     */
    registerField("largeur_emplacement", m_champLargeur);
    registerField("hauteur_emplacement", m_champHauteur);
    registerField("hauteur_regroupement", m_champHauteurCouleurGroupement);
    registerField("couleur_emplacement", m_champCouleurFond, "color");
    registerField("couleur_bordure", m_champCouleurBordure, "color");
    registerField("epaisseur_bordure", m_champEpaisseurBordure);
    registerField("police_titre_emplacement", m_champPoliceTitre, "font");
    registerField("police_sousTitre_emplacement", m_champPoliceSousTitre, "font");
    registerField("police_description_emplacement", m_champPoliceDescription, "font");
    registerField("police_prix_emplacement", m_champPolicePrix, "font");
    registerField("marge", m_champMarge);
}





int PageGraphisme::nextId() const
{
    return -1;
}

