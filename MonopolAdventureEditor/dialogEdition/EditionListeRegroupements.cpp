#include "EditionListeRegroupements.hpp"

#include "dialogEdition/modeles/RegroupementListModel.hpp"
#include "dialogEdition/widgetsEditeurs/RegroupementEditWidget.hpp"





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
        m_listeEditable << new Regroupement(m_listeOriginale.at(i));
    }
    
    
    
    /* Création du widget d'édition.
     */
    m_widgetEditionListeRegroupements = new ListeRegroupementEditWidget(m_listeEditable);
    
    
    
    /* Aménagement de la fenêtre de dialogue.
     */
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
    delete m_dialog;
    
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
        /* On déplace les regroupements de la liste éditable vers la liste originale.
         */
        for (int i(0), iEnd(m_listeOriginale.count()); i < iEnd; i++)
        {
            // On supprime tous les regroupements originaux.
            delete m_listeOriginale.takeLast();
        }
        m_listeOriginale = m_listeEditable;
        m_listeEditable.clear();
        
        for (int i(0), iEnd(m_listeOriginale.count()); i < iEnd; i++)
        {
            m_listeOriginale.at(i)->termineEdition();
        }
        
        
        
        return true;
    }
    else
    {
        return false;
    }
}

