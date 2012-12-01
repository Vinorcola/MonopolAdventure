#ifndef REGLE_HPP
#define REGLE_HPP

#include <QtGlobal>





/**
 * @class Regle Regle.hpp donnees/Regle.hpp
 * Cette classe contient les principales règle de jeu.
 * 
 * Cette classe contient toutes les règles de jeu paramétrable par les joueurs. Elle appartient à la classe Plateau.
 */
class Regle
{
    private:
        quint8 m_nombreMaisonsPourHotel;
        quint8 m_nombreMaxHotel;
        
        
        
    public:
        /**
         * Construit une règle par défaut.
         */
        Regle();
        
        
        
        /**
         * Renseigne le nombre de maisons nécessaires pour construire un hôtel.
         * @return Nombre de maisons nécessaires pour construire un hôtel.
         */
        quint8 getNombreMaisonsPourHotel() const;
        
        
        
        /**
         * Change le nombre de maisons nécessaire pour construire un hôtel.
         * @param nombre Nouveau nombre de maisons.
         */
        void editNombreMaisonsPourHotel(const quint8 nombre);
        
        
        
        /**
         * Renseigne le nombre maximum d'hôtels constructibles sur un terrain.
         * @return Nombre maximum d'hôtels constructibles sur un terrain.
         */
        quint8 getNombreMaxHotel() const;
        
        
        
        /**
         * Change le nombre maximum d'hôtels constructibles sur un terrain.
         * @param nombre Nouveau nombre d'hôtel.
         */
        void editNombreMaxHotel(const quint8 nombre);
};

#endif // REGLE_HPP
