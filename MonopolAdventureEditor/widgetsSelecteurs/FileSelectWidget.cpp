#include "FileSelectWidget.hpp"





FileSelectWidget::FileSelectWidget(QWidget* parent,
                                   const bool openingMode,
                                   const QString& defaultFile) :
    QWidget(parent),
    m_file(defaultFile),
    m_widget(new QLineEdit),
    m_button(new QPushButton(tr("Modifier"))),
    m_openingMode(openingMode)
{
    /* Configuration du QLabel qui affiche le chemin vers le fichier.
     */
    m_widget->setMaximumHeight(m_button->sizeHint().height());
    m_widget->setReadOnly(true);
    updateFileWidget();
    
    
    
    /* Configuration du QPushButton.
     */
    connect(m_button, SIGNAL(clicked()), this, SLOT(askNewFile()));
    
    
    
    /* Disposition
     */
    QHBoxLayout* layout = new QHBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_widget);
    layout->addWidget(m_button);
    
    setLayout(layout);
}





void FileSelectWidget::setFilePath(const QString& file)
{
    if (file != m_file)
    {
        m_file = file;
        updateFileWidget();
        emit fileChange(m_file);
    }
}





const QString& FileSelectWidget::getFilePath() const
{
    return m_file;
}





void FileSelectWidget::askNewFile()
{
    QString newFile;
    
    if (m_openingMode)
    {
        newFile = QFileDialog::getOpenFileName(parentWidget(), tr("Sélectionnez un plateau à ouvrir"), QString(), tr("Plateau MonopolAdventure (*.map)"));
    }
    else
    {
        newFile = QFileDialog::getSaveFileName(parentWidget(), tr("Sélectionnez un fichier à enregistrer"), QString(), tr("Plateau MonopolAdventure (*.map)"));
    }
    
    
    
    if (!newFile.isEmpty() && newFile != m_file)
    {
        m_file = newFile;
        updateFileWidget();
        emit fileChange(m_file);
    }
}





void FileSelectWidget::updateFileWidget()
{
    m_widget->setText(m_file);
}

