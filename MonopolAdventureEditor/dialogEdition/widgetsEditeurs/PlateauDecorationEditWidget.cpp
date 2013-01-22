#include "PlateauDecorationEditWidget.hpp"

#include "donnees/Plateau.hpp"





PlateauDecorationEditWidget::PlateauDecorationEditWidget(Plateau* plateau) :
    QWidget(),
    m_plateau(plateau),
    m_champTitre(new QLineEdit(plateau->getTitre())),
    m_champCouleur(new ColorSelectWidget(this, plateau->getCouleurFond())),
    m_champImage(new ImageSelectWidget(this, plateau->getImage()))
{
    /* Mise en forme du contenu
     */
    QFormLayout* layout(new QFormLayout);
    layout->addRow(tr("Titre"), m_champTitre);
    layout->addRow(tr("Couleur de fond"), m_champCouleur);
    layout->addRow(tr("Image"), m_champImage);
    
    setLayout(layout);
    
    
    
    /* Connexion de signaux et slots.
     */
    connect(m_champCouleur, SIGNAL(colorChange(QColor)), m_champImage, SLOT(setBackgroundColor(QColor)));
}





void PlateauDecorationEditWidget::sauvegarde()
{
    m_plateau->editTitre(m_champTitre->text());
    m_plateau->editCouleurFond(m_champCouleur->getColor());
    m_plateau->editImage(m_champImage->getImage());
}

