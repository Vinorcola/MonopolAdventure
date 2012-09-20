#include "Propriete.hpp"





Propriete::Propriete(const Type::Emplacement type) :
    Emplacement(type),
    m_prixAchat(0),
    m_valeurHypotheque(0)
{
    
}





Propriete::~Propriete()
{
    
}





quint16 Propriete::getPrixAchat() const
{
    return m_prixAchat;
}





void Propriete::editPrixAchat(const quint16 montant)
{
    if (montant > MONTANT_MAX_EDITEUR)
    {
        m_prixAchat = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_prixAchat = montant;
    }
}





quint16 Propriete::getValeurHypotheque() const
{
    return m_valeurHypotheque;
}





void Propriete::editValeurHypotheque(const quint16 montant)
{
    if (montant > MONTANT_MAX_EDITEUR)
    {
        m_valeurHypotheque = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_valeurHypotheque = montant;
    }
}

