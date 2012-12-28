#include "MainWindow.hpp"

#include "assistants/creationPlateau/AssistantCreationPlateau.hpp"





MainWindow::MainWindow() :
    QMainWindow(),
    m_plateau(new Plateau(this)),
    m_vueCentrale(new QGraphicsView),
    m_barreOutils(addToolBar(tr("Outils d'édition"))),
    m_actionQuitter(new QAction(tr("Quitter"), this)),
    m_actionAssistantCreation(new QAction(tr("Créer un nouveau plateau"), this)),
    m_actionRegroupement(new QAction(tr("Regroupements"), this)),
    m_actionEditionTypeEMplacement(new QAction(tr("Edition de type d'emplacement"), this))
{
    /* Configuration de la fenêtre.
     */
    setWindowIcon(QIcon("data/MonopolAdventureEditorIcon.png"));
    setWindowTitle("MonopolAdventureEditor");
    
    
    
    /* Configuration du widget central.
     */
    setCentralWidget(m_vueCentrale);
    m_vueCentrale->setScene(m_plateau);
    
    
    
    /* Configuration des actions.
     */
    m_actionQuitter->setShortcut(Qt::CTRL + Qt::Key_Q);
    connect(m_actionQuitter, SIGNAL(triggered()), this, SLOT(quitter()));
    connect(m_actionAssistantCreation, SIGNAL(triggered()), this, SLOT(startAssistant()));
    connect(m_actionRegroupement, SIGNAL(triggered()), m_plateau, SLOT(editListeRegroupement()));
    
    m_actionEditionTypeEMplacement->setCheckable(true);
    
    
    
    /* Configuration des menus.
     */
    QMenu* menuJeu(menuBar()->addMenu(tr("MonopolAdventureEditor")));
    menuJeu->addAction(m_actionAssistantCreation);
    menuJeu->addSeparator();
    menuJeu->addAction(m_actionQuitter);
    
    
    
    /* Configuration des barres d'outils.
     */
    m_barreOutils->addAction(m_actionRegroupement);
    m_barreOutils->addAction(m_actionEditionTypeEMplacement);
    m_barreOutils->hide();
    
    
    
    /* Lancement de l'assistant de création de plateau.
     */
    QTimer::singleShot(500, this, SLOT(startAssistant()));
}





bool MainWindow::editionTypeActive() const
{
    return m_actionEditionTypeEMplacement->isChecked();
}





void MainWindow::quitter()
{
    delete m_plateau;
    qApp->quit();
}





void MainWindow::startAssistant()
{
    AssistantCreationPlateau* assistant(new AssistantCreationPlateau(m_plateau));
    if (assistant->exec())
    {
        m_barreOutils->show();
        m_actionAssistantCreation->setEnabled(false);// Désactivation de la création de nouveau plateau.
    }
}

