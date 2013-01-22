#include "PagePrix.hpp"





PagePrix::PagePrix(Plateau* plateau) :
    QWizardPage(),
    m_champPrix(new AffichagePrixEditWidget(plateau))
{
    /* Configuration de la page
     */
    setTitle(tr("Devise et prix"));
    setSubTitle(tr("Dans cette page, vous allez configurer la devise et l'affichage des prix."));
    
    
    
    /* Mise en forme du contenu
     */
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_champPrix);
    
    setLayout(layout);
}





int PagePrix::nextId() const
{
    return 5;
}





void PagePrix::sauvegarde()
{
    m_champPrix->sauvegarde();
}

