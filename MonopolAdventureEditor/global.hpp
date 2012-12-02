#ifndef GLOBAL_HPP
#define GLOBAL_HPP



#define MONTANT_MAX_EDITEUR 50000/* Permet d'appliquer une fourchette maximale pour tous les montants configurés
                                  * dans l'éditeur.
                                  */



namespace Type
{
    /**
     * Énumération permettant de déterminer le type d'emplacement.
     * @note Ne pas changer les valeurs. Elles sont utilisées dans l'ordre dans TypeEmplacementEditWidget.
     */
    enum Emplacement
    {
        CompagnieTransport = 0,
        Depart = 8,
        Deplacement = 1,
        ParcGratuit = 2,
        Pioche = 3,
        Prison = 9,
        Service = 4,
        SimpleVisite = 5,
        Taxe = 6,
        Terrain = 7
    };
}

#endif // GLOBAL_HPP
