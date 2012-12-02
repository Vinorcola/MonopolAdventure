#include "TypeEmplacementEditWidget.hpp"





TypeEmplacementEditWidget::TypeEmplacementEditWidget(Emplacement* emplacement) :
    QWidget(),
    m_emplacement(emplacement),
    m_champTypes(new QComboBox),
    m_description(new QLabel)
{
    /* Configuration des champs.
     */
    m_champTypes->insertItem(Type::CompagnieTransport, tr("Compagnie de transport"), tr("Une compagnie de transport est un propriété que les joueurs peuvent acheter. Les loyers varient en fonction du nombre de compagnies possédées par le propriétaire."));
    m_champTypes->insertItem(Type::Deplacement, tr("Déplacement"), tr("Cet emplacement oblige le joueur qui tombe dessus à se redéplacer immédiatement vers un autre emplacement. Il est possible de configurer une amende que le joueur doit payer avant de se déplacer."));
    m_champTypes->insertItem(Type::ParcGratuit, tr("Parc gratuit"), tr("Le parc gratuit est un emplacement de repos. Le joueur ne gagne rien, mais il ne paye rien non plus. Il est cependant possible de configurer des gains (les taxes payés par les autres joueurs) dans les règles de jeu."));
    m_champTypes->insertItem(Type::Pioche, tr("Pioche"), tr("Un joueur qui s'arrête sur un emplacement « Pioche » pioche une carte dans une certaine pile de cartes. Il doit ensuite effectué l'action que demande la carte."));
    m_champTypes->insertItem(Type::Service, tr("Service"), tr("Un service est une propriété que les joueurs peuvent acheter. Les loyers varient en fonction du montant obtenu avec les dés et du nombre de services possédés par le propriétaire."));
    m_champTypes->insertItem(Type::SimpleVisite, tr("Simple visite"), tr("Un emplacement en simple visite est neutre : le joueur ne gagne rien, mais il ne paye rien. Une prison peut être associée à ce type d'emplacement."));
    m_champTypes->insertItem(Type::Taxe, tr("Taxe"), tr("Lorsqu'un joueur se pose sur une taxe, il doit la payer. Une taxe peut être fixée à un montant unique, ou à un pourcentage de la fortune du joueur (ou bien les deux, le joueur peut alors choisir son mode de paiement)."));
    m_champTypes->insertItem(Type::Terrain, tr("Terrain"), tr("Cette propriété que les joueurs peuvent acheter est regroupée avec d'autres terrains pour constituer des regroupements. Lorsqu'un joueur possède tous les terrains d'un même regroupement, alors il peut entammer l'aménagement de ces terrains (en faisant des constructions) pour en augmenter les loyers."));
    m_champTypes->setCurrentIndex(emplacement->getType());
    
    changeDescription(emplacement->getType());
    m_description->setWordWrap(true);
    m_description->setAlignment(Qt::AlignJustify);
    
    
    
    /* Mise en forme du widget.
     */
    QFormLayout* layout = new QFormLayout;
    layout->addRow(tr("Type d'emplacement"), m_champTypes);
    layout->addRow(tr("Description"), m_description);
    
    setLayout(layout);
    
    
    
    /* Connexion des champs aux slots.
     */
    connect(m_champTypes, SIGNAL(currentIndexChanged(int)), this, SLOT(changeDescription(int)));
}





Type::Emplacement TypeEmplacementEditWidget::getTypeEmplacement() const
{
    return (Type::Emplacement) m_champTypes->currentIndex();
}





void TypeEmplacementEditWidget::changeDescription(int index)
{
    m_description->setText(m_champTypes->itemData(index).toString());
}

