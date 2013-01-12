#include "ActionEditWidget.hpp"

#include "donnees/cartes/PileCartes.hpp"





ActionEditWidget::ActionEditWidget(Action* action,
                                   const QList<Emplacement*>& emplacements,
                                   const QList<PileCartes*>& pilesCartes) :
    QScrollArea(),
    m_action(action),
    m_slotsInactifs(false),
    m_emplacements(emplacements),
    m_pilesCartes(pilesCartes),
    m_groupeDeplacement(new QGroupBox(tr("Déplacement absolu"))),
    m_radioAvance(new QRadioButton(tr("en avançant"))),
    m_radioRecule(new QRadioButton(tr("en reculant"))),
    m_groupeRadioDeplacement(new QButtonGroup),
    m_emplacement(new PointerComboBox<Emplacement>),
    
    m_groupeDeplacementRelatif(new QGroupBox(tr("Déplacement relatif"))),
    m_radioAvanceRelatif(new QRadioButton(tr("en avançant"))),
    m_radioReculeRelatif(new QRadioButton(tr("en reculant"))),
    m_groupeRadioDeplacementRelatif(new QButtonGroup),
    m_nombreEmplacements(new QSpinBox),
    
    m_groupeDeplacementAuProchain(new QGroupBox(tr("Déplacement au type d'emplacement le proche"))),
    m_radioAvanceAuProchain(new QRadioButton(tr("en avançant"))),
    m_radioReculeAuProchain(new QRadioButton(tr("en reculant"))),
    m_groupeRadioDeplacementAuProchain(new QButtonGroup),
    m_typeEmplacement(new QComboBox),
    
    //m_labelNombreEmplacements(new QLabel(tr("Nombre d'emplacements"))),
    m_groupeTransaction(new QGroupBox(tr("Mouvement d'argent"))),
    m_radioGagne(new QRadioButton(tr("créditer"))),
    m_radioPerd(new QRadioButton(tr("débiter"))),
    m_groupeRadioArgent(new QButtonGroup),
    m_montant(new QSpinBox),
    m_destinataire(new QComboBox),
    m_groupeReparation(new QGroupBox(tr("Réparation des constructions"))),
    m_montantParMaison(new QSpinBox),
    m_montantParHotel(new QSpinBox),
    m_groupePayeOuPioche(new QGroupBox(tr("Paye une amende ou pioche une autre carte"))),
    m_amende(new QSpinBox),
    m_pileCartesPayeOuPioche(new PointerComboBox<PileCartes>),
    m_groupePioche(new QGroupBox(tr("Pioche une carte"))),
    m_pileCartesPioche(new PointerComboBox<PileCartes>),
    m_groupeLiberePrison(new QGroupBox(tr("Libéré de prison")))
{
    /* Configuration générale des entrées
     */
    // Groupe Déplacement absolu
    m_groupeDeplacement->setCheckable(true);
    
    m_groupeRadioDeplacement->addButton(m_radioAvance);
    m_groupeRadioDeplacement->addButton(m_radioRecule);
    QVBoxLayout* layoutRadioDeplacement(new QVBoxLayout);
    layoutRadioDeplacement->addWidget(m_radioAvance);
    layoutRadioDeplacement->addWidget(m_radioRecule);
    
    for (int i(0), iEnd(m_emplacements.count()); i < iEnd; ++i)
    {
        Emplacement* emplacement(m_emplacements.at(i));
        m_emplacement->addItem(QString::number(i) + ". " + emplacement->getTitre(), emplacement);
    }
    
    if (m_action->isDeplacementAbsolu())
    {
        m_groupeDeplacement->setChecked(true);
        m_radioAvance->setChecked(m_action->joueurAvance());
        m_radioRecule->setChecked(m_action->joueurRecule());
        m_emplacement->setCurrentIndex(m_action->getEmplacement());
    }
    else
    {
        helper_resetGroupeDeplacement();
    }
    
    
    
    // Groupe Déplacement relatif
    m_groupeDeplacementRelatif->setCheckable(true);
    
    m_groupeRadioDeplacementRelatif->addButton(m_radioAvanceRelatif);
    m_groupeRadioDeplacementRelatif->addButton(m_radioReculeRelatif);
    QVBoxLayout* layoutRadioDeplacementRelatif(new QVBoxLayout);
    layoutRadioDeplacementRelatif->addWidget(m_radioAvanceRelatif);
    layoutRadioDeplacementRelatif->addWidget(m_radioReculeRelatif);
    
    m_nombreEmplacements->setMinimum(1);
    
    QHBoxLayout* layoutNombreEmplacements(new QHBoxLayout);
    layoutNombreEmplacements->addWidget(m_nombreEmplacements);
    layoutNombreEmplacements->addWidget(new QLabel(tr("emplacements")));
    
    if (m_action->isDeplacementRelatif())
    {
        m_groupeDeplacementRelatif->setChecked(true);
        m_radioAvanceRelatif->setChecked(m_action->joueurAvance());
        m_radioReculeRelatif->setChecked(m_action->joueurRecule());
        m_nombreEmplacements->setValue(m_action->getNombreEmplacements());
    }
    else
    {
        helper_resetGroupeDeplacementRelatif();
    }
    
    
    
    // Groupe Déplacement jusqu'au prochain type d'emplacement
    m_groupeDeplacementAuProchain->setCheckable(true);
    
    m_groupeRadioDeplacementAuProchain->addButton(m_radioAvanceAuProchain);
    m_groupeRadioDeplacementAuProchain->addButton(m_radioReculeAuProchain);
    QVBoxLayout* layoutRadioDeplacementAuProchain(new QVBoxLayout);
    layoutRadioDeplacementAuProchain->addWidget(m_radioAvanceAuProchain);
    layoutRadioDeplacementAuProchain->addWidget(m_radioReculeAuProchain);
    
    m_typeEmplacement->insertItem(Type::CompagnieTransport, tr("Compagnie de transport"));
    m_typeEmplacement->insertItem(Type::Deplacement, tr("Emplacement de type « Déplacement »"));
    m_typeEmplacement->insertItem(Type::ParcGratuit, tr("Parc gratuit"));
    m_typeEmplacement->insertItem(Type::Pioche, tr("Emplacement de type « Pioche »"));
    m_typeEmplacement->insertItem(Type::Service, tr("Service"));
    m_typeEmplacement->insertItem(Type::SimpleVisite, tr("Emplacement de type « Simple visite »"));
    m_typeEmplacement->insertItem(Type::Taxe, tr("Emplacement de type « Taxe »"));
    m_typeEmplacement->insertItem(Type::Terrain, tr("Terrain"));
    
    if (m_action->isDeplacementJusquauProchain())
    {
        m_groupeDeplacementAuProchain->setChecked(true);
        m_radioAvanceAuProchain->setChecked(m_action->joueurAvance());
        m_radioReculeAuProchain->setChecked(m_action->joueurRecule());
        m_typeEmplacement->setCurrentIndex(m_action->deplacementJusquauProchain());
    }
    else
    {
        helper_resetGroupeDeplacementAuProchain();
    }
    
    
    
    // Groupe Mouvement d'argent
    m_groupeTransaction->setCheckable(true);
    
    m_groupeRadioArgent->addButton(m_radioGagne);
    m_groupeRadioArgent->addButton(m_radioPerd);
    QVBoxLayout* layoutRadioArgent(new QVBoxLayout);
    layoutRadioArgent->addWidget(m_radioGagne);
    layoutRadioArgent->addWidget(m_radioPerd);
    
    m_montant->setSingleStep(10);
    m_montant->setMaximum(MONTANT_MAX_EDITEUR);
    
    m_destinataire->addItem(tr("d'un autre joueur"));
    m_destinataire->addItem(tr("de la banque"));
    m_destinataire->addItem(tr("de tous les autres joueurs"));
    
    if (m_action->isTransaction())
    {
        m_groupeTransaction->setChecked(true);
        m_radioGagne->setChecked(m_action->joueurGagneArgent());
        m_radioPerd->setChecked(m_action->joueurPerdArgent());
        m_montant->setValue(m_action->getMontantTransaction());
        
        if (m_action->isTransactionAvecAutreJoueur())
        {
            m_destinataire->setCurrentIndex(0);
        }
        else if (m_action->isTransactionAvecBanque())
        {
            m_destinataire->setCurrentIndex(1);
        }
        else if (m_action->isTransactionAvecTousLesJoueurs())
        {
            m_destinataire->setCurrentIndex(2);
        }
    }
    else
    {
        helper_resetGroupeTransaction();
    }
    
    
    
    // Groupe Réparation des constructions
    m_groupeReparation->setCheckable(true);
    
    m_montantParMaison->setSingleStep(5);
    m_montantParMaison->setMaximum(MONTANT_MAX_EDITEUR);
    
    m_montantParHotel->setSingleStep(5);
    m_montantParHotel->setMaximum(MONTANT_MAX_EDITEUR);
    
    if (m_action->isReparationConstructions())
    {
        m_groupeReparation->setChecked(true);
        m_montantParMaison->setValue(m_action->getMontantParMaison());
        m_montantParHotel->setValue(m_action->getMontantParHotel());
    }
    else
    {
        helper_resetGroupeReparation();
    }
    
    
    
    // Groupe Paye ou Pioche
    m_groupePayeOuPioche->setCheckable(true);
    
    m_amende->setSingleStep(5);
    m_amende->setMaximum(MONTANT_MAX_EDITEUR);
    
    for (int i(0), iEnd(m_pilesCartes.count()); i < iEnd; ++i)// Mise à jour des deux listes de piles de cartes.
    {
        PileCartes* pileCartes(m_pilesCartes.at(i));
        QString texte(QString::number(i) + ". " + pileCartes->getTitre());
        
        m_pileCartesPayeOuPioche->addItem(texte, pileCartes);
        m_pileCartesPioche->addItem(texte, pileCartes);
    }
    
    if (m_action->isPayeOuPioche())
    {
        m_groupePayeOuPioche->setChecked(true);
        m_amende->setValue(m_action->getAmende());
        m_pileCartesPayeOuPioche->setCurrentIndex(m_action->getPileCartes());
    }
    else
    {
        helper_resetGroupePayeOuPioche();
    }
    
    
    
    // Groupe Pioche
    m_groupePioche->setCheckable(true);
    
    if (m_action->isPioche())
    {
        m_groupePioche->setChecked(true);
        m_pileCartesPioche->setCurrentIndex(m_action->getPileCartes());
    }
    else
    {
        helper_resetGroupePioche();
    }
    
    
    
    // Groupe Libéré de prison
    m_groupeLiberePrison->setCheckable(true);
    
    helper_resetGroupeLibereDePrison();
    
    
    
    /* Mise en forme
     */
    QFormLayout* layoutDeplacement(new QFormLayout);
    QLabel* consigne(new QLabel(tr("Le joueur doit se déplacer en avançant ou en reculant sur un emplacement précis.")));
    consigne->setWordWrap(true);
    consigne->setAlignment(Qt::AlignJustify);
    layoutDeplacement->addRow(consigne);
    layoutDeplacement->addRow(tr("Le joueur se déplace"), layoutRadioDeplacement);
    layoutDeplacement->addRow(tr("Se déplacer sur"), m_emplacement);
    m_groupeDeplacement->setLayout(layoutDeplacement);
    
    QFormLayout* layoutDeplacementRelatif(new QFormLayout);
    consigne = new QLabel(tr("Le joueur doit se déplacer en avançant ou en reculant d'un certain nombre d'emplacements par rapport à sa position actuelle."));
    consigne->setWordWrap(true);
    consigne->setAlignment(Qt::AlignJustify);
    layoutDeplacementRelatif->addRow(consigne);
    layoutDeplacementRelatif->addRow(tr("Le joueur se déplace"), layoutRadioDeplacementRelatif);
    layoutDeplacementRelatif->addRow(tr("Se déplacer de"), layoutNombreEmplacements);
    m_groupeDeplacementRelatif->setLayout(layoutDeplacementRelatif);
    
    QFormLayout* layoutDeplacementAuProchain(new QFormLayout);
    consigne = new QLabel(tr("Le joueur doit se déplacer en avançant ou en reculant jusqu'au premier emplacement d'un type précis."));
    consigne->setWordWrap(true);
    consigne->setAlignment(Qt::AlignJustify);
    layoutDeplacementAuProchain->addRow(consigne);
    layoutDeplacementAuProchain->addRow(tr("Le joueur se déplace"), layoutRadioDeplacementAuProchain);
    layoutDeplacementAuProchain->addRow(tr("Se déplacer au prochain"), m_typeEmplacement);
    m_groupeDeplacementAuProchain->setLayout(layoutDeplacementAuProchain);
    
    QFormLayout* layoutArgent(new QFormLayout);
    consigne = new QLabel(tr("Un mouvement d'argent s'effectue entre le joueur et le (ou les) destinatare(s). S'il y a plusieurs destinataires, il s'effectue autant de transaction que de destinataire. Le joueur doit donc verser (ou recevoir) en tout : le montant indiqué × nombre de destinataire."));
    consigne->setWordWrap(true);
    consigne->setAlignment(Qt::AlignJustify);
    layoutArgent->addRow(consigne);
    layoutArgent->addRow(tr("Le compte du joueur est"), layoutRadioArgent);
    layoutArgent->addRow(tr("Montant de la transaction"), m_montant);
    layoutArgent->addRow(tr("La transaction s'effectue auprès"), m_destinataire);
    m_groupeTransaction->setLayout(layoutArgent);
    
    QFormLayout* layoutReparation(new QFormLayout);
    consigne = new QLabel(tr("Le joueur est imposé de réparer l'intégralité de ses construction. Un prix de réparation est fixé pour chaque maison et pour chaque hôtel"));
    consigne->setWordWrap(true);
    consigne->setAlignment(Qt::AlignJustify);
    layoutReparation->addRow(consigne);
    layoutReparation->addRow(tr("Montant des réparations pour chaque maison construite"), m_montantParMaison);
    layoutReparation->addRow(tr("Montant des réparations pour chaque hôtel construit"), m_montantParHotel);
    m_groupeReparation->setLayout(layoutReparation);
    
    QFormLayout* layoutPayeOuPioche(new QFormLayout);
    consigne = new QLabel(tr("Le joueur a le choix entre payer une amende ou bien piocher un nouvelle carte."));
    consigne->setWordWrap(true);
    consigne->setAlignment(Qt::AlignJustify);
    layoutPayeOuPioche->addRow(consigne);
    layoutPayeOuPioche->addRow(tr("Montant de l'amende à payer"), m_amende);
    layoutPayeOuPioche->addRow(tr("Piocher une nouvelle carte de la pile"), m_pileCartesPayeOuPioche);
    m_groupePayeOuPioche->setLayout(layoutPayeOuPioche);
    
    QFormLayout* layoutPioche(new QFormLayout);
    consigne = new QLabel(tr("Le joueur pioche une carte."));
    consigne->setWordWrap(true);
    consigne->setAlignment(Qt::AlignJustify);
    layoutPioche->addRow(consigne);
    layoutPioche->addRow(tr("Piocher dans la pile"), m_pileCartesPioche);
    m_groupePioche->setLayout(layoutPioche);
    
    QVBoxLayout* layoutLiberePrison(new QVBoxLayout);
    consigne = new QLabel(tr("Le joueur peut donner cette carte pour sortir de prison gratuitement. Le joueur conserve cette carte jusqu'à utilisation ou bien échange. Lorsqu'elle est utilisée, elle est remise dans la pile de cartes."));
    consigne->setWordWrap(true);
    consigne->setAlignment(Qt::AlignJustify);
    layoutLiberePrison->addWidget(consigne);
    m_groupeLiberePrison->setLayout(layoutLiberePrison);
    
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_groupeDeplacement);
    layout->addWidget(m_groupeDeplacementRelatif);
    layout->addWidget(m_groupeDeplacementAuProchain);
    layout->addWidget(m_groupeTransaction);
    layout->addWidget(m_groupeReparation);
    layout->addWidget(m_groupePayeOuPioche);
    layout->addWidget(m_groupePioche);
    layout->addWidget(m_groupeLiberePrison);
    
    QWidget* widgetCentral(new QWidget);
    widgetCentral->setLayout(layout);
    setWidget(widgetCentral);
    setWidgetResizable(true);
    setMinimumWidth(widgetCentral->minimumSizeHint().width() + verticalScrollBar()->size().width());
    
    
    
    /* Connexion des entrées à leur slot respectifs
     */
    connect(m_groupeDeplacement, SIGNAL(clicked(bool)), this, SLOT(groupeDeplacement_clicked(bool)));
    connect(m_groupeDeplacementRelatif, SIGNAL(clicked(bool)), this, SLOT(groupeDeplacementRelatif_clicked(bool)));
    connect(m_groupeDeplacementAuProchain, SIGNAL(clicked(bool)), this, SLOT(groupeDeplacementAuProchain_clicked(bool)));
    connect(m_groupeTransaction, SIGNAL(clicked(bool)), this, SLOT(groupeTransaction_clicked(bool)));
    connect(m_groupeReparation, SIGNAL(clicked(bool)), this, SLOT(groupeReparation_clicked(bool)));
    connect(m_groupePayeOuPioche, SIGNAL(clicked(bool)), this, SLOT(groupePayeOuPioche_clicked(bool)));
    connect(m_groupePioche, SIGNAL(clicked(bool)), this, SLOT(groupePioche_clicked(bool)));
    connect(m_groupeLiberePrison, SIGNAL(clicked(bool)), this, SLOT(groupeLibereDePrison_clicked(bool)));
}





void ActionEditWidget::sauvegarde()
{
    if (m_groupeDeplacement->isChecked())
    {
        m_action->setDeplacement(m_radioAvance->isChecked(),
                                 m_emplacement->getCurrentPointeur());
    }
    else if (m_groupeDeplacementRelatif->isChecked())
    {
        m_action->setDeplacement(m_radioAvanceRelatif->isChecked(),
                                 m_nombreEmplacements->value());
    }
    else if (m_groupeDeplacementAuProchain->isChecked())
    {
        m_action->setDeplacementJusquauProchain(m_radioAvanceAuProchain->isChecked(),
                                                (Type::Emplacement) m_typeEmplacement->currentIndex());
    }
    else if (m_groupeTransaction->isChecked())
    {
        if (m_destinataire->currentIndex() == 0)
        {
            m_action->setTransactionAvecAutreJoueur(m_radioGagne->isChecked(), m_montant->value());
        }
        else if (m_destinataire->currentIndex() == 1)
        {
            m_action->setTransactionAvecBanque(m_radioGagne->isChecked(), m_montant->value());
        }
        else if (m_destinataire->currentIndex() == 2)
        {
            m_action->setTransactionAvecTousLesJoueurs(m_radioGagne->isChecked(), m_montant->value());
        }
    }
    else if (m_groupeReparation->isChecked())
    {
        m_action->setReparationConstructions(m_montantParMaison->value(),
                                             m_montantParHotel->value());
    }
    else if (m_groupePayeOuPioche->isChecked())
    {
        m_action->setPayeOuPioche(m_amende->value(), m_pileCartesPayeOuPioche->getCurrentPointeur());
    }
    else if (m_groupePioche->isChecked())
    {
        m_action->setPioche(m_pileCartesPioche->getCurrentPointeur());
    }
    else if (m_groupeLiberePrison->isChecked())
    {
        m_action->setLibereDePrison();
    }
}





void ActionEditWidget::groupeDeplacement_clicked(bool checked)
{
    if (!m_slotsInactifs)
    {
        m_slotsInactifs = true;
        
        if (checked)
        {
            helper_resetGroupeDeplacementRelatif();
            helper_resetGroupeDeplacementAuProchain();
            helper_resetGroupeTransaction();
            helper_resetGroupeReparation();
            helper_resetGroupePayeOuPioche();
            helper_resetGroupePioche();
            helper_resetGroupeLibereDePrison();
        }
        else
        {
            // Il ne peut pas y avoir aucun groupe de sélectionné
            m_groupeDeplacement->setChecked(true);
        }
        
        m_slotsInactifs = false;
    }
}





void ActionEditWidget::groupeDeplacementRelatif_clicked(bool checked)
{
    if (!m_slotsInactifs)
    {
        m_slotsInactifs = true;
        
        if (checked)
        {
            helper_resetGroupeDeplacement();
            helper_resetGroupeDeplacementAuProchain();
            helper_resetGroupeTransaction();
            helper_resetGroupeReparation();
            helper_resetGroupePayeOuPioche();
            helper_resetGroupePioche();
            helper_resetGroupeLibereDePrison();
        }
        else
        {
            // Il ne peut pas y avoir aucun groupe de sélectionné
            m_groupeDeplacementRelatif->setChecked(true);
        }
        
        m_slotsInactifs = false;
    }
}





void ActionEditWidget::groupeDeplacementAuProchain_clicked(bool checked)
{
    if (!m_slotsInactifs)
    {
        m_slotsInactifs = true;
        
        if (checked)
        {
            helper_resetGroupeDeplacement();
            helper_resetGroupeDeplacementRelatif();
            helper_resetGroupeTransaction();
            helper_resetGroupeReparation();
            helper_resetGroupePayeOuPioche();
            helper_resetGroupePioche();
            helper_resetGroupeLibereDePrison();
        }
        else
        {
            // Il ne peut pas y avoir aucun groupe de sélectionné
            m_groupeDeplacementAuProchain->setChecked(true);
        }
        
        m_slotsInactifs = false;
    }
}





void ActionEditWidget::groupeTransaction_clicked(bool checked)
{
    if (!m_slotsInactifs)
    {
        m_slotsInactifs = true;
        
        if (checked)
        {
            helper_resetGroupeDeplacement();
            helper_resetGroupeDeplacementRelatif();
            helper_resetGroupeDeplacementAuProchain();
            helper_resetGroupeReparation();
            helper_resetGroupePayeOuPioche();
            helper_resetGroupePioche();
            helper_resetGroupeLibereDePrison();
        }
        else
        {
            // Il ne peut pas y avoir aucun groupe de sélectionné
            m_groupeTransaction->setChecked(true);
        }
        
        m_slotsInactifs = false;
    }
}





void ActionEditWidget::groupeReparation_clicked(bool checked)
{
    if (!m_slotsInactifs)
    {
        m_slotsInactifs = true;
        
        if (checked)
        {
            helper_resetGroupeDeplacement();
            helper_resetGroupeDeplacementRelatif();
            helper_resetGroupeDeplacementAuProchain();
            helper_resetGroupeTransaction();
            helper_resetGroupePayeOuPioche();
            helper_resetGroupePioche();
            helper_resetGroupeLibereDePrison();
        }
        else
        {
            // Il ne peut pas y avoir aucun groupe de sélectionné
            m_groupeReparation->setChecked(true);
        }
        
        m_slotsInactifs = false;
    }
}





void ActionEditWidget::groupePayeOuPioche_clicked(bool checked)
{
    if (!m_slotsInactifs)
    {
        m_slotsInactifs = true;
        
        if (checked)
        {
            helper_resetGroupeDeplacement();
            helper_resetGroupeDeplacementRelatif();
            helper_resetGroupeDeplacementAuProchain();
            helper_resetGroupeTransaction();
            helper_resetGroupeReparation();
            helper_resetGroupePioche();
            helper_resetGroupeLibereDePrison();
        }
        else
        {
            // Il ne peut pas y avoir aucun groupe de sélectionné
            m_groupePayeOuPioche->setChecked(true);
        }
        
        m_slotsInactifs = false;
    }
}





void ActionEditWidget::groupePioche_clicked(bool checked)
{
    if (!m_slotsInactifs)
    {
        m_slotsInactifs = true;
        
        if (checked)
        {
            helper_resetGroupeDeplacement();
            helper_resetGroupeDeplacementRelatif();
            helper_resetGroupeDeplacementAuProchain();
            helper_resetGroupeTransaction();
            helper_resetGroupeReparation();
            helper_resetGroupePayeOuPioche();
            helper_resetGroupeLibereDePrison();
        }
        else
        {
            // Il ne peut pas y avoir aucun groupe de sélectionné
            m_groupePioche->setChecked(true);
        }
        
        m_slotsInactifs = false;
    }
}





void ActionEditWidget::groupeLibereDePrison_clicked(bool checked)
{
    if (!m_slotsInactifs)
    {
        m_slotsInactifs = true;
        
        if (checked)
        {
            helper_resetGroupeDeplacement();
            helper_resetGroupeDeplacementRelatif();
            helper_resetGroupeDeplacementAuProchain();
            helper_resetGroupeTransaction();
            helper_resetGroupeReparation();
            helper_resetGroupePayeOuPioche();
            helper_resetGroupePioche();
        }
        else
        {
            // Il ne peut pas y avoir aucun groupe de sélectionné
            m_groupeLiberePrison->setChecked(true);
        }
        
        m_slotsInactifs = false;
    }
}





void ActionEditWidget::helper_resetGroupeDeplacement()
{
    m_groupeDeplacement->setChecked(false);
    
    m_radioAvance->setChecked(true);// Sélection par défaut : premier élément du QButtonGroup
    m_emplacement->setCurrentIndex(0);
}





void ActionEditWidget::helper_resetGroupeDeplacementRelatif()
{
    m_groupeDeplacementRelatif->setChecked(false);
    
    m_radioAvanceRelatif->setChecked(true);// Sélection par défaut : premier élément du QButtonGroup
    m_nombreEmplacements->setValue(1);
}





void ActionEditWidget::helper_resetGroupeDeplacementAuProchain()
{
    m_groupeDeplacementAuProchain->setChecked(false);
    
    m_radioAvanceAuProchain->setChecked(true);// Sélection par défaut : premier élément du QButtonGroup
    m_typeEmplacement->setCurrentIndex(0);
}





void ActionEditWidget::helper_resetGroupeTransaction()
{
    m_groupeTransaction->setChecked(false);
    
    m_radioGagne->setChecked(true);// Sélection par défaut : premier élément du QButtonGroup
    m_montant->setValue(0);
    m_destinataire->setCurrentIndex(0);
}





void ActionEditWidget::helper_resetGroupeReparation()
{
    m_groupeReparation->setChecked(false);
    
    m_montantParMaison->setValue(0);
    m_montantParHotel->setValue(0);
}





void ActionEditWidget::helper_resetGroupePayeOuPioche()
{
    m_groupePayeOuPioche->setChecked(false);
    
    m_amende->setValue(0);
    m_pileCartesPayeOuPioche->setCurrentIndex(0);
}





void ActionEditWidget::helper_resetGroupePioche()
{
    m_groupePioche->setChecked(false);
    
    m_pileCartesPioche->setCurrentIndex(0);
}





void ActionEditWidget::helper_resetGroupeLibereDePrison()
{
    m_groupeLiberePrison->setChecked(false);
}

