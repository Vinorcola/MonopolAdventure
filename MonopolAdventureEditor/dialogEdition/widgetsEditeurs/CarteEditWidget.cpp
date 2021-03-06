#include "CarteEditWidget.hpp"





CarteEditWidget::CarteEditWidget(Carte* carte,
                                 const QList<Emplacement*>& emplacements,
                                 const QList<PileCartes*>& pilesCartes) :
    QTabWidget(),
    m_carte(carte),
    m_consigne(new QTextEdit(carte->getConsigne())),
    m_image(new ImageSelectWidget(this, carte->getImage())),
    m_gauche(new QRadioButton(tr("Image à gauche du texte."))),
    m_droite(new QRadioButton(tr("Image à droite du texte."))),
    m_haut(new QRadioButton(tr("Image au-dessus du texte."))),
    m_bas(new QRadioButton(tr("Image en dessous du texte."))),
    m_positionImage(new QButtonGroup),
    m_action(new ActionEditWidget(&(carte->getAction()), emplacements, pilesCartes))
{
    // Configuration
    QWidget* onglet(new QWidget);
    
    m_positionImage->addButton(m_gauche);
    m_positionImage->addButton(m_droite);
    m_positionImage->addButton(m_haut);
    m_positionImage->addButton(m_bas);
    switch (carte->getDispositionImage())
    {
        case Carte::GAUCHE:
            m_gauche->setChecked(true);
            break;
            
        case Carte::DROITE:
            m_droite->setChecked(true);
            break;
            
        case Carte::HAUT:
            m_haut->setChecked(true);
            break;
            
        case Carte::BAS:
            m_bas->setCheckable(true);
            break;
    }
    
    QVBoxLayout* layoutPositionImage(new QVBoxLayout);
    layoutPositionImage->addWidget(m_gauche);
    layoutPositionImage->addWidget(m_droite);
    layoutPositionImage->addWidget(m_haut);
    layoutPositionImage->addWidget(m_bas);
    
    
    
    // Mise en forme
    QFormLayout* layout(new QFormLayout);
    layout->addRow(tr("Consigne"), m_consigne);
    layout->addRow(tr("Image"), m_image);
    layout->addRow(tr("Position de l'image"), layoutPositionImage);
    onglet->setLayout(layout);
    
    addTab(onglet, "Configuration de la carte");
    addTab(m_action, "Configuration de l'action");
}





void CarteEditWidget::sauvegarde()
{
    m_action->sauvegarde();
    m_carte->editConsigne(m_consigne->toPlainText());
    m_carte->editImage(m_image->getImage());
    
    if (m_gauche->isChecked())
    {
        m_carte->editDispositionImage(Carte::GAUCHE);
    }
    else if (m_droite->isChecked())
    {
        m_carte->editDispositionImage(Carte::DROITE);
    }
    else if (m_haut->isChecked())
    {
        m_carte->editDispositionImage(Carte::HAUT);
    }
    else if (m_bas->isChecked())
    {
        m_carte->editDispositionImage(Carte::BAS);
    }
}
