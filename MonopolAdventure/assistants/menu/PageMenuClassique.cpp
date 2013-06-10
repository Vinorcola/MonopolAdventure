#include "PageMenuClassique.hpp"





PageMenuClassique::PageMenuClassique() :
    QWidget(),
    m_nouvellePartie(new QPushButton(tr("Commencer une nouvelle Partie"))),
    m_chargerPartie(new QPushButton(tr("Charger une Partie"))),
    m_retour(new QPushButton(tr("Retour")))
{
    /* Configuration des boutons.
     */
    m_chargerPartie->setDisabled(true);// Pas encore disponible.
    
    
    
    /* Mise en forme du widget.
     */
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_nouvellePartie);
    layout->addWidget(m_chargerPartie);
    layout->addWidget(m_retour);
    setLayout(layout);
    
    
    
    /* Connexion des signaux.
     */
    connect(m_nouvellePartie, SIGNAL(clicked()), this, SIGNAL(nouvellePartieClicked()));
    connect(m_chargerPartie, SIGNAL(clicked()), this, SIGNAL(chargerPartieClicked()));
    connect(m_retour, SIGNAL(clicked()), this, SIGNAL(retourClicked()));
}

