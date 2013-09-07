#ifndef COULEURLISTMODEL_HPP
#define COULEURLISTMODEL_HPP

#include <QAbstractListModel>
#include <QStringList>





class CouleurListModel : public QAbstractListModel
{
        Q_OBJECT
        
        
    private:
        static QList<int> m_listeCouleurUtilisee;///< Liste répertoriant les couleurs utilisées (leur rang).
        static const QStringList m_listeCouleur;///< Liste des couleurs disponibles.
        int m_rangSelectionne;///< Numéro du rang sélectionné dans la vue associée.
        
        
        
    public:
        /**
         * Construit un nouveau modèle.
         * @param parent Objet parent.
         */
        CouleurListModel(QObject* parent);
        
        
        
        /**
         * Indique le nombre de rangs contenus dans le modèle.
         * @param parent Index racine.
         * @return Le nombre de rangs contenus dans le modèle.
         */
        int rowCount(const QModelIndex& parent = QModelIndex()) const;
        
        
        
        /**
         * Indique la donnée à afficher.
         * @param index Index racine.
         * @param role Rôle de la donnée.
         * @return Donnée.
         */
        QVariant data(const QModelIndex& index,
                      int role = Qt::DisplayRole) const;
        
        
        
        /**
         * Indique les caractéristiques d'un élément.
         * @param index Index racine.
         * @return Caractéristiques.
         */
        Qt::ItemFlags flags(const QModelIndex& index) const;
        
        
        
    public slots:
        /**
         * Indique au modèle l'élément sélectionné dans la vue.
         * @param row Rang de l'élément sélectionné.
         */
        void setSelectedItem(int row);
};

#endif // COULEURLISTMODEL_HPP
