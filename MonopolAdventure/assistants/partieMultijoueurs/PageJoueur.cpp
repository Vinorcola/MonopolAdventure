#include "PageJoueur.hpp"





PageJoueur::PageJoueur() :
    QWizardPage(),
    m_joueurs()
{
    // Pour le moment, on créé 4 joueurs.
    m_joueurs.append(new JoueurConfigWidget);
    m_joueurs.append(new JoueurConfigWidget);
    m_joueurs.append(new JoueurConfigWidget);
    m_joueurs.append(new JoueurConfigWidget);
    
    
    
    /* Mise en forme des widgets.
     */
    QVBoxLayout* layout = new QVBoxLayout;
    for (int i(0), iEnd(m_joueurs.size()); i < iEnd; i++)
    {
        layout->addWidget(m_joueurs.at(i));
    }
    setLayout(layout);
}

