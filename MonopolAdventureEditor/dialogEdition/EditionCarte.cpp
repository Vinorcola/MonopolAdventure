#include "EditionCarte.hpp"





EditionCarte::EditionCarte(Carte* carte,
                           const QList<Emplacement*>& emplacements,
                           const QList<PileCartes*>& pilesCartes,
                           QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_champ(new CarteEditWidget(carte, emplacements, pilesCartes))
{
    /* Aménagement de la fenêtre de dialogue.
     */
    QDialogButtonBox* boutons(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel));
    QObject::connect(boutons, SIGNAL(accepted()), m_dialog, SLOT(accept()));
    QObject::connect(boutons, SIGNAL(rejected()), m_dialog, SLOT(reject()));
    
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_champ);
    layout->addWidget(boutons);
    
    m_dialog->setLayout(layout);
}





EditionCarte::~EditionCarte()
{
    delete m_dialog;
}





bool EditionCarte::executer()
{
    if (m_dialog->exec())
    {
        m_champ->sauvegarde();
        
        return true;
    }
    else
    {
        return false;
    }
}

