#ifndef ACTIONINFOS_HPP
#define ACTIONINFOS_HPP

class PileCartes;
class Plateau;
#include "donnees/emplacements/Emplacement.hpp"





/**
 * @class Action Action.hpp donnees/cartes/Action.hpp
 * Cette classe représente une action à éxécuter par un joueur.
 * 
 * Une action peut indiquer au joueur qu'il doit payer quelquechose à quelqu'un, qu'il doit se déplacer quelque part, qu'il doit piocher une autre carte, etc.
 */
class Action
{
    private:
        /* Deplacement
         */
        bool m_deplacement;///< Indique si le joueur doit se déplacer.
        bool m_joueurAvance;///< Indique si le joueur doit se déplacer en avançant ou en reculant.
        quint8 m_deplacementRelatif;///< Indique le nombre d'emplacements à se déplacer depuis l'emplacement actuel du joueur.
        const Emplacement* m_deplacementEmplacement;///< Emplacement sur lequel le joueur doit se déplacer.
        Type::Emplacement m_deplacementJusquauProchain;///< Indique si le joueur doit ce déplacer jusqu'au prochain emplacements qui possède ce flag.
        quint8 m_coefficientLoyer;///< Si le joueur arrive sur une propriete appartenant à un autre joueur, son loyer est multiplié par ce coefficient.
        bool m_relanceDes;///< Indique si le joueur doit relancer les dés s'il se déplace sur un service appartenant à un autre joueur afin de calculer le nouveau loyer.
        
        
        /* Transaction
         */
        bool m_transaction;///< Indique si une transaction a lieu.
        bool m_gainArgent;///< Indique si le joueur gagne ou perd de l'argent.
        /**
         * Indique si l'échange se fait entre le joueur actuel et tous les autres joueurs à la fois.
         * 
         * Il se fait donc autant de transaction qu'il y a de concurrents.
         * 
         * @note Si @a m_enversTousLesJoueurs est à @b @c false, la transaction se fait entre le joueur et la banque.
         */
        bool m_enversTousLesJoueurs;
        quint16 m_montant;///< Indique le montant de l'échange ou bien le montant de l'amende dans le cas d'une carte "Paye une amende ou pioche une autre carte".
        
        
        /* Réparation
         */
        bool m_reparation;///< Indique si le action doit faire des réparations dans ses maisons.
        quint16 m_montantParMaison;///< Indique le montant à payer par maison à réparer.
        quint16 m_montantParHotel;///< Indique le montant à payer par hôtel à réparer.
        quint16 m_montantParGratteCiel;///< Indique le montant à payer par gratte-ciel à réparer.
        
        
        /* Paye ou pioche
         */
        bool m_payeOuPioche;///< Indique si le joueur peut avoir le choix entre payer une ammende ou piocher une nouvelle carte.
        const PileCartes* m_pileCartes;///< Pile de cartes à piocher.
        
        
        /* Pioche
         */
        bool m_pioche;///< Indique si le joueur doit piocher une nouvelle carte depuis la pile de cartes @c m_pileCartes.
        
        
        /* Libéré de prison
         */
        bool m_libereDePrison;///< Indique si le joueur peut être libéré de prison.
        
        
        
    public:
        /**
         * Construit une action par défaut : le joueur doit payer 100.
         */
        Action();
        
        
        
        /**
         * Retourne une description détaillée de l'action.
         * @param devise Devise utilisée sur le plateau.
         * @return Description détaillée de l'action.
         */
        QString getDescription(const QString& devise) const;
        
        
        
        /**
         * Indique si l'action est un déplacement.
         * @return @b @c true si l'action est un déplacement.
         */
        bool isDeplacement() const;
        
        
        
        /**
         * Indique si le joueur se déplace en avançant.
         * @return @b @c true si le joueur se déplace en avançant.
         */
        bool joueurAvance() const;
        
        
        
        /**
         * Indique si le joueur se déplace en reculant.
         * @return @b @c true si le joueur se déplace en reculant, @b @c false dans le cas sontraire.
         */
        bool joueurRecule() const;
        
        
        
        /**
         * Indique si le déplacement est un déplacement absolu.
         * @return @b @c true si le déplacement est absolu, @b @c false le cas contraire.
         */
        bool isDeplacementAbsolu() const;
        
        
        
        /**
         * Indique si le déplacement est un déplacement relatif.
         * @return @b @c true si le déplacement est relatif.
         */
        bool isDeplacementRelatif() const;
        
        
        
        /**
         * Indique si le déplacement est un déplacement jusqu'au prochain emplacement d'un certain type.
         * @return @b @c true si le déplacement est jusqu'au prochain emplacement d'un certain type.
         */
        bool isDeplacementJusquauProchain() const;
        
        
        
        /**
         * Retourne le nombre d'emplacements à se déplacer.
         * @return Nombre d'emplacements à se déplacer.
         */
        quint8 getNombreEmplacements() const;
        
        
        
        /**
         * Retourne l'emplacement vers lequel se déplacer.
         * @return Emplacement vers lequel se déplacer.
         */
        const Emplacement* getEmplacement() const;
        
        
        
        /**
         * Retourne jusqu'a quel type de terrain se déplacer.
         * @return Type de terrain jusqu'auquel se déplacer.
         */
        Type::Emplacement deplacementJusquauProchain() const;
        
        
        
        /**
         * Renseigne le coefficient à appliquer sur les loyers si le joueur se déplace sur une propriété appartenant déjà à un joueur.
         * @return Coefficient à appliquer sur les loyers.
         */
        quint8 getCoefficientLoyer() const;
        
        
        
        /**
         * Indique si le joueur doit relancer les dés lorsqu'il se déplace sur un service appartenant à un autre joueur afin de calculer le loyer.
         * @return @b @c true si le joueur doit relancer les dés.
         */
        bool relanceDesPourLoyerService() const;
        
        
        
        /**
         * Change l'action en déplacement absolu.
         * @param avance Indique si le joueur avance.
         * @param emplacement Emplacement vers lequel se déplacer.
         * @param coefficientLoyer Si le joueur arrive sur une propriete appartenant à un autre joueur, son loyer est multiplié par ce coefficient.
         * @param relanceDes Indique si le joueur doit relancer les dés s'il se déplace sur un service appartenant à un autre joueur afin de calculer le nouveau loyer.
         */
        void setDeplacement(const bool avance,
                            const Emplacement* emplacement,
                            const quint8 coefficientLoyer = 1,
                            const bool relanceDes = false);
        
        
        
        /**
         * Change l'action en déplacement relatif.
         * @param avance Indique si le joueur avance.
         * @param nombreEmplacements Nombre d'emplacements à se déplacer.
         * @param coefficientLoyer Si le joueur arrive sur une propriete appartenant à un autre joueur, son loyer est multiplié par ce coefficient.
         * @param relanceDes Indique si le joueur doit relancer les dés s'il se déplace sur un service appartenant à un autre joueur afin de calculer le nouveau loyer.
         */
        void setDeplacement(const bool avance,
                            const quint8 nombreEmplacements,
                            const quint8 coefficientLoyer = 1,
                            const bool relanceDes = false);
        
        
        
        /**
         * Change l'action en déplacement jusqu'au prochain emplacement d'un certain type.
         * @param avance Indique si le joueur avance.
         * @param typeEmplacement Type d'emplacement vers lequel se déplacer.
         * @param coefficientLoyer Si le joueur arrive sur une propriete appartenant à un autre joueur, son loyer est multiplié par ce coefficient.
         * @param relanceDes Indique si le joueur doit relancer les dés s'il se déplace sur un service appartenant à un autre joueur afin de calculer le nouveau loyer.
         */
        void setDeplacementJusquauProchain(const bool avance,
                                           const Type::Emplacement typeEmplacement,
                                           const quint8 coefficientLoyer = 1,
                                           const bool relanceDes = false);
        
        
        
        /**
         * Indique si l'action est une transaction.
         * @return @b @c true si l'action est une transaction.
         */
        bool isTransaction() const;
        
        
        
        /**
         * Indique si le joueur acteur gagne de l'argent lors de la transaction.
         * @return @b @c true si le joueur acteur gagne de l'argent.
         */
        bool joueurGagneArgent() const;
        
        
        
        /**
         * Indique si le joueur acteur perd de l'argent lors de la transaction.
         * @return @b @c true si le joueur acteur perd de l'argent.
         */
        bool joueurPerdArgent() const;
        
        
        
        /**
         * Indique si la transaction se déroule entre le joueur acteur et la banque.
         * @return @b @c true si la transaction se déroule entre le joueur acteur et la banque.
         */
        bool isTransactionAvecBanque() const;
        
        
        
        /**
         * Indique si la transaction se déroule entre le joueur acteur et tous les autres joueurs.
         * @return @b @c true si la transaction se déroule entre le joueur acteur et tous les autres joueurs.
         */
        bool isTransactionAvecTousLesJoueurs() const;
        
        
        
        /**
         * Retourne le montant de la transaction.
         * @return Montant de la transaction.
         */
        quint16 getMontantTransaction() const;
        
        
        
        /**
         * Change l'action en transaction avec la banque.
         * @param gain Indique si le joueur acteur gagne l'argent de la transaction.
         * @param montant Montant de la transaction.
         */
        void setTransactionAvecBanque(const bool gain,
                                      const quint16 montant);
        
        
        
        /**
         * Change l'action en transaction avec tous les autres joueurs.
         * @param gain Indique si le joueur acteur gagne l'argent de la transaction.
         * @param montant Montant de la transaction.
         */
        void setTransactionAvecTousLesJoueurs(const bool gain,
                                              const quint16 montant);
        
        
        
        /**
         * Indique si l'action est une réparation des constructions.
         * @return @b @c true si l'action est une réparation des constructions.
         */
        bool isReparationConstructions() const;
        
        
        
        /**
         * Retourne le montant des réparations pour une maison.
         * @return Montant des réparations pour une maison.
         */
        quint16 getMontantParMaison() const;
        
        
        
        /**
         * Retourne le montant des réparations pour un hôtel.
         * @return Montant des réparations pour un hôtel.
         */
        quint16 getMontantParHotel() const;
        
        
        
        /**
         * Retourne le montant des réparations pour un gratte-ciel.
         * @return Montant des réparations pour un gratte-ciel.
         */
        quint16 getMontantParGratteCiel() const;
        
        
        
        /**
         * Change l'action en réparation des constructions.
         * @param montantParMaison Montant des réparations pour une maison.
         * @param montantParHotel Montant des réparations pour un hôtel.
         * @param montantParGratteCiel Montant des réparations pour un gratte-ciel.
         */
        void setReparationConstructions(const quint16 montantParMaison,
                                        const quint16 montantParHotel,
                                        const quint16 montantParGratteCiel = 0);
        
        
        
        /**
         * Indique si l'action est de type "Paye ou Pioche".
         *
         * L'action "Paye ou Pioche" laisse le choix au joueur entre payer une amende ou piocher une nouvelle carte.
         *
         * @return @b @c true si l'action est de type "Paye ou Pioche".
         */
        bool isPayeOuPioche() const;
        
        
        
        /**
         * Indique si l'action consiste à piocher une carte.
         * @return @b @c true si l'action consiste à piocher une carte.
         */
        bool isPioche() const;
        
        
        
        /**
         * Retourne la pile de cartes dans laquelle piocher la carte.
         * @return Pile de cartes dans laquelle piocher la carte.
         */
        const PileCartes* getPileCartes() const;
        
        
        
        /**
         * Retourne le montant de l'amende à payer.
         * @return Montant de l'amende à payer.
         */
        quint16 getAmende() const;
        
        
        
        /**
         * Change l'action en action de type "Paye ou Pioche".
         * @param amende Montant de l'amende.
         * @param pileCartes Pile de cartes dans laquelle piocher une carte.
         */
        void setPayeOuPioche(const quint16 amende,
                             const PileCartes* pileCartes);
        
        
        
        /**
         * Change l'action pour une action consistant à piocher une carte.
         * @param pileCartes Pile de cartes dans laquelle piocher une carte.
         */
        void setPioche(const PileCartes* pileCartes);
        
        
        
        /**
         * Indique si l'action est de type "Libéré de prison".
         * @return @b @c true si l'action est de type "Libéré de prison".
         */
        bool isLibereDePrison() const;
        
        
        
        /**
         * Change l'action en action de type "Libéré de prison".
         */
        void setLibereDePrison();
        
        
        
        /**
         * Change l'emplacement associé à l'action (utilisé dans le changement de type des emplacement).
         * @param emplacement Nouvel emplacement.
         */
        void setEmplacement(const Emplacement* emplacement);
        
        
        
        /**
         * Change la pile de cartes associée à l'action (utilisé dans l'édition des listes de piles de cartes).
         * @param pileCartes Nouvelle pile de cartes.
         */
        void setPileCartes(const PileCartes* pileCartes);
        
        
        
        /**
         * Charge les informations concernant l'action depuis le flux de données.
         * @param lecture Flux de données depuis le fichier à lire
         * @param version Version du fichier.
         * @param plateau Plateau de jeu.
         */
        void loadFromFile(QDataStream& lecture,
                          const quint16 version,
                          const Plateau* plateau);
};

#endif // ACTIONINFOS_HPP
