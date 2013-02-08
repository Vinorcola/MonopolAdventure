#ifndef DES_HPP
#define DES_HPP

#include <QDateTime>
#include <QPixmap>





/**
 * @class Des Des.hpp jeu/Des.hpp
 * Cette classe représente une paire de dés que les joueurs peuvent lancer chacun leur tour.
 * 
 * Elle peut aussi contenir un dé spécial, aussi appelé « dé rapide ».
 */
class Des
{
    private:
        /**
         * Énumération pour le dé rapide.
         */
        enum DeRapide
        {
            Un = 1,
            Deux = 2,
            Trois = 3,
            Bus = 4,
            MMonopoly1 = 5,
            MMonopoly2 = 6
        };
        
        
        
        static bool m_init;///< Indique si le générateur de nombre aléatoire a été initialisé au cours du programme.
        
        const QPixmap face1;///< Image de la face 1.
        const QPixmap face2;///< Image de la face 2.
        const QPixmap face3;///< Image de la face 3.
        const QPixmap face4;///< Image de la face 4.
        const QPixmap face5;///< Image de la face 5.
        const QPixmap face6;///< Image de la face 6.
        const QPixmap faceMonopoly;///< Image de la face Monsieur Monopoly.
        const QPixmap faceBus;///< Image de la face bus.
        bool m_deRapideActif;///< Indique si le dé rapide est actif.
        quint8 m_result1;///< Résultat obtenu avec le premier dé.
        quint8 m_result2;///< Résultat obtenu avec le deuxième dé.
        quint8 m_resultRapide;///< Résultat obtenu avec le dé rapide.
        
        
        
    public:
        /**
         * Créé une nouvelle paire de dés.
         * @param activeDeRapide Indique si le dé rapide doit être activé ou non.
         */
        Des(const bool activeDeRapide = false);
        
        
        
        /**
         * Lance les dés.
         * @return Résultat obtenue aux dés.
         */
        int lancer(const bool avecDeRapide = true);
        
        
        
        /**
         * Retourne le résultat du dernier lancé de dés.
         * @return Résultat du dernier lancé de dés.
         */
        int getResultat();
        
        
        
        /**
         * Retourne le résultat du premier dé lors du dernier lancé.
         * @return Résultat du premier dé lors du dernier lancé.
         */
        int getResultatDe1();
        
        
        
        /**
         * Retourne le résultat du deuxième dé lors du dernier lancé.
         * @return Résultat du deuxième dé lors du dernier lancé.
         */
        int getResultatDe2();
        
        
        
        /**
         * Indique si le dernier lancé est un double.
         * @return @b @c true si le dernier lancé est un double, @b @c false sinon.
         */
        bool isDouble();
        
        
        
        /**
         * Indique si le dernier lancé est un triple (avec le dé rapide).
         * @return @b @c true si le dernier lancé est un triple, @b @c false sinon.
         */
        bool isTriple();
        
        
        
        /**
         * Indique si le dé rapide est tombé sur Monsieur Monopoly.
         * @return @b @c true si le dé rapide est tombé sur Monsieur Monopoly, @b @c false sinon.
         */
        bool isMonsieurMonopoly();
        
        
        
        /**
         * Indique si le dé rapide est tombé sur le bus.
         * @return @b @c true si le dé rapide est tombé sur le bus, @b @c false sinon.
         */
        bool isBus();
};

#endif // DES_HPP
