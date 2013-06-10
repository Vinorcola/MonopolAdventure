#include "PageMenuAventure.hpp"





PageMenuAventure::PageMenuAventure() :
    QWidget(),
    m_nouvelleAventure(new QPushButton(tr("Commencer une nouvelle Aventure"))),
    m_chargerAventure(new QPushButton(tr("Charger une Aventure"))),
    m_retour(new QPushButton(tr("Retour")))
{
    /* Configuration des boutons.
     */
    m_nouvelleAventure->setDisabled(true);// Pas encore disponible.
    m_chargerAventure->setDisabled(true);// Pas encore disponible.
    
    
    
    /* Mise en forme du widget.
     */
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_nouvelleAventure);
    layout->addWidget(m_chargerAventure);
    layout->addWidget(m_retour);
    setLayout(layout);
    
    
    
    /* Connexion des signaux.
     */
    connect(m_nouvelleAventure, SIGNAL(clicked()), this, SIGNAL(nouvelleAventureClicked()));
    connect(m_chargerAventure, SIGNAL(clicked()), this, SIGNAL(chargerAventureClicked()));
    connect(m_retour, SIGNAL(clicked()), this, SIGNAL(retourClicked()));
}

