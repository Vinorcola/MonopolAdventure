#include "Plateau.hpp"

#include "donnees/emplacements/Emplacements.hpp"
#include "MainWindow.hpp"





Plateau::Plateau(MainWindow* parent) :
    QGraphicsScene(),
    m_parent(parent),
    m_sauvegarde(true),
    m_titre(tr("Nouveau plateau")),
    m_taille(0, 0),
    m_devise(" €"),
    m_prixCoefficient(0),
    m_prixAffichageComplet(true),
    m_couleurFond(255, 255, 255),
    m_image(),
    m_graphicsItemImage(new QGraphicsPixmapItem),
    m_graphismeEmplacement(),
    m_regle(),
    m_pilesCartes(),
    m_emplacements(),
    m_regroupements()
{
    // Ajout de l'élément graphique permettant d'afficher l'image de fond du plateau.
    addItem(m_graphicsItemImage);
}





Plateau::~Plateau()
{
    for (int i(0), iEnd(m_pilesCartes.size()); i < iEnd; ++i)
    {
        delete m_pilesCartes.takeLast();
    }
    
    for (int i(0), iEnd(m_emplacements.size()); i < iEnd; ++i)
    {
        delete m_emplacements.takeLast();
    }
    
    for (int i(0), iEnd(m_regroupements.size()); i < iEnd; ++i)
    {
        delete m_regroupements.takeLast();
    }
}





void Plateau::dessiner()
{
    /* Configuration et affichage des emplacements.
     */
    for (int i(1), iEnd(m_emplacements.size()); i < iEnd; ++i)
    {
        helper_dessineEmplacement(m_emplacements.at(i));
    }
    
    /* Configuration et affichage de la prison en dernier pour qu'elle soit au dessus de l'emplacement
     * « Simple visite ».
     */
    helper_dessineEmplacement(m_emplacements.first());
    
    /* Configuration et affichage de l'image au centre du plateau.
     */
    helper_dessineImageCentre();
}





const QString& Plateau::getTitre() const
{
    return m_titre;
}





const QSize& Plateau::getTaille() const
{
    return m_taille;
}





const QString& Plateau::getDevise()
{
    return m_devise;
}





quint32 Plateau::getCoefficientPrix() const
{
    return qPow(10, m_prixCoefficient);
}





bool Plateau::affichageIntegraleActif() const
{
    return m_prixAffichageComplet;
}





const QColor& Plateau::getCouleurFond() const
{
    return m_couleurFond;
}





const QPixmap& Plateau::getImage() const
{
    return m_image;
}





const QSize& Plateau::getTailleEmplacementsNormaux() const
{
    return m_graphismeEmplacement.getTailleNormale();
}





const QSize& Plateau::getTailleEmplacementsEnCoin() const
{
    return m_graphismeEmplacement.getTailleEnCoin();
}





quint16 Plateau::getHauteurRectangleCouleur() const
{
    return m_graphismeEmplacement.getHauteurRectangleCouleur();
}





const QPen& Plateau::getCrayonBordureEmplacement() const
{
    return m_graphismeEmplacement.getCrayonBordure();
}





quint8 Plateau::getMarge() const
{
    return m_graphismeEmplacement.getMarge();
}





const QColor& Plateau::getCouleurFondEmplacement() const
{
    return m_graphismeEmplacement.getCouleurFond();
}





const QFont& Plateau::getFonteTitreEmplacement() const
{
    return m_graphismeEmplacement.getFonteTitre();
}





const QFont& Plateau::getFonteSousTitreEmplacement() const
{
    return m_graphismeEmplacement.getFonteSousTitre();
}





const QFont& Plateau::getFonteDescriptionEmplacement() const
{
    return m_graphismeEmplacement.getFonteDescription();
}





const QFont& Plateau::getFontePrixEmplacement() const
{
    return m_graphismeEmplacement.getFontePrix();
}





const Regle& Plateau::getRegle() const
{
    return m_regle;
}





const QList<Regroupement*>& Plateau::getListeRegroupement()
{
    return m_regroupements;
}





const Emplacement* Plateau::getEmplacement(quint8 id) const
{
    if (id < m_emplacements.count())
    {
        return m_emplacements.at(id);
    }
    
    return 0;
}





const PileCartes* Plateau::getPileCartes(quint8 id) const
{
    if (id < m_pilesCartes.count())
    {
        return m_pilesCartes.at(id);
    }
    
    return 0;
}





int Plateau::getNombrePropriete() const
{
    int qte(m_compagniesTransport.count() + m_services.count());
    
    for (int i(0), iEnd(m_regroupements.count()); i < iEnd; i++)
    {
        qte += m_regroupements.at(i)->getNombreTerrains();
    }
    
    return qte;
}





bool Plateau::loadFromFile(QString cheminFichier)
{
    if (QFile::exists(cheminFichier))
    {
        QFile* fichier(new QFile(cheminFichier));
        if (fichier->open(QIODevice::ReadOnly))
        {
            //Création du flux de lecture.
            QDataStream lecture(fichier);
            
            // Configuration de la méthode de lecture de l'en-tête.
            lecture.setVersion(QDataStream::Qt_4_8);
            
            // Ecriture de l'en-tête du fichier de sauvegarde.
            quint32 tag, version;
            lecture >> tag >> version;
            
            if (tag == TAG_SECURITE)
            {
                // Suppression de ce qui existe déjà dans le plateau.
                for (int i(0), iEnd(m_pilesCartes.size()); i < iEnd; ++i)
                {
                    delete m_pilesCartes.takeLast();
                }
                
                for (int i(0), iEnd(m_emplacements.size()); i < iEnd; ++i)
                {
                    delete m_emplacements.takeLast();
                }
                m_compagniesTransport.clear();
                m_services.clear();
                
                for (int i(0), iEnd(m_regroupements.size()); i < iEnd; ++i)
                {
                    delete m_regroupements.takeLast();
                }
                
                
                
                switch (version)
                {
                    default:
                        // Lecture des données du plateau.
                        lecture >> m_titre
                                >> m_taille
                                >> m_devise
                                >> m_prixCoefficient
                                >> m_prixAffichageComplet
                                >> m_couleurFond
                                >> m_image;
                        setBackgroundBrush(QBrush(m_couleurFond));
                        
                        
                        
                        // Lecture de la règle du plateau.
                        m_regle.loadFromFile(lecture, version);
                        
                        
                        
                        // Lecture des graphismes des emplacements.
                        m_graphismeEmplacement.loadFromFile(lecture, version);
                        
                        
                        
                        // Lecture du nombre de piles de cartes et création.
                        quint8 nbPilesCartes;
                        lecture >> nbPilesCartes;
                        for (int i(0); i < nbPilesCartes; i++)
                        {
                            m_pilesCartes.append(new PileCartes);
                        }
                        
                        
                        
                        // Lecture du nombre d'emplacements.
                        quint8 nbEmplacements;
                        lecture >> nbEmplacements;
                        
                        // Lecture des types d'emplacement et création.
                        for (int i(0); i < nbEmplacements; i++)
                        {
                            quint8 typeEmplacement;
                            lecture >> typeEmplacement;
                            
                            switch ((Type::Emplacement) typeEmplacement)
                            {
                                case Type::CompagnieTransport:
                                    m_compagniesTransport.append(new CompagnieTransport(m_graphismeEmplacement, m_devise));
                                    m_emplacements.append(m_compagniesTransport.last());
                                    break;
                                    
                                case Type::Depart:
                                    m_emplacements.append(new Depart(m_graphismeEmplacement, m_devise));
                                    break;
                                    
                                case Type::Deplacement:
                                    m_emplacements.append(new Deplacement(m_graphismeEmplacement, m_devise));
                                    break;
                                    
                                case Type::ParcGratuit:
                                    m_emplacements.append(new ParcGratuit(m_graphismeEmplacement));
                                    break;
                                    
                                case Type::Pioche:
                                    m_emplacements.append(new Pioche(m_graphismeEmplacement));
                                    break;
                                    
                                case Type::Prison:
                                    m_emplacements.append(new Prison(m_graphismeEmplacement, 0));
                                    break;
                                    
                                case Type::Service:
                                    m_services.append(new Service(m_graphismeEmplacement, m_devise));
                                    m_emplacements.append(m_services.last());
                                    break;
                                    
                                case Type::SimpleVisite:
                                    m_emplacements.append(new SimpleVisite(m_graphismeEmplacement));
                                    break;
                                    
                                case Type::Taxe:
                                    m_emplacements.append(new Taxe(m_graphismeEmplacement, m_devise));
                                    break;
                                    
                                case Type::Terrain:
                                    m_emplacements.append(new Terrain(m_graphismeEmplacement, m_devise));
                                    break;
                                    
                                default:
                                    break;
                            }
                        }
                        
                        
                        
                        // Lecture des emplacements.
                        for (int i(0); i < nbEmplacements; i++)
                        {
                            Emplacement* emplacement(m_emplacements.at(i));
                            switch (emplacement->getType())
                            {
                                case Type::CompagnieTransport:
                                    static_cast<CompagnieTransport*>(emplacement)->loadFromFile(lecture, version);
                                    break;
                                    
                                case Type::Depart:
                                    static_cast<Depart*>(emplacement)->loadFromFile(lecture, version);
                                    break;
                                    
                                case Type::Deplacement:
                                    static_cast<Deplacement*>(emplacement)->loadFromFile(lecture, version, this);
                                    break;
                                    
                                case Type::ParcGratuit:
                                    static_cast<ParcGratuit*>(emplacement)->loadFromFile(lecture, version);
                                    break;
                                    
                                case Type::Pioche:
                                    static_cast<Pioche*>(emplacement)->loadFromFile(lecture, version, this);
                                    break;
                                    
                                case Type::Prison:
                                    static_cast<Prison*>(emplacement)->loadFromFile(lecture, version, this);
                                    break;
                                    
                                case Type::Service:
                                    static_cast<Service*>(emplacement)->loadFromFile(lecture, version);
                                    break;
                                    
                                case Type::SimpleVisite:
                                    static_cast<SimpleVisite*>(emplacement)->loadFromFile(lecture, version);
                                    break;
                                    
                                case Type::Taxe:
                                    static_cast<Taxe*>(emplacement)->loadFromFile(lecture, version);
                                    break;
                                    
                                case Type::Terrain:
                                    static_cast<Terrain*>(emplacement)->loadFromFile(lecture, version);
                                    break;
                                    
                                default:
                                    break;
                            }
                        }
                        
                        
                        
                        // Lecture des regroupements.
                        quint8 nbRegroupements;
                        lecture >> nbRegroupements;
                        for (int i(0); i < nbRegroupements; i++)
                        {
                            Regroupement* regroupement(new Regroupement);
                            regroupement->loadFromFile(lecture, version, this);
                            m_regroupements.append(regroupement);
                        }
                        
                        
                        
                        // Lecture des piles de cartes.
                        for (int i(0) ; i < nbPilesCartes; i++)
                        {
                            m_pilesCartes.at(i)->loadFromFile(lecture, version, this);
                        }
                        
                        
                        
                        // Lecture du tag de sécurité.
                        lecture >> tag;
                        
                        if (tag != TAG_SECURITE)
                        {
                            QMessageBox::warning(m_parent, tr("Problème de lacture du fichier."), tr("Le chargement du plateau ne s'est pas passé comme prévu. Le fichier semble corrompu."));
                            return false;
                        }
                        
                }
            }
            else
            {
                QMessageBox::warning(m_parent, tr("Impossible d'ouvrir le fichier."), tr("Le fichier ") + cheminFichier + tr(" n'est pas un fichier de sauvegarde valide. Le plateau n'a pas été chargé."));
                return false;
            }
            
            
            
            fichier->close();
            m_sauvegarde = true;
        }
        else
        {
            QMessageBox::warning(m_parent, tr("Impossible d'ouvrir le fichier."), tr("Impossible d'ouvrir le fichier ") + cheminFichier + tr(". Le plateau n'a pas été chargé."));
            return false;
        }
    }
    
    return true;
}





void Plateau::helper_dessineEmplacement(Emplacement* emplacement)
{
    if (m_emplacements.contains(emplacement))
    {
        int rang(m_emplacements.indexOf(emplacement));
        
        // Configuration de la position et de la rotation.
        emplacement->setupElementGraphique(helper_getPositionEmplacement(rang),
                                           helper_getRotationEmplacement(rang),
                                           this);
        
        // Configuration du type d'emplacement.
        if (helper_isEmplacementEnCoin(rang))
        {
            emplacement->setEmplacementEnCoin();
        }
        else
        {
            emplacement->setEmplacementNormal();
        }
        
        // Dessin de l'élément.
        emplacement->dessiner();
    }
}





bool Plateau::helper_isEmplacementEnCoin(int id) const
{
    return (id == 0 // Prison
         || id == 1 // Départ
         || id == m_taille.width()
         || id == m_taille.width() + m_taille.height() - 1
         || id == m_taille.width() * 2 + m_taille.height() - 2);
}





QPoint Plateau::helper_getPositionEmplacement(int id) const
{
    int largeur(m_taille.width());
    int hauteur(m_taille.height());
    
    int largeurEmplacement(m_graphismeEmplacement.getTailleNormale().width());
    int hauteurEmplacement(m_graphismeEmplacement.getTailleNormale().height());
    
    if (id == 0)
    // Prison
    {
        const SimpleVisite* simpleVisiteAssociee(static_cast<Prison*>(m_emplacements.first())->getEmplacementAssocie());
        
        if (simpleVisiteAssociee)
        {
            return helper_getPositionEmplacement(m_emplacements.indexOf((SimpleVisite*) simpleVisiteAssociee));
        }
    }
    else
    {
        if (id >= 1 && id < largeur)
        // Côté bas du plateau
        {
            return QPoint(hauteurEmplacement + (largeur - 1 - id) * largeurEmplacement,
                          hauteurEmplacement + (hauteur - 2) * largeurEmplacement);
        }
        else if (id >= largeur && id < largeur + hauteur - 1)
        // Côté gauche
        {
            return QPoint(hauteurEmplacement,
                          hauteurEmplacement + (largeur + hauteur - 2 - id) * largeurEmplacement);
        }
        else if (id >= largeur + hauteur - 1 && id < 2 * largeur + hauteur - 2)
        // Côté haut
        {
            return QPoint(hauteurEmplacement + (id - hauteur - largeur + 1) * largeurEmplacement,
                          hauteurEmplacement);
        }
        else
        // Côté droit
        {
            return QPoint(hauteurEmplacement + (largeur - 2) * largeurEmplacement,
                          hauteurEmplacement + (id - 2 * largeur - hauteur + 2) * largeurEmplacement);
        }
    }
    
    return QPoint();
}





int Plateau::helper_getRotationEmplacement(int id) const
{
    int largeur(m_taille.width());
    int hauteur(m_taille.height());
    
    if (id == 0)
    // Prison
    {
        const SimpleVisite* simpleVisiteAssociee(static_cast<Prison*>(m_emplacements.first())->getEmplacementAssocie());
        
        if (simpleVisiteAssociee)
        {
            return helper_getRotationEmplacement(m_emplacements.indexOf((SimpleVisite*) simpleVisiteAssociee));
        }
    }
    if (id >= largeur && id < largeur + hauteur - 1)
    // Côté gauche
    {
        return 90;
    }
    else if (id >= largeur + hauteur - 1 && id < 2 * largeur + hauteur - 2)
    // Côté haut
    {
        return 180;
    }
    else if (id >= 2 * largeur + hauteur - 2)
    // Côté droit
    {
        return 270;
    }
    
    return 0;
}





void Plateau::helper_dessineImageCentre()
{
    QSize taille(m_graphismeEmplacement.getTailleNormale());
    
    // Déplacement de l'image au centre du plateau.
    m_graphicsItemImage->setPos(taille.height(), taille.height());
    
    // Redimenssionnement de l'image au centre du plateau.
    if (!m_image.isNull())
    {
        int h((m_taille.height() - 2) * taille.width());// On enlève 2 pour les bords du plateau.
        int w((m_taille.width() - 2) * taille.width());// Idem ici.
        m_graphicsItemImage->setPixmap(m_image.scaled(w, h));
    }
    else
    {
        m_graphicsItemImage->setPixmap(m_image);
    }
}

