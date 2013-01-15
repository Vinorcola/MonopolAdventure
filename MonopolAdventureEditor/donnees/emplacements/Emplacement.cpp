#include "Emplacement.hpp"

#include "dialogEdition/EditionEmplacement.hpp"





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





void Emplacement::editTitre(const QString& titre)
{
    // Change le titre
    if (titre.isNull())
    {
        m_titre = "";
    }
    else
    {
        m_titre = titre;
    }
    
    // Mise à jour de l'affichage du titre
    if (m_elementGraphique)
    {
        m_elementGraphique->updateTitre(m_titre);
    }
}





const QString& Emplacement::getSousTitre() const
{
    return m_sousTitre;
}





void Emplacement::editSousTitre(const QString& sousTitre)
{
    // Change le sous-titre
    if (sousTitre.isNull())
    {
        m_sousTitre = "";
    }
    else
    {
        m_sousTitre = sousTitre;
    }
    
    // Mise à jour de l'affichage du sous-titre
    if (m_elementGraphique)
    {
        m_elementGraphique->updateSousTitre(m_sousTitre);
    }
}





const QString& Emplacement::getDescription() const
{
    return m_description;
}





void Emplacement::editDescription(const QString& description)
{
    // Change la description
    if (description.isNull())
    {
        m_description = "";
    }
    else
    {
        m_description = description;
    }
    
    // Mise à jour de l'affichage de la description
    if (m_elementGraphique)
    {
        m_elementGraphique->updateDescription(m_description);
    }
}





const QPixmap& Emplacement::getImage() const
{
    return m_image;
}





void Emplacement::editImage(const QPixmap& image)
{
    // Change l'image
    m_image = image;
    
    // Mise à jour de l'affichage de l'image
    if (m_elementGraphique)
    {
        m_elementGraphique->updateImage(m_image);
    }
}





void Emplacement::setEmplacementEnCoin()
{
    /* Pour mettre à jour l'affichage graphique, on doit regarder si le type d'emplacement à changer. Si oui, on doit
     * reconstruire tous l'élément graphique.
     */
    if (m_elementGraphique)
    {
        if (!m_enCoin)
        {
            // Reconstruction de l'élément graphique.
            delete m_elementGraphique;
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
                                                          true,
                                                          true);
            m_scene->addItem(m_elementGraphique);
        }
    }
    
    // Modification de l'information.
    m_enCoin = true;
}





void Emplacement::setEmplacementNormal()
{
    /* Voir explication dans Emplacement::setEmplacementEnCoin().
     */
    if (m_elementGraphique)
    {
        if (m_enCoin)
        {
            delete m_elementGraphique;
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
                                                          false,
                                                          true);
            m_scene->addItem(m_elementGraphique);
        }
    }
    
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





void Emplacement::saveInFile(QDataStream& ecriture) const
{
    ecriture << m_titre
             << m_sousTitre
             << m_description
             << m_image;
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

