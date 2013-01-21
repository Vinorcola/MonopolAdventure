#include "EditionPrix.hpp"





EditionPrix::EditionPrix(Plateau* plateau,
                         QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_champ(new PrixEditWidget(plateau))
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





EditionPrix::~EditionPrix()
{
    delete m_dialog;
}





bool EditionPrix::executer()
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

