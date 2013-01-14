#include "EditionEmplacement.hpp"

#include "dialogEdition/widgetsEditeurs/ConstructionEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/DepartEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/DeplacementEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/LoyerCompagnieTransportEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/LoyerServiceEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/LoyerTerrainEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/PiocheEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/PrisonEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/ProprieteEditWidget.hpp"
#include "dialogEdition/widgetsEditeurs/TaxeEditWidget.hpp"





EditionEmplacement::EditionEmplacement(CompagnieTransport* compagnieTransport,
                                       const int nombreCompagnies,
                                       QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_onglets(new QTabWidget),
    m_onglet1(new EmplacementEditWidget(compagnieTransport)),
    m_onglet2(new ProprieteEditWidget(compagnieTransport)),
    m_onglet3(new LoyerCompagnieTransportEditWidget(compagnieTransport, nombreCompagnies)),
    m_onglet4(0)
{
    /* Configuration du widget d'édition.
     */
    m_onglets->addTab(m_onglet1, QObject::tr("Informations générales"));
    m_onglets->addTab(m_onglet2, QObject::tr("Propriété"));
    m_onglets->addTab(m_onglet3, QObject::tr("Loyers"));
    
    
    
    /* Configurations générales de la fenêtre de dialogue.
     */
    amenageFenetre();
}





EditionEmplacement::EditionEmplacement(Depart* depart,
                                       QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_onglets(new QTabWidget),
    m_onglet1(new EmplacementEditWidget(depart)),
    m_onglet2(new DepartEditWidget(depart)),
    m_onglet3(0),
    m_onglet4(0)
{
    /* Configuration du widget d'édition.
     */
    m_onglets->addTab(m_onglet1, QObject::tr("Informations générales"));
    m_onglets->addTab(m_onglet2, QObject::tr("Départ"));
    
    
    
    /* Configurations générales de la fenêtre de dialogue.
     */
    amenageFenetre();
}





EditionEmplacement::EditionEmplacement(Deplacement* deplacement,
                                       const QList<Emplacement*>& emplacements,
                                       QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_onglets(new QTabWidget),
    m_onglet1(new EmplacementEditWidget(deplacement)),
    m_onglet2(new DeplacementEditWidget(deplacement, emplacements)),
    m_onglet3(0),
    m_onglet4(0)
{
    /* Configuration du widget d'édition.
     */
    m_onglets->addTab(m_onglet1, QObject::tr("Informations générales"));
    m_onglets->addTab(m_onglet2, QObject::tr("Déplacement"));
    
    
    
    /* Configurations générales de la fenêtre de dialogue.
     */
    amenageFenetre();
}





EditionEmplacement::EditionEmplacement(ParcGratuit* parcGratuit,
                                       QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_onglets(new QTabWidget),
    m_onglet1(new EmplacementEditWidget(parcGratuit)),
    m_onglet2(0),
    m_onglet3(0),
    m_onglet4(0)
{
    /* Configuration du widget d'édition.
     */
    m_onglets->addTab(m_onglet1, QObject::tr("Informations générales"));
    
    
    
    /* Configurations générales de la fenêtre de dialogue.
     */
    amenageFenetre();
}





EditionEmplacement::EditionEmplacement(Pioche* pioche,
                                       const QList<PileCartes*>& pilesCartes,
                                       QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_onglets(new QTabWidget),
    m_onglet1(new EmplacementEditWidget(pioche)),
    m_onglet2(new PiocheEditWidget(pioche, pilesCartes)),
    m_onglet3(0),
    m_onglet4(0)
{
    /* Configuration du widget d'édition.
     */
    m_onglets->addTab(m_onglet1, QObject::tr("Informations générales"));
    m_onglets->addTab(m_onglet2, QObject::tr("Carte à piocher"));
    
    
    
    /* Configurations générales de la fenêtre de dialogue.
     */
    amenageFenetre();
}





EditionEmplacement::EditionEmplacement(Prison* prison,
                                       QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_onglets(new QTabWidget),
    m_onglet1(new EmplacementEditWidget(prison)),
    m_onglet2(new PrisonEditWidget(prison)),
    m_onglet3(0),
    m_onglet4(0)
{
    /* Configuration du widget d'édition.
     */
    m_onglets->addTab(m_onglet1, QObject::tr("Informations générales"));
    m_onglets->addTab(m_onglet2, QObject::tr("Prison"));
    
    
    
    /* Configurations générales de la fenêtre de dialogue.
     */
    amenageFenetre();
}





EditionEmplacement::EditionEmplacement(Service* service,
                                       const int nombreServices,
                                       QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_onglets(new QTabWidget),
    m_onglet1(new EmplacementEditWidget(service)),
    m_onglet2(new ProprieteEditWidget(service)),
    m_onglet3(new LoyerServiceEditWidget(service, nombreServices)),
    m_onglet4(0)
{
    /* Configuration du widget d'édition.
     */
    m_onglets->addTab(m_onglet1, QObject::tr("Informations générales"));
    m_onglets->addTab(m_onglet2, QObject::tr("Propriété"));
    m_onglets->addTab(m_onglet3, QObject::tr("Loyers"));
    
    
    
    /* Configurations générales de la fenêtre de dialogue.
     */
    amenageFenetre();
}





EditionEmplacement::EditionEmplacement(SimpleVisite* simpleVisite,
                                       QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_onglets(new QTabWidget),
    m_onglet1(new EmplacementEditWidget(simpleVisite)),
    m_onglet2(0),
    m_onglet3(0),
    m_onglet4(0)
{
    /* Configuration du widget d'édition.
     */
    m_onglets->addTab(m_onglet1, QObject::tr("Informations générales"));
    
    
    
    /* Configurations générales de la fenêtre de dialogue.
     */
    amenageFenetre();
}





EditionEmplacement::EditionEmplacement(Taxe* taxe,
                                       QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_onglets(new QTabWidget),
    m_onglet1(new EmplacementEditWidget(taxe)),
    m_onglet2(new TaxeEditWidget(taxe)),
    m_onglet3(0),
    m_onglet4(0)
{
    /* Configuration du widget d'édition.
     */
    m_onglets->addTab(m_onglet1, QObject::tr("Informations générales"));
    m_onglets->addTab(m_onglet2, QObject::tr("Taxe"));
    
    
    
    /* Configurations générales de la fenêtre de dialogue.
     */
    amenageFenetre();
}





EditionEmplacement::EditionEmplacement(Terrain* terrain,
                                       QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_onglets(new QTabWidget),
    m_onglet1(new EmplacementEditWidget(terrain)),
    m_onglet2(new ProprieteEditWidget(terrain)),
    m_onglet3(new ConstructionEditWidget(terrain)),
    m_onglet4(new LoyerTerrainEditWidget(terrain))
{
    /* Configuration du widget d'édition.
     */
    m_onglets->addTab(m_onglet1, QObject::tr("Informations générales"));
    m_onglets->addTab(m_onglet2, QObject::tr("Propriété"));
    m_onglets->addTab(m_onglet3, QObject::tr("Constructions")),
    m_onglets->addTab(m_onglet4, QObject::tr("Loyers"));
    
    
    
    /* Configurations générales de la fenêtre de dialogue.
     */
    amenageFenetre();
}





EditionEmplacement::~EditionEmplacement()
{
    delete m_dialog;
}





bool EditionEmplacement::executer()
{
    if (m_dialog->exec())
    {
        m_onglet1->sauvegarde();
        
        if (m_onglet2)
        {
            static_cast<SauvegardeInterface*>(m_onglet2)->sauvegarde();
        }
        
        if (m_onglet3)
        {
            static_cast<SauvegardeInterface*>(m_onglet3)->sauvegarde();
        }
        
        if (m_onglet4)
        {
            static_cast<SauvegardeInterface*>(m_onglet4)->sauvegarde();
        }
        
        return true;
    }
    else
    {
        return false;
    }
}





void EditionEmplacement::amenageFenetre()
{
    /* Aménagement de la fenêtre de dialogue.
     */
    QDialogButtonBox* boutons(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel));
    QObject::connect(boutons, SIGNAL(accepted()), m_dialog, SLOT(accept()));
    QObject::connect(boutons, SIGNAL(rejected()), m_dialog, SLOT(reject()));
    
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_onglets);
    layout->addWidget(boutons);
    
    m_dialog->setLayout(layout);
}

