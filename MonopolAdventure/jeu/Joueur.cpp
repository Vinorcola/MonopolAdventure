#include "Joueur.hpp"





Joueur::Joueur(const QString& pseudo,
               const qint32 cagnotteDepart) :
    m_pseudo(pseudo),
    m_image(),
    m_cagnotte(cagnotteDepart),
    m_nbTourEnPrisonRestant(0),
    m_proprietes()
{
    
}





const QString& Joueur::getPseudo() const
{
    return m_pseudo;
}





qint32 Joueur::getCagnotte() const
{
    return m_cagnotte;
}





bool Joueur::getNbTourEnPrisonRestant() const
{
    return m_nbTourEnPrisonRestant;
}

