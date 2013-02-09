#include "FontSelectWidget.hpp"





FontSelectWidget::FontSelectWidget(QWidget* parent,
                                   const QFont& defaultFont) :
    QWidget(parent),
    m_font(defaultFont),
    m_widget(new QLabel),
    m_button(new QPushButton(tr("Modifier")))
{
    /* Configuration du QLabel qui affiche le texte.
     */
    m_widget->setMaximumHeight(m_button->sizeHint().height());
    updateFontWidget();
    
    
    
    /* Configuration du QPushButton.
     */
    connect(m_button, SIGNAL(clicked()), this, SLOT(askNewFont()));
    
    
    
    /* Disposition
     */
    QHBoxLayout* layout = new QHBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_widget);
    layout->addWidget(m_button);
    
    setLayout(layout);
}





void FontSelectWidget::setFont(const QFont& font)
{
    if (font != m_font)
    {
        m_font = font;
        updateFontWidget();
        emit fontChange(m_font);
    }
}





const QFont& FontSelectWidget::getFont() const
{
    return m_font;
}





void FontSelectWidget::askNewFont()
{
    bool ok;
    QFont newFont = QFontDialog::getFont(&ok, m_font, parentWidget(), tr("Sélectionnez une fonte de caractères"));
    if (ok && newFont != m_font)
    {
        m_font = newFont;
        updateFontWidget();
        emit fontChange(m_font);
    }
}





void FontSelectWidget::updateFontWidget()
{
    QString text("<span style=\"font-family:" + m_font.family() + ";\">" + m_font.family() + "</span>, " + QString::number(m_font.pointSize()) + tr("pt"));
    
    if (m_font.italic())
    {
        text += ", <i>" + tr("italique") + "</i>";
    }
    
    if (m_font.bold())
    {
        text += ", <b>"+ tr("gras") + "</b>";
    }
    
    if (m_font.underline())
    {
        text += ", <span style=\"text-decoration:underline;\">" + tr("souligné") + "</span>";
    }
    
    if (m_font.strikeOut())
    {
        text += ", <span style=\"text-decoration:line-through;\">" + tr("barré") + "</span>";
    }
    
    m_widget->setText(text);
}

