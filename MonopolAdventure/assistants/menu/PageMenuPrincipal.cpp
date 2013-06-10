#include "PageMenuPrincipal.hpp"





PageMenuPrincipal::PageMenuPrincipal() :
    QWidget(),
    m_modeClassique(new QPushButton(tr("Mode Classique"))),
    m_modeAventure(new QPushButton(tr("Mode Aventure"))),
    m_modeEnLigne(new QPushButton(tr("Mode En-Ligne"))),
    m_quitter(new QPushButton(tr("Quitter")))
{
    /* Configuration des boutons.
     */
    m_modeEnLigne->setDisabled(true);// Ce mode n'est pas encore développé.
    
    
    
    /* Mise en forme du widget.
     */
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_modeClassique);
    layout->addWidget(m_modeAventure);
    layout->addWidget(m_modeEnLigne);
    layout->addWidget(m_quitter);
    setLayout(layout);
    
    
    
    /* Connexion des signaux.
     */
    connect(m_modeClassique, SIGNAL(clicked()), this, SIGNAL(modeClassiqueClicked()));
    connect(m_modeAventure, SIGNAL(clicked()), this, SIGNAL(modeAventureClicked()));
    connect(m_modeEnLigne, SIGNAL(clicked()), this, SIGNAL(modeEnLigneClicked()));
    connect(m_quitter, SIGNAL(clicked()), this, SIGNAL(quitterClicked()));
}

