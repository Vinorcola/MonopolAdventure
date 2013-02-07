#include "GraphismeEmplacementInfos.hpp"





GraphismeEmplacementInfos::GraphismeEmplacementInfos() :
    m_tailleNormale(200, 250),
    m_tailleEnCoin(250, 250),
    m_hauteurRectangleCouleur(50),
    m_crayonBordure(QBrush(QColor(0, 0, 0)), 1),
    m_couleurFond(255, 255, 128),
    m_marge(5),
    m_fontTitre("Comic Sans MS", 18, QFont::Bold),
    m_fontSousTitre("Arial", 16),
    m_fontDescription("Arial", 12),
    m_fontPrix("DejaVu Sans Mono", 12)
{
    
}





const QSize& GraphismeEmplacementInfos::getTailleNormale() const
{
    return m_tailleNormale;
}





const QSize& GraphismeEmplacementInfos::getTailleEnCoin() const
{
    return m_tailleEnCoin;
}





quint16 GraphismeEmplacementInfos::getHauteurRectangleCouleur() const
{
    return m_hauteurRectangleCouleur;
}





const QPen& GraphismeEmplacementInfos::getCrayonBordure() const
{
    return m_crayonBordure;
}





const QColor& GraphismeEmplacementInfos::getCouleurFond() const
{
    return m_couleurFond;
}





quint8 GraphismeEmplacementInfos::getMarge() const
{
    return m_marge;
}





const QFont& GraphismeEmplacementInfos::getFonteTitre() const
{
    return m_fontTitre;
}





const QFont& GraphismeEmplacementInfos::getFonteSousTitre() const
{
    return m_fontSousTitre;
}





const QFont& GraphismeEmplacementInfos::getFonteDescription() const
{
    return m_fontDescription;
}





const QFont& GraphismeEmplacementInfos::getFontePrix() const
{
    return m_fontPrix;
}





void GraphismeEmplacementInfos::loadFromFile(QDataStream& lecture,
                                             const quint16 version)
{
    switch (version)
    {
        default:
            lecture >> m_tailleNormale
                    >> m_hauteurRectangleCouleur
                    >> m_crayonBordure
                    >> m_couleurFond
                    >> m_marge
                    >> m_fontTitre
                    >> m_fontSousTitre
                    >> m_fontDescription
                    >> m_fontPrix;
            
            
            m_tailleEnCoin.setHeight(m_tailleNormale.height());
            m_tailleEnCoin.setWidth(m_tailleNormale.height());
    }
}

