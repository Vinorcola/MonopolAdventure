#include "Regle.hpp"

#include "donnees/Plateau.hpp"





Regle::Regle() :
    m_nombreProprietesAuDepart(0),
    m_enchereDepart(false),
    m_premierTourSansAchat(false),
    m_salaireDouble(false),
    m_taxeInParcGratuit(false),
    m_amendeCarteInParcGratuit(false),
    m_cagnotteFixe(false),
    m_montantFixe(0),
    m_nombreMaxTourEnPrison(3),
    m_joueurPeutPercevoirLoyerEnPrison(true),
    m_joueurPeutParticiperEncheresEnPrison(true),
    m_joueurPeutEchangerEnPrison(true),
    m_joueurPeutConstruireEnPrison(true),
    m_banquePeutFaireFaillite(false),
    m_montantMaxBanque(0),
    m_nombreTotalMaison(32),
    m_nombreTotalHotel(12),
    m_enchereSurBiensRecuperes(true),
    m_enchereSurNonAchete(true),
    m_constructionHomogene(true),
    m_tousTerrainsVendusPourConstruire(false),
    m_toutesProprietesVenduesPourConstruire(false),
    m_possessionRegroupementPourConstruire(true),
    m_joueurPresentPourConstruire(false),
    m_nombreTourMax(0),
    m_partieRapide(false),
    m_partieRuineLaBanque(false)
{
    
}





qint8 Regle::nombreProprietesAuDepart() const
{
    return m_nombreProprietesAuDepart;
}





void Regle::setNombreProprietesAuDepart(qint8 nombre,
                                        const Plateau* const plateau)
{
    int nbMaxEmplacements(plateau->getNombrePropriete() / 2);
    
    if (nombre < 0)
    {
        m_nombreProprietesAuDepart = -1;
    }
    else if (nombre > nbMaxEmplacements)
    {
        m_nombreProprietesAuDepart = nbMaxEmplacements;
    }
    else
    {
        m_nombreProprietesAuDepart = nombre;
    }
}





bool Regle::enchereDepart() const
{
    return m_enchereDepart;
}





void Regle::setEnchereDepart(const bool actif)
{
    m_enchereDepart = actif;
}





bool Regle::premierTourSansAchat() const
{
    return m_premierTourSansAchat;
}





void Regle::setPremierTourSansAchat(const bool actif)
{
    m_premierTourSansAchat = actif;
}





bool Regle::salaireDouble() const
{
    return m_salaireDouble;
}





void Regle::setSalaireDouble(const bool actif)
{
    m_salaireDouble = actif;
}





bool Regle::taxeInParcGratuit() const
{
    return m_taxeInParcGratuit;
}





void Regle::setTaxeInParcGratuit(const bool actif)
{
    m_taxeInParcGratuit = actif;
}





bool Regle::amendeCarteInParcGratuit() const
{
    return m_amendeCarteInParcGratuit;
}





void Regle::setAmendeCarteInParcGratuit(const bool actif)
{
    m_amendeCarteInParcGratuit = actif;
}





bool Regle::cagnotteFixe() const
{
    return m_cagnotteFixe;
}





void Regle::setCagnotteFixe(const bool actif)
{
    m_cagnotteFixe = actif;
}





quint16 Regle::montantFixe() const
{
    return m_montantFixe;
}





void Regle::setMontantFixe(const quint16 montant)
{
    if (montant > MONTANT_MAX_EDITEUR)
    {
        m_montantFixe = MONTANT_MAX_EDITEUR;
    }
    else
    {
        m_montantFixe = montant;
    }
}





quint8 Regle::nombreMaxTourEnPrison() const
{
    return m_nombreMaxTourEnPrison;
}





void Regle::setNombreMaxTourEnPrison(const quint8 nombre)
{
    if (nombre > NOMBRE_TOURS_MAX_PRISON)
    {
        m_nombreMaxTourEnPrison = NOMBRE_TOURS_MAX_PRISON;
    }
    else
    {
        m_nombreMaxTourEnPrison = nombre;
    }
}





bool Regle::joueurPeutPercevoirLoyerEnPrison() const
{
    return m_joueurPeutPercevoirLoyerEnPrison;
}





void Regle::setJoueurPeutPercevoirLoyerEnPrison(const bool actif)
{
    m_joueurPeutPercevoirLoyerEnPrison = actif;
}





bool Regle::joueurPeutParticiperEncheresEnPrison() const
{
    return m_joueurPeutParticiperEncheresEnPrison;
}





void Regle::setJoueurPeutParticiperEncheresEnPrison(const bool actif)
{
    m_joueurPeutParticiperEncheresEnPrison = actif;
}





bool Regle::joueurPeutEchangerEnPrison() const
{
    return m_joueurPeutEchangerEnPrison;
}





void Regle::setJoueurPeutEchangerEnPrison(const bool actif)
{
    m_joueurPeutEchangerEnPrison = actif;
}





bool Regle::joueurPeutConstruireEnPrison() const
{
    return m_joueurPeutConstruireEnPrison;
}





void Regle::setJoueurPeutConstruireEnPrison(const bool actif)
{
    m_joueurPeutConstruireEnPrison = actif;
}





bool Regle::banquePeutFaireFaillite() const
{
    return m_banquePeutFaireFaillite;
}





void Regle::setBanquePeutFaireFaillite(const bool actif)
{
    if (actif)
    {
        m_banquePeutFaireFaillite = true;
    }
    else
    {
        if (!m_partieRuineLaBanque)
        {
            m_banquePeutFaireFaillite = false;
            m_montantMaxBanque = 0;
        }
    }
}





quint32 Regle::montantMaxBanque() const
{
    return m_montantMaxBanque;
}





void Regle::setMontantMaxBanque(const quint32 montant)
{
    if (m_banquePeutFaireFaillite)
    {
        if (montant > MONTANT_MAX_EDITEUR)
        {
            m_montantMaxBanque = MONTANT_MAX_EDITEUR;
        }
        else
        {
            m_montantMaxBanque = montant;
        }
    }
}





quint8 Regle::nombreTotalMaison() const
{
    return m_nombreTotalMaison;
}





void Regle::setNombreTotalMaison(const quint8 nombre)
{
    m_nombreTotalMaison = nombre;
}





quint8 Regle::nombreTotalHotel() const
{
    return m_nombreTotalHotel;
}





void Regle::setNombreTotalHotel(const quint8 nombre)
{
    m_nombreTotalHotel = nombre;
}





bool Regle::enchereSurBiensRecperes() const
{
    return m_enchereSurBiensRecuperes;
}





void Regle::setEnchereSurBiensRecuperes(const bool actif)
{
    m_enchereSurBiensRecuperes = actif;
}





bool Regle::enchereSurNonAchete() const
{
    return m_enchereSurNonAchete;
}





void Regle::setEnchereSurNonAchete(const bool actif)
{
    m_enchereSurNonAchete = actif;
}





bool Regle::constructionHomogene() const
{
    return m_constructionHomogene;
}





void Regle::setConstructionHomogene(const bool actif)
{
    m_constructionHomogene = (actif && m_possessionRegroupementPourConstruire);
}





bool Regle::tousTerrainsVendusPourConstruire() const
{
    return m_tousTerrainsVendusPourConstruire;
}





void Regle::setTousTerrainsVendusPourConstruire(const bool actif)
{
    m_tousTerrainsVendusPourConstruire = actif;
    m_toutesProprietesVenduesPourConstruire = (m_toutesProprietesVenduesPourConstruire && !actif);
}





bool Regle::toutesProprietesVenduesPourConstruire() const
{
    return m_toutesProprietesVenduesPourConstruire;
}





void Regle::setToutesProprietesVenduesPourConstruire(const bool actif)
{
    m_tousTerrainsVendusPourConstruire = (m_tousTerrainsVendusPourConstruire && !actif);
    m_toutesProprietesVenduesPourConstruire = actif;
}





bool Regle::possessionRegroupementPourConstruire() const
{
    return m_possessionRegroupementPourConstruire;
}





void Regle::setPossessionRegroupementPourConstruire(const bool actif)
{
    m_possessionRegroupementPourConstruire = actif;
    
    if (!actif)
    {
        m_constructionHomogene = false;
    }
}





bool Regle::joueurPresentPourConstruire() const
{
    return m_joueurPresentPourConstruire;
}





void Regle::setJoueurPresentPourConstruire(const bool actif)
{
    m_joueurPresentPourConstruire = actif;
}





quint8 Regle::nombreTourMax() const
{
    return m_nombreTourMax;
}





void Regle::setNombreTourMax(const quint8 nombre)
{
    m_nombreTourMax = nombre;
}





bool Regle::partieNormale() const
{
    return !(m_partieRapide || m_partieRuineLaBanque);
}





void Regle::setPartieNormale(const bool actif)
{
    m_partieRapide = (m_partieRapide && !actif);
    m_partieRuineLaBanque = (m_partieRuineLaBanque && !actif);
}





bool Regle::partieRapide() const
{
    return m_partieRapide;
}





void Regle::setPartieRapide(const bool actif)
{
    m_partieRapide = actif;
    m_partieRuineLaBanque = (m_partieRuineLaBanque && !actif);
}





bool Regle::partieRuineLaBanque() const
{
    return m_partieRuineLaBanque;
}





void Regle::setPartieRuineLaBanque(const bool actif)
{
    m_partieRapide = (m_partieRapide && !actif);
    m_partieRuineLaBanque = actif;
}





void Regle::saveInFile(QDataStream& ecriture) const
{
    ecriture << m_nombreProprietesAuDepart
             << m_enchereDepart
             << m_premierTourSansAchat
             << m_salaireDouble
             << m_taxeInParcGratuit
             << m_amendeCarteInParcGratuit
             << m_cagnotteFixe
             << m_montantFixe
             << m_nombreMaxTourEnPrison
             << m_joueurPeutPercevoirLoyerEnPrison
             << m_joueurPeutParticiperEncheresEnPrison
             << m_joueurPeutEchangerEnPrison
             << m_joueurPeutConstruireEnPrison
             << m_banquePeutFaireFaillite
             << m_montantMaxBanque
             << m_nombreTotalMaison
             << m_nombreTotalHotel
             << m_enchereSurBiensRecuperes
             << m_enchereSurNonAchete
             << m_constructionHomogene
             << m_tousTerrainsVendusPourConstruire
             << m_toutesProprietesVenduesPourConstruire
             << m_possessionRegroupementPourConstruire
             << m_joueurPresentPourConstruire
             << m_nombreTourMax
             << m_partieRapide
             << m_partieRuineLaBanque;
}





void Regle::loadFromFile(QDataStream& lecture,
                         const quint16 version)
{
    switch (version)
    {
        default:
            lecture >> m_nombreProprietesAuDepart
                    >> m_enchereDepart
                    >> m_premierTourSansAchat
                    >> m_salaireDouble
                    >> m_taxeInParcGratuit
                    >> m_amendeCarteInParcGratuit
                    >> m_cagnotteFixe
                    >> m_montantFixe
                    >> m_nombreMaxTourEnPrison
                    >> m_joueurPeutPercevoirLoyerEnPrison
                    >> m_joueurPeutParticiperEncheresEnPrison
                    >> m_joueurPeutEchangerEnPrison
                    >> m_joueurPeutConstruireEnPrison
                    >> m_banquePeutFaireFaillite
                    >> m_montantMaxBanque
                    >> m_nombreTotalMaison
                    >> m_nombreTotalHotel
                    >> m_enchereSurBiensRecuperes
                    >> m_enchereSurNonAchete
                    >> m_constructionHomogene
                    >> m_tousTerrainsVendusPourConstruire
                    >> m_toutesProprietesVenduesPourConstruire
                    >> m_possessionRegroupementPourConstruire
                    >> m_joueurPresentPourConstruire
                    >> m_nombreTourMax
                    >> m_partieRapide
                    >> m_partieRuineLaBanque;
    }
}

