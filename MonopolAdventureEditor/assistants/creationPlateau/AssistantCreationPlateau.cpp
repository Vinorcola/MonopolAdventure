#include "AssistantCreationPlateau.hpp"

#include "assistants/creationPlateau/PageGeneral.hpp"
#include "assistants/creationPlateau/PageGraphisme.hpp"
#include "assistants/creationPlateau/PageIntro.hpp"
#include "assistants/creationPlateau/PageOuvrir.hpp"
#include "assistants/creationPlateau/PagePrix.hpp"
#include "assistants/creationPlateau/PageTaille.hpp"





AssistantCreationPlateau::AssistantCreationPlateau(Plateau* plateau) :
    m_plateau(plateau),
    m_pageGeneral(new PageGeneral(plateau)),
    m_pageGraphisme(new PageGraphisme(plateau)),
    m_pagePrix(new PagePrix(plateau))
{
    /* Configuration de la fenêtre
     */
    setWindowTitle(tr("Assistant de création de plateau"));
    setMinimumSize(800, 500);
    setAttribute(Qt::WA_DeleteOnClose);
    
    
    
    /* Configuration des pages
     */
    setPage(1, new PageIntro);
    setPage(2, new PageTaille);
    setPage(3, m_pageGeneral);
    setPage(4, m_pagePrix);
    setPage(5, m_pageGraphisme);
    setPage(6, new PageOuvrir);
}





void AssistantCreationPlateau::accept()
{
    if (field("nouveau").toBool())
    {
        m_pageGeneral->sauvegarde();
        m_pagePrix->sauvegarde();
        m_pageGraphisme->sauvegarde();
        
        /* La configuration de la taille du plateau doit être éditée en dernière car le plateau à besoin des informations
         * concernant la taille des emplacements.
         */
        m_plateau->editTaille(QSize(field("largeur_plateau").toInt(), field("hauteur_plateau").toInt()));
    }
    else
    {
        m_plateau->loadFromFile(field("fichier_ouvrir").toString());
    }
    
    m_plateau->dessiner();
    
    QWizard::accept();
}

