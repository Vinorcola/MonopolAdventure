#include "MainWindow.hpp"





MainWindow::MainWindow() :
    QMainWindow(),
    m_plateau(0),
    m_vueCentrale(new QGraphicsView),
    m_actionQuitter(new QAction(tr("Quitter"), this)),
    m_actionLancerNouvellePartie(new QAction(tr("Nouvelle partie"), this)),
    m_actionZoomPlus(new QAction(tr("Zoom +"), this)),
    m_actionZoomMoins(new QAction(tr("Zoom -"), this))
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
    connect(m_actionLancerNouvellePartie, SIGNAL(triggered()), this, SLOT(startAssistantPartieMultijoueurs()));
    
    m_actionZoomPlus->setShortcut(QKeySequence::ZoomIn);
    connect(m_actionZoomPlus, SIGNAL(triggered()), this, SLOT(zoomPlus()));
    m_actionZoomMoins->setShortcut(QKeySequence::ZoomOut);
    connect(m_actionZoomMoins, SIGNAL(triggered()), this, SLOT(zoomMoins()));
    
    
    
    /* Configuration des menus.
     */
    QMenu* menuJeu(menuBar()->addMenu(tr("MonopolAdventure")));
    menuJeu->addAction(m_actionLancerNouvellePartie);
    menuJeu->addSeparator();
    menuJeu->addAction(m_actionQuitter);
    
    QMenu* menuVue(menuBar()->addMenu(tr("Affichage")));
    menuVue->addAction(m_actionZoomPlus);
    menuVue->addAction(m_actionZoomMoins);
    
    
    
    /* Lancement de l'assistant de création de plateau.
     */
    QTimer::singleShot(500, this, SLOT(startAssistantPartieMultijoueurs()));
}





void MainWindow::quitter()
{
    qApp->quit();
}





void MainWindow::startAssistantPartieMultijoueurs()
{
    AssistantPartieMultijoueurs* assistant(new AssistantPartieMultijoueurs(this));
    connect(assistant, SIGNAL(plateauLoaded(Plateau*)), this, SLOT(dessinePlateau(Plateau*)));
    
    assistant->exec();
}





void MainWindow::dessinePlateau(Plateau* plateau)
{
    m_plateau = plateau;
    plateau->dessiner();
    m_vueCentrale->setScene(plateau);
}





void MainWindow::zoomPlus()
{
    if (m_vueCentrale->transform().m11() < ZOOM_MAX)
    {
        m_vueCentrale->scale(1.2, 1.2);
        
        if (m_vueCentrale->transform().m11() > ZOOM_MAX)
        {
            m_vueCentrale->setTransform(QTransform::fromScale(ZOOM_MAX, ZOOM_MAX));
        }
    }
}





void MainWindow::zoomMoins()
{
    if (m_vueCentrale->transform().m11() > ZOOM_MIN)
    {
        m_vueCentrale->scale(1 / 1.2, 1 / 1.2);
        
        if (m_vueCentrale->transform().m11() < ZOOM_MIN)
        {
            m_vueCentrale->setTransform(QTransform::fromScale(ZOOM_MIN, ZOOM_MIN));
        }
    }
}

