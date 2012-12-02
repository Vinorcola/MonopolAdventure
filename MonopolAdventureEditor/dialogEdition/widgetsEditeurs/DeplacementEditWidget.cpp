#include "DeplacementEditWidget.hpp"





DeplacementEditWidget::DeplacementEditWidget(Deplacement* const deplacement,
                                             const QList<Emplacement*>& emplacements,
                                             Emplacement* emplacementParDefaut) :
    QWidget(),
    m_deplacement(deplacement),
    m_champDestination(new QComboBox),
    m_modeleEmplacementSelectionnable(new EmplacementListModel(emplacements, m_deplacement, m_champDestination)),
    m_champAmende(new QSpinBox)
{
    /* Configuration des champs.
     */
    m_champDestination->setModel(m_modeleEmplacementSelectionnable);
    int rangParDefaut(emplacements.indexOf(emplacementParDefaut));
    m_champDestination->setCurrentIndex(rangParDefaut == -1 ? 0 : rangParDefaut);
    
    m_champAmende->setSingleStep(5);
    m_champAmende->setMaximum(MONTANT_MAX_EDITEUR);
    m_champAmende->setValue(m_deplacement->getMontantAmende());
    
    
    
    /* Mise en forme du widget.
     */
    QFormLayout* layout = new QFormLayout;
    layout->addRow(tr("Destination"), m_champDestination);
    layout->addRow(tr("Montant de l'amende que le joueur doit payer avant de sa déplacer"), m_champAmende);
    
    setLayout(layout);
}

