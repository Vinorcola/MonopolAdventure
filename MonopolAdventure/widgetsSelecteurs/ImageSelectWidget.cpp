#include "ImageSelectWidget.hpp"





ImageSelectWidget::ImageSelectWidget(QWidget* parent,
                                     const QPixmap& image,
                                     const QColor& color) :
    QWidget(parent),
    m_image(image),
    m_widget(new QLabel),
    m_button(new QPushButton(tr("Modifier")))
{
    m_widget->setAlignment(Qt::AlignCenter);
    m_widget->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_widget->setLineWidth(2);
    m_widget->setAutoFillBackground(true);
    updateImageWidget();
    if (color.isValid())
    {
        setBackgroundColor(color);
    }
    
    QHBoxLayout* layout = new QHBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_widget);
    layout->addWidget(m_button);
    
    setLayout(layout);
    
    connect(m_button, SIGNAL(clicked()), this, SLOT(askNewImage()));
}





void ImageSelectWidget::setImage(const QPixmap& image)
{
    if (image.toImage() != m_image.toImage())
    {
        m_image = image;
        updateImageWidget();
        emit imageChange();
    }
}





const QPixmap& ImageSelectWidget::getImage() const
{
    return m_image;
}





void ImageSelectWidget::askNewImage()
{
    QString newImage = QFileDialog::getOpenFileName(parentWidget(), QString(), QString(), tr("Images (*.bmp *.gif *.jpeg *.jpg *.png *.xpm)"));
    
    if (!newImage.isEmpty())
    {
        m_image.load(newImage);
        updateImageWidget();
        emit imageChange();
    }
}





void ImageSelectWidget::setBackgroundColor(const QColor& color)
{
    QPalette palette(m_widget->palette());
    palette.setColor(QPalette::Window, color);
    m_widget->setPalette(palette);
}





void ImageSelectWidget::resetImage()
{
    m_image = QPixmap();
    emit imageChange();
}





void ImageSelectWidget::updateImageWidget()
{
    m_widget->setPixmap(m_image);
}

