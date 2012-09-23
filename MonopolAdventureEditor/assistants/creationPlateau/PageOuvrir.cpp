#include "PageOuvrir.hpp"





PageOuvrir::PageOuvrir() :
    QWizardPage(),
    m_champOuvrir(new FileSelectWidget(this)),
    m_champCopier(new QCheckBox(tr("Enregistrer les modifications dans un nouveau fichier."))),
    m_labelEnregistrerSous(new QLabel(tr("Sélectionnez un fichier à enregistrer"))),
    m_champEnregistrerSous(new FileSelectWidget(this, false))
{
    /* Configuration de la page
     */
    setTitle(tr("Ouvrir un plateau"));
    setSubTitle(tr("Sélectionnez un fichier .map pour modifier un plateau existant."));
    
    
    
    /* Configuration du contenu
     */
    m_champCopier->setChecked(true);
    
    connect(m_champCopier, SIGNAL(stateChanged(int)), this, SLOT(checkBoxStateChanged(int)));
    connect(m_champEnregistrerSous, SIGNAL(fileChange(QString)), this, SLOT(checkSavePath(QString)));
    
    
    
    /* Mise en forme du contenu
     */
    QFormLayout* layout(new QFormLayout);
    layout->addRow(tr("Sélectionnez un plateau à ouvrir"), m_champOuvrir);
    layout->addRow(m_champCopier);
    layout->addRow(m_labelEnregistrerSous, m_champEnregistrerSous);
    
    setLayout(layout);
    
    
    
    /* Enregistrement des champs
     */
    registerField("fichier_ouvrir", m_champOuvrir, "file");
    registerField("copier_ouvrir", m_champCopier);
    registerField("fichier_enregistrer", m_champEnregistrerSous, "file");
}





int PageOuvrir::nextId() const
{
    return -1;
}





void PageOuvrir::checkBoxStateChanged(int state)
{
    if (state == Qt::Checked)
    {
        m_labelEnregistrerSous->setEnabled(true);
        m_champEnregistrerSous->setEnabled(true);
    }
    else if (state == Qt::Unchecked)
    {
        m_labelEnregistrerSous->setEnabled(false);
        m_champEnregistrerSous->setEnabled(false);
    }
}





void PageOuvrir::checkSavePath(QString file)
{
    if (file.right(4) != ".map")
    {
        m_champEnregistrerSous->setFilePath(file + ".map");
    }
}

