#include "Joueur.hpp"





Joueur::Joueur(const QString& pseudo,
               const qint32 cagnotteDepart,
               const QString& couleur,
               const QString& devise) :
    m_pseudo(pseudo),
    m_image(new GraphismeJoueur(couleur)),
    m_cagnotte(cagnotteDepart),
    m_nbTourEnPrisonRestant(0),
    m_proprietes(),
    m_panneauInfos(new PanneauInfosJoueur(this, devise))
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





PanneauInfosJoueur* Joueur::getPanneauInformations() const
{
    return m_panneauInfos;
}

