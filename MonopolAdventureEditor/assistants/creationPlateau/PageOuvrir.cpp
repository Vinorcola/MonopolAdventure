#include "PageOuvrir.hpp"





PageOuvrir::PageOuvrir() :
    QWizardPage(),
    m_champOuvrir(new FileSelectWidget(this))
{
    /* Configuration de la page
     */
    setTitle(tr("Ouvrir un plateau"));
    setSubTitle(tr("Sélectionnez un fichier .plt pour modifier un plateau existant."));
    
    
    
    /* Mise en forme du contenu
     */
    QFormLayout* layout(new QFormLayout);
    layout->addRow(tr("Sélectionnez le plateau à éditer"), m_champOuvrir);
    
    setLayout(layout);
    
    
    
    /* Enregistrement des champs
     */
    registerField("fichier_ouvrir*", m_champOuvrir, "file");
    
    
    
    /* Connexion du signal
     */
    connect(m_champOuvrir, SIGNAL(fileChange(QString)), this, SIGNAL(completeChanged()));
}





int PageOuvrir::nextId() const
{
    return -1;
}

