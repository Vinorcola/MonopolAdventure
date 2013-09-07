#include "JoueurConfigWidget.hpp"





JoueurConfigWidget::JoueurConfigWidget() :
    QWidget(),
    m_pseudo(new QLineEdit),
    m_boutonSupprimer(new QPushButton(tr("x"))),
    m_listeCouleur(new QComboBox),
    m_modeleCouleur(new CouleurListModel(this))
{
    /* Mise en forme du widget.
     */
    QHBoxLayout* layout(new QHBoxLayout);
    layout->addWidget(m_pseudo);
    layout->addWidget(m_listeCouleur);
    layout->addWidget(m_boutonSupprimer);
    
    setLayout(layout);
    
    
    /* Configuration de la liste.
     */
    m_listeCouleur->setModel(m_modeleCouleur);
    
    
    /* Connexion des signals et slots.
     */
    connect(m_listeCouleur, SIGNAL(currentIndexChanged(int)), m_modeleCouleur, SLOT(setSelectedItem(int)));
    connect(m_boutonSupprimer, SIGNAL(clicked()), this, SIGNAL(supprimer()));
}





JoueurConfigWidget::~JoueurConfigWidget()
{
    m_listeCouleur->setCurrentIndex(0);
}





QString JoueurConfigWidget::pseudo()
{
    return m_pseudo->text();
}

