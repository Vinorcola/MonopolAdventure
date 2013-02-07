#include "Taxe.hpp"





Taxe::Taxe(const GraphismeEmplacementInfos& graphismeInfos,
           const QString& devise) :
    Emplacement(Type::Taxe, graphismeInfos),
    m_payeMontantFixe(false),
    m_montantFixe(0),
    m_payePourcentageFortune(false),
    m_pourcentageFortune(0),
    m_devise(devise)
{
    
}





Taxe::~Taxe()
{
    
}





bool Taxe::isMontantFixe() const
{
    return m_payeMontantFixe;
}





quint16 Taxe::getMontantFixe() const
{
    return m_montantFixe;
}





bool Taxe::isPourcentageFortune() const
{
    return m_payePourcentageFortune;
}





quint16 Taxe::getPourcentageFortune() const
{
    return m_pourcentageFortune;
}





void Taxe::loadFromFile(QDataStream& lecture,
                        const quint16 version)
{
    switch (version)
    {
        default:
            Emplacement::loadFromFile(lecture, version);
            
            lecture >> m_payeMontantFixe
                    >> m_montantFixe
                    >> m_payePourcentageFortune
                    >> m_pourcentageFortune;
    }
}





QString Taxe::helper_getPrix() const
{
    QString texte("");
    
    if (m_payeMontantFixe)
    {
        texte += QString::number(m_montantFixe) + m_devise;
    }
    
    if (m_payePourcentageFortune)
    {
        if (m_payeMontantFixe)
        {
            texte += " " + QObject::tr("ou") + " ";
        }
        
        texte += QString::number(m_pourcentageFortune) + "%";
    }
    
    return texte;
}

