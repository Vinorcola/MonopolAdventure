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





void GraphismeEmplacementInfos::editTaille(const QSize taille)
{
    m_tailleNormale = taille;
    m_tailleEnCoin.setHeight(taille.height());
    m_tailleEnCoin.setWidth(taille.height());
    
    /*
     * Correction : taille minimale = 50 x 50.
     */
    if (m_tailleNormale.height() < 50)
    {
        m_tailleNormale.setHeight(50);
        m_tailleEnCoin.setHeight(50);
        m_tailleEnCoin.setWidth(50);
    }
    if (m_tailleNormale.width() < 50)
    {
        m_tailleNormale.setWidth(50);
    }
}





quint16 GraphismeEmplacementInfos::getHauteurRectangleCouleur() const
{
    return m_hauteurRectangleCouleur;
}





void GraphismeEmplacementInfos::editHauteurRectangleCouleur(const quint16 hauteur)
{
    if (hauteur > m_tailleNormale.height())
    {
        m_hauteurRectangleCouleur = m_tailleNormale.height();
    }
    else
    {
        m_hauteurRectangleCouleur = hauteur;
    }
}





const QPen& GraphismeEmplacementInfos::getCrayonBordure() const
{
    return m_crayonBordure;
}





void GraphismeEmplacementInfos::editCrayonBordure(const QPen& crayon)
{
    m_crayonBordure = crayon;
}





const QColor& GraphismeEmplacementInfos::getCouleurFond() const
{
    return m_couleurFond;
}





void GraphismeEmplacementInfos::editCouleurFond(const QColor& couleur)
{
    if (couleur.isValid())
    {
        m_couleurFond = couleur;
    }
    else
    {
        m_couleurFond.setRgb(255, 255, 255);
    }
}





quint8 GraphismeEmplacementInfos::getMarge() const
{
    return m_marge;
}





void GraphismeEmplacementInfos::editMarge(const quint8 marge)
{
    if (marge > m_tailleNormale.width() / 2)
    {
        m_marge = m_tailleNormale.width() / 2;
    }
    else
    {
        m_marge = marge;
    }
}





const QFont& GraphismeEmplacementInfos::getFonteTitre() const
{
    return m_fontTitre;
}





void GraphismeEmplacementInfos::editFonteTitre(const QFont& fonte)
{
    m_fontTitre = fonte;
}





const QFont& GraphismeEmplacementInfos::getFonteSousTitre() const
{
    return m_fontSousTitre;
}





void GraphismeEmplacementInfos::editFonteSousTitre(const QFont& fonte)
{
    m_fontSousTitre = fonte;
}





const QFont& GraphismeEmplacementInfos::getFonteDescription() const
{
    return m_fontDescription;
}





void GraphismeEmplacementInfos::editFonteDescription(const QFont& fonte)
{
    m_fontDescription = fonte;
}





const QFont& GraphismeEmplacementInfos::getFontePrix() const
{
    return m_fontPrix;
}





void GraphismeEmplacementInfos::editFontePrix(const QFont& fonte)
{
    m_fontPrix = fonte;
}





void GraphismeEmplacementInfos::saveInFile(QDataStream& ecriture) const
{
    ecriture << m_tailleNormale
             << m_hauteurRectangleCouleur
             << m_crayonBordure
             << m_couleurFond
             << m_marge
             << m_fontTitre
             << m_fontSousTitre
             << m_fontDescription
             << m_fontPrix;
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

