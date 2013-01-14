#include "Plateau.hpp"

#include "dialogEdition/widgetsEditeurs/TypeEmplacementEditWidget.hpp"
#include "dialogEdition/EditionEmplacement.hpp"
#include "dialogEdition/EditionListePilesCartes.hpp"
#include "dialogEdition/EditionListeRegroupements.hpp"
#include "donnees/emplacements/Emplacements.hpp"
#include "MainWindow.hpp"





Plateau::Plateau(MainWindow* parent) :
    QGraphicsScene(),
    m_parent(parent),
    m_titre(""),
    m_taille(0, 0),
    m_devise(""),
    m_prixCoefficient(1),
    m_prixAffichageComplet(true),
    m_couleurFond(255, 255, 255),
    m_image(),
    m_graphismeEmplacement(),
    m_regle(),
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
    for (int i(1), iEnd(m_emplacements.size()); i < iEnd; ++i)
    {
        m_emplacements.at(i)->setupElementGraphique(helper_getPositionEmplacement(i), helper_getRotationEmplacement(i), this);/** @todo Voir si on ne peut pas faire ces config dans la méthode editTaille() plutôt qu'ici. */
        GraphismeEmplacement* elementGraphique(m_emplacements.at(i)->dessiner());
        connect(elementGraphique, SIGNAL(editEmplacement(Emplacement*)), this, SLOT(editEmplacement(Emplacement*)));
    }
    
    /* On affiche la prison en dernier pour qu'elle soit au dessus de l'emplacement « Simple visite ».
     */
    m_emplacements.first()->setupElementGraphique(helper_getPositionEmplacement(0), helper_getRotationEmplacement(0), this);
    GraphismeEmplacement* elementGraphique(m_emplacements.first()->dessiner());
    connect(elementGraphique, SIGNAL(editEmplacement(Emplacement*)), this, SLOT(editEmplacement(Emplacement*)));
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
    /* L'édition de la taille du plateau consiste en plusieurs choses :
     *   → Si c'est la première configuration, il faut créer les emplacements obligatoires (Départ, Prison, etc.)
     *      → Si la taille augmente, il faut créer de nouveaux emplacements (terrains par défaut appartenant au premier regroupement).
     *   → Si la taille a diminué, il faut supprimer les derniers emplacements de la liste en trop.
     * Ensuite, il faut repositionner tous les emplacements, indiquer les nouveaux emplacement en coin, etc.
     */
    
    // Taille min : 3x3 | Taille max : 50x50
    if (taille != m_taille
     && taille.height() >= 3 && taille.height() <= 50
     && taille.width() >= 3 && taille.width() <= 50)
    {
        m_taille = taille;
        
        
        
        /* Création de l'emplacement Prison et Départ, les deux emplacements obligatoires. On créé aussi un emplacement
         * « Simple visite » nécessaire pour la prison.
         */
        SimpleVisite* simpleVisite(0);
        Prison* prison(0);
        Depart* depart(0);
        if (m_emplacements.isEmpty())
        // C'est la toute première configuration.
        {
            simpleVisite = new SimpleVisite(m_graphismeEmplacement);
            simpleVisite->editTitre(tr("Simple"));
            simpleVisite->editSousTitre(tr("visite"));
            
            prison = new Prison(m_graphismeEmplacement, simpleVisite);
            prison->editTitre(tr("Prison"));
            prison->editCaution(50);
            
            depart = new Depart(m_graphismeEmplacement, m_devise);
            depart->editTitre(tr("Départ"));
            depart->editDescription(tr("Recevez"));
            depart->editSalaire(200);
            
            m_emplacements << prison << depart;
        }
        
        
        
        /* Modification de la liste des emplacements :
         *   → Création de terrains si la nouvelle taille est plus grande ;
         *   → Suppression de terrains si la nouvelle taille est plus petite.
         */
        int nombreEmplacementPrecedent(m_emplacements.size());
        int nombreEmplacement(taille.height() * 2 + taille.width() * 2 - 3);// - 3 => - 4 (chaque coin) + 1 (Prison)
        
        if (nombreEmplacement > nombreEmplacementPrecedent)
        {
            /* Il faut créer de nouveaux emplacements (terrain par défaut insérés dans le premier regroupement).
             */
            for (int i(0), iEnd(nombreEmplacement - nombreEmplacementPrecedent); i < iEnd; ++i)
            {
                Terrain* terrain(new Terrain(m_graphismeEmplacement, m_devise));
                terrain->editTitre(tr("Terrain") + "_" + QString::number(i));
                terrain->editSousTitre(tr("Nouveau"));
                terrain->editDescription(tr("Veuillez configurer ce terrain"));
                m_regroupements.first()->insertTerrain(terrain);
                
                m_emplacements << terrain;
            }
        }
        else if (nombreEmplacement < nombreEmplacementPrecedent)
        {
            /* Il faut détruire certains emplacements (les derniers de la liste).
             */
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
            // On le place par défaut dans le coin bas-gauche du plateau (m_taille.width() ).
            delete m_emplacements.at(m_taille.width());
            m_emplacements[m_taille.width()] = simpleVisite;
        }
        
        
        
        /* Rectification des informations des emplacements.
         */
        for (int i(0), iEnd(m_emplacements.size()); i < iEnd; ++i)
        {
            m_emplacements.at(i)->setupElementGraphique(helper_getPositionEmplacement(i), helper_getRotationEmplacement(i), this);
            
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





const Regle& Plateau::getRegle() const
{
    return m_regle;
}





const QList<Regroupement*>& Plateau::getListeRegroupement()
{
    return m_regroupements;
}





quint8 Plateau::getIdentifiantEmplacement(const Emplacement* emplacement) const
{
    if (m_emplacements.contains((Emplacement*) emplacement))
    {
        return m_emplacements.indexOf((Emplacement*) emplacement);
    }
    else
    {
        return 255;
    }
}





quint8 Plateau::getIdentifiantPileCartes(const PileCartes* pileCartes) const
{
    if (m_pilesCartes.contains((PileCartes*) pileCartes))
    {
        return m_pilesCartes.indexOf((PileCartes*) pileCartes);
    }
    else
    {
        return 255;
    }
}





void Plateau::editListeRegroupements()
{
    EditionListeRegroupements fenetre(m_regroupements, m_parent);
    fenetre.executer();
}





void Plateau::editListePilesCartes()
{
    EditionListePilesCartes fenetre(m_pilesCartes, m_emplacements, m_devise, m_parent);
    fenetre.executer();
}





void Plateau::editEmplacement(Emplacement* emplacement)
{
    if (m_parent->editionTypeActive())
    {
        editEmplacementType(emplacement);
    }
    else
    {
        editEmplacementInformations(emplacement);
    }
}





void Plateau::saveInFile(QString cheminFichier) const
{
    QFile* fichier(new QFile(cheminFichier));
    if (fichier->open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        //Création du flux d'écriture
        QDataStream ecriture(fichier);
        
        // Configuration de la méthode d'écriture.
        ecriture.setVersion(QDataStream::Qt_5_0);
        
        // Ecriture de l'en-tête du fichier de sauvegarde.
        ecriture << TAG_SECURITE << VERSION_ECRITURE;
        
        
        
        // Ecriture des données du plateau.
        ecriture << m_titre
                 << m_taille
                 << m_devise
                 << m_prixCoefficient
                 << m_prixAffichageComplet
                 << m_couleurFond
                 << m_image;
        
        
        
        // Ecriture des piles de cartes.
        ecriture << m_pilesCartes.count();// Ecriture du nombre de piles de cartes.
        for (int i(0), iEnd(m_pilesCartes.count()); i < iEnd; i++)
        {
            m_pilesCartes.at(i)->saveInFile(ecriture, this);
        }
        
        
        
        // Ecriture des emplacements.
        ecriture << m_emplacements.count();// Ecriture du nombre d'emplacements.
        for (int i(0), iEnd(m_emplacements.count()); i < iEnd; i++)
        {
            Emplacement* emplacement(m_emplacements.at(i));
            switch (emplacement->getType())
            {
                case Type::CompagnieTransport:
                    static_cast<CompagnieTransport*>(emplacement)->saveInFile(ecriture);
                    break;
                    
                case Type::Depart:
                    static_cast<Depart*>(emplacement)->saveInFile(ecriture);
                    break;
                    
                case Type::Deplacement:
                    static_cast<Deplacement*>(emplacement)->saveInFile(ecriture, this);
                    break;
                    
                case Type::ParcGratuit:
                    static_cast<ParcGratuit*>(emplacement)->saveInFile(ecriture);
                    break;
                    
                case Type::Pioche:
                    static_cast<Pioche*>(emplacement)->saveInFile(ecriture, this);
                    break;
                    
                case Type::Prison:
                    static_cast<Prison*>(emplacement)->saveInFile(ecriture, this);
                    break;
                    
                case Type::Service:
                    static_cast<Service*>(emplacement)->saveInFile(ecriture);
                    break;
                    
                case Type::SimpleVisite:
                    static_cast<SimpleVisite*>(emplacement)->saveInFile(ecriture);
                    break;
                    
                case Type::Taxe:
                    static_cast<Taxe*>(emplacement)->saveInFile(ecriture);
                    break;
                    
                case Type::Terrain:
                    static_cast<Terrain*>(emplacement)->saveInFile(ecriture);
                    break;
                    
                default:
                    break;
            }
        }
        
        
        
        // Ecriture des regroupements.
        ecriture << m_regroupements.count();// Ecriture du nombre de regroupements.
        for (int i(0), iEnd(m_regroupements.count()); i < iEnd; i++)
        {
            m_regroupements.at(i)->saveInFile(ecriture, this);
        }
        
        
        
        fichier->close();
    }
    else
    {
        QMessageBox::warning(m_parent, tr("Impossible d'ouvrir le fichier."), tr("Impossible d'ouvrir le fichier ") + cheminFichier + tr(". Le plateau n'a pas été sauvegardé."));
    }
}





void Plateau::editEmplacementInformations(Emplacement* emplacement)
{
    EditionEmplacement* fenetre;
    switch (emplacement->getType())
    {
        case Type::CompagnieTransport:
            fenetre = new EditionEmplacement(static_cast<CompagnieTransport*>(emplacement), m_compagniesTransport.count(), m_parent);
            break;
            
        case Type::Depart:
            fenetre = new EditionEmplacement(static_cast<Depart*>(emplacement), m_parent);
            break;
            
        case Type::Deplacement:
            fenetre = new EditionEmplacement(static_cast<Deplacement*>(emplacement), m_emplacements, m_parent);
            break;
            
        case Type::ParcGratuit:
            fenetre = new EditionEmplacement(static_cast<ParcGratuit*>(emplacement), m_parent);
            break;
            
        case Type::Pioche:
            fenetre = new EditionEmplacement(static_cast<Pioche*>(emplacement), m_pilesCartes, m_parent);
            break;
            
        case Type::Prison:
            fenetre = new EditionEmplacement(static_cast<Prison*>(emplacement), m_parent);
            break;
            
        case Type::Service:
            fenetre = new EditionEmplacement(static_cast<Service*>(emplacement), m_services.count(), m_parent);
            break;
            
        case Type::SimpleVisite:
            fenetre = new EditionEmplacement(static_cast<SimpleVisite*>(emplacement), m_parent);
            break;
            
        case Type::Taxe:
            fenetre = new EditionEmplacement(static_cast<Taxe*>(emplacement), m_parent);
            break;
            
        case Type::Terrain:
            fenetre = new EditionEmplacement(static_cast<Terrain*>(emplacement), m_parent);
            break;
            
        default:
            break;
    }
    
    fenetre->executer();
    
    delete fenetre;
}





void Plateau::editEmplacementType(Emplacement* emplacement)
{
    if (emplacement->getType() == Type::Depart)
    {
        QMessageBox::information(m_parent, tr("Erreur"), tr("Vous ne pouvez pas changer le type de l'emplacement « Départ ». Vous pouvez cependant l'intervertir avec un autre emplacement."));
    }
    else if (emplacement->getType() == Type::Prison)
    {
        QMessageBox::information(m_parent, tr("Erreur"), tr("Vous ne pouvez pas changer le type de la prison. Pour changer la prison d'endroit, associez-la avec un autre emplacement « Simple visite ». Vous devez donc créer au préalable un nouvel emplacement « Simple visite » qui accueillera la prison."));
    }
    else if (static_cast<Prison*>(m_emplacements.first())->getEmplacementAssocie() == emplacement)
    {
        QMessageBox::information(m_parent, tr("Erreur"), tr("Impossible de changer le type de cet emplacement car la prison lui est associé. Créez d'abord un nouvel emplacement « Simple visite » puis associez ce dernier à la prison (fenêtre d'édition de la prison). Vous pourrez ensuite changer le type de cet emplacement."));
    }
    else
    {
        QDialog* dialog = new QDialog(m_parent);
        
        QDialogButtonBox* boutons(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel));
        QObject::connect(boutons, SIGNAL(accepted()), dialog, SLOT(accept()));
        QObject::connect(boutons, SIGNAL(rejected()), dialog, SLOT(reject()));
        
        QVBoxLayout* layout(new QVBoxLayout);
        TypeEmplacementEditWidget* widgetEdition(new TypeEmplacementEditWidget(emplacement));
        layout->addWidget(widgetEdition);
        layout->addWidget(boutons);
        
        dialog->setLayout(layout);
        
        if (dialog->exec())
        {
            changeTypeEmplacement(emplacement, widgetEdition->getTypeEmplacement());
        }
        
        delete dialog;
    }
}





void Plateau::changeTypeEmplacement(Emplacement* emplacement,
                                    Type::Emplacement nouveauType)
{
    Type::Emplacement ancienType(emplacement->getType());
    
    if (ancienType != nouveauType)
    {
        /* Suppression de l'emplacement des racourcis.
         */
        if (ancienType == Type::CompagnieTransport)
        {
            m_compagniesTransport.removeOne(static_cast<CompagnieTransport*>(emplacement));
            
            // On notifie à toutes les compagnies le nombre total de compagnies sur le plateau.
            for (int i(0), iEnd(m_compagniesTransport.count()); i < iEnd; i++)
            {
                m_compagniesTransport.at(i)->setupNombreCompagnies(iEnd);
            }
        }
        else if (ancienType == Type::Service)
        {
            m_services.removeOne(static_cast<Service*>(emplacement));
            
            // On notifie à toutes les services le nombre total de services sur le plateau.
            for (int i(0), iEnd(m_services.count()); i < iEnd; i++)
            {
                m_services.at(i)->setupNombreServices(iEnd);
            }
        }
        
        
        Emplacement* nouvelEmplacement;
        
        /* Création et configurations spécifiques de l'emplacement (si on change juste de type de propriété).
         */
        switch (nouveauType)
        {
            case Type::CompagnieTransport:
                {
                    CompagnieTransport* compagnie(new CompagnieTransport(m_graphismeEmplacement, m_devise));
                    
                    /* Si l'ancien emplacement était une propriété (service ou terrain), alors on garde les parix achat et
                     * la valeur de l'hypothèque.
                     */
                    if (emplacement->getType() == Type::Service || emplacement->getType() == Type::Terrain)
                    {
                        compagnie->editPrixAchat(static_cast<Propriete*>(emplacement)->getPrixAchat());
                        compagnie->editValeurHypotheque(static_cast<Propriete*>(emplacement)->getValeurHypotheque());
                    }
                    
                    m_compagniesTransport << compagnie;
                    nouvelEmplacement = compagnie;
                    
                    // On notifie à toutes les compagnies le nombre total de compagnies sur le plateau.
                    for (int i(0), iEnd(m_compagniesTransport.count()); i < iEnd; i++)
                    {
                        m_compagniesTransport.at(i)->setupNombreCompagnies(iEnd);
                    }
                }
                break;
                
            case Type::Deplacement:
                nouvelEmplacement = new Deplacement(m_graphismeEmplacement, m_devise);
                break;
                
            case Type::ParcGratuit:
                nouvelEmplacement = new ParcGratuit(m_graphismeEmplacement);
                break;
                
            case Type::Pioche:
                nouvelEmplacement = new Pioche(m_graphismeEmplacement);
                break;
                
            case Type::Service:
                {
                    Service* service(new Service(m_graphismeEmplacement, m_devise));
                    
                    /* Si l'ancien emplacement était une propriété (compagnie ou terrain), alors on garde les parix achat et
                     * la valeur de l'hypothèque.
                     */
                    if (emplacement->getType() == Type::CompagnieTransport || emplacement->getType() == Type::Terrain)
                    {
                        service->editPrixAchat(static_cast<Propriete*>(emplacement)->getPrixAchat());
                        service->editValeurHypotheque(static_cast<Propriete*>(emplacement)->getValeurHypotheque());
                    }
                    
                    m_services << service;
                    nouvelEmplacement = service;
                    
                    // On notifie à toutes les services le nombre total de services sur le plateau.
                    for (int i(0), iEnd(m_services.count()); i < iEnd; i++)
                    {
                        m_services.at(i)->setupNombreServices(iEnd);
                    }
                }
                break;
                
            case Type::SimpleVisite:
                nouvelEmplacement = new SimpleVisite(m_graphismeEmplacement);
                break;
                
            case Type::Taxe:
                nouvelEmplacement = new Taxe(m_graphismeEmplacement, m_devise);
                break;
                
            case Type::Terrain:
                {
                    Terrain* terrain(new Terrain(m_graphismeEmplacement, m_devise));
                    
                    /* Si l'ancien emplacement était une propriété (compagnie ou service), alors on garde les parix achat et
                     * la valeur de l'hypothèque.
                     */
                    if (emplacement->getType() == Type::CompagnieTransport || emplacement->getType() == Type::Service)
                    {
                        terrain->editPrixAchat(static_cast<Propriete*>(emplacement)->getPrixAchat());
                        terrain->editValeurHypotheque(static_cast<Propriete*>(emplacement)->getValeurHypotheque());
                    }
                    
                    nouvelEmplacement = terrain;
                }
                break;
                
            default:
                QMessageBox::information(m_parent, tr("Erreur"), tr("Erreur lors du changement de type de l'emplacement. Cette conversion est interdite."));
        }
        
        
        
        /* Configurations générales de l'emplacement.
         */
        nouvelEmplacement->editTitre(emplacement->getTitre());
        nouvelEmplacement->editSousTitre(emplacement->getSousTitre());
        nouvelEmplacement->editDescription(emplacement->getDescription());
        nouvelEmplacement->editImage(emplacement->getImage());
        
        
        
        /* Recherche d'éventuels emplacements « Déplacement » qui pointaient vers l'ancien emplacement.
         */
        for (int i(0), iEnd(m_emplacements.count()); i < iEnd; i++)
        {
            if (m_emplacements.at(i)->getType() == Type::Deplacement)
            {
                Deplacement* deplacement(static_cast<Deplacement*>(m_emplacements.at(i)));
                
                if (deplacement->getDestination() == emplacement)
                {
                    deplacement->editDestination(nouvelEmplacement);
                }
            }
        }
        
        
        
        /* Recherche d'éventuelles cartes qui pointaient vers l'ancien emplacement.
         */
        for (int i(0), iEnd(m_pilesCartes.count()); i < iEnd; i++)
        {
            PileCartes* pileCartes(m_pilesCartes.at(i));
            for (int j(0), jEnd(pileCartes->getNombreCartes()); j < jEnd; j++)
            {
                Action& action(pileCartes->getCarteAt(j)->getAction());
                
                if (action.getEmplacement() == emplacement)
                {
                    action.setEmplacement(nouvelEmplacement);
                }
            }
        }
        
        
        
        /* Remplacement de l'emplacement.
         */
        int rang(m_emplacements.indexOf(emplacement));
        m_emplacements[rang] = nouvelEmplacement;
        delete emplacement;
        
        
        
        /* Dessein de l'emplacement.
         */
        nouvelEmplacement->setupElementGraphique(helper_getPositionEmplacement(rang), helper_getRotationEmplacement(rang), this);
        GraphismeEmplacement* elementGraphique(nouvelEmplacement->dessiner());
        connect(elementGraphique, SIGNAL(editEmplacement(Emplacement*)), this, SLOT(editEmplacement(Emplacement*)));
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

