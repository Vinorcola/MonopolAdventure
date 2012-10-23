#include "Plateau.hpp"





Plateau::Plateau() :
    QGraphicsScene(),
    m_titre(""),
    m_taille(0, 0),
    m_devise(""),
    m_prixCoefficient(1),
    m_prixAffichageComplet(true),
    m_couleurFond(255, 255, 255),
    m_image(),
    m_graphismeEmplacement(),
    m_pilesCartes(),
    m_emplacements(),
    m_regroupements()
{
    // Création d'un regroupement pour mettre par défaut tous les terrains créés.
    Regroupement* regroupement(new Regroupement());
    regroupement->editCouleur(QColor(0, 128, 0));
    regroupement->editTitre(tr("Défaut"));
    
    // Ajout du regroupement dans la liste
    m_regroupements << regroupement;
}





Plateau::~Plateau()
{
    for (int i(0), iEnd(m_pilesCartes.size()); i < iEnd; ++i)
    {
        delete m_pilesCartes.takeLast();
    }
    
    for (int i(0), iEnd(m_regroupements.size()); i < iEnd; ++i)
    {
        delete m_regroupements.takeLast();
    }
    
    for (int i(0), iEnd(m_emplacements.size()); i < iEnd; ++i)
    {
        delete m_emplacements.takeLast();
    }
}





void Plateau::dessiner()
{
    for (int i(1), iEnd(m_emplacements.size()); i < iEnd; ++i)
    {
        m_emplacements.at(i)->registerScene(this, helper_getPositionEmplacement(i), helper_getRotationEmplacement(i));
        m_emplacements.at(i)->dessiner(this);
    }
    
    /* On affiche la prison en dernier pour qu'elle soit au dessus de l'emplacement « Simple visite ».
     */
    m_emplacements.first()->registerScene(this, helper_getPositionEmplacement(0), helper_getRotationEmplacement(0));
    m_emplacements.first()->dessiner(this);
}





void Plateau::updateCouleurRegroupement()
{
    for (int i(0), iEnd(m_emplacements.size()); i < iEnd; ++i)
    {
        if (m_emplacements.at(i)->getType() == Type::Terrain)
        {
            Terrain* terrain(static_cast<Terrain*>(m_emplacements.at(i)));
            terrain->updateAffichageCouleurRegroupement(this);
        }
    }
}





const QString& Plateau::getTitre() const
{
    return m_titre;
}





void Plateau::editTitre(const QString& titre)
{
    if (!titre.isEmpty())
    {
        m_titre = titre;
    }
}





const QSize& Plateau::getTaille() const
{
    return m_taille;
}





void Plateau::editTaille(const QSize& taille)
{
    if (taille != m_taille
     && taille.height() >= 3 && taille.height() <= 50
     && taille.width() >= 3 && taille.width() <= 50)
    {
        m_taille = taille;
        
        
        
        /* Création de l'emplacement Prison et Départ, les deux emplacements obligatoires. On créé aussi un emplacement
         * « Simple visite » nécessaire pour créer la prison.
         */
        SimpleVisite* simpleVisite(0);
        Prison* prison(0);
        Depart* depart(0);
        if (m_emplacements.isEmpty())
        {
            simpleVisite = new SimpleVisite(m_graphismeEmplacement);
            simpleVisite->editTitre(tr("Simple"));
            simpleVisite->editSousTitre(tr("visite"));
            
            prison = new Prison(m_graphismeEmplacement, simpleVisite);
            prison->editTitre(tr("Prison"));
            prison->editCaution(50);
            
            depart = new Depart(m_graphismeEmplacement);
            depart->editTitre(tr("Départ"));
            depart->editDescription(tr("Recevez 200 €"));
            depart->editSalaire(200);
            
            m_emplacements << prison << depart;
        }
        
        
        
        /* Modification de la liste des emplacements :
         *   - Création de terrains si la nouvelle taille est plus grande ;
         *   - Suppression de terrains si la nouvelle taille est plus petite.
         */
        int nombreEmplacementPrecedent(m_emplacements.size());
        int nombreEmplacement(taille.height() * 2 + taille.width() * 2 - 3);// - 3 => - 4 + 1 (Prison)
        
        if (nombreEmplacement > nombreEmplacementPrecedent)
        {
            for (int i(0), iEnd(nombreEmplacement - nombreEmplacementPrecedent); i < iEnd; ++i)
            {
                Terrain* terrain(new Terrain(m_graphismeEmplacement, m_devise));
                terrain->editTitre(tr("Terrain") + "_" + QString::number(i));
                terrain->editSousTitre(tr("Nouveau"));
                terrain->editDescription(tr("Veuillez configurer ce terrain"));
                terrain->editRegroupement(m_regroupements.first());
                
                m_emplacements << terrain;
            }
        }
        else if (nombreEmplacement < nombreEmplacementPrecedent)
        {
            for (int i(0), iEnd(nombreEmplacementPrecedent - nombreEmplacement); i < iEnd; ++i)
            {
                Emplacement* emplacement(m_emplacements.takeLast());
                
                /* Si l'emplacement à supprimer est un emplacement « Simple visite », on vérifie si c'est celui associé
                 * à la prison. Si oui, on recré un nouvel emplacement « Simple visite » que l'on associe et que l'on
                 * insèrera après dans le plateau.
                 */
                if (emplacement->getType() == Type::SimpleVisite)
                {
                    Prison* prison(static_cast<Prison*>(m_emplacements.first()));
                    
                    if (emplacement == prison->getEmplacementAssocie())
                    {
                        simpleVisite = new SimpleVisite(m_graphismeEmplacement);
                        simpleVisite->editTitre(tr("Simple"));
                        simpleVisite->editSousTitre(tr("visite"));
                        
                        prison->editEmplacementAssocie(simpleVisite);
                    }
                }
                
                delete emplacement;
            }
        }
        
        
        
        /* Si c'est la première configuration (simpleVisite != 0), alors on insère l'emplacement « Simple visite ».
         * Si l'emplacement « Simple visite » a été supprimé, on réassigne le nouveau.
         */
        if (simpleVisite)
        {
            delete m_emplacements.at(m_taille.width());
            m_emplacements[m_taille.width()] = simpleVisite;
        }
        
        
        
        /* Rectification des informations des emplacements.
         */
        for (int i(0), iEnd(m_emplacements.size()); i < iEnd; ++i)
        {
            m_emplacements.at(i)->registerScene(this, helper_getPositionEmplacement(i), helper_getRotationEmplacement(i));
            
            if (helper_isEmplacementEnCoin(i))
            {
                m_emplacements.at(i)->setEmplacementEnCoin();
            }
            else
            {
                m_emplacements.at(i)->setEmplacementNormal();
            }
        }
    }
}





const QString& Plateau::getDevise()
{
    return m_devise;
}





void Plateau::editDevise(const QString& devise)
{
    if (!devise.isEmpty() && devise.count() <= 5)
    {
        m_devise = devise;
    }
}





quint32 Plateau::getCoefficientPrix() const
{
    return qPow(10, m_prixCoefficient);
}





void Plateau::editCoefficientPrix(const quint32 coefficient)
{
    switch (coefficient)
    {
        case 1:
            m_prixCoefficient = 0;
            break;
        case 10:
            m_prixCoefficient = 1;
            break;
        case 100:
            m_prixCoefficient = 2;
            break;
        case 1000:
            m_prixCoefficient = 3;
            break;
        case 10000:
            m_prixCoefficient = 4;
            break;
        case 100000:
            m_prixCoefficient = 5;
            break;
        case 1000000:
            m_prixCoefficient = 6;
            break;
        case 10000000:
            m_prixCoefficient = 7;
            break;
        case 100000000:
            m_prixCoefficient = 8;
            break;
    }
}





bool Plateau::affichageIntegraleActif() const
{
    return m_prixAffichageComplet;
}





void Plateau::editAffichageIntegrale(const bool actif)
{
    m_prixAffichageComplet = actif;
}





const QColor& Plateau::getCouleurFond() const
{
    return m_couleurFond;
}





void Plateau::editCouleurFond(const QColor& couleur)
{
    m_couleurFond = couleur;
}





const QPixmap& Plateau::getImage() const
{
    return m_image;
}





void Plateau::editImage(const QPixmap& image)
{
    m_image = image;
}





const QSize& Plateau::getTailleEmplacementsNormaux() const
{
    return m_graphismeEmplacement.getTailleNormale();
}





const QSize& Plateau::getTailleEmplacementsEnCoin() const
{
    return m_graphismeEmplacement.getTailleEnCoin();
}





void Plateau::editTailleEmplacements(const QSize& taille)
{
    m_graphismeEmplacement.editTaille(taille);
}





quint16 Plateau::getHauteurRectangleCouleur() const
{
    return m_graphismeEmplacement.getHauteurRectangleCouleur();
}





void Plateau::editHauteurRectangleCouleur(const quint16 hauteur)
{
    m_graphismeEmplacement.editHauteurRectangleCouleur(hauteur);
}





const QPen& Plateau::getCrayonBordureEmplacement() const
{
    return m_graphismeEmplacement.getCrayonBordure();
}





void Plateau::editCrayonBordureEmplacement(const QPen& crayon)
{
    m_graphismeEmplacement.editCrayonBordure(crayon);
}





quint8 Plateau::getMarge() const
{
    return m_graphismeEmplacement.getMarge();
}





void Plateau::editMarge(quint8 marge)
{
    m_graphismeEmplacement.editMarge(marge);
}





const QColor& Plateau::getCouleurFondEmplacement() const
{
    return m_graphismeEmplacement.getCouleurFond();
}





void Plateau::editCouleurFondEmplacement(const QColor& couleur)
{
    m_graphismeEmplacement.editCouleurFond(couleur);
}





const QFont& Plateau::getFonteTitreEmplacement() const
{
    return m_graphismeEmplacement.getFonteTitre();
}





void Plateau::editFonteTitreEmplacement(const QFont& fonte)
{
    m_graphismeEmplacement.editFonteTitre(fonte);
}





const QFont& Plateau::getFonteSousTitreEmplacement() const
{
    return m_graphismeEmplacement.getFonteSousTitre();
}





void Plateau::editFonteSousTitreEmplacement(const QFont& fonte)
{
    m_graphismeEmplacement.editFonteSousTitre(fonte);
}





const QFont& Plateau::getFonteDescriptionEmplacement() const
{
    return m_graphismeEmplacement.getFonteDescription();
}





void Plateau::editFonteDescriptionEmplacement(const QFont& fonte)
{
    m_graphismeEmplacement.editFonteDescription(fonte);
}





const QFont& Plateau::getFontePrixEmplacement() const
{
    return m_graphismeEmplacement.getFontePrix();
}





void Plateau::editFontePrixEmplacement(const QFont& fonte)
{
    m_graphismeEmplacement.editFontePrix(fonte);
}





const GraphismeEmplacementInfos& Plateau::getInformationGraphismeEmplacement() const
{
    return m_graphismeEmplacement;
}





QList<Regroupement*>& Plateau::getListeRegroupement()
{
    return m_regroupements;
}





bool Plateau::helper_isEmplacementEnCoin(int id) const
{
    return (id == 0
         || id == 1
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
        SimpleVisite* simpleVisiteAssociee(static_cast<Prison*>(m_emplacements.first())->getEmplacementAssocie());
        
        if (simpleVisiteAssociee)
        {
            return helper_getPositionEmplacement(m_emplacements.indexOf(simpleVisiteAssociee));
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
        SimpleVisite* simpleVisiteAssociee(static_cast<Prison*>(m_emplacements.first())->getEmplacementAssocie());
        
        if (simpleVisiteAssociee)
        {
            return helper_getRotationEmplacement(m_emplacements.indexOf(simpleVisiteAssociee));
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

