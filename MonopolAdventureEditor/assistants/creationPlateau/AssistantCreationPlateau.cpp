#include "AssistantCreationPlateau.hpp"

#include "assistants/creationPlateau/PageGraphisme.hpp"
#include "assistants/creationPlateau/PageImage.hpp"
#include "assistants/creationPlateau/PageIntro.hpp"
#include "assistants/creationPlateau/PageOuvrir.hpp"
#include "assistants/creationPlateau/PagePrix.hpp"
#include "assistants/creationPlateau/PageTaille.hpp"





AssistantCreationPlateau::AssistantCreationPlateau(Plateau* plateau) :
    m_plateau(plateau)
{
    /* Configuration de la fenêtre
     */
    setWindowTitle(tr("Assistant de création de plateau"));
    setMinimumSize(800, 450);
    setAttribute(Qt::WA_DeleteOnClose);
    
    
    
    /* Configuration des pages
     */
    setPage(1, new PageIntro);
    setPage(2, new PageTaille);
    setPage(3, new PagePrix);
    setPage(4, new PageImage);
    setPage(5, new PageGraphisme);
    setPage(6, new PageOuvrir);
}





void AssistantCreationPlateau::accept()
{
    if (field("nouveau").toBool())
    {
        m_plateau->editTitre(field("titre_plateau").toString());
        m_plateau->editDevise(field("devise_plateau").toString());
        m_plateau->editCoefficientPrix(field("coefficient_prix").toInt());
        m_plateau->editAffichageIntegrale(field("affichage_complet_prix").toBool());
        m_plateau->editCouleurFond(field("couleur_plateau").value<QColor>());
        m_plateau->editImage(field("image_plateau").value<QPixmap>());
        m_plateau->editTailleEmplacements(QSize(field("largeur_emplacement").toInt(), field("hauteur_emplacement").toInt()));
        m_plateau->editHauteurRectangleCouleur(field("hauteur_regroupement").toInt());
        m_plateau->editCrayonBordureEmplacement(QPen(QBrush(field("couleur_bordure").value<QColor>()), field("epaisseur_bordure").toInt()));
        m_plateau->editMarge(field("marge").toInt());
        m_plateau->editCouleurFondEmplacement(field("couleur_emplacement").value<QColor>());
        m_plateau->editFonteTitreEmplacement(field("police_titre_emplacement").value<QFont>());
        m_plateau->editFonteSousTitreEmplacement(field("police_sousTitre_emplacement").value<QFont>());
        m_plateau->editFonteDescriptionEmplacement(field("police_description_emplacement").value<QFont>());
        m_plateau->editFontePrixEmplacement(field("police_prix_emplacement").value<QFont>());
        
        /* La configuration de la taille du plateau doit être faite en dernière car le plateau à besoin des informations
         * concernant la taille des emplacements.
         */
        m_plateau->editTaille(QSize(field("largeur_plateau").toInt(), field("hauteur_plateau").toInt()));
    }
    else
    {
        /** @todo ICI : Charger le plateau depuis un fichier .map. */
    }
    
    m_plateau->dessiner();
    
    QWizard::accept();
}

