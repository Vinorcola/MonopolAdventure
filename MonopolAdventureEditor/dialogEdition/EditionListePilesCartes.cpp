#include "EditionListePilesCartes.hpp"

#include "donnees/emplacements/Pioche.hpp"





EditionListePilesCartes::EditionListePilesCartes(QList<PileCartes*>& pilesCartes,
                                                 const QList<Emplacement*>& emplacements,
                                                 const QString& devise,
                                                 QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_listeOriginale(pilesCartes),
    m_listeEditable(),
    m_widgetEdition(0),
    m_pileCartesPioche()
{
    // Création de la liste éditable.
    for (int i(0), iEnd(pilesCartes.count()); i < iEnd; i++)
    {
        m_listeEditable << new PileCartes(pilesCartes.at(i));
    }
    
    /* Correction des piles de cartes liées aux actions des cartes.
     */
    for (int i(0), iEnd(pilesCartes.count()); i < iEnd; i++)
    {
        PileCartes* pileCartes(m_listeEditable.at(i));
        for (int j(0), jEnd(pileCartes->getNombreCartes()); j < jEnd; j++)
        {
            Action& action(pileCartes->getCarteAt(i)->getAction());
            
            if (action.isPayeOuPioche() || action.isPioche())
            {
                // On récupère l'index de la pile de cartes dans la liste originale.
                int index(pilesCartes.indexOf((PileCartes*) action.getPileCartes()));
                
                // On change la pile de cartes par celle correspondant à l'index dans la liste editable.
                action.setPileCartes(m_listeEditable.at(index));
            }
        }
    }
    
    /* Enregistrement des piles de cartes liées aux emplacements « Pioche ».
     */
    for (int i(0), iEnd(emplacements.count()); i < iEnd; i++)
    {
        if (emplacements.at(i)->getType() == Type::Pioche)
        {
            Pioche* pioche(static_cast<Pioche*>(emplacements.at(i)));
            m_pileCartesPioche[pioche] = m_listeEditable.at(pilesCartes.indexOf((PileCartes*) pioche->getPileCartes()));
        }
    }
    
    
    
    // Création du widget d'édition.
    m_widgetEdition = new ListePilesCartesEditWidget(m_listeEditable, m_pileCartesPioche, emplacements, devise);
    
    
    
    // Aménagement du widget.
    QDialogButtonBox* boutons(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel));
    QObject::connect(boutons, SIGNAL(accepted()), m_dialog, SLOT(accept()));
    QObject::connect(boutons, SIGNAL(rejected()), m_dialog, SLOT(reject()));
    
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_widgetEdition);
    layout->addWidget(boutons);
    
    m_dialog->setLayout(layout);
}





EditionListePilesCartes::~EditionListePilesCartes()
{
    delete m_dialog;
    
    // Destruction des pileCartesData.
    for (int i(0), iEnd(m_listeEditable.count()); i < iEnd; i++)
    {
        delete m_listeEditable.takeLast();
    }
}





bool EditionListePilesCartes::executer()
{
    if (m_dialog->exec())
    {
        /* On déplace les piles de cartes de la liste éditable vers la liste originale.
         */
        for (int i(0), iEnd(m_listeOriginale.count()); i < iEnd; i++)
        {
            // On supprime toutes les piles de cartes originales.
            delete m_listeOriginale.takeLast();
        }
        m_listeOriginale = m_listeEditable;
        m_listeEditable.clear();
        
        /* Correction des piles de cartes liées aux emplacements « Pioche ».
         */
        PileCartePioche::const_iterator i(m_pileCartesPioche.constBegin());
        while (i != m_pileCartesPioche.constEnd())
        {
            // On change la pile de cartes associées par la version qui était en cours d'édition.
            static_cast<Pioche*>(i.key())->editPileCartes(i.value());
            i++;
        }
        
        
        
        return true;
    }
    else
    {
        return false;
    }
}

