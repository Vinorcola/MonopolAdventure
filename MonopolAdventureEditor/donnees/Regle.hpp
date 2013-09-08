#ifndef REGLE_HPP
#define REGLE_HPP

#include <QtGlobal>

class Plateau;





/**
 * @class Regle Regle.hpp donnees/Regle.hpp
 * Cette classe contient les principales règle de jeu.
 * 
 * Cette classe contient toutes les règles de jeu paramétrable par les joueurs. Elle appartient à la classe Plateau.
 */
class Regle
{
    private:
        // Options début de la partie
        /**
         * Option "Nombre de propriétés au départ".
         *
         * Nombre de propriétés distribuées aléatoirement aux joueurs au début de la partie (-1 pour toutes).
         */
        qint8 m_nombreProprietesAuDepart;
        
        /**
         * Option "Enchères de départ".
         *
         * Les joueurs vont faire des enchères afin d'obtenir le droit de commencer. Le joueur qui fait l'offre la plus forte commence la partie.
         */
        bool m_enchereDepart;
        
        /**
         * Option "Premier tour sans achat".
         *
         * Chaque joueur doit passer par la case Départ au moins une fois avant de pouvoir acheter des propriétés.
         */
        bool m_premierTourSansAchat;
        
        /**
         * Option "Argent au départ".
         * 
         * Argent donné à chaque joueur pour commencer la partie.
         */
        quint16 m_argentDepart;
        
        
        
        // Options depart
        /**
         * Option "Salaire double".
         *
         * Le joueur reçoit un salaire double s'il s'arrête sur la case Départ. Il continu de recevoir un salaire normal s'il ne fait que passé.
         */
        bool m_salaireDouble;
        
        
        
        // Options parc gratuit
        /**
         * Option "Taxes au Parc gratuit".
         *
         * Les joueurs qui tombent sur les cases Taxes versent le montant de l'amende non plus à la banque, mais au Parc gratuit afin de constituer une cagnotte. Le prochain joueur qui s'arrête au Parc gratuit récolte le cumulte de la cagnotte. La cagnotte est alors remise à zéro.
         *
         * @note Cette option ne peut pas être activée si :
         * @li l'option "Cagnotte fixe" est active (MAOptionsGlobales::m_optionCagotteFixe).
         */
        bool m_taxeInParcGratuit;
        
        /**
         * Option "Amendes des cartes au Parc gratuit".
         *
         * Les joueurs qui doivent verser de l'argent à cause d'une carte versent le montant de l'amende non plus à la banque, mais au Parc gratuit afin de constituer une cagnotte. Le prochain joueur qui s'arrête au Parc gratuit récolte le cumulte de la cagnotte. La cagnotte est alors remise à zéro.
         *
         * @note Cette option ne peut pas être activée si :
         * @li l'option "Cagnotte fixe" est active (MAOptionsGlobales::m_optionCagnotteFixe).
         */
        bool m_amendeCarteInParcGratuit;
        
        /**
         * Option "Cagnotte fixe".
         *
         * Les joueurs qui s'arrêtent au Parc gratuit récolte un montant fixe.
         *
         * @note Cette option ne peut pas être activée si :
         * @li l'option "Taxes au Parc gratuit" est active (MAOptionsGlobales::m_optionTaxeInParcGratuit) ;
         * @li OU l'option "Amendes des cartes au Parc gratuit" est active (MAOptionsGlobales::m_optionAmendeCarteInParcGratuit).
         */
        bool m_cagnotteFixe;
        
        /**
         * Option "Montant de la cagnotte fixe".
         *
         * Indique le montant de la cagnotte fixe.
         *
         * @note Cette option n'est prise en compte que si :
         * @li l'option "Cagnotte fixe" est active (MAOptionsGlobales::m_optionCagnotteFixe).
         */
        quint16 m_montantFixe;
        
        
        
        // Options prison
        /**
         * Option "Nombre maximum de tours en prison".
         *
         * Indique le nombre de tours consécutifs maximum qu'un joueur peut passer en prison. Lors qu'un joueur est envoyé en prison, son tour se finis. Son prochain tour est considéré comme son premier tour en prison. Lorsqu'il arrive à son @a m_optionNombreMaxTourEnPrison ème tour, s'il ne fait pas de doubles aux dés, le joueur doit payer la caution pour sortir (ou utiliser une carte sortir de prison) et avancer de nombre de cases indiquées par les dés.
         */
        quint8 m_nombreMaxTourEnPrison;
        
        /**
         * Option "Le joueur peut percevoir ses loyers en prison".
         *
         * Si cette option est désactivée, le joueur ne peut pas recevoir de loyers s'il est en prison.
         */
        bool m_joueurPeutPercevoirLoyerEnPrison;
        
        /**
         * Option "Le joueur peut participer aux enchères en prison".
         *
         * Si cette option est désactivée, le joueur ne peut pas participer aux enchères sur les propriétés invendues s'il est en prison.
         */
        bool m_joueurPeutParticiperEncheresEnPrison;
        
        /**
         * Option "Le joueur peut échanger en prison".
         *
         * Si cette option est désactivée, le joueur ne peut pas échanger de propriétés avec un autre joueur s'il est en prison.
         */
        bool m_joueurPeutEchangerEnPrison;
        
        /**
         * Option "Le joueur peut construire en prison".
         *
         * Si cette option est désactivée, le joueur ne peut ni construire, ni détruire de bâtiments sur ces propriétés s'il est en prison.
         */
        bool m_joueurPeutConstruireEnPrison;// et détruire ...
        
        
        
        // Options banque
        /**
         * Option "Banque peut faire faillite".
         *
         * La banque à un budget limité et peut faire faillite. Tous les joueurs restant sur le plateau gagnent la partie.
         */
        bool m_banquePeutFaireFaillite;
        
        /**
         * Option "Montant maximum de la banque".
         *
         * Détermine le budget de la banque lorsqu'elle peut faire faillite.
         *
         * @note Cette option n'est prise en compte que si :
         * @li l'option "Banque peut faire faillite" est active (MAOptionsGlobales::m_optionBanquePeutFaireFaillite.
         */
        quint32 m_montantMaxBanque;
        
        /**
         * Option "Nombre total de maisons".
         *
         * Indique le nombre total de maisons que peut vendre la banque aux joueurs.
         */
        quint8 m_nombreTotalMaison;
        
        /**
         * Option "Nombre total d'hôtels".
         *
         * Indique le nombre total d'hôtels que peut vendre la banque aux joueurs.
         */
        quint8 m_nombreTotalHotel;
        
        /**
         * Option "Enchères sur biens récupérés".
         *
         * Indique si la banque revends immédiatement aux enchères las biens qu'elle a récupérés suite à la faillite d'un joueur.
         */
        bool m_enchereSurBiensRecuperes;
        
        /**
         * Option "Enchères sur biens non achetés".
         *
         * Indique si la banque met en place des enchères sur les propriétés que les joueurs refusent d'acheter.
         */
        bool m_enchereSurNonAchete;
        
        
        
        // Options construction
        /**
         * Option "Constructions homogènes".
         *
         * Les joueurs doivent faire leurs constructions de manière homogène : un terrain du regroupement ne peut pas posséder plus d'une construction d'écart avec les autres terrains du regropement.
         *
         * C'est-à-dire que pour construire la troisième maison sur un terrain, il faut que les autres terrains du regroupement aient au moins deux maisons chacun.
         */
        bool m_constructionHomogene;
        
        /**
         * Option "Tous les terains vendus pour construire".
         *
         * Les joueurs doivent attendre que tous les terrains soient vendues pour commencer à construire.
         */
        bool m_tousTerrainsVendusPourConstruire;
        
        /**
         * Option "Toutes les propriétés vendues pour construire".
         *
         * Les joueurs doivent attendre que toutes les propriétés (terrains, compagnies de transport, services) soient vendues pour commencer à construire.
         */
        bool m_toutesProprietesVenduesPourConstruire;
        
        /**
         * Option "Possession du regroupement pour construire".
         *
         * Les joueurs doivent posséder tous les terrains d'un regroupement pour pouvoir construire sur ces dits terrains.
         */
        bool m_possessionRegroupementPourConstruire;
        
        /**
         * Option "Jouer présent pour construire".
         *
         * Le joueur doit être présent sur le terrains pour le construire.
         */
        bool m_joueurPresentPourConstruire;
        
        
        
        // Autres options
        /**
         * Option "Nombre maximum de tour".
         *
         * Chaque joueur doit passer autant de fois indiqué par la case Départ afin de terminer la partie (0 pour infini). Le joueur le plus riche (argent, possessions, constructions) gagne la partie.
         */
        quint8 m_nombreTourMax;
        
        /**
         * Option "Partie rapide"
         *
         * cf. Règle partie rapide avec le 3ème dé spécial.
         */
        bool m_partieRapide;
        
        /**
         * Option "Partie « Ruine la banque »".
         *
         * L'objectif de la partie est de ruinner la banque. Les joueurs peuvent jouer tous ensemble contre la banque. Ils peuvent aussi se répartir en équipe ou joueur individuellement. Dans le cas, l'équipe ou le joeur qui ruine la banque gagne la partie.
         *
         * @note Si cette option est activé :
         * @li l'option "Banque peut faire faillite" est activée aussi (MAOptionsGlobales::m_optionBanquePeutFaireFaillite) ;
         * @li l'option "Montant maximum de la banque" doit être spécifiée (MAOptionsGlobales::m_optionMontantMaxBanque).
         */
        bool m_partieRuineLaBanque;
        
        
        
    public:
        /**
         * Construit une règle par défaut avec toutes les valeurs par défaut (selon la règle officielle du Monopoly©).
         */
        Regle();
        
        
        
        qint8 nombreProprietesAuDepart() const;
        void setNombreProprietesAuDepart(qint8 nombre,
                                         const Plateau* const plateau);
        
        
        
        bool enchereDepart() const;
        void setEnchereDepart(const bool actif);
        
        
        
        bool premierTourSansAchat() const;
        void setPremierTourSansAchat(const bool actif);
        
        
        
        quint16 argentDepart() const;
        void setArgentDepart(const quint16 montant);
        
        
        
        bool salaireDouble() const;
        void setSalaireDouble(const bool actif);
        
        
        
        bool taxeInParcGratuit() const;
        void setTaxeInParcGratuit(const bool actif);
        
        
        
        bool amendeCarteInParcGratuit() const;
        void setAmendeCarteInParcGratuit(const bool actif);
        
        
        
        bool cagnotteFixe() const;
        void setCagnotteFixe(const bool actif);
        
        
        
        quint16 montantFixe() const;
        void setMontantFixe(const quint16 montant);
        
        
        
        quint8 nombreMaxTourEnPrison() const;
        void setNombreMaxTourEnPrison(const quint8 nombre);
        
        
        
        bool joueurPeutPercevoirLoyerEnPrison() const;
        void setJoueurPeutPercevoirLoyerEnPrison(const bool actif);
        
        
        
        bool joueurPeutParticiperEncheresEnPrison() const;
        void setJoueurPeutParticiperEncheresEnPrison(const bool actif);
        
        
        
        bool joueurPeutEchangerEnPrison() const;
        void setJoueurPeutEchangerEnPrison(const bool actif);
        
        
        
        bool joueurPeutConstruireEnPrison() const;
        void setJoueurPeutConstruireEnPrison(const bool actif);
        
        
        
        bool banquePeutFaireFaillite() const;
        void setBanquePeutFaireFaillite(const bool actif);
        
        
        
        quint32 montantMaxBanque() const;
        void setMontantMaxBanque(const quint32 montant);
        
        
        
        quint8 nombreTotalMaison() const;
        void setNombreTotalMaison(const quint8 nombre);
        
        
        
        quint8 nombreTotalHotel() const;
        void setNombreTotalHotel(const quint8 nombre);
        
        
        
        bool enchereSurBiensRecperes() const;
        void setEnchereSurBiensRecuperes(const bool actif);
        
        
        
        bool enchereSurNonAchete() const;
        void setEnchereSurNonAchete(const bool actif);
        
        
        
        bool constructionHomogene() const;
        void setConstructionHomogene(const bool actif);
        
        
        
        bool tousTerrainsVendusPourConstruire() const;
        void setTousTerrainsVendusPourConstruire(const bool actif);
        
        
        
        bool toutesProprietesVenduesPourConstruire() const;
        void setToutesProprietesVenduesPourConstruire(const bool actif);
        
        
        
        bool possessionRegroupementPourConstruire() const;
        void setPossessionRegroupementPourConstruire(const bool actif);
        
        
        
        bool joueurPresentPourConstruire() const;
        void setJoueurPresentPourConstruire(const bool actif);
        
        
        
        quint8 nombreTourMax() const;
        void setNombreTourMax(const quint8 nombre);
        
        
        
        bool partieNormale() const;
        void setPartieNormale(const bool actif);
        
        
        
        bool partieRapide() const;
        void setPartieRapide(const bool actif);
        
        
        
        bool partieRuineLaBanque() const;
        void setPartieRuineLaBanque(const bool actif);
        
        
        
        void saveInFile(QDataStream& ecriture) const;
        
        
        
        void loadFromFile(QDataStream& lecture,
                          const quint16 version);
};

#endif // REGLE_HPP
