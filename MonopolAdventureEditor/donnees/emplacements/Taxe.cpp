#include "Taxe.hpp"





Taxe::Taxe() :
    Emplacement(Type::Taxe),
    m_payeMontantFixe(false),
    m_montantFixe(0),
    m_payePourcentageFortune(false),
    m_pourcentageFortune(0)
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
}





void Taxe::disableMontantFixe()
{
    m_payeMontantFixe = false;
    m_montantFixe = 0;
}





bool Taxe::isPourcentageFortune() const
{
    return m_payePourcentageFortune;
}





quint16 Taxe::getPourcentageFortune() const
{
    return m_pourcentageFortune;
}





void Taxe::enablePourcentageFortune(const quint16 pourcentage)
{
    m_payePourcentageFortune = true;
    if (montant > MONTANT_MAX_EDITEUR)
    {
        m_pourcentageFortune = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_pourcentageFortune = montant;
    }
}





void Taxe::disablePourcentageFortune()
{
    m_payePourcentageFortune = false;
    m_pourcentageFortune = 0;
}

