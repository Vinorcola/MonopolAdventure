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





const Action &Carte::getAction()
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





const QPixmap& Carte::getImage() const
{
    return m_image;
}





Carte::ImageDisposition Carte::getDispositionImage() const
{
    return m_dispositionImage;
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

