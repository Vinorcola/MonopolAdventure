#include "ColorSelectWidget.hpp"





ColorSelectWidget::ColorSelectWidget(QWidget* parent,
                                     const QColor& defaultColor) :
    QWidget(parent),
    m_color(defaultColor),
    m_widget(new QLabel),
    m_button(new QPushButton(tr("Modifier")))
{
    /* Configuration du QLabel qui affiche la couleur.
     */
    m_widget->setAlignment(Qt::AlignCenter);
    m_widget->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_widget->setLineWidth(2);
    m_widget->setAutoFillBackground(true);
    m_widget->setMaximumHeight(m_button->sizeHint().height());
    updateColorWidget();
    
    
    
    /* Configuration du QPushButton.
     */
    connect(m_button, SIGNAL(clicked()), this, SLOT(askNewColor()));
    
    
    
    /* Disposition
     */
    QHBoxLayout* layout = new QHBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_widget);
    layout->addWidget(m_button);
    
    setLayout(layout);
}





void ColorSelectWidget::setColor(const QColor& color)
{
    if (color != m_color)
    {
        m_color = color;
        updateColorWidget();
        emit colorChange(m_color);
    }
}





const QColor& ColorSelectWidget::getColor() const
{
    return m_color;
}





void ColorSelectWidget::askNewColor()
{
    QColor newColor = QColorDialog::getColor(m_color, parentWidget());
    if (newColor.isValid() && newColor != m_color)
    {
        m_color = newColor;
        updateColorWidget();
        emit colorChange(m_color);
    }
}





void ColorSelectWidget::updateColorWidget()
{
    m_widget->setText(m_color.name());
    
    QPalette palette(m_widget->palette());
    palette.setColor(QPalette::Window, m_color);
    
    if (m_color.value() < 200)
    {
        QColor textColor(255, 255, 255);
        palette.setColor(QPalette::WindowText, textColor);
    }
    else
    {
        QColor textColor(0, 0, 0);
        palette.setColor(QPalette::WindowText, textColor);
    }
    
    m_widget->setPalette(palette);
}

