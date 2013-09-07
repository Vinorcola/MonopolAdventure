#include "PageRegle.hpp"

#include "donnees/Plateau.hpp"





PageRegle::PageRegle(Plateau* plateau) :
    QWizardPage(),
    m_plateau(plateau),
    m_widgetCentral(new RegleConfigWidget)
{
    /* Configuration de la page
     */
    setTitle(tr("Personnaliser les régles"));
    setSubTitle(tr("Dans cet onglet, vous pouvez personnaliser les régles avec lesquelles vous souhaitez jouer."));
    
    
    
    /* Mise en forme du contenu
     */
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_widgetCentral);
    
    setLayout(layout);
}





void PageRegle::initializePage()
{
    m_widgetCentral->setRegle(&m_plateau->getRegle(), m_plateau->helper_getSalaireDepart());
}

