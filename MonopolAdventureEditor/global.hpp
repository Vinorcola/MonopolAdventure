#ifndef GLOBAL_HPP
#define GLOBAL_HPP



#define MONTANT_MAX_EDITEUR 50000/* Permet d'appliquer une fourchette maximale pour tous les montants configurés
                                  * dans l'éditeur.
                                  */



namespace Type
{
    /**
     * Énumération permettant de déterminer le type d'emplacement.
     */
    enum Emplacement
    {
        Aucun = 0,
        
        CompagnieTransport = 1,
        Depart = 2,
        Deplacement = 4,
        ParcGratuit = 8,
        Pioche = 16,
        Prison = 32,
        Service = 128,
        SimpleVisite = 256,
        Taxe = 512,
        Terrain = 1024
    };
}

#endif // GLOBAL_HPP