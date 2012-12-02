#include "EditionEmplacement.hpp"

#include "dialogEdition/widgetsEditeurs/ConstructionEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/DepartEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/DeplacementEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/EmplacementEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/LoyerCompagnieTransportEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/PrisonEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/ProprieteEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/TaxeEditWidget.hpp"





EditionEmplacement::EditionEmplacement(Emplacement* emplacement,
                                       QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_emplacement(emplacement),
    m_onglets(new QTabWidget),
    m_onglet1(new EmplacementEditWidget(m_emplacement)),
    m_onglet2(0),
    m_onglet3(0),
    m_onglet4(0)
{
    /* Configuration du widget d'édition.
     */
    m_onglets->addTab(m_onglet1, QObject::tr("Informations générales"));
    switch (m_emplacement->getType())
    {
        case Type::CompagnieTransport:
            /* Constructeur spécialisé. */
            break;
            
        case Type::Depart:
            m_onglet2 = new DepartEditWidget(static_cast<Depart*>(m_emplacement));
            m_onglets->addTab(m_onglet2, QObject::tr("Départ"));
            break;
            
        case Type::Deplacement:
            /* Constructeur spécialisé. */
            break;
            
        case Type::ParcGratuit:
            
            break;
            
        case Type::Pioche:
            
            break;
            
        case Type::Prison:
            m_onglet2 = new PrisonEditWidget(static_cast<Prison*>(m_emplacement));
            m_onglets->addTab(m_onglet2, QObject::tr("Prison"));
            break;
            
        case Type::Service:
            m_onglet2 = new ProprieteEditWidget(static_cast<Propriete*>(m_emplacement));
            m_onglets->addTab(m_onglet2, QObject::tr("Valeur de la propriété"));
            break;
            
        case Type::SimpleVisite:
            
            break;
            
        case Type::Taxe:
            m_onglet2 = new TaxeEditWidget(static_cast<Taxe*>(m_emplacement));
            m_onglets->addTab(m_onglet2, QObject::tr("Taxe"));
            break;
            
        case Type::Terrain:
            m_onglet2 = new ProprieteEditWidget(static_cast<Propriete*>(m_emplacement));
            m_onglets->addTab(m_onglet2, QObject::tr("Valeur de la propriété"));
            break;
    }
    
    
    
    /* Aménagement de la fenêtre de dialogue.
     */
    amenageFenetre();
}





EditionEmplacement::EditionEmplacement(Deplacement* deplacement,
                                       const QList<Emplacement*>& emplacements,
                                       QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_emplacement(deplacement),
    m_onglets(new QTabWidget),
    m_onglet1(new EmplacementEditWidget(m_emplacement)),
    m_onglet2(new DeplacementEditWidget(deplacement, emplacements)),
    m_onglet3(0),
    m_onglet4(0)
{
    /* Configuration du widget d'édition.
     */
    m_onglets->addTab(m_onglet1, QObject::tr("Informations générales"));
    m_onglets->addTab(m_onglet2, QObject::tr("Déplacement"));
    
    
    
    /* Aménagement de la fenêtre de dialogue.
     */
    amenageFenetre();
}





EditionEmplacement::EditionEmplacement(CompagnieTransport* compagnieTransport,
                                       const int nombreCompagnies,
                                       QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_emplacement(compagnieTransport),
    m_onglets(new QTabWidget),
    m_onglet1(new EmplacementEditWidget(m_emplacement)),
    m_onglet2(new ProprieteEditWidget(compagnieTransport)),
    m_onglet3(new LoyerCompagnieTransportEditWidget(compagnieTransport, nombreCompagnies)),
    m_onglet4(0)
{
    /* Configuration du widget d'édition.
     */
    m_onglets->addTab(m_onglet1, QObject::tr("Informations générales"));
    m_onglets->addTab(m_onglet2, QObject::tr("Valeur de la propriété"));
    m_onglets->addTab(m_onglet3, QObject::tr("Loyers"));
}





bool EditionEmplacement::executer()
{
    if (m_dialog->exec())
    {
        /* Sauvegarde des données ici. */
        
        return true;
    }
    else
    {
        return false;
    }
}





void EditionEmplacement::amenageFenetre()
{
    m_dialog->setAttribute(Qt::WA_DeleteOnClose);
    
    QDialogButtonBox* boutons(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel));
    QObject::connect(boutons, SIGNAL(accepted()), m_dialog, SLOT(accept()));
    QObject::connect(boutons, SIGNAL(rejected()), m_dialog, SLOT(reject()));
    
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_onglets);
    layout->addWidget(boutons);
    
    m_dialog->setLayout(layout);
}

