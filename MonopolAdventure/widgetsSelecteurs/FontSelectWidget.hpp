#ifndef FONTSELECTWIDGET_HPP
#define FONTSELECTWIDGET_HPP

#include <QFont>
#include <QFontDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>





/**
 * @class FontSelectWidget FontSelectWidget.hpp plateau/edition/widgets/FontSelectWidget.hpp
 * Widget proposant à l'utilisateur de sélectionner une fonte de caractères.
 * 
 * Affiche un QLabel avec le nom de la police ainsi que des différents attributs (gras, italique, etc.), puis un QPushButton qui ouvre une QFontDialog. Lorsque l'utilisateur change la fonte de caractères, le QLabel se met automatiquement à jour avec le nouveau texte et le signal @c fontChange() est émis.
 */
class FontSelectWidget : public QWidget
{
        Q_OBJECT
        Q_PROPERTY(QFont font READ getFont WRITE setFont NOTIFY fontChange)///< Fonte de caractères sélectionnée par l'utilisateur.
        
        
    protected:
        QFont m_font;///< Fonte de caractères sélectionnée par l'utilisateur.
        QLabel* m_widget;///< QLabel affichant le nom de la police ainsi que les différents attributs.
        QPushButton* m_button;///< Bouton affichant la QFontDialog.
        
        
        
    public:
        /**
         * Constructeur.
         * @param parent Fenêtre parent (uniquement utilisée pour centrer la QFontDialog sur la fenêtre parent).
         * @param defaultFont Fonte de caractères sélectionnée par défaut.
         */
        FontSelectWidget(QWidget* parent,
                          const QFont& defaultFont);
        
        
        
        /**
         * Modifie la fonte de caractères sélectionnée.
         * @param font Nouvelle fonte de caractères.
         */
        void setFont(const QFont& font);
        
        
        
        /**
         * Retourne la fonte de caractères sélectionnée par l'utilisateur.
         * @return Fonte de caractères sélectionnée par l'utilisateur.
         */
        const QFont& getFont() const;
        
        
        
    public slots:
        /**
         * Ouvre la QFontDialog pour demander la nouvelle fonte de caractères à l'utilisateur puis enregistre cette dernière.
         */
        void askNewFont();
        
        
        
    signals:
        /**
         * Signal émis lorsque l'utilisateur à changé la fonte de caractères.
         */
        void fontChange(QFont font);
        
        
        
    protected:
        /**
         * Met à jour le texte du QLabel.
         */
        void updateFontWidget();
};

#endif // FONTSELECTWIDGET_HPP
