#include "Regle.hpp"





Regle::Regle() :
    m_nombreMaisonsPourHotel(4),
    m_nombreMaxHotel(1)
{
    
}





quint8 Regle::getNombreMaisonsPourHotel() const
{
    return m_nombreMaisonsPourHotel;
}





void Regle::editNombreMaisonsPourHotel(const quint8 nombre)
{
    m_nombreMaisonsPourHotel = nombre;
}





quint8 Regle::getNombreMaxHotel() const
{
    return m_nombreMaxHotel;
}





void Regle::editNombreMaxHotel(const quint8 nombre)
{
    m_nombreMaxHotel = nombre;
}

