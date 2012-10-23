#include "MainWindow.hpp"





MainWindow::MainWindow() :
    QMainWindow(),
    m_plateau(new Plateau),
    m_vueCentrale(new QGraphicsView),
    m_barreOutils(addToolBar(tr("Outils d'édition"))),
    m_actionQuitter(new QAction(tr("Quitter"), this)),
    m_actionAssistantCreation(new QAction(tr("Créer un nouveau plateau"), this)),
    m_actionRegroupement(new QAction(tr("Regroupements"), this))
{
    /* Configuration de la fenêtre.
     */
    setWindowIcon(QIcon("data/MonopolAdventureEditorIcon.png"));
    setWindowTitle("MonopolAdventureEditor");
    setWindowState(Qt::WindowMaximized);
    
    
    
    /* Configuration du widget central.
     */
    setCentralWidget(m_vueCentrale);
    m_vueCentrale->setScene(m_plateau);
    
    
    
    /* Configuration des actions.
     */
    m_actionQuitter->setShortcut(Qt::CTRL + Qt::Key_Q);
    connect(m_actionQuitter, SIGNAL(triggered()), this, SLOT(quitter()));
    connect(m_actionAssistantCreation, SIGNAL(triggered()), this, SLOT(startAssistant()));
    connect(m_actionRegroupement, SIGNAL(triggered()), this, SLOT(editRegroupements()));
    
    
    
    /* Configuration des menus.
     */
    QMenu* menuJeu(menuBar()->addMenu(tr("MonopolAdventureEditor")));
    menuJeu->addAction(m_actionAssistantCreation);
    menuJeu->addSeparator();
    menuJeu->addAction(m_actionQuitter);
    
    
    
    /* Configuration des barres d'outils.
     */
    m_barreOutils->addAction(m_actionRegroupement);
    m_barreOutils->hide();
    
    
    
    /* Lancement de l'assistant de création de plateau.
     */
    QTimer::singleShot(500, this, SLOT(startAssistant()));
}





void MainWindow::quitter()
{
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





void MainWindow::editRegroupements()
{
    QDialog* dialog(new QDialog(this));
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    
    ListeRegroupementEditWidget* editWidget(new ListeRegroupementEditWidget(m_plateau->getListeRegroupement()));
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(editWidget);
    
    dialog->setLayout(layout);
    
    dialog->exec();
    
    // Actualisation de l'affichage du plateau.
    m_plateau->dessiner();
}

