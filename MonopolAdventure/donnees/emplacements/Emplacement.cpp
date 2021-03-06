#include "Emplacement.hpp"





Emplacement::Emplacement(Type::Emplacement type,
                         const GraphismeEmplacementInfos& graphismeInfos) :
    m_type(type),
    m_titre(""),
    m_sousTitre(""),
    m_description(""),
    m_image(),
    m_graphismeInfos(graphismeInfos),
    m_scene(0),
    m_elementGraphique(0),
    m_coordonnees(),
    m_rotation(0),
    m_enCoin(false)
{
    
}





Emplacement::~Emplacement()
{
    if (m_elementGraphique)
    {
        delete m_elementGraphique;
    }
}





Type::Emplacement Emplacement::getType() const
{
    return m_type;
}





const QString& Emplacement::getTitre() const
{
    return m_titre;
}





const QString& Emplacement::getSousTitre() const
{
    return m_sousTitre;
}





const QString& Emplacement::getDescription() const
{
    return m_description;
}





const QPixmap& Emplacement::getImage() const
{
    return m_image;
}





void Emplacement::setEmplacementEnCoin()
{
    m_enCoin = true;
}





void Emplacement::setEmplacementNormal()
{
    m_enCoin = false;
}





const GraphismeEmplacementInfos& Emplacement::getGraphismeInfos() const
{
    return m_graphismeInfos;
}





void Emplacement::setupElementGraphique(const QPoint& position,
                                        const int rotation,
                                        QGraphicsScene* scene)
{
    m_coordonnees = position;
    m_rotation = rotation;
    
    if (scene)
    {
        m_scene = scene;
    }
}





GraphismeEmplacement* Emplacement::dessiner()
{
    if (m_scene)
    {
        if (m_elementGraphique)
        {
            delete m_elementGraphique;
        }
        
        m_elementGraphique = new GraphismeEmplacement(m_graphismeInfos,
                                                      this,
                                                      m_coordonnees,
                                                      m_rotation,
                                                      m_titre,
                                                      m_sousTitre,
                                                      m_description,
                                                      helper_getPrix(),
                                                      m_image,
                                                      helper_getCouleurRegroupement(),
                                                      m_enCoin,
                                                      true);
        m_scene->addItem(m_elementGraphique);
    }
    
    return m_elementGraphique;
}





void Emplacement::loadFromFile(QDataStream& lecture,
                               const quint16 version)
{
    switch (version)
    {
        default:
            lecture >> m_titre
                    >> m_sousTitre
                    >> m_description
                    >> m_image;
    }
}





QString Emplacement::helper_getPrix() const
{
    return QString();
}





QColor Emplacement::helper_getCouleurRegroupement() const
{
    return QColor();
}

