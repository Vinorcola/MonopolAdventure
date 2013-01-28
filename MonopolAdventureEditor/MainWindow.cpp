#include "MainWindow.hpp"

#include "assistants/creationPlateau/AssistantCreationPlateau.hpp"





MainWindow::MainWindow() :
    QMainWindow(),
    m_plateau(0),
    m_vueCentrale(new QGraphicsView),
    m_barreOutils(addToolBar(tr("Outils d'édition"))),
    m_actionQuitter(new QAction(tr("Quitter"), this)),
    m_actionAssistantCreation(new QAction(tr("Éditer un plateau"), this)),
    m_actionSauvegarder(new QAction(tr("Enregistrer le plateau"), this)),
    m_actionFermerPlateau(new QAction(tr("Fermer le plateau"), this)),
    m_actionZoomPlus(new QAction(tr("Zoom +"), this)),
    m_actionZoomMoins(new QAction(tr("Zoom -"), this)),
    m_actionInfosGeneralesPlateau(new QAction(tr("Infos générales du plateau"), this)),
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
    m_actionQuitter->setShortcut(QKeySequence::Quit);
    connect(m_actionQuitter, SIGNAL(triggered()), this, SLOT(quitter()));
    connect(m_actionAssistantCreation, SIGNAL(triggered()), this, SLOT(startAssistant()));
    m_actionSauvegarder->setDisabled(true);
    connect(m_actionSauvegarder, SIGNAL(triggered()), this, SLOT(enregistrer()));
    m_actionFermerPlateau->setDisabled(true);
    connect(m_actionFermerPlateau, SIGNAL(triggered()), this, SLOT(fermerPlateau()));
    
    m_actionZoomPlus->setShortcut(QKeySequence::ZoomIn);
    connect(m_actionZoomPlus, SIGNAL(triggered()), this, SLOT(zoomPlus()));
    m_actionZoomMoins->setShortcut(QKeySequence::ZoomOut);
    connect(m_actionZoomMoins, SIGNAL(triggered()), this, SLOT(zoomMoins()));
    
    m_actionEditionTypeEmplacement->setCheckable(true);
    
    
    
    /* Configuration des menus.
     */
    QMenu* menuJeu(menuBar()->addMenu(tr("MonopolAdventureEditor")));
    menuJeu->addAction(m_actionAssistantCreation);
    menuJeu->addAction(m_actionSauvegarder);
    menuJeu->addAction(m_actionFermerPlateau);
    menuJeu->addSeparator();
    menuJeu->addAction(m_actionQuitter);
    
    QMenu* menuVue(menuBar()->addMenu(tr("Affichage")));
    menuVue->addAction(m_actionZoomPlus);
    menuVue->addAction(m_actionZoomMoins);
    
    
    
    /* Configuration des barres d'outils.
     */
    m_barreOutils->addAction(m_actionInfosGeneralesPlateau);
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
    if (m_plateau)
    {
        bool annulationFermer(false);
        
        if (!m_plateau->isSave())
        {
            QMessageBox msgBox;
            msgBox.setText("Voulez-vous enregistrer les modifications apportées au plateau avant de quitter MonopolAdventureEditor ?");
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
            delete m_plateau;
            qApp->quit();
        }
    }
    else
    {
        qApp->quit();
    }
}





void MainWindow::fermerPlateau()
{
    if (m_plateau)
    {
        bool annulationFermer(false);
        
        if (!m_plateau->isSave())
        {
            QMessageBox msgBox;
            msgBox.setText("Voulez-vous enregistrer les modifications apportées au plateau avant de le fermer ?");
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
            // Suppression du plateau.
            delete m_plateau;
            m_plateau = 0;
            
            // Mise à jour du statut des actions.
            m_barreOutils->hide();
            m_actionAssistantCreation->setEnabled(true);
            m_actionSauvegarder->setDisabled(true);
            m_actionFermerPlateau->setDisabled(true);
        }
    }
}





void MainWindow::startAssistant()
{
    AssistantCreationPlateau* assistant(new AssistantCreationPlateau(this));
    connect(assistant, SIGNAL(plateauCreated(Plateau*)), this, SLOT(dessinePlateau(Plateau*)));
    
    if (assistant->exec())
    {
        m_vueCentrale->setScene(m_plateau);
    }
}





void MainWindow::dessinePlateau(Plateau *plateau)
{
    m_plateau = plateau;
    
    // Dessin et affichage du plateau.
    plateau->dessiner();
    m_vueCentrale->setScene(plateau);
    
    // Activation de la barre d'outils.
    m_barreOutils->show();
    connect(m_actionDecoration, SIGNAL(triggered()), plateau, SLOT(editDecoration()));
    connect(m_actionPrix, SIGNAL(triggered()), plateau, SLOT(editAffichagePrix()));
    connect(m_actionRegroupements, SIGNAL(triggered()), plateau, SLOT(editListeRegroupements()));
    connect(m_actionPilesCartes, SIGNAL(triggered()), plateau, SLOT(editListePilesCartes()));
    connect(m_actionGraphismeEmplacement, SIGNAL(triggered()), plateau, SLOT(editGraphismeEmplacement()));
    m_actionEditionTypeEmplacement->setChecked(false);
    
    // Activation/Désactivation des actions.
    m_actionAssistantCreation->setDisabled(true);// Désactivation de la création de nouveau plateau.
    m_actionSauvegarder->setEnabled(true);
    m_actionFermerPlateau->setEnabled(true);
}





bool MainWindow::enregistrer()
{
    bool annulation(false);
    bool sauvegarder(false);
    QString fichier;
    
    
    
    // Récupération du chemin du fichier à enregistrer.
    while (!annulation && !sauvegarder)
    {
        fichier = QFileDialog::getSaveFileName(this, "", "data/", QString("Plateau MonopolAdventure (*") + EXTENSION_FICHIER + ")");
        
        if (fichier.isEmpty())
        {
            // L'utilisateur a cliqué sur Annuler.
            annulation = true;
        }
        else if (fichier.endsWith(EXTENSION_FICHIER))
        {
            sauvegarder = true;
        }
        else
        {
            // On rajoute l'extension au fichier.
            fichier.append(EXTENSION_FICHIER);
            
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

