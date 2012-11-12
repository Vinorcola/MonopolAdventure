#include "EditionListeRegroupements.hpp"





EditionListeRegroupements::EditionListeRegroupements(QList<Regroupement*>& regroupements,
                                                     QWidget* parent) :
    QDialog(parent),
    m_listeOriginale(regroupements),
    m_listeEditable(),
    m_modeleRegroupementsEditables(0)
{
    /* Création de la liste éditable.
     */
    for (int i(0), iEnd(m_listeOriginale.count()); i < iEnd; ++i)
    {
        m_listeEditable << new RegroupementData(m_listeOriginale.at(i));
    }
    
    
    
    /* Création du modèle de données de regroupements.
     */
    m_modeleRegroupementsEditables = new RegroupementListModel(m_listeEditable);
    
    
    
    /* Création du widget d'édition.
     */
    m_widgetEditionListeRegroupements = new ListeRegroupementEditWidget(m_listeEditable);
    
    
    
    /* Aménagement de la fenêtre de dialogue.
     */
    setAttribute(Qt::WA_DeleteOnClose);
    
    QDialogButtonBox* boutons(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel));
    QObject::connect(boutons, SIGNAL(accepted()), this, SLOT(accept()));
    QObject::connect(boutons, SIGNAL(rejected()), this, SLOT(reject()));
    
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_widgetEditionListeRegroupements);
    layout->addWidget(boutons);
    
    setLayout(layout);
}





EditionListeRegroupements::~EditionListeRegroupements()
{
    // Destruction des regroupementData.
    for (int i(0), iEnd(m_listeEditable.count()); i < iEnd; ++i)
    {
        delete m_listeEditable.takeLast();
    }
    
    // Destruction des modèles.
    if (m_modeleRegroupementsEditables)
    {
        delete m_modeleRegroupementsEditables;
    }
}





bool EditionListeRegroupements::executer()
{
    /* Execution de la fenêtre.
     */
    if (exec())
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

