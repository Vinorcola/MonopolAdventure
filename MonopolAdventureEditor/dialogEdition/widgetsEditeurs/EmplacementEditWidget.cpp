#include "EmplacementEditWidget.hpp"





EmplacementEditWidget::EmplacementEditWidget(Emplacement* const emplacement) :
    QWidget(),
    m_emplacement(emplacement),
    m_champTitre(new QLineEdit(m_emplacement->getTitre())),
    m_champSousTitre(new QLineEdit(m_emplacement->getSousTitre())),
    m_champDescription(new QTextEdit(m_emplacement->getDescription())),
    m_champImage(new ImageSelectWidget(this, m_emplacement->getImage(), m_emplacement->getGraphismeInfos().getCouleurFond()))
{
    /* Mise en forme du widget.
     */
    QFormLayout* layout = new QFormLayout;
    layout->addRow(tr("Titre"), m_champTitre);
    layout->addRow(tr("Sous-titre"), m_champSousTitre);
    layout->addRow(tr("Description"), m_champDescription);
    layout->addRow(tr("Image"), m_champImage);
    
    setLayout(layout);
}





void EmplacementEditWidget::sauvegarde()
{
    m_emplacement->editTitre(m_champTitre->text());
    m_emplacement->editSousTitre(m_champSousTitre->text());
    m_emplacement->editDescription(m_champDescription->toPlainText());
    m_emplacement->editImage(m_champImage->getImage());
}
