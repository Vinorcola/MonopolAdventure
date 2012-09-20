#include "MainWindow.hpp"





MainWindow::MainWindow() :
    QMainWindow()
{
    /* Configuration de la fenêtre.
     */
    setWindowIcon(QIcon("data/MonopolAdventureEditorIcon.png"));
    setWindowTitle("MonopolAdventureEditor");
    setWindowState(Qt::WindowMaximized);
}

