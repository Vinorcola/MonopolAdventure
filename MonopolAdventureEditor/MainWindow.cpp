#include "MainWindow.hpp"

#include "assistants/creationPlateau/AssistantCreationPlateau.hpp"





MainWindow::MainWindow() :
    QMainWindow(),
    m_plateau(new Plateau(this)),
    m_vueCentrale(new QGraphicsView),
    m_barreOutils(addToolBar(tr("Outils d'édition"))),
    m_actionQuitter(new QAction(tr("Quitter"), this)),
    m_actionAssistantCreation(new QAction(tr("Éditer un plateau"), this)),
    m_actionSauvegarder(new QAction(tr("Enregistrer le plateau"), this)),
    m_actionFermerPlateau(new QAction(tr("Fermer le plateau"), this)),
    m_actionDecoration(new QAction(tr("Infos générales du plateau"), this)),
    m_actionPrix(new QAction(tr("Affichage des prix"), this)),
    m_actionRegroupements(new QAction(tr("Regroupements"), this)),
    m_actionPilesCartes(new QAction(tr("Piles de cartes"), this)),
    m_actionEditionTypeEmplacement(new QAction(tr("Edition de type d'emplacement"), this)),
    m_actionGraphismeEmplacement(new QAction(tr("Graphismes des emplacements"), this))
{
    /* Configuration de la fenêtre.
     */
    setWindowIcon(QIcon("data/MonopolAdventureEditorIcon.png"));
    setWindowTitle("MonopolAdventureEditor");
    
    
    
    /* Configuration du widget central.
     */
    setCentralWidget(m_vueCentrale);
    
    
    
    /* Configuration des actions.
     */
    m_actionQuitter->setShortcut(Qt::CTRL + Qt::Key_Q);
    connect(m_actionQuitter, SIGNAL(triggered()), this, SLOT(quitter()));
    connect(m_actionAssistantCreation, SIGNAL(triggered()), this, SLOT(startAssistant()));
    m_actionSauvegarder->setDisabled(true);
    connect(m_actionSauvegarder, SIGNAL(triggered()), this, SLOT(enregistrer()));
    m_actionFermerPlateau->setDisabled(true);
    connect(m_actionFermerPlateau, SIGNAL(triggered()), this, SLOT(fermerPlateau()));
    
    connect(m_actionDecoration, SIGNAL(triggered()), m_plateau, SLOT(editDecoration()));
    connect(m_actionPrix, SIGNAL(triggered()), m_plateau, SLOT(editAffichagePrix()));
    connect(m_actionRegroupements, SIGNAL(triggered()), m_plateau, SLOT(editListeRegroupements()));
    connect(m_actionPilesCartes, SIGNAL(triggered()), m_plateau, SLOT(editListePilesCartes()));
    connect(m_actionGraphismeEmplacement, SIGNAL(triggered()), m_plateau, SLOT(editGraphismeEmplacement()));
    m_actionEditionTypeEmplacement->setCheckable(true);
    
    
    
    /* Configuration des menus.
     */
    QMenu* menuJeu(menuBar()->addMenu(tr("MonopolAdventureEditor")));
    menuJeu->addAction(m_actionAssistantCreation);
    menuJeu->addAction(m_actionSauvegarder);
    menuJeu->addAction(m_actionFermerPlateau);
    menuJeu->addSeparator();
    menuJeu->addAction(m_actionQuitter);
    
    
    
    /* Configuration des barres d'outils.
     */
    m_barreOutils->addAction(m_actionDecoration);
    m_barreOutils->addAction(m_actionPrix);
    m_barreOutils->addAction(m_actionRegroupements);
    m_barreOutils->addAction(m_actionPilesCartes);
    m_barreOutils->addAction(m_actionEditionTypeEmplacement);
    m_barreOutils->addAction(m_actionGraphismeEmplacement);
    m_barreOutils->hide();
    
    
    
    /* Lancement de l'assistant de création de plateau.
     */
    QTimer::singleShot(500, this, SLOT(startAssistant()));
}





bool MainWindow::editionTypeActive() const
{
    return m_actionEditionTypeEmplacement->isChecked();
}





void MainWindow::quitter()
{
    delete m_plateau;
    qApp->quit();
}





void MainWindow::fermerPlateau()
{
    bool annulationFermer(false);
    
    if (!m_plateau->isSave())
    {
        QMessageBox msgBox;
        msgBox.setText("Voulez-vous enregistrer les modifications apportées au plateau ?");
        msgBox.setInformativeText("Les modifications non-enregistrées seront perdues.");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        
        bool ok;
        switch (msgBox.exec())
        {
            case QMessageBox::Save:
                ok = enregistrer();
                while (!ok)
                {
                    switch (msgBox.exec())
                    {
                        case QMessageBox::Cancel:
                            annulationFermer = true;
                            ok = true;
                            break;
                        case QMessageBox::Discard:
                            ok = true;
                            break;
                        default:
                            ok = enregistrer();
                    }
                }
                break;
            case QMessageBox::Cancel:
                annulationFermer = true;
                break;
            case QMessageBox::Discard:
                break;
        }
    }
    
    
    if (!annulationFermer)
    {
        // Création d'un plateau vide.
        delete m_plateau;
        m_plateau = new Plateau(this);
        
        // Mise à jour du statut des actions.
        m_barreOutils->hide();
        m_actionAssistantCreation->setEnabled(true);
        m_actionSauvegarder->setDisabled(true);
        m_actionFermerPlateau->setDisabled(true);
    }
}





void MainWindow::startAssistant()
{
    AssistantCreationPlateau* assistant(new AssistantCreationPlateau(m_plateau));
    if (assistant->exec())
    {
        m_vueCentrale->setScene(m_plateau);
        m_barreOutils->show();
        m_actionAssistantCreation->setDisabled(true);// Désactivation de la création de nouveau plateau.
        m_actionSauvegarder->setEnabled(true);
        m_actionFermerPlateau->setEnabled(true);
    }
}





bool MainWindow::enregistrer()
{
    bool annulation(false);
    bool sauvegarder(false);
    QString fichier;
    
    
    
    // Récupération du chemin du fichier à enregistrer.
    while (!annulation && !sauvegarder)
    {
        fichier = QFileDialog::getSaveFileName(this, "", "data/", "MonopolAdventure Plateau (*.plt)");
        
        if (fichier.isEmpty())
        {
            // L'utilisateur a cliqué sur Annuler.
            annulation = true;
        }
        else if (fichier.endsWith(".plt"))
        {
            sauvegarder = true;
        }
        else
        {
            // On rajoute l'extension au fichier.
            fichier.append(".plt");
            
            // On doit revérifier que le fichier n'existe pas déjà vu qu'on a rajouter l'extension.
            if (QFile::exists(fichier))
            {
                // S'il existe, on demande confirmation à l'utilisateur pour écraser le contenu.
                if (QMessageBox::question(this, "Le fichier existe déjà ...", "Le fichier « " + fichier + " » existe déjà. Voulez-vous le remplacer ?", QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Ok)
                {
                    sauvegarder = true;
                }
            }
            else
            {
                sauvegarder = true;
            }
        }
    }
    
    
    
    // Sauvegarde des données dans le fichier.
    if (sauvegarder)
    {
        m_plateau->saveInFile(fichier);
    }
    
    
    
    return !annulation;
}

