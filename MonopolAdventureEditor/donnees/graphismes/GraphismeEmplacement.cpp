#include "GraphismeEmplacement.hpp"
#include "donnees/emplacements/Emplacement.hpp"





GraphismeEmplacement::GraphismeEmplacement(const GraphismeEmplacementInfos& infosGraphiques,
                                           Emplacement* const emplacement,
                                           const QPoint& position,
                                           const int rotation,
                                           const QString& titre,
                                           const QString& sousTitre,
                                           const QString& description,
                                           const QString& prix,
                                           const QPixmap& image,
                                           const QColor& couleurRegroupement,
                                           const bool emplacementEnCoin) :
    QGraphicsRectItem(QRectF(QPointF(0, 0), (emplacementEnCoin ? infosGraphiques.getTailleEnCoin() : infosGraphiques.getTailleNormale()))),
    m_infosGraphiques(infosGraphiques),
    m_emplacement(emplacement),
    m_position(position),
    m_rotation(rotation),
    m_titre(titre),
    m_sousTitre(sousTitre),
    m_description(description),
    m_prix(prix),
    m_image(image),
    m_couleurRegroupement(couleurRegroupement),
    m_emplacementEnCoin(emplacementEnCoin),
    m_graphCouleur(0),
    m_graphCouleurEnCoin(0),
    m_graphTitre(0),
    m_graphSousTitre(0),
    m_graphDescription(0),
    m_graphPrix(0),
    m_graphImage(0)
{
    /* Correction de la taille pour la prison
     */
    if (m_emplacement->getType() == Type::Prison)
    {
        setRect(0, 0, m_infosGraphiques.getTailleNormale().height() - m_infosGraphiques.getHauteurRectangleCouleur(), m_infosGraphiques.getTailleNormale().height() - m_infosGraphiques.getHauteurRectangleCouleur());
    }
    
    
    
    /* Dessin des sous-éléments.
     */
    updateAffichage();
    
    
    
    /* Configuration de l'élément.
     */
    setPen(m_infosGraphiques.getCrayonBordure());
    setBrush(QBrush(m_infosGraphiques.getCouleurFond()));
    setPos(position);
    setRotation(rotation);
}





void GraphismeEmplacement::updateCouleurRegroupement(const QColor& couleur)
{
    if (couleur != m_couleurRegroupement)
    {
        m_couleurRegroupement = couleur;
        setupCouleurRegroupement();
    }
}





void GraphismeEmplacement::updateTitre(const QString& titre)
{
    if (titre != m_titre)
    {
        m_titre = titre;
        
        if (m_graphTitre && m_titre.isEmpty())
        {
            /* Suppression de m_graphTitre.
             */
            delete m_graphTitre;
            m_graphTitre = 0;
            
            
            /* Repositionnement des éléments graphiques.
             */
            positionneSousTitre();
            positionneImage();
        }
        else if (!m_graphTitre && !m_titre.isEmpty())
        {
            /* Création de m_graphTitre.
             */
            setupTitre();
            
            
            /* Repositionnement des éléments graphiques.
             */
            positionneTitre();
            positionneSousTitre();
            positionneImage();
        }
        else
        /* Note : ici, on ne peut pas avoir (!m_graphTitre && m_titre.isEmpty()) car dans ce cas, au début on aurait
         * eu (titre == m_titre). Il nous reste donc le cas où (m_graphTitre && !m_titre.isEmpty()). Il nous suffit
         * donc de mettre à jour le texte.
         */
        {
            setupTitre();
        }
    }
}





void GraphismeEmplacement::updateSousTitre(const QString& sousTitre)
{
    if (sousTitre != m_sousTitre)
    {
        m_sousTitre = sousTitre;
        
        if (m_graphSousTitre && m_sousTitre.isEmpty())
        {
            /* Suppression de m_graphSousTitre.
             */
            delete m_graphSousTitre;
            m_graphSousTitre = 0;
            
            
            /* Repositionnement des éléments graphiques.
             */
            positionneImage();
        }
        else if (!m_graphSousTitre && !m_sousTitre.isEmpty())
        {
            /* Création de m_graphSousTitre.
             */
            setupSousTitre();
            
            
            /* Repositionnement des éléments graphiques.
             */
            positionneSousTitre();
            positionneImage();
        }
        else
        /* Note : ici, on ne peut pas avoir (!m_graphSousTitre && m_sousTitre.isEmpty()) car dans ce cas, au début on
         * aurait eu (sousTitre == m_sousTitre). Il nous reste donc le cas où
         * (m_graphSousTitre && !m_sousTitre.isEmpty()). Il nous suffit donc de mettre à jour le texte.
         */
        {
            setupSousTitre();
        }
    }
}





void GraphismeEmplacement::updateImage(const QPixmap& image)
{
    if (image.toImage() != m_image.toImage())
    {
        m_image = image;
        
        if (m_graphImage && m_image.isNull())
        {
            /* Suppression de m_graphImage.
             */
            delete m_graphImage;
            m_graphImage = 0;
        }
        else if (!m_graphImage && !m_image.isNull())
        {
            /* Création de m_graphImage.
             */
            setupImage();
            
            
            /* Repositionnement des éléments graphiques.
             */
            positionneImage();
        }
        else
        /* Note : ici, on ne peut pas avoir (!m_graphImage && m_image.isNull()) car dans ce cas, au début on aurait
         * eu (image == m_image). Il nous reste donc le cas où (m_graphImage && !m_image.isNull()). Il nous suffit donc
         * de mettre à jour l'image.
         */
        {
            setupImage();
        }
    }
}





void GraphismeEmplacement::updateDescription(const QString& description)
{
    if (description != m_description)
    {
        m_description = description;
        
        if (m_graphDescription && m_description.isEmpty())
        {
            /* Suppression de m_graphDescription.
             */
            delete m_graphDescription;
            m_graphDescription = 0;
            
            
            /* Repositionnement des éléments graphiques.
             */
            positionneImage();
        }
        else if (!m_graphDescription && !m_description.isEmpty())
        {
            /* Création de m_graphDescription.
             */
            setupDescription();
            
            
            /* Repositionnement des éléments graphiques.
             */
            positionneImage();
            positionneDescription();
        }
        else
        /* Note : ici, on ne peut pas avoir (!m_graphDescription && m_description.isEmpty()) car dans ce cas, au début
         * on aurait eu (description == m_description). Il nous reste donc le cas où
         * (m_graphDescription && !m_description.isEmpty()). Il nous suffit donc de mettre à jour le texte.
         */
        {
            setupDescription();
        }
    }
}





void GraphismeEmplacement::updatePrix(const QString& prix)
{
    if (prix != m_prix)
    {
        m_prix = prix;
        
        if (m_graphPrix && m_prix.isEmpty())
        {
            /* Suppression de m_graphPrix.
             */
            delete m_graphPrix;
            m_graphPrix = 0;
            
            
            /* Repositionnement des éléments graphiques.
             */
            positionneImage();
            positionneDescription();
        }
        else if (!m_graphPrix && !m_prix.isEmpty())
        {
            /* Création de m_graphPrix.
             */
            setupPrix();
            
            
            /* Repositionnement des éléments graphiques.
             */
            positionneImage();
            positionneDescription();
            positionnePrix();
        }
        else
        /* Note : ici, on ne peut pas avoir (!m_graphPrix && m_prix.isEmpty()) car dans ce cas, au début on aurait
         * eu (prix == m_prix). Il nous reste donc le cas où (m_graphPrix && !m_prix.isEmpty()). Il nous suffit donc
         * de mettre à jour le texte.
         */
        {
            setupPrix();
        }
    }
}





void GraphismeEmplacement::updateAffichage()
{
    setupCouleurRegroupement();
    setupTitre();
    setupSousTitre();
    setupImage();
    setupDescription();
    setupPrix();
    
    positionneTitre();
    positionneSousTitre();
    positionneImage();
    positionneDescription();
    positionnePrix();
}





void GraphismeEmplacement::setupCouleurRegroupement()
{
    if (m_couleurRegroupement.isValid())
    {
        if (m_emplacement->getType() == Type::Terrain)
        {
            if (m_emplacementEnCoin)
            {
                if (!m_graphCouleurEnCoin)
                {
                    m_graphCouleurEnCoin = new QGraphicsEllipseItem(this);
                }
                
                m_graphCouleurEnCoin->setRect(-m_infosGraphiques.getHauteurRectangleCouleur(),
                                              -m_infosGraphiques.getHauteurRectangleCouleur(),
                                              m_infosGraphiques.getHauteurRectangleCouleur() * 2,
                                              m_infosGraphiques.getHauteurRectangleCouleur() * 2);
                m_graphCouleurEnCoin->setPen(m_infosGraphiques.getCrayonBordure());
                m_graphCouleurEnCoin->setBrush(QBrush(m_couleurRegroupement));
                m_graphCouleurEnCoin->setStartAngle(4320);// 4320 = 270 * 16
                m_graphCouleurEnCoin->setSpanAngle(1440);// 1440 = 90 * 16
            }
            else
            {
                if (!m_graphCouleur)
                {
                    m_graphCouleur = new QGraphicsRectItem(this);
                }
                
                m_graphCouleur->setRect(0, 0, rect().width(), m_infosGraphiques.getHauteurRectangleCouleur());
                m_graphCouleur->setPen(m_infosGraphiques.getCrayonBordure());
                m_graphCouleur->setBrush(QBrush(m_couleurRegroupement));
            }
        }
    }
}





void GraphismeEmplacement::setupTitre()
{
    if (!m_titre.isEmpty())
    {
        if (!m_graphTitre)
        {
            m_graphTitre = new QGraphicsTextItem(this);
            
            if (m_emplacementEnCoin && m_emplacement->getType() != Type::SimpleVisite)
            {
                m_graphTitre->setRotation(315);
            }
        }
        
        helper_setupGraphicsTextItem(m_graphTitre, m_titre, m_infosGraphiques.getFonteTitre());
    }
}





void GraphismeEmplacement::setupSousTitre()
{
    if (!m_sousTitre.isEmpty())
    {
        if (!m_graphSousTitre)
        {
            m_graphSousTitre = new QGraphicsTextItem(this);
            
            if (m_emplacementEnCoin)
            {
                if (m_emplacement->getType() == Type::SimpleVisite)
                {
                    m_graphSousTitre->setRotation(270);
                }
                else
                {
                    m_graphSousTitre->setRotation(315);
                }
            }
        }
        
        if (m_emplacement->getType() == Type::SimpleVisite)
        {
            helper_setupGraphicsTextItem(m_graphSousTitre, m_sousTitre, m_infosGraphiques.getFonteTitre());
        }
        else
        {
            helper_setupGraphicsTextItem(m_graphSousTitre, m_sousTitre, m_infosGraphiques.getFonteSousTitre());
        }
    }
}





void GraphismeEmplacement::setupImage()
{
    if (!m_image.isNull())
    {
        if (!m_graphImage)
        {
            m_graphImage = new QGraphicsPixmapItem(this);
        }
        
        m_graphImage->setPixmap(m_image);
    }
}





void GraphismeEmplacement::setupDescription()
{
    if (!m_description.isEmpty())
    {
        if (m_emplacement->getType() != Type::SimpleVisite)
        {
            if (!m_graphDescription)
            {
                m_graphDescription = new QGraphicsTextItem(this);
                
                if (m_emplacementEnCoin)
                {
                    m_graphDescription->setRotation(315);
                }
            }
            
            helper_setupGraphicsTextItem(m_graphDescription, m_description, m_infosGraphiques.getFonteDescription());
        }
    }
}





void GraphismeEmplacement::setupPrix()
{
    if (!m_prix.isEmpty())
    {
        if (m_emplacement->getType() != Type::SimpleVisite)
        {
            if (!m_graphPrix)
            {
                m_graphPrix = new QGraphicsTextItem(this);
                
                if (m_emplacementEnCoin)
                {
                    m_graphPrix->setRotation(315);
                }
            }
            
            helper_setupGraphicsTextItem(m_graphPrix, m_prix, m_infosGraphiques.getFontePrix());
        }
    }
}





void GraphismeEmplacement::positionneTitre()
{
    if (m_graphTitre)
    {
        if (m_emplacementEnCoin)
        {
            if (m_emplacement->getType() == Type::SimpleVisite)
            {
                int x((rect().width() - m_graphTitre->boundingRect().width()) / 2);
                int y(rect().height() - m_infosGraphiques.getHauteurRectangleCouleur() / 2 - m_graphTitre->boundingRect().height() / 2);
                
                m_graphTitre->setPos(x, y);
            }
            else
            {
                /* NOTE :
                 * 
                 * Dans les calculs suivants, on utilise deux valeurs « a » et « b » pour positionner les items. La
                 * valeur « a » représente les coordonnées du point  C correspondant au centre du bord suppérieur du
                 * QGraphicsItem. La valeur « b » est une valeur relative permettant de trouver les coordonnées du
                 * point G représentant le coin suppérieur gauche du QGraphicsItem.
                 * 
                 *                             C
                 *                 G ._________.__________
                 *                   |                    |     NOTE : Le point G servira à positionner le
                 *                   |    QGraphicsItem   |     QGraphicsItem sur l'emplacement. On applique une
                 *                   |____________________|     rotation de 45° antihoraire d'où la naissance des ces
                 *                                              calculs complexes.
                 */
                int marge(m_infosGraphiques.getMarge());
                
                if (m_graphCouleurEnCoin)
                {
                    marge += m_graphCouleurEnCoin->boundingRect().height() / 2;
                }
                
                if (marge < MARGE_MIN_DIAGONALE)
                {
                    marge = MARGE_MIN_DIAGONALE;
                }
                
                int a(qSqrt(qPow(marge, 2) / 2));
                int b(qSqrt(qPow(rect().width() - m_infosGraphiques.getMarge() * 2, 2) / 8));
                
                m_graphTitre->setPos(a - b, a + b);
            }
        }
        else
        {
            int x(rect().width() / 2 - m_graphTitre->boundingRect().width() / 2);
            int y(m_infosGraphiques.getMarge());
            
            if (m_graphCouleur)
            {
                y += m_graphCouleur->boundingRect().height();
            }
            
            m_graphTitre->setPos(x, y);
        }
    }
}





void GraphismeEmplacement::positionneSousTitre()
{
    if (m_graphSousTitre)
    {
        if (m_emplacementEnCoin)
        {
            if (m_emplacement->getType() == Type::SimpleVisite)
            {
                int x(rect().height() - m_infosGraphiques.getHauteurRectangleCouleur() / 2 - m_graphSousTitre->boundingRect().height() / 2);
                int y((rect().width() + m_graphSousTitre->boundingRect().width()) / 2);
                
                m_graphSousTitre->setPos(x, y);
            }
            else
            {
                /* NOTE : Cf. NOTE dans GraphismeEmplacement::positionneTitre().
                 */
                int marge(m_infosGraphiques.getMarge());
                
                if (m_graphCouleurEnCoin)
                {
                    marge += m_graphCouleurEnCoin->boundingRect().height() / 2;
                }
                
                if (marge < MARGE_MIN_DIAGONALE)
                {
                    marge = MARGE_MIN_DIAGONALE;
                }
                
                if (m_graphTitre)
                {
                    marge += m_graphTitre->boundingRect().height() + m_infosGraphiques.getMarge();
                }
                
                int a(qSqrt(qPow(marge, 2) / 2));
                int b(qSqrt(qPow(rect().width() - m_infosGraphiques.getMarge() * 2, 2) / 8));
                
                m_graphSousTitre->setPos(a - b, a + b);
            }
        }
        else
        {
            int x(rect().width() / 2 - m_graphSousTitre->boundingRect().width() / 2);
            int y(m_infosGraphiques.getMarge());
            
            if (m_graphCouleur)
            {
                y += m_graphCouleur->boundingRect().height();
            }
            
            if (m_graphTitre)
            {
                y += m_graphTitre->boundingRect().height() + m_infosGraphiques.getMarge();
            }
            
            m_graphSousTitre->setPos(x, y);
        }
    }
}





void GraphismeEmplacement::positionneImage()
{
    if (m_graphImage)
    {
        if (m_emplacementEnCoin)
        {
            if (m_emplacement->getType() == Type::SimpleVisite)
            {
                int x(0);
                int y(rect().height() - m_graphImage->boundingRect().height());
                
                m_graphImage->setPos(x, y);
            }
            else
            {
                int margeHaute(0);
                int margeBasse(rect().height());
                
                if (m_graphCouleurEnCoin)
                {
                    margeHaute += m_graphCouleurEnCoin->boundingRect().height() / 2;
                }
                
                if (m_graphTitre)
                {
                    margeHaute += m_graphTitre->boundingRect().height() + m_infosGraphiques.getMarge();
                }
                
                if (m_graphSousTitre)
                {
                    margeHaute += m_graphSousTitre->boundingRect().height() + m_infosGraphiques.getMarge();
                }
                
                if (m_graphDescription)
                {
                    margeBasse -= m_graphDescription->boundingRect().height() - m_infosGraphiques.getMarge();
                }
                
                if (m_graphPrix)
                {
                    margeBasse -= m_graphPrix->boundingRect().height() - m_infosGraphiques.getMarge();
                }
                
                margeHaute = qSqrt(qPow(margeHaute, 2) / 2);
                margeBasse = qSqrt(qPow(margeBasse, 2) / 2);
                
                int x((rect().width() - m_graphImage->boundingRect().width()) / 2);
                int y((rect().height() + margeHaute - margeBasse - m_graphImage->boundingRect().height()) / 2);
                
                m_graphImage->setPos(x, y);
            }
        }
        else
        {
            int margeHaute(0);
            int margeBasse(rect().height());
            
            if (m_graphCouleur)
            {
                margeHaute += m_graphCouleur->boundingRect().height();
            }
            
            if (m_graphTitre)
            {
                margeHaute += m_graphTitre->boundingRect().height() + m_infosGraphiques.getMarge();
            }
            
            if (m_graphSousTitre)
            {
                margeHaute += m_graphSousTitre->boundingRect().height() + m_infosGraphiques.getMarge();
            }
            
            if (m_graphDescription)
            {
                margeBasse -= m_graphDescription->boundingRect().height() - m_infosGraphiques.getMarge();
            }
            
            if (m_graphPrix)
            {
                margeBasse -= m_graphPrix->boundingRect().height() - m_infosGraphiques.getMarge();
            }
            
            int x((rect().width() - m_graphImage->boundingRect().width()) / 2);
            int y((rect().height() + margeHaute - margeBasse - m_graphImage->boundingRect().height()) / 2);
            
            m_graphImage->setPos(x, y);
        }
    }
}





void GraphismeEmplacement::positionneDescription()
{
    if (m_graphDescription)
    {
        if (m_emplacementEnCoin)
        {
            if (m_emplacement->getType() != Type::SimpleVisite)
            {
                /* NOTE : Cf. NOTE dans GraphismeEmplacement::positionneTitre().
                 */
                int marge(rect().height() - m_infosGraphiques.getMarge());
                
                if (marge < rect().height() - MARGE_MIN_DIAGONALE)
                {
                    marge = rect().height() - MARGE_MIN_DIAGONALE;
                }
                
                if (m_graphPrix)
                {
                    marge -= m_graphPrix->boundingRect().height() - m_infosGraphiques.getMarge();
                }
                
                marge -= m_graphDescription->boundingRect().height();
                
                int a(qSqrt(qPow(marge, 2) / 2));
                int b(qSqrt(qPow(rect().width() - m_infosGraphiques.getMarge() * 2, 2) / 8));
                
                m_graphDescription->setPos(a - b, a + b);
            }
        }
        else
        {
            int x(rect().width() / 2 - m_graphDescription->boundingRect().width() / 2);
            int y(rect().height() - m_graphDescription->boundingRect().height() - m_infosGraphiques.getMarge());
            
            if (m_graphPrix)
            {
                y -= m_graphPrix->boundingRect().height() - m_infosGraphiques.getMarge();
            }
            
            m_graphDescription->setPos(x, y);
        }
    }
}





void GraphismeEmplacement::positionnePrix()
{
    if (m_graphPrix)
    {
        if (m_emplacementEnCoin)
        {
            if (m_emplacement->getType() != Type::SimpleVisite)
            {
                /* NOTE : Cf. NOTE dans GraphismeEmplacement::positionneTitre().
                 */
                int marge(rect().height() - m_infosGraphiques.getMarge());
                
                if (marge < rect().height() - MARGE_MIN_DIAGONALE)
                {
                    marge = rect().height() - MARGE_MIN_DIAGONALE;
                }
                
                marge -= m_graphPrix->boundingRect().height();
                
                int a(qSqrt(qPow(marge, 2) / 2));
                int b(qSqrt(qPow(rect().width() - m_infosGraphiques.getMarge() * 2, 2) / 8));
                
                m_graphPrix->setPos(a - b, a + b);
            }
        }
        else
        {
            int x(rect().width() / 2 - m_graphPrix->boundingRect().width() / 2);
            int y(rect().height() - m_graphPrix->boundingRect().height() - m_infosGraphiques.getMarge());
            
            m_graphPrix->setPos(x, y);
        }
    }
}





void GraphismeEmplacement::helper_setupGraphicsTextItem(QGraphicsTextItem* item,
                                                        const QString& texte,
                                                        const QFont& font,
                                                        const QColor& couleur)
{
    QString nouveauTexte(texte);
    nouveauTexte.replace("<", "&lt;");
    nouveauTexte.replace(">", "&gt;");
    nouveauTexte.replace("&lt;br /&gt;", "<br />");// On ne désactive pas les retour à la ligne.
    item->setHtml("<center>" + nouveauTexte + "</center>");
    item->setTextWidth(rect().width() - m_infosGraphiques.getMarge() * 2);
    item->setFont(font);
    item->setDefaultTextColor(couleur);
}

