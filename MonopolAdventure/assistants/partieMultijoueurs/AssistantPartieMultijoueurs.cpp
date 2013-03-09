#include "AssistantPartieMultijoueurs.hpp"





AssistantPartieMultijoueurs::AssistantPartieMultijoueurs(MainWindow* parent) :
    QWizard(),
    m_plateau(new Plateau(parent))
{
    /* Configuration de la fenêtre
     */
    setWindowTitle(tr("Assistant de chargement d'une partie multijoueurs"));
    setMinimumSize(800, 500);
    setAttribute(Qt::WA_DeleteOnClose);
    
    
    
    /* Configuration des pages
     */
    setPage(1, new PagePlateau(m_plateau));
    setPage(2, new PageRegle(m_plateau));
}





void AssistantPartieMultijoueurs::accept()
{
    emit plateauLoaded(m_plateau);
    
    QWizard::accept();
}





void AssistantPartieMultijoueurs::reject()
{
    delete m_plateau;
    
    QWizard::reject();
}

