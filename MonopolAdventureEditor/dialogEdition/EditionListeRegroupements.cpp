#include "EditionListeRegroupements.hpp"





EditionListeRegroupements::EditionListeRegroupements(QList<Regroupement*>& regroupements,
                                                     QWidget* parent) :
    m_dialog(new QDialog(parent)),
    m_listeOriginale(regroupements),
    m_listeEditable()
{
    /* Création de la liste éditable.
     */
    for (int i(0), iEnd(m_listeOriginale.count()); i < iEnd; ++i)
    {
        m_listeEditable << new RegroupementData(m_listeOriginale.at(i));
    }
    
    
    
    /* Création du widget d'édition.
     */
    m_widgetEditionListeRegroupements = new ListeRegroupementEditWidget(m_listeEditable);
    
    
    
    /* Aménagement de la fenêtre de dialogue.
     */
    m_dialog->setAttribute(Qt::WA_DeleteOnClose);
    
    QDialogButtonBox* boutons(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel));
    QObject::connect(boutons, SIGNAL(accepted()), m_dialog, SLOT(accept()));
    QObject::connect(boutons, SIGNAL(rejected()), m_dialog, SLOT(reject()));
    
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_widgetEditionListeRegroupements);
    layout->addWidget(boutons);
    
    m_dialog->setLayout(layout);
}





EditionListeRegroupements::~EditionListeRegroupements()
{
    // Destruction des regroupementData.
    for (int i(0), iEnd(m_listeEditable.count()); i < iEnd; ++i)
    {
        delete m_listeEditable.takeLast();
    }
}





bool EditionListeRegroupements::executer()
{
    /* Execution de la fenêtre.
     */
    if (m_dialog->exec())
    {
        /* Sauvegarde des données.
         * 
         * NOTE : Pour modifier la liste des terrains, on va déplacer les terrains d'un regroupements à un autre. Comme
         *        aucun terrain ne peut rester sans regroupement, il nous suffit de déplacer vers un regroupement tous
         *        les terrains qui lui ont été ajoutés. Les terrains en trop seront retirés lors de leur ajout dans un
         *        autre regroupement.
         * 
         * On récupère d'abord la taille de la plus petite liste. Cela nous permet de mettre à jour les regroupements
         * qui n'ont été ni ajoutés, ni supprimés.
         */
        int taille(m_listeOriginale.count());
        if (m_listeEditable.count() < m_listeOriginale.count())
        {
            taille = m_listeEditable.count();
        }
        
        for (int i(0); i < taille; ++i)
        {
            Regroupement* regroupement(m_listeOriginale.at(i));
            RegroupementData* regroupementEdite(m_listeEditable.at(i));
            
            // Modification du titre et de la couleur.
            regroupement->editTitre(regroupementEdite->getTitre());
            regroupement->editCouleur(regroupementEdite->getCouleur());
            
            // Modifier la liste des terrains.
            for (int j(0), jEnd(regroupementEdite->getListeTerrains().count()); j < jEnd; ++j)
            {
                regroupementEdite->getListeTerrains().at(j)->getTerrain()->editRegroupement(regroupement);
                /* NOTE : La méthode Terrain::editRegroupement() vérifie si le regroupement est différent avant
                 *        d'effectuer des modifications. Si le terrain appartient déjà au regroupement, il n'y aura
                 *        aucune opération réalisée.
                 */
            }
        }
        
        
        
        /* Si c'est la liste éditable qui contient plus de regroupements, on va donc devoir en créer. On repart depuis
         * la taille où l'on s'était arrêté précédemment.
         */
        if (m_listeOriginale.count() < m_listeEditable.count())
        {
            for (int i(taille), iEnd(m_listeEditable.count()); i < iEnd; ++i)
            {
                Regroupement* regroupement(new Regroupement);
                RegroupementData* regroupementEdite(m_listeEditable.at(i));
                
                // Configuration du titre et de la couleur.
                regroupement->editTitre(regroupementEdite->getTitre());
                regroupement->editCouleur(regroupementEdite->getCouleur());
                
                // Configuration de la liste des terrains.
                for (int j(0), jEnd(regroupementEdite->getListeTerrains().count()); j < jEnd; ++j)
                {
                    regroupementEdite->getListeTerrains().at(j)->getTerrain()->editRegroupement(regroupement);
                }
                
                // Ajout du regroupement dans la liste.
                m_listeOriginale.append(regroupement);
            }
        }
        else if (m_listeOriginale.count() > m_listeEditable.count())
        {
            /* Ici, on peut supprimer les regroupements car tous les terrains ont été déplacés auparavant.
             */
            for (int i(taille), iEnd(m_listeOriginale.count()); i < iEnd; ++i)
            {
                delete m_listeOriginale.takeLast();
            }
        }
        
        
        return true;
    }
    else
    {
        return false;
    }
}

