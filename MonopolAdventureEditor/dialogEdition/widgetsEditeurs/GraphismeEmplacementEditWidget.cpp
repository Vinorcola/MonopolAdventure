#include "GraphismeEmplacementEditWidget.hpp"

#include "donnees/Plateau.hpp"





GraphismeEmplacementEditWidget::GraphismeEmplacementEditWidget(Plateau* plateau) :
    QWidget(),
    m_plateau(plateau),
    m_champLargeur(new QSpinBox),
    m_champHauteur(new QSpinBox),
    m_champHauteurCouleurRegroupement(new QSpinBox),
    m_champCouleurFond(new ColorSelectWidget(this, QColor(255, 255, 128))),
    m_champCouleurBordure(new ColorSelectWidget(this, QColor(0, 0, 0))),
    m_champEpaisseurBordure(new QSpinBox),
    m_champFonteTitre(new FontSelectWidget(this, QFont("Comic Sans MS", 20, QFont::Bold))),
    m_champFonteSousTitre(new FontSelectWidget(this, QFont("Arial", 16))),
    m_champFonteDescription(new FontSelectWidget(this, QFont("Arial", 12))),
    m_champFontePrix(new FontSelectWidget(this, QFont("DejaVu Sans Mono", 12))),
    m_champMarge(new QSpinBox)
{
    /* Configuration du contenu
     */
    m_champLargeur->setMinimum(200);
    m_champLargeur->setMaximum(500);
    m_champLargeur->setSingleStep(10);
    m_champLargeur->setValue(plateau->getTailleEmplacementsNormaux().width());
    
    m_champHauteur->setMinimum(200);
    m_champHauteur->setMaximum(650);
    m_champHauteur->setSingleStep(10);
    m_champHauteur->setValue(plateau->getTailleEmplacementsNormaux().height());
    
    m_champHauteurCouleurRegroupement->setMinimum(0);
    m_champHauteurCouleurRegroupement->setMaximum(150);
    m_champHauteurCouleurRegroupement->setSingleStep(5);
    m_champHauteurCouleurRegroupement->setValue(plateau->getHauteurRectangleCouleur());
    
    m_champEpaisseurBordure->setMinimum(0);
    m_champEpaisseurBordure->setMaximum(10);
    m_champEpaisseurBordure->setValue(plateau->getCrayonBordureEmplacement().width());
    
    m_champMarge->setMinimum(0);
    m_champMarge->setMaximum(20);
    m_champMarge->setValue(plateau->getMarge());
    
    
    
    /* Mise en forme du contenu
     */
    QHBoxLayout* layoutTaille(new QHBoxLayout);
    layoutTaille->addWidget(m_champLargeur);
    layoutTaille->addWidget(new QLabel("X"));
    layoutTaille->addWidget(m_champHauteur);
    layoutTaille->addStretch(1);
    
    QFormLayout* layout(new QFormLayout);
    layout->addRow(tr("Taille des emplacements"), layoutTaille);
    layout->addRow(tr("Hauteur de la bande de couleur des terrains"), m_champHauteurCouleurRegroupement);
    layout->addRow(tr("Couleur de fond des emplacements"), m_champCouleurFond);
    layout->addRow(tr("Couleur de la bordure des emplacements"), m_champCouleurBordure);
    layout->addRow(tr("Épaisseur de la bordure des emplacements"), m_champEpaisseurBordure);
    layout->addRow(tr("Fonte de caractère du titre"), m_champFonteTitre);
    layout->addRow(tr("Fonte de caractère du sous-titre"), m_champFonteSousTitre);
    layout->addRow(tr("Fonte de caractère de la description"), m_champFonteDescription);
    layout->addRow(tr("Fonte de caractère du prix"), m_champFontePrix);
    layout->addRow(tr("Marge minimale entre le texte et la bordure"), m_champMarge);
    
    setLayout(layout);
}





void GraphismeEmplacementEditWidget::sauvegarde()
{
    m_plateau->editTailleEmplacements(QSize(m_champLargeur->value(), m_champHauteur->value()));
    m_plateau->editHauteurRectangleCouleur(m_champHauteurCouleurRegroupement->value());
    m_plateau->editCouleurFondEmplacement(m_champCouleurFond->getColor());
    m_plateau->editCrayonBordureEmplacement(QPen(QBrush(m_champCouleurBordure->getColor()), m_champEpaisseurBordure->value()));
    m_plateau->editMarge(m_champMarge->value());
    m_plateau->editFonteTitreEmplacement(m_champFonteTitre->getFont());
    m_plateau->editFonteSousTitreEmplacement(m_champFonteSousTitre->getFont());
    m_plateau->editFonteDescriptionEmplacement(m_champFonteDescription->getFont());
    m_plateau->editFontePrixEmplacement(m_champFontePrix->getFont());
}

