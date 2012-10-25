#include "Propriete.hpp"





Propriete::Propriete(const Type::Emplacement type,
                     const GraphismeEmplacementInfos& graphismeInfos,
                     const QString& devise) :
    Emplacement(type, graphismeInfos),
    m_prixAchat(0),
    m_valeurHypotheque(0),
    m_devise(devise)
{
    
}





Propriete::Propriete(const Propriete& propriete) :
    Emplacement(propriete),
    m_prixAchat(propriete.m_prixAchat),
    m_valeurHypotheque(propriete.m_valeurHypotheque),
    m_devise(propriete.m_devise)
{
    
}





Propriete::~Propriete()
{
    
}





Propriete& Propriete::operator =(const Propriete& propriete)
{
    if (getType() == propriete.getType())
    {
        Emplacement::operator =(propriete);
        m_prixAchat = propriete.m_prixAchat;
        m_valeurHypotheque = propriete.m_valeurHypotheque;
    }
    
    return *this;
}





quint16 Propriete::getPrixAchat() const
{
    return m_prixAchat;
}





void Propriete::editPrixAchat(const quint16 montant)
{
    // Change le prix d'achat.
    if (montant > MONTANT_MAX_EDITEUR)
    {
        m_prixAchat = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_prixAchat = montant;
    }
    
    // Mise à jour de l'affichage du prix.
    if (m_elementGraphique)
    {
        m_elementGraphique->updatePrix(helper_getPrix());
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





QString Propriete::helper_getPrix() const
{
    return QString::number(m_prixAchat) + m_devise;
}

