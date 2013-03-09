#include "PageRegle.hpp"

#include "donnees/Plateau.hpp"





PageRegle::PageRegle(Plateau* plateau) :
    QWizardPage(),
    m_plateau(plateau),
    m_widgetCentral(new RegleConfigWidget)
{
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_widgetCentral);
    
    setLayout(layout);
}





void PageRegle::initializePage()
{
    m_widgetCentral->setRegle(&m_plateau->getRegle());/** @todo Passer le salaire en paramètre. */
}

