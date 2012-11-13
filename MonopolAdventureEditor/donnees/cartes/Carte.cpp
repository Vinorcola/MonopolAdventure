#include "Carte.hpp"





Carte::Carte() :
    m_pileCartes(0),
    m_consigne(""),
    m_image(),
    m_dispositionImage(GAUCHE),
    m_action()
{
    
}





Carte::~Carte()
{
    /* Enlève la carte de la pile de cartes.
     */
    if (m_pileCartes)
    {
        m_pileCartes->removeOne(this);
    }
}





Action &Carte::getAction() const
{
    return m_action;
}





PileCartes* Carte::getPileCartes() const
{
    return m_pileCartes;
}





void Carte::editPileCartes(PileCartes* const pileCartes)
{
    if (pileCartes != m_pileCartes)
    {
        /* Enlève la carte de l'ancienne pile de cartes.
         */
        if (m_pileCartes)
        {
            m_pileCartes->removeOne(this);
        }
        
        
        m_pileCartes = pileCartes;
        
        
        /* Ajoute lacarte dans la nouvelle pile de cartes.
         */
        if (m_pileCartes)
        {
            m_pileCartes->append(this);
        }
    }
}





const QString& Carte::getConsigne() const
{
    return m_consigne;
}





void Carte::editConsigne(const QString& consigne)
{
    if (consigne.isNull())
    {
        m_consigne = "";
    }
    else
    {
        m_consigne = consigne;
    }
}





const QPixmap& Carte::getImage() const
{
    return m_image;
}





void Carte::editImage(const QPixmap& image)
{
    m_image = image;
}





CarteImageDisposition Carte::getDispositionImage() const
{
    return m_dispositionImage;
}





void Carte::editDispositionImage(const CarteImageDisposition disposition)
{
    m_dispositionImage = disposition;
}

