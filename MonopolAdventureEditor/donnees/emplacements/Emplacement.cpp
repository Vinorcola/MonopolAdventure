#include "Emplacement.hpp"





Emplacement::Emplacement(Type::Emplacement type) :
    m_type(type),
    m_titre(""),
    m_sousTitre(""),
    m_description(""),
    m_image()
{
    
}





Emplacement::~Emplacement()
{
    
}





Type::Emplacement Emplacement::getType() const
{
    return m_type;
}





const QString& Emplacement::getTitre() const
{
    return m_titre;
}





void Emplacement::editTitre(const QString& titre)
{
    if (titre.isNull())
    {
        m_titre = "";
    }
    else
    {
        m_titre = titre;
    }
}





const QString& Emplacement::getSousTitre() const
{
    return m_sousTitre;
}





void Emplacement::editSousTitre(const QString& sousTitre)
{
    if (sousTitre.isNull())
    {
        m_sousTitre = "";
    }
    else
    {
        m_sousTitre = sousTitre;
    }
}





const QString& Emplacement::getDescription() const
{
    return m_description;
}





void Emplacement::editDescription(const QString& description)
{
    if (description.isNull())
    {
        m_description = "";
    }
    else
    {
        m_description = description;
    }
}





const QPixmap& Emplacement::getImage() const
{
    return m_image;
}





void Emplacement::editImage(const QPixmap& image)
{
    m_image = image;
}

