#ifndef GLOBAL_HPP
#define GLOBAL_HPP



#define MONTANT_MAX_EDITEUR 50000/* Permet d'appliquer une fourchette maximale pour tous les montants
                                  * configurés dans l'éditeur.
                                  */
#define NOMBRE_TOURS_MAX_PRISON 10// Fourchette maximale du nombre de tours en prison.



#define VERSION_ECRITURE 100// Version actuelle d'écriture dans les fichiers.
#define TAG_SECURITE 0x7F10A504/* Sécurité pour vérifier que le fichier de sauvegarde est valide.
                                * NE JAMAIS CHANGER CETTE VALEUR !
                                */

#define ZOOM_MAX 1.0
#define ZOOM_MIN 0.1



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
        Terrain = 7,
        
        Aucun = 100// Nécessaire pour Action.
    };
}

#endif // GLOBAL_HPP
