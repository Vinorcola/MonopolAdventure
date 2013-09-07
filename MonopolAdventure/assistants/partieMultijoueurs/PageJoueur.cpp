#include "PageJoueur.hpp"





PageJoueur::PageJoueur() :
    QWizardPage(),
    m_joueurs(),
    m_layout(new QVBoxLayout),
    m_signalMapper(new QSignalMapper(this)),
    m_boutonAjout(new QPushButton(tr("+")))
{
    /* Configuration de la page.
     */
    setTitle(tr("Configuration des joueurs"));
    setSubTitle(tr("Configurez les joueurs qui prendront part au jeu."));
    
    
    
    /* Création de 2 joueurs minimum.
     */
    m_joueurs.append(new JoueurConfigWidget);
    m_joueurs.append(new JoueurConfigWidget);
    
    
    
    /* Mise en forme des widgets et connexion des signaux au QSignalMapper.
     */
    for (int i(0), iEnd(m_joueurs.size()); i < iEnd; i++)
    {
        JoueurConfigWidget* champ(m_joueurs.at(i));
        
        // Mise en forme.
        m_layout->addWidget(champ);
        
        // Gestion des signaux et slots via le QSignalMapper.
        connect(champ, SIGNAL(supprimer()), m_signalMapper, SLOT(map()));
        m_signalMapper->setMapping(champ, i);
    }
    m_layout->addWidget(m_boutonAjout);
    
    setLayout(m_layout);
    
    
    
    /* Connexion des signaux et slots.
     */
    connect(m_boutonAjout, SIGNAL(clicked()), this, SLOT(ajouterJoueur()));
    connect(m_signalMapper, SIGNAL(mapped(int)), this, SLOT(enleverJoueur(int)));
}





void PageJoueur::ajouterJoueur()
{
    // Création du widget est insertion dans la liste.
    JoueurConfigWidget* widget(new JoueurConfigWidget);
    m_joueurs.append(widget);
    
    // Insertion du nouveau widget dans le layout.
    m_layout->insertWidget(m_joueurs.size() - 1, widget);
    
    // Enregistrement du widget auprès du QSignalMapper.
    connect(widget, SIGNAL(supprimer()), m_signalMapper, SLOT(map()));
    m_signalMapper->setMapping(widget, m_joueurs.size() - 1);
}





void PageJoueur::enleverJoueur(int index)
{
    // La partie doit compter 2 joueurs au minimum.
    if (m_joueurs.size() > 2)
    {
        // Suppression du widget concerné.
        JoueurConfigWidget* widget(m_joueurs.takeAt(index));
        m_layout->removeWidget(widget);
        
        delete widget;
        
        // Remapping des champs auprès de QSignalMapper.
        for (int i(0), iEnd(m_joueurs.size()); i < iEnd; i++)
        {
            m_signalMapper->setMapping(m_joueurs.at(i), i);
        }
    }
}

