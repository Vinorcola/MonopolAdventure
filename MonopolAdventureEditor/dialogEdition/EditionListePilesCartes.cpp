#include "EditionListePilesCartes.hpp"





EditionListePilesCartes::EditionListePilesCartes(QList<PileCartes*>& pilesCartes,
                                                 const QList<Emplacement*>& emplacements,
                                                 const QString& devise,
                                                 QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_listeOriginale(pilesCartes),
    m_listeEditable(),
    m_widgetEdition(0)
{
    // Création de la liste éditable.
    for (int i(0), iEnd(m_listeOriginale.count()); i < iEnd; i++)
    {
        m_listeEditable << new PileCartesData(m_listeOriginale.at(i));
    }
    
    /* Correction des piles de cartes liées aux actions des cartes (on insère un pointeur vers l'objet PileCartesData en
     * plus du pointeur vers PileCartes).
     */
    for (int i(0), iEnd(m_listeEditable.count()); i < iEnd; i++)
    {
        PileCartesData* pileCartes(m_listeEditable.at(i));
        for (int j(0), jEnd(pileCartes->getListeCartes().count()); j < jEnd; j++)
        {
            Action& action(pileCartes->getListeCartes().at(i)->getAction());
            
            if (action.isPayeOuPioche() || action.isPioche())
            {
                int index(m_listeOriginale.indexOf(action.getPileCartes()));
                action.setPileCartesEdition(m_listeEditable.at(index));
            }
        }
    }
    
    
    
    // Création du widget d'édition.
    m_widgetEdition = new ListePilesCartesEditWidget(m_listeEditable, emplacements, devise);
    
    
    
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
        /* On équilibre le nombre de piles de cartes entre les deux listes.
         */
        if (m_listeOriginale.count() < m_listeEditable.count())
        {
            for (int i(0), iEnd(m_listeEditable.count() - m_listeOriginale.count()); i < iEnd; i++)
            {
                m_listeOriginale.append(new PileCartes);
            }
        }
        else
        {
            for (int i(0), iEnd(m_listeOriginale.count() - m_listeEditable.count()); i < iEnd; i++)
            {
                delete m_listeOriginale.takeLast();
            }
        }
        
        
        
        /* On transfère les cartes.
         */
        for (int i(0); i < m_listeOriginale.count(); i++)
        {
            PileCartes* pileCartesOriginale(m_listeOriginale.at(i));
            PileCartesData* pileCartesEditee(m_listeEditable.at(i));    
            
            // Mise à jour du titre de la pile de cartes.
            pileCartesOriginale->editTitre(pileCartesEditee->getTitre());
            
            // On rapatrie toutes les cartes de la pile de cartes éditable dans la pile originale
            pileCartesOriginale->vider();
            pileCartesEditee->transfereCartes(pileCartesOriginale);
        }
        
        
        
        /* On corrige les piles de cartes liées aux actions.
         */
        for (int i(0), iEnd(m_listeOriginale.count()); i < iEnd; i++)
        {
            PileCartes* pileCartes(m_listeOriginale.at(i));
            for (int j(0), jEnd(pileCartes->getNombreCartes()); j < jEnd; j++)
            {
                Action& action(pileCartes->getCarte(j)->getAction());
                
                if (action.isPayeOuPioche() || action.isPioche())
                {
                    int index(m_listeEditable.indexOf(action.getPileCartesEdition()));
                    action.setPileCartesEdition(m_listeOriginale.at(index));
                }
            }
        }
        
        
        
        return true;
    }
    else
    {
        return false;
    }
}

