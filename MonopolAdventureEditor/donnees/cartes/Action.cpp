#include "Action.hpp"

#include "donnees/cartes/PileCartes.hpp"





Action::Action() :
    m_deplacement(false),
    m_joueurAvance(false),
    m_deplacementRelatif(0),
    m_deplacementEmplacement(false),
    m_deplacementJusquauProchain(Type::Aucun),
    m_coefficientLoyer(1),
    m_relanceDes(false),
    
    m_transaction(false),
    m_gainArgent(false),
    m_enversBanque(false),
    m_enversTousLesJoueurs(false),
    m_montant(0),
    
    m_reparation(false),
    m_montantParMaison(0),
    m_montantParHotel(0),
    m_montantParGratteCiel(0),
    
    m_payeOuPioche(false),
    m_pileCartes(0),
    
    m_pioche(false),
    
    m_libereDePrison(false)
{
    setDeplacement(true, 1);
}





bool Action::isDeplacement() const
{
    return m_deplacement;
}





bool Action::joueurAvance() const
{
    if (isDeplacement())
    {
        return m_joueurAvance;
    }
    
    return false;
}





bool Action::joueurRecule() const
{
    return !joueurAvance();
}





bool Action::isDeplacementAbsolu() const
{
    if (isDeplacement())
    {
        return m_deplacementEmplacement != 0;
    }
    
    return false;
}





bool Action::isDeplacementRelatif() const
{
    if (isDeplacement())
    {
        return m_deplacementRelatif != 0;
    }
    
    return false;
}





bool Action::isDeplacementJusquauProchain() const
{
    if (isDeplacement())
    {
        return m_deplacementJusquauProchain != Type::Aucun;
    }
    
    return false;
}





quint8 Action::deplacementNombreEmplacements() const
{
    if (isDeplacementRelatif())
    {
        return m_deplacementRelatif;
    }
    
    return 0;
}





Emplacement* Action::deplacementEmplacement() const
{
    if (isDeplacementAbsolu())
    {
        return m_deplacementEmplacement;
    }
    
    return false;
}





Type::Emplacement Action::deplacementJusquauProchain() const
{
    if (isDeplacementJusquauProchain())
    {
        return m_deplacementJusquauProchain;
    }
    
    return Type::Aucun;
}





quint8 Action::coefficientLoyer() const
{
    return m_coefficientLoyer;
}





bool Action::relanceDesPourLoyerService() const
{
    return m_relanceDes;
}





void Action::setDeplacement(const bool avance,
                            Emplacement* emplacement,
                            const quint8 coefficientLoyer,
                            const bool relanceDes)
{
    if (emplacement)
    {
        m_deplacement = true;
        m_joueurAvance = avance;
        m_deplacementRelatif = 0;
        m_deplacementEmplacement = emplacement;
        m_deplacementJusquauProchain = Type::Aucun;
        m_coefficientLoyer = coefficientLoyer;
        m_relanceDes = relanceDes;
        m_transaction = false;
        m_gainArgent = false;
        m_enversBanque = false;
        m_enversTousLesJoueurs = false;
        m_montant = 0;
        m_reparation = false;
        m_montantParMaison = 0;
        m_montantParHotel = 0;
        m_montantParGratteCiel = 0;
        m_payeOuPioche = false;
        m_pileCartes = 0;
        m_pioche = false;
        m_libereDePrison = false;
    }
}





void Action::setDeplacement(const bool avance,
                            const quint8 nombreEmplacements,
                            const quint8 coefficientLoyer,
                            const bool relanceDes)
{
    if (nombreEmplacements > 0)
    {
        m_deplacement = true;
        m_joueurAvance = avance;
        m_deplacementRelatif = nombreEmplacements;
        m_deplacementEmplacement = 0;
        m_deplacementJusquauProchain = Type::Aucun;
        m_coefficientLoyer = coefficientLoyer;
        m_relanceDes = relanceDes;
        m_transaction = false;
        m_gainArgent = false;
        m_enversBanque = false;
        m_enversTousLesJoueurs = false;
        m_montant = 0;
        m_reparation = false;
        m_montantParMaison = 0;
        m_montantParHotel = 0;
        m_montantParGratteCiel = 0;
        m_payeOuPioche = false;
        m_pileCartes = 0;
        m_pioche = false;
        m_libereDePrison = false;
    }
}





void Action::setDeplacementJusquauProchain(const bool avance,
                                           const Type::Emplacement typeEmplacement,
                                           const quint8 coefficientLoyer,
                                           const bool relanceDes)
{
    m_deplacement = true;
    m_joueurAvance = avance;
    m_deplacementRelatif = 0;
    m_deplacementEmplacement = 0;
    m_deplacementJusquauProchain = typeEmplacement;
    m_coefficientLoyer = coefficientLoyer;
    m_relanceDes = relanceDes;
    m_transaction = false;
    m_gainArgent = false;
    m_enversBanque = false;
    m_enversTousLesJoueurs = false;
    m_montant = 0;
    m_reparation = false;
    m_montantParMaison = 0;
    m_montantParHotel = 0;
    m_montantParGratteCiel = 0;
    m_payeOuPioche = false;
    m_pileCartes = 0;
    m_pioche = false;
    m_libereDePrison = false;
}





bool Action::isTransaction() const
{
    return m_transaction;
}





bool Action::joueurGagneArgent() const
{
    if (isTransaction())
    {
        return m_gainArgent;
    }
    
    return false;
}





bool Action::joueurPerdArgent() const
{
    return !joueurGagneArgent();
}





bool Action::isTransactionAvecJoueurSecondaire() const
{
    if (isTransaction())
    {
        return !m_enversBanque && !m_enversTousLesJoueurs;
    }
    
    return false;
}





bool Action::isTransactionAvecBanque() const
{
    if (isTransaction())
    {
        return m_enversBanque;
    }
    
    return false;
}





bool Action::isTransactionAvecTousLesJoueurs() const
{
    if (isTransaction())
    {
        return m_enversTousLesJoueurs;
    }
    
    return false;
}





quint16 Action::montant() const
{
    if (isTransaction())
    {
        return m_montant;
    }
    
    return 0;
}





void Action::setTransactionAvecJoueurSecondaire(const bool gain,
                                                const quint16 montant)
{
    m_deplacement = false;
    m_joueurAvance = false;
    m_deplacementRelatif = 0;
    m_deplacementEmplacement = 0;
    m_deplacementJusquauProchain = Type::Aucun;
    m_coefficientLoyer = 1;
    m_relanceDes = false;
    m_transaction = true;
    m_gainArgent = gain;
    m_enversBanque = false;
    m_enversTousLesJoueurs = false;
    m_montant = montant;
    m_reparation = false;
    m_montantParMaison = 0;
    m_montantParHotel = 0;
    m_montantParGratteCiel = 0;
    m_payeOuPioche = false;
    m_pileCartes = 0;
    m_pioche = false;
    m_libereDePrison = false;
}





void Action::setTransactionAvecBanque(const bool gain,
                                      const quint16 montant)
{
    m_deplacement = false;
    m_joueurAvance = false;
    m_deplacementRelatif = 0;
    m_deplacementEmplacement = 0;
    m_deplacementJusquauProchain = Type::Aucun;
    m_coefficientLoyer = 1;
    m_relanceDes = false;
    m_transaction = true;
    m_gainArgent = gain;
    m_enversBanque = true;
    m_enversTousLesJoueurs = false;
    m_montant = montant;
    m_reparation = false;
    m_montantParMaison = 0;
    m_montantParHotel = 0;
    m_montantParGratteCiel = 0;
    m_payeOuPioche = false;
    m_pileCartes = 0;
    m_pioche = false;
    m_libereDePrison = false;
}





void Action::setTransactionAvecTousLesJoueurs(const bool gain,
                                              const quint16 montant)
{
    m_deplacement = false;
    m_joueurAvance = false;
    m_deplacementRelatif = 0;
    m_deplacementEmplacement = 0;
    m_deplacementJusquauProchain = Type::Aucun;
    m_coefficientLoyer = 1;
    m_relanceDes = false;
    m_transaction = true;
    m_gainArgent = gain;
    m_enversBanque = false;
    m_enversTousLesJoueurs = true;
    m_montant = montant;
    m_reparation = false;
    m_montantParMaison = 0;
    m_montantParHotel = 0;
    m_montantParGratteCiel = 0;
    m_payeOuPioche = false;
    m_pileCartes = 0;
    m_pioche = false;
    m_libereDePrison = false;
}





bool Action::isReparationConstructions() const
{
    return m_reparation;
}





quint16 Action::montantParMaison() const
{
    if (isReparationConstructions())
    {
        return m_montantParMaison;
    }
    
    return 0;
}





quint16 Action::montantParHotel() const
{
    if (isReparationConstructions())
    {
        return m_montantParHotel;
    }
    
    return 0;
}





quint16 Action::montantParGratteCiel() const
{
    if( isReparationConstructions())
    {
        return m_montantParGratteCiel;
    }
    
    return 0;
}





void Action::setReparationConstructions(const quint16 montantParMaison,
                                        const quint16 montantParHotel,
                                        const quint16 montantParGratteCiel)
{
    m_deplacement = false;
    m_joueurAvance = false;
    m_deplacementRelatif = 0;
    m_deplacementEmplacement = 0;
    m_deplacementJusquauProchain = Type::Aucun;
    m_coefficientLoyer = 1;
    m_relanceDes = false;
    m_transaction = false;
    m_gainArgent = false;
    m_enversBanque = false;
    m_enversTousLesJoueurs = false;
    m_montant = 0;
    m_reparation = true;
    m_montantParMaison = montantParMaison;
    m_montantParHotel = montantParHotel;
    m_montantParGratteCiel = montantParGratteCiel;
    m_payeOuPioche = false;
    m_pileCartes = 0;
    m_pioche = false;
    m_libereDePrison = false;
}





bool Action::isPayeOuPioche() const
{
    return m_payeOuPioche;
}





bool Action::isPioche() const
{
    return m_pioche;
}





PileCartes* Action::pileCartes() const
{
    if (isPayeOuPioche() || isPioche())
    {
        return m_pileCartes;
    }
    
    return 0;
}





quint16 Action::montantAmende() const
{
    if (isPayeOuPioche())
    {
        return m_montant;
    }
    
    return 0;
}





void Action::setPayeOuPioche(const quint16 montantAmende,
                             PileCartes* pileDeCartes)
{
    m_deplacement = false;
    m_joueurAvance = false;
    m_deplacementRelatif = 0;
    m_deplacementEmplacement = 0;
    m_deplacementJusquauProchain = Type::Aucun;
    m_coefficientLoyer = 1;
    m_relanceDes = false;
    m_transaction = false;
    m_gainArgent = false;
    m_enversBanque = false;
    m_enversTousLesJoueurs = false;
    m_montant = montantAmende;
    m_reparation = false;
    m_montantParMaison = 0;
    m_montantParHotel = 0;
    m_montantParGratteCiel = 0;
    m_payeOuPioche = true;
    m_pileCartes = pileDeCartes;
    m_pioche = false;
    m_libereDePrison = false;
}





void Action::setPioche(PileCartes* pileDeCartes)
{
    m_deplacement = false;
    m_joueurAvance = false;
    m_deplacementRelatif = 0;
    m_deplacementEmplacement = 0;
    m_deplacementJusquauProchain = Type::Aucun;
    m_coefficientLoyer = 1;
    m_relanceDes = false;
    m_transaction = false;
    m_gainArgent = false;
    m_enversBanque = false;
    m_enversTousLesJoueurs = false;
    m_montant = 0;
    m_reparation = false;
    m_montantParMaison = 0;
    m_montantParHotel = 0;
    m_montantParGratteCiel = 0;
    m_payeOuPioche = false;
    m_pileCartes = pileDeCartes;
    m_pioche = true;
    m_libereDePrison = false;
}





bool Action::isLibereDePrison() const
{
    return m_libereDePrison;
}





void Action::setLibereDePrison()
{
    m_deplacement = false;
    m_joueurAvance = false;
    m_deplacementRelatif = 0;
    m_deplacementEmplacement = 0;
    m_deplacementJusquauProchain = Type::Aucun;
    m_coefficientLoyer = 1;
    m_relanceDes = false;
    m_transaction = false;
    m_gainArgent = false;
    m_enversBanque = false;
    m_enversTousLesJoueurs = false;
    m_montant = 0;
    m_reparation = false;
    m_montantParMaison = 0;
    m_montantParHotel = 0;
    m_montantParGratteCiel = 0;
    m_payeOuPioche = false;
    m_pileCartes = 0;
    m_pioche = false;
    m_libereDePrison = true;
}

