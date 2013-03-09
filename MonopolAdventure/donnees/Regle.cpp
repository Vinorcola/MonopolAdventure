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





bool Regle::enchereDepart() const
{
    return m_enchereDepart;
}





bool Regle::premierTourSansAchat() const
{
    return m_premierTourSansAchat;
}





bool Regle::salaireDouble() const
{
    return m_salaireDouble;
}





bool Regle::taxeInParcGratuit() const
{
    return m_taxeInParcGratuit;
}





bool Regle::amendeCarteInParcGratuit() const
{
    return m_amendeCarteInParcGratuit;
}





bool Regle::cagnotteFixe() const
{
    return m_cagnotteFixe;
}





quint16 Regle::montantFixe() const
{
    return m_montantFixe;
}





quint8 Regle::nombreMaxTourEnPrison() const
{
    return m_nombreMaxTourEnPrison;
}





bool Regle::joueurPeutPercevoirLoyerEnPrison() const
{
    return m_joueurPeutPercevoirLoyerEnPrison;
}





bool Regle::joueurPeutParticiperEncheresEnPrison() const
{
    return m_joueurPeutParticiperEncheresEnPrison;
}





bool Regle::joueurPeutEchangerEnPrison() const
{
    return m_joueurPeutEchangerEnPrison;
}





bool Regle::joueurPeutConstruireEnPrison() const
{
    return m_joueurPeutConstruireEnPrison;
}





bool Regle::banquePeutFaireFaillite() const
{
    return m_banquePeutFaireFaillite;
}





quint32 Regle::montantMaxBanque() const
{
    return m_montantMaxBanque;
}





quint8 Regle::nombreTotalMaison() const
{
    return m_nombreTotalMaison;
}





quint8 Regle::nombreTotalHotel() const
{
    return m_nombreTotalHotel;
}





bool Regle::enchereSurBiensRecperes() const
{
    return m_enchereSurBiensRecuperes;
}





bool Regle::enchereSurNonAchete() const
{
    return m_enchereSurNonAchete;
}





bool Regle::constructionHomogene() const
{
    return m_constructionHomogene;
}





bool Regle::tousTerrainsVendusPourConstruire() const
{
    return m_tousTerrainsVendusPourConstruire;
}





bool Regle::toutesProprietesVenduesPourConstruire() const
{
    return m_toutesProprietesVenduesPourConstruire;
}





bool Regle::possessionRegroupementPourConstruire() const
{
    return m_possessionRegroupementPourConstruire;
}





bool Regle::joueurPresentPourConstruire() const
{
    return m_joueurPresentPourConstruire;
}





quint8 Regle::nombreTourMax() const
{
    return m_nombreTourMax;
}





bool Regle::partieNormale() const
{
    return !(m_partieRapide || m_partieRuineLaBanque);
}





bool Regle::partieRapide() const
{
    return m_partieRapide;
}





bool Regle::partieRuineLaBanque() const
{
    return m_partieRuineLaBanque;
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

