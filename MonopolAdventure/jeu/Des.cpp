#include "Des.hpp"




bool Des::m_init = false;





Des::Des(const bool activeDeRapide) :
    face1("data/des/des1.png"),
    face2("data/des/des2.png"),
    face3("data/des/des3.png"),
    face4("data/des/des4.png"),
    face5("data/des/des5.png"),
    face6("data/des/des6.png"),
    faceMonopoly("data/des/desMonopoly.png"),
    faceBus("data/des/desBus.png"),
    m_deRapideActif(activeDeRapide),
    m_result1(0),
    m_result2(0),
    m_resultRapide(0)
{
    if (!m_init)
    {
        qsrand(QDateTime::currentDateTime().toTime_t());
        m_init = true;
    }
}





int Des::lancer(const bool avecDeRapide)
{
    m_result1 = (qrand() % 6) + 1;
    m_result2 = (qrand() % 6) + 1;
    if (m_deRapideActif)
    {
        if (avecDeRapide)
        {
            m_resultRapide = (qrand() % 6) + 1;
        }
        else
        {
            m_resultRapide = 0;
        }
    }
    
    return m_result1 + m_result2 + (m_resultRapide <= Trois ? m_resultRapide : 0);
}





int Des::getResultat()
{
    return m_result1 + m_result2 + (m_resultRapide <= Trois ? m_resultRapide : 0);
}





int Des::getResultatDe1()
{
    return m_result1;
}





int Des::getResultatDe2()
{
    return m_result2;
}





bool Des::isDouble()
{
    return m_result1 == m_result2 && !isTriple();
    /* Note : Un triple aux dés n'est pas compté comme double. Le joueur ne relance pas les dés.
     */
}





bool Des::isTriple()
{
    // Le triple n'est possible que si les trois dés valent 1, 2 ou 3.
    return m_result1 == m_result2 && m_result1 == m_resultRapide && m_resultRapide <= 3;
    /* Note : Si le dé rapide n'est pas actif, m_resultRapide vaut 0. Ce résultat est alors différent des deux autres,
     *        et il n'y a pas triple.
     */
}





bool Des::isMonsieurMonopoly()
{
    return m_deRapideActif && (m_resultRapide == MMonopoly1 || m_resultRapide == MMonopoly2);
}





bool Des::isBus()
{
    return m_deRapideActif && m_resultRapide == Bus;
}

