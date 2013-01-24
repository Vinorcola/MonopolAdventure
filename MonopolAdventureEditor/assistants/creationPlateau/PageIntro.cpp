#include "PageIntro.hpp"





PageIntro::PageIntro() :
    QWizardPage(),
    m_introduction(new QLabel(tr("Cet assistant va vous guider dans la configuration du nouveau plateau, étape par étape."))),
    m_choix(new QLabel(tr("Que souhaitez-vous faire ?"))),
    m_radioCreer(new QRadioButton(tr("Créer un nouveau plateau"))),
    m_radioOuvrir(new QRadioButton(tr("Ouvrir un plateau existant")))
{
    /* Configuration de la page
     */
    setTitle(tr("Introduction"));
    setSubTitle(tr("Bienvenue dans l'assistant de création de nouveau plateau."));
    
    
    
    /* Configuration du contenu
     */
    m_introduction->setWordWrap(true);
    m_introduction->setAlignment(Qt::AlignJustify);
    
    m_choix->setWordWrap(true);
    m_choix->setAlignment(Qt::AlignJustify);
    
    m_radioOuvrir->setChecked(true);
    
    
    
    /* Mise en forme du contenu
     */
    QFormLayout* formLayout(new QFormLayout);
    formLayout->addRow(m_radioOuvrir);
    formLayout->addRow(m_radioCreer);
    
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_introduction);
    layout->addWidget(m_choix);
    layout->addLayout(formLayout);
    
    setLayout(layout);
    
    
    
    /* Enregistrement des champs
     */
    registerField("nouveau", m_radioCreer);
}





int PageIntro::nextId() const
{
    if (m_radioCreer->isChecked())
    {
        return 2;
    }
    else
    {
        return 6;
    }
}

