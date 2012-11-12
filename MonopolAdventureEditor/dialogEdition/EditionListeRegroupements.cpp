#include "EditionListeRegroupements.hpp"





EditionListeRegroupements::EditionListeRegroupements(QList<Regroupement*>& regroupements,
                                                     QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_listeOriginale(regroupements),
    m_listeEditable()
{
    /* Création de la liste éditable.
     */
    for (int i(0), iEnd(m_listeOriginale.count()); i < iEnd; ++i)
    {
        m_listeEditable << new RegroupementData(m_listeOriginale.at(i));
    }
    
    
    
    /* Création du widget d'édition.
     */
    m_widgetEditionListeRegroupements = new ListeRegroupementEditWidget(m_listeEditable);
    
    
    
    /* Aménagement de la fenêtre de dialogue.
     */
    m_dialog->setAttribute(Qt::WA_DeleteOnClose);
    
    QDialogButtonBox* boutons(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel));
    QObject::connect(boutons, SIGNAL(accepted()), m_dialog, SLOT(accept()));
    QObject::connect(boutons, SIGNAL(rejected()), m_dialog, SLOT(reject()));
    
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_widgetEditionListeRegroupements);
    layout->addWidget(boutons);
    
    m_dialog->setLayout(layout);
}





EditionListeRegroupements::~EditionListeRegroupements()
{
    // Destruction des regroupementData.
    for (int i(0), iEnd(m_listeEditable.count()); i < iEnd; ++i)
    {
        delete m_listeEditable.takeLast();
    }
}





bool EditionListeRegroupements::executer()
{
    /* Execution de la fenêtre.
     */
    if (m_dialog->exec())
    {
        /* Sauvegarde des données.
         */
        
        
        
        return true;
    }
    else
    {
        return false;
    }
}

