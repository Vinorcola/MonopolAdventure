#ifndef COLORSELECTWIDGET_HPP
#define COLORSELECTWIDGET_HPP

#include <QColor>
#include <QColorDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>





/**
 * @class ColorSelectWidget ColorSelectWidget.hpp plateau/edition/widgets/ColorSelectWidget.hpp
 * Widget proposant à l'utilisateur de sélectionner une couleur.
 * 
 * Affiche un QLabel avec la couleur par défaut, puis un QPushButton qui ouvre une QColorDialog. Lorsque l'utilisateur change la couleur, le QLabel se met automatiquement à jour avec la nouvelle couleur en fond et le signal @c colorChange() est émis.
 */
class ColorSelectWidget : public QWidget
{
        Q_OBJECT
        Q_PROPERTY(QColor color READ getColor WRITE setColor NOTIFY colorChange)///< Couleur sélectionnée par l'utilisateur.
        
        
    protected:
        QColor m_color;///< Couleur sélectionnée par l'utilisateur.
        QLabel* m_widget;///< QLabel affichant la couleur.
        QPushButton* m_button;///< Bouton affichant la QColorDialog.
        
        
        
    public:
        /**
         * Constructeur.
         * @param parent Fenêtre parent (uniquement utilisée pour centrer la QColorDialog sur la fenêtre parent).
         * @param defaultColor Couleur sélectionnée par défaut.
         */
        ColorSelectWidget(QWidget* parent,
                          const QColor& defaultColor = QColor(255, 255, 255));
        
        
        
        /**
         * Modifie la couleur sélectionnée.
         * @param color Nouvelle couleur.
         */
        void setColor(const QColor& color);
        
        
        
        /**
         * Retourne la couleur sélectionnée par l'utilisateur.
         * @return Couleur sélectionnée par l'utilisateur.
         */
        const QColor& getColor() const;
        
        
        
    public slots:
        /**
         * Ouvre la QColorDialog pour demander la nouvelle couleur à l'utilisateur puis enregistre cette dernière.
         */
        void askNewColor();
        
        
        
    signals:
        /**
         * Signal émis lorsque l'utilisateur à changé la couleur.
         */
        void colorChange(QColor color);
        
        
        
    protected:
        /**
         * Met à jour la couleur du QLabel.
         */
        void updateColorWidget();
};

#endif // COLORSELECTWIDGET_HPP
