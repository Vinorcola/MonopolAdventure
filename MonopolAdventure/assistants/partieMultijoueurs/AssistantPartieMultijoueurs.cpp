#include "AssistantPartieMultijoueurs.hpp"





AssistantPartieMultijoueurs::AssistantPartieMultijoueurs(MainWindow* parent) :
    QWizard(),
    m_plateau(new Plateau(parent)),
    m_pageRegle(new PageRegle(m_plateau))
{
    /* Configuration de la fenêtre
     */
    setWindowTitle(tr("Assistant de chargement d'une partie multijoueurs"));
    setMinimumSize(800, 500);
    setAttribute(Qt::WA_DeleteOnClose);
    
    
    
    /* Configuration des pages
     */
    setPage(1, new PagePlateau(m_plateau));
    setPage(2, m_pageRegle);
    setPage(3, new PageJoueur);
}





void AssistantPartieMultijoueurs::accept()
{
    // Configuration de la règle du plateau.
    m_pageRegle->configureRegle(m_plateau->getReglePourConfig(), m_plateau);
    
    // Émission du signal pour prévenir que le plateau est prêt.
    emit plateauLoaded(m_plateau);
    
    QWizard::accept();
}





void AssistantPartieMultijoueurs::reject()
{
    delete m_plateau;
    
    QWizard::reject();
}

