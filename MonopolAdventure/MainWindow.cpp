#include "MainWindow.hpp"





MainWindow::MainWindow() :
    QMainWindow(),
    m_plateau(0),
    m_vueCentrale(new QGraphicsView),
    m_actionQuitter(new QAction(tr("Quitter"), this)),
    m_actionLancerNouvellePartie(new QAction(tr("Nouvelle partie"), this))
{
    /* Configuration de la fenêtre.
     */
    setWindowIcon(QIcon("data/MonopolAdventureIcon.png"));
    setWindowTitle("MonopolAdventureEditor");
    
    
    
    /* Configuration du widget central.
     */
    setCentralWidget(m_vueCentrale);
    
    
    
    /* Configuration des actions.
     */
    m_actionQuitter->setShortcut(QKeySequence::Quit);
    connect(m_actionQuitter, SIGNAL(triggered()), this, SLOT(quitter()));
    m_actionLancerNouvellePartie->setShortcut(Qt::CTRL + Qt::Key_N);
    
    
    
    /* Configuration des menus.
     */
    QMenu* menuJeu(menuBar()->addMenu(tr("MonopolAdventure")));
    menuJeu->addAction(m_actionLancerNouvellePartie);
    menuJeu->addSeparator();
    menuJeu->addAction(m_actionQuitter);
}





void MainWindow::quitter()
{
    qApp->quit();
}

