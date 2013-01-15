#include "Carte.hpp"

#include "donnees/cartes/PileCartes.hpp"





Carte::Carte(const PileCartes* pileCartes) :
    m_pileCartes(pileCartes),
    m_consigne(QObject::tr("Nouvelle carte")),
    m_image(),
    m_dispositionImage(GAUCHE),
    m_action()
{
    
}





Carte::Carte(const Carte* autre,
             const PileCartes* pileCartes) :
    m_pileCartes(pileCartes),
    m_consigne(autre->m_consigne),
    m_image(autre->m_image),
    m_dispositionImage(autre->m_dispositionImage),
    m_action(autre->m_action)
{
    
}





Action &Carte::getAction()
{
    return m_action;
}





const PileCartes* Carte::getPileCartes() const
{
    return m_pileCartes;
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





Carte::ImageDisposition Carte::getDispositionImage() const
{
    return m_dispositionImage;
}





void Carte::editDispositionImage(const ImageDisposition disposition)
{
    m_dispositionImage = disposition;
}





void Carte::saveInFile(QDataStream& ecriture,
                       const Plateau* plateau) const
{
    ecriture << m_consigne
             << m_image
             << (quint8) m_dispositionImage;
    
    m_action.saveInFile(ecriture, plateau);
}





void Carte::loadFromFile(QDataStream& lecture,
                         const quint16 version,
                         const Plateau* plateau)
{
    switch (version)
    {
        default:
            quint8 dispositionImage;
            
            lecture >> m_consigne
                    >> m_image
                    >> dispositionImage;
            
            m_dispositionImage = (ImageDisposition) dispositionImage;
            
            m_action.loadFromFile(lecture, version, plateau);
    }
}

