#include "JoueurConfigWidget.hpp"





JoueurConfigWidget::JoueurConfigWidget() :
    QWidget(),
    m_pseudo(new QLineEdit)
{
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(m_pseudo);
    
    setLayout(layout);
}





QString JoueurConfigWidget::pseudo()
{
    return m_pseudo->text();
}

