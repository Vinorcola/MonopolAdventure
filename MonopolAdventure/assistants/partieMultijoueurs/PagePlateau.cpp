#include "PagePlateau.hpp"





PagePlateau::PagePlateau(Plateau* plateau) :
    QWizardPage(),
    m_plateau(plateau),
    m_fichier(new FileSelectWidget(this)),
    m_msgConfirmation(new QLabel(tr("<span style=\"color:#ff0000\">Aucun plateau chargé.</span>"))),
    m_plateauCharge(false)
{
    /* Configuration de la page
     */
    setTitle(tr("Introduction"));
    setSubTitle(tr("Bienvenue dans l'assistant de chargement de partie multijoueurs."));
    
    
    
    /* Configuration du contenu.
     */
    QLabel* label(new QLabel("Commencez par sélectionner un plateau à charger pour lancer une partie."));
    label->setWordWrap(true);
    label->setAlignment(Qt::AlignJustify);
    
    
    
    /* Mise en forme du contenu
     */
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(label);
    layout->addWidget(m_fichier);
    layout->addWidget(m_msgConfirmation);
    
    setLayout(layout);
    
    
    
    /* Connexion des slots.
     */
    connect(m_fichier, SIGNAL(fileChange(QString)), this, SLOT(chargePlateau(QString)));
}





bool PagePlateau::isComplete() const
{
    return m_plateauCharge;
}





void PagePlateau::chargePlateau(const QString& chemin)
{
    if (!chemin.isEmpty())
    {
        if (m_plateau->loadFromFile(chemin))
        {
            m_msgConfirmation->setText(tr("Le plateau ") + m_plateau->getTitre() + tr(" a bien été chargé."));
            m_plateauCharge = true;
            emit completeChanged();
        }
        else
        {
            m_fichier->setFilePath("");
            m_msgConfirmation->setText(tr("<span style=\"color:#ff0000\">Aucun plateau chargé.</span>"));
            m_plateauCharge = false;
            emit completeChanged();
        }
    }
}

