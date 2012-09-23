#include "PageImage.hpp"





PageImage::PageImage() :
    QWizardPage(),
    m_champCouleur(new ColorSelectWidget(this, QColor(255, 255, 255))),
    m_champImage(new ImageSelectWidget(this))
{
    /* Configuration de la page
     */
    setTitle(tr("Image du plateau"));
    setSubTitle(tr("Sélectionnez la couleur de fond du plateau ainsi qu'une image à placer au centre du plateau."));
    
    
    
    /* Configuration du contenu
     */
    m_champImage->setBackgroundColor(QColor(255, 255, 255));
    
    connect(m_champCouleur, SIGNAL(colorChange(QColor)), m_champImage, SLOT(setBackgroundColor(QColor)));
    
    
    
    /* Mise en forme du contenu
     */
    QFormLayout* layout(new QFormLayout);
    layout->addRow(tr("Couleur de fond"), m_champCouleur);
    layout->addRow(tr("Image"), m_champImage);
    
    setLayout(layout);
    
    
    
    /* Enregistrement des champs
     */
    registerField("couleur_plateau", m_champCouleur, "color");
    registerField("image_plateau", m_champImage, "image");
}





int PageImage::nextId() const
{
    return 5;
}

