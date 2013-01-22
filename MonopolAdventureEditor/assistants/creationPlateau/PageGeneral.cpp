#include "PageGeneral.hpp"





PageGeneral::PageGeneral(Plateau* plateau) :
    QWizardPage(),
    m_champ(new PlateauDecorationEditWidget(plateau))
{
    /* Configuration de la page
     */
    setTitle(tr("Image du plateau"));
    setSubTitle(tr("Sélectionnez la couleur de fond du plateau ainsi qu'une image à placer au centre du plateau."));
    
    
    
    /* Mise en forme du contenu
     */
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_champ);
    
    setLayout(layout);
}





int PageGeneral::nextId() const
{
    return 4;
}





void PageGeneral::sauvegarde()
{
    m_champ->sauvegarde();
}

