#include "PanneauInfosJoueur.hpp"





PanneauInfosJoueur::PanneauInfosJoueur(const Joueur* const joueur,
                                       const QString& devise) :
    QDockWidget(joueur->getPseudo()),
    m_widgetCentral(new QWidget),
    m_devise(devise),
    m_argent(new QLabel(QString::number(joueur->getCagnotte()) + devise)),
    m_etatPlateau(new QGraphicsScene),
    m_vueEtatPlateau(new QGraphicsView)
{
    // Association de la vue et de la scène.
    m_vueEtatPlateau->setScene(m_etatPlateau);
    
    // Création du layout du widget central.
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_argent);
    layout->addWidget(m_vueEtatPlateau);
    m_widgetCentral->setLayout(layout);
    
    // Association du widget central.
    setWidget(m_widgetCentral);
}





void PanneauInfosJoueur::updateArgent(qint32 cagnotte)
{
    m_argent->setText(QString::number(cagnotte) + m_devise);
}

