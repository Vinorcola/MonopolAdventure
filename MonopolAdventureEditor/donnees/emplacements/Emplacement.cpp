#include "Emplacement.hpp"





Emplacement::Emplacement(Type::Emplacement type,
                         const GraphismeEmplacementInfos& graphismeInfos) :
    m_type(type),
    m_titre(""),
    m_sousTitre(""),
    m_description(""),
    m_image(),
    m_graphismeInfos(graphismeInfos),
    m_enCoin(false),
    m_scenes()
{
    
}





Emplacement::~Emplacement()
{
    foreach (ElementGraphique element, m_scenes)
    {
        if (element.elementGraphique)
        {
            delete element.elementGraphique;
        }
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





void Emplacement::setEmplacementEnCoin()
{
    m_enCoin = true;
}





void Emplacement::setEmplacementNormal()
{
    m_enCoin = false;
}





void Emplacement::registerScene(QGraphicsScene* scene,
                                const QPoint& coordonnees,
                                const int rotation)
{
    if (m_scenes.contains(scene))
    {
        m_scenes[scene].coordonnees = coordonnees;
        m_scenes[scene].rotation = rotation;
    }
    else
    {
        m_scenes[scene].elementGraphique = 0;
        m_scenes[scene].coordonnees = coordonnees;
        m_scenes[scene].rotation = rotation;
    }
}





void Emplacement::dessiner(QGraphicsScene* scene)
{
    if (scene)
    {
        if (m_scenes.contains(scene))
        {
            if (!m_scenes[scene].elementGraphique)
            {
                m_scenes[scene].elementGraphique = new GraphismeEmplacement(m_graphismeInfos,
                                                                            this,
                                                                            m_scenes[scene].coordonnees,
                                                                            m_scenes[scene].rotation,
                                                                            m_titre,
                                                                            m_sousTitre,
                                                                            m_description,
                                                                            helper_getPrix(),
                                                                            m_image,
                                                                            helper_getCouleurRegroupement(),
                                                                            m_enCoin);
                scene->addItem(m_scenes[scene].elementGraphique);
            }
        }
    }
    else
    {
        foreach (ElementGraphique element, m_scenes)
        {
            element.elementGraphique->updateAffichage();
            scene->addItem(element.elementGraphique);
        }
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

