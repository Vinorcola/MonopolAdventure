#include "RegleConfigWidget.hpp"




RegleConfigWidget::RegleConfigWidget(const Regle* defaut,
                                     const quint16 salaire) :
    QScrollArea(),
    m_groupeConstruction(new QGroupBox(tr("Constructions"))),
    m_nombreTotalMaison(new QSpinBox),
    m_nombreTotalHotel(new QSpinBox),
    m_possessionRegroupement(new QCheckBox(tr("Possession du regroupement pour construire"))),
    m_constructionsUniformes(new QCheckBox(tr("Constructions uniformes"))),
    m_joueurPresentPourConstruire(new QCheckBox(tr("Joueur présent pour la construction"))),
    m_tousTerrainVendus(new QCheckBox(tr("Tous les terrains doivent être vendus pour construire"))),
    m_toutesPprtVendues(new QCheckBox(tr("Toutes les propriétés doivent être vendues pour construire"))),
    
    m_groupeDepart(new QGroupBox(tr("Case Départ"))),
    m_salaire(new QSpinBox),
    m_doubleSalaire(new QCheckBox(tr("Salaire doublé lors de l'arrêt sur la case Départ"))),
    
    m_groupeDebut(new QGroupBox(tr("Début de la partie"))),
    m_nbPprtAuDebut(new QSpinBox),
    m_toutesPprtAuDebut(new QCheckBox(tr("Toutes"))),
    m_encheresDepart(new QCheckBox(tr("Enchère de départ"))),
    m_premierTourSansAchat(new QCheckBox(tr("Premier tour du plateau sans achat"))),
    
    m_groupeParcGratuit(new QGroupBox(tr("Parc gratuit"))),
    m_taxeAuParcGratuit(new QCheckBox(tr("Les taxes sotn redistribuées au Parc gratuit"))),
    m_amendeCarteAuParcGratuit(new QCheckBox(tr("Les amendes des cartes sont redistribuées au Parc gratuit"))),
    m_cagnotteFixe(new QCheckBox(tr("Une cagnotte est distribuée au Parc gratuit"))),
    m_labelMontantCagnotte(new QLabel(tr("Montant de la cagnotte"))),
    m_montantCagnotte(new QSpinBox),
    
    m_groupePrison(new QGroupBox(tr("Prison"))),
    m_maxTourEnPrison(new QSpinBox),
    m_percevoirLoyerEnPrison(new QCheckBox(tr("Le joueur en prison peut percevoir ses loyers"))),
    m_participerEnchereEnPrison(new QCheckBox(tr("Le joueur en prison peut participer aux enchères"))),
    m_echangerEnPrison(new QCheckBox(tr("Le joueur en prison peut échanger avec un autre joueur"))),
    m_construireEnPrison(new QCheckBox(tr("Le joueur en prison gérer des constructions"))),
    m_tousLesDroitsEnPrison(new QPushButton(tr("Tout autoriser"))),
    m_aucunDroitEnPrison(new QPushButton(tr("Tout interdire"))),
    
    m_groupeEncheres(new QGroupBox(tr("Enchères sur biens"))),
    m_encheresSurBiensPerdus(new QCheckBox(tr("Enchères sur biens perdus"))),
    m_encheresSurNonAchete(new QCheckBox(tr("Enchères sur biens non-achetés"))),
    
    m_groupeAutres(new QGroupBox(tr("Autres options"))),
    m_deRapide(new QCheckBox(tr("Utilisation du dé rapide"))),
    m_nbMaxTours(new QCheckBox(tr("Nombre maximum de tours"))),
    m_nbTours(new QSpinBox)
{
    /* Configuration générale des champs.
     */
    
    // Groupe Construction.
    m_nombreTotalMaison->setMinimum(4);
    m_nombreTotalMaison->setMaximum(252);
    m_nombreTotalMaison->setSingleStep(4);
    
    m_nombreTotalHotel->setMinimum(1);
    m_nombreTotalHotel->setMaximum(252);
    
    
    // Groupe Départ
    m_salaire->setMinimum(10);
    m_salaire->setMaximum(MONTANT_MAX_EDITEUR);
    m_salaire->setSingleStep(50);
    
    
    // Groupe Début
    m_nbPprtAuDebut->setMaximum(50);
    
    
    // Groupe Parc gratuit
    m_montantCagnotte->setMaximum(MONTANT_MAX_EDITEUR);
    m_montantCagnotte->setSingleStep(10);
    
    
    // Groupe Prison
    m_maxTourEnPrison->setMinimum(1);
    m_maxTourEnPrison->setMaximum(10);
    
    
    // Groupe Autre
    m_nbTours->setMinimum(10);
    m_nbTours->setMaximum(250);
    
    
    
    /* Mise en forme
     */
    QFormLayout* layoutConstruction(new QFormLayout);
    layoutConstruction->addRow(tr("Nombre maximum de maisons disponibles"), m_nombreTotalMaison);
    layoutConstruction->addRow(tr("Nombre maximum d'hôtels disponibles"), m_nombreTotalHotel);
    layoutConstruction->addRow(m_possessionRegroupement);
    layoutConstruction->addRow(m_constructionsUniformes);
    layoutConstruction->addRow(m_joueurPresentPourConstruire);
    layoutConstruction->addRow(m_tousTerrainVendus);
    layoutConstruction->addRow(m_toutesPprtVendues);
    m_groupeConstruction->setLayout(layoutConstruction);
    
    QFormLayout* layoutDepart(new QFormLayout);
    layoutDepart->addRow(tr("Salaire"), m_salaire);
    layoutDepart->addRow(m_doubleSalaire);
    m_groupeDepart->setLayout(layoutDepart);
    
    QHBoxLayout* layoutNbPprt(new QHBoxLayout);
    layoutNbPprt->addWidget(new QLabel(tr("Nombre de propriété distribuées aux joueurs")));
    layoutNbPprt->addWidget(m_nbPprtAuDebut);
    layoutNbPprt->addWidget(m_toutesPprtAuDebut);
    layoutNbPprt->addStretch(1);
    QVBoxLayout* layoutDebut(new QVBoxLayout);
    layoutDebut->addLayout(layoutNbPprt);
    layoutDebut->addWidget(m_encheresDepart);
    layoutDebut->addWidget(m_premierTourSansAchat);
    m_groupeDebut->setLayout(layoutDebut);
    
    QFormLayout* layoutParcGratuit(new QFormLayout);
    layoutParcGratuit->addRow(m_taxeAuParcGratuit);
    layoutParcGratuit->addRow(m_amendeCarteAuParcGratuit);
    layoutParcGratuit->addRow(m_cagnotteFixe, m_montantCagnotte);
    m_groupeParcGratuit->setLayout(layoutParcGratuit);
    
    QHBoxLayout* layoutBoutons(new QHBoxLayout);
    layoutBoutons->addWidget(m_tousLesDroitsEnPrison);
    layoutBoutons->addWidget(m_aucunDroitEnPrison);
    layoutBoutons->addStretch(1);
    QFormLayout* layoutPrison(new QFormLayout);
    layoutPrison->addRow(tr("Nombres de tours maximum en prison"), m_maxTourEnPrison);
    layoutPrison->addRow(m_percevoirLoyerEnPrison);
    layoutPrison->addRow(m_participerEnchereEnPrison);
    layoutPrison->addRow(m_echangerEnPrison);
    layoutPrison->addRow(m_construireEnPrison);
    layoutPrison->addRow(layoutBoutons);
    m_groupePrison->setLayout(layoutPrison);
    
    QVBoxLayout* layoutEncheres(new QVBoxLayout);
    layoutEncheres->addWidget(m_encheresSurBiensPerdus);
    layoutEncheres->addWidget(m_encheresSurNonAchete);
    m_groupeEncheres->setLayout(layoutEncheres);
    
    QFormLayout* layoutAutres(new QFormLayout);
    layoutAutres->addRow(m_deRapide);
    layoutAutres->addRow(m_nbMaxTours, m_nbTours);
    m_groupeAutres->setLayout(layoutAutres);
    
    
    
    QVBoxLayout* layout(new QVBoxLayout);
    layout->addWidget(m_groupeConstruction);
    layout->addWidget(m_groupePrison);
    layout->addWidget(m_groupeEncheres);
    layout->addWidget(m_groupeDebut);
    layout->addWidget(m_groupeDepart);
    layout->addWidget(m_groupeParcGratuit);
    layout->addWidget(m_groupeAutres);
    
    QWidget* widgetCentral(new QWidget);
    widgetCentral->setLayout(layout);
    setWidget(widgetCentral);
    setWidgetResizable(true);
    setMinimumWidth(widgetCentral->minimumSizeHint().width() + verticalScrollBar()->size().width());
    
    
    
    /* Configuration du widget en fonction de la regle.
     */
    setRegle(defaut, salaire);
    
    
    
    /* Connexion slots/signaux.
     */
    connect(m_tousLesDroitsEnPrison, SIGNAL(clicked()), this, SLOT(tousLesDroitsEnPrison()));
    connect(m_aucunDroitEnPrison, SIGNAL(clicked()), this, SLOT(aucunDroitEnPrison()));
}






void RegleConfigWidget::setRegle(const Regle* regle,
                                 const quint16 salaire)
{
    if (regle)
    {
        // Groupe Construction
        m_nombreTotalMaison->setValue(regle->nombreTotalMaison());
        m_nombreTotalHotel->setValue(regle->nombreTotalHotel());
        m_possessionRegroupement->setChecked(regle->possessionRegroupementPourConstruire());
        m_constructionsUniformes->setChecked(regle->constructionHomogene());
        m_joueurPresentPourConstruire->setChecked(regle->joueurPresentPourConstruire());
        m_tousTerrainVendus->setChecked(regle->tousTerrainsVendusPourConstruire());
        m_toutesPprtVendues->setChecked(regle->toutesProprietesVenduesPourConstruire());
        
        
        
        // Groupe Case Départ
        m_salaire->setValue(salaire);
        m_doubleSalaire->setChecked(regle->salaireDouble());
        
        
        
        // Groupe Début de la partie
        qint8 nbPprtAuDepart(regle->nombreProprietesAuDepart());
        if (nbPprtAuDepart == -1)
        {
            m_nbPprtAuDebut->setDisabled(true);
            m_nbPprtAuDebut->setValue(0);
            m_toutesPprtAuDebut->setChecked(true);
        }
        else
        {
            m_nbPprtAuDebut->setEnabled(true);
            m_nbPprtAuDebut->setValue(nbPprtAuDepart);
            m_toutesPprtAuDebut->setChecked(false);
        }
        m_encheresDepart->setChecked(regle->enchereDepart());
        m_premierTourSansAchat->setChecked(regle->premierTourSansAchat());
        
        
        
        // Groupe Parc Gratuit
        m_taxeAuParcGratuit->setChecked(regle->taxeInParcGratuit());
        m_amendeCarteAuParcGratuit->setChecked(regle->amendeCarteInParcGratuit());
        if (regle->cagnotteFixe())
        {
            m_cagnotteFixe->setChecked(true);
            m_labelMontantCagnotte->setEnabled(true);
            m_montantCagnotte->setValue(regle->montantFixe());
        }
        else
        {
            m_cagnotteFixe->setChecked(false);
            m_labelMontantCagnotte->setDisabled(true);
            m_montantCagnotte->setDisabled(true);
            m_montantCagnotte->setValue(0);
        }
        
        
        
        // Groupe Prison
        m_maxTourEnPrison->setValue(regle->nombreMaxTourEnPrison());
        m_percevoirLoyerEnPrison->setChecked(regle->joueurPeutPercevoirLoyerEnPrison());
        m_participerEnchereEnPrison->setChecked(regle->joueurPeutParticiperEncheresEnPrison());
        m_echangerEnPrison->setChecked(regle->joueurPeutEchangerEnPrison());
        m_construireEnPrison->setChecked(regle->joueurPeutConstruireEnPrison());
        
        
        
        // Groupe Enchères
        m_encheresSurBiensPerdus->setChecked(regle->enchereSurBiensRecperes());
        m_encheresSurNonAchete->setChecked(regle->enchereSurNonAchete());
        
        
        
        // Groupe Autre
        m_deRapide->setChecked(regle->partieRapide());
        quint8 nbMaxTour(regle->nombreTourMax());
        if (nbMaxTour == 0)
        {
            m_nbMaxTours->setChecked(false);
            m_nbTours->setDisabled(true);
            m_nbTours->setValue(0);
        }
        else
        {
            m_nbMaxTours->setChecked(true);
            m_nbTours->setEnabled(true);
            m_nbTours->setValue(nbMaxTour);
        }
    }
}






void RegleConfigWidget::tousLesDroitsEnPrison()
{
    m_percevoirLoyerEnPrison->setChecked(true);
    m_participerEnchereEnPrison->setChecked(true);
    m_echangerEnPrison->setChecked(true);
    m_construireEnPrison->setChecked(true);
}





void RegleConfigWidget::aucunDroitEnPrison()
{
    m_percevoirLoyerEnPrison->setChecked(false);
    m_participerEnchereEnPrison->setChecked(false);
    m_echangerEnPrison->setChecked(false);
    m_construireEnPrison->setChecked(false);
}

