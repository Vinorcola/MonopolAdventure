#include "JoueurConfigWidget.hpp"





JoueurConfigWidget::JoueurConfigWidget() :
    QWidget(),
    m_pseudo(new QLineEdit),
    m_boutonSupprimer(new QPushButton(tr("x")))
{
    /* Mise en forme du widget.
     */
    QHBoxLayout* layout(new QHBoxLayout);
    layout->addWidget(m_pseudo);
    layout->addWidget(m_boutonSupprimer);
    
    setLayout(layout);
    
    
    /* Connexion des signals et slots.
     */
    connect(m_boutonSupprimer, SIGNAL(clicked()), this, SIGNAL(supprimer()));
}





QString JoueurConfigWidget::pseudo()
{
    return m_pseudo->text();
}

