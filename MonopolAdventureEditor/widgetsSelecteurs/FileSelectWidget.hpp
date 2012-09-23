#ifndef FILESELECTWIDGET_HPP
#define FILESELECTWIDGET_HPP

#include <QFileDialog>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>





/**
 * @class FileSelectWidget FileSelectWidget.hpp plateau/edition/widgets/FileSelectWidget.hpp
 * Widget proposant à l'utilisateur de sélectionner un fichier.
 * 
 * Affiche un QLabel puis un QPushButton qui ouvre une QFileDialog. Lorsque l'utilisateur sélectionne un nouveau fichier, le QLabel affiche le chemin complet vers le fichier et le signal @c fileChange() est émis.
 */
class FileSelectWidget : public QWidget
{
        Q_OBJECT
        Q_PROPERTY(QString file READ getFilePath NOTIFY fileChange)///< Chemin complet vers le fichier sélectionné par l'utilisateur.
        
        
    protected:
        QString m_file;///< Chemin complet vers le fichier sélectionné par l'utilisateur.
        QLineEdit* m_widget;///< QLabel affichant le chemin complet vers le fichier.
        QPushButton* m_button;///< Bouton affichant la QFileDialog.
        bool m_openingMode;///< Indique si le widget doit être en mode Ouverture ou Enregistrement de fichier.
        
        
        
    public:
        /**
         * Constructeur.
         * @param parent Fenêtre parent (uniquement utilisée pour centrer la QFileDialog sur la fenêtre parent).
         * @param openingMode Indique si le widget doit être en mode Ouverture ou Enregistrement de fichier.
         * @param defaultFile Fichier sélectionné par défaut (aucun par défaut).
         */
        FileSelectWidget(QWidget* parent,
                         const bool openingMode = true,
                         const QString& defaultFile = QString());
        
        
        
        /**
         * Modifie le chemin vers le fichier sélectionné.
         * @param file Chemin vers le nouveau fichier sélectionné.
         */
        void setFilePath(const QString& file);
        
        
        
        /**
         * Retourne le chemin vers le fichier sélectionné par l'utilisateur.
         * @return Chemin vers le fichier sélectionné par l'utilisateur.
         */
        const QString& getFilePath() const;
        
        
        
    public slots:
        /**
         * Ouvre la QFileDialog pour demander le nouveau fichier à l'utilisateur, puis enregistre le chemin vers ce dernier.
         */
        void askNewFile();
        
        
        
    signals:
        /**
         * Signal émis lorsque l'utilisateur à changé le fichier.
         */
        void fileChange(QString file);
        
        
        
    protected:
        /**
         * Met à jour le chemin vers le fichier du QLabel.
         */
        void updateFileWidget();
};

#endif // FILESELECTWIDGET_HPP
