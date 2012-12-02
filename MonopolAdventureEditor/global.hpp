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
        Depart = 1,
        Deplacement = 2,
        ParcGratuit = 3,
        Pioche = 4,
        Prison = 5,
        Service = 6,
        SimpleVisite = 7,
        Taxe = 8,
        Terrain = 9
    };
}

#endif // GLOBAL_HPP
