#include "PageGraphisme.hpp"





PageGraphisme::PageGraphisme(Plateau* plateau) :
    QWizardPage(),
    m_champ(new GraphismeEmplacementEditWidget(plateau))
{
    /* Configuration de la page
     */
    setTitle(tr("Graphisme des emplacements"));
    setSubTitle(tr("Sur cette page, vous allez configurer les graphismes des emplacements."));
    
    
    
    /* Mise en forme du contenu
     */
    QHBoxLayout* layout(new QHBoxLayout);
    layout->addWidget(m_champ);
    
    setLayout(layout);
}





int PageGraphisme::nextId() const
{
    return -1;
}





void PageGraphisme::sauvegarde()
{
    m_champ->sauvegarde();
}

