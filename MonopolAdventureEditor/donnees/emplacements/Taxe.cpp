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





void Taxe::enableMontantFixe(const quint16 montant)
{
    m_payeMontantFixe = true;
    if (montant > MONTANT_MAX_EDITEUR)
    {
        m_montantFixe = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_montantFixe = montant;
    }
    
    // Mise à jour de l'affichage.
    if (m_elementGraphique)
    {
        m_elementGraphique->updatePrix(helper_getPrix());
    }
}





void Taxe::disableMontantFixe()
{
    m_payeMontantFixe = false;
    m_montantFixe = 0;
    
    // Mise à jour de l'affichage.
    if (m_elementGraphique)
    {
        m_elementGraphique->updatePrix(helper_getPrix());
    }
}





bool Taxe::isPourcentageFortune() const
{
    return m_payePourcentageFortune;
}





quint16 Taxe::getPourcentageFortune() const
{
    return m_pourcentageFortune;
}





void Taxe::enablePourcentageFortune(const quint8 pourcentage)
{
    m_payePourcentageFortune = true;
    if (pourcentage > 100)
    {
        m_pourcentageFortune = 100;
    }
    else
    {
        m_pourcentageFortune = pourcentage;
    }
    
    // Mise à jour de l'affichage.
    if (m_elementGraphique)
    {
        m_elementGraphique->updatePrix(helper_getPrix());
    }
}





void Taxe::disablePourcentageFortune()
{
    m_payePourcentageFortune = false;
    m_pourcentageFortune = 0;
    
    // Mise à jour de l'affichage.
    if (m_elementGraphique)
    {
        m_elementGraphique->updatePrix(helper_getPrix());
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

