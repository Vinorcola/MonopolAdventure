#ifndef IMAGESELECTWIDGET_HPP
#define IMAGESELECTWIDGET_HPP

#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>





/**
 * @class ImageSelectWidget ImageSelectWidget.hpp plateau/edition/widgets/ImageSelectWidget.hpp
 * Widget proposant à l'utilisateur de sélectionner une image.
 * 
 * Affiche un QLabel avec l'image par défaut, puis un QPushButton qui ouvre une QFileDialog. Lorsque l'utilisateur change l'image, le QLabel se met automatiquement à jour en affichant la nouvelle image et le signal @c imageChange() est émis. L'utilisateur a aussi la possibilité de changer la couleur de fond.
 * 
 * @todo Pouvoir supprimer l'image.
 */
class ImageSelectWidget : public QWidget
{
        Q_OBJECT
        Q_PROPERTY(QPixmap image READ getImage NOTIFY imageChange)///< Image chargée par l'utilisateur.
        
        
    protected:
        QPixmap m_image;///< Image chargée par l'utilisateur.
        QLabel* m_widget;///< QLabel affichant l'image.
        QPushButton* m_button;///< Bouton affichant la QFileDialog.
        
        
        
    public:
        /**
         * Constructeur par défaut.
         * @param parent Fenêtre parent (uniquement utilisée pour centrer la QColorDialog sur la fenêtre parent).
         * @param image Image chargé par défaut.
         * @param color Couleur de fond.
         */
        ImageSelectWidget(QWidget* parent,
                          const QPixmap& image = QPixmap(),
                          const QColor& color = QColor());
        
        
        
        /**
         * Modifie l'image sélectionnée.
         * @param image Nouvelle image.
         */
        void setImage(const QPixmap& image);
        
        
        
        /**
         * Retourne une référence vers l'image chargée.
         * @return Image chargée.
         */
        const QPixmap& getImage() const;
        
        
        
    public slots:
        /**
         * Ouvre la QFileDialog pour demander la nouvelle image à l'utilisateur puis enregistre cette dernière.
         */
        void askNewImage();
        
        
        
        /**
         * Change la couleur de fond du QLabel affichant l'image.
         */
        void setBackgroundColor(const QColor& color);
        
        
        
        /**
         * Supprime l'image chargée.
         */
        void resetImage();
        
        
        
    signals:
        /**
         * Signal émis lorsque que l'utilisateur à changé l'image.
         */
        void imageChange();
        
        
        
    protected:
        /**
         * Met à jour l'image du QLabel.
         */
        void updateImageWidget();
};

#endif // IMAGESELECTWIDGET_HPP
