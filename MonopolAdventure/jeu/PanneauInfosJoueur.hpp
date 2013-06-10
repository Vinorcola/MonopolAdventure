#ifndef PANNEAUINFOSJOUEUR_HPP
#define PANNEAUINFOSJOUEUR_HPP

#include <QDockWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QVBoxLayout>

class Joueur;
#include "jeu/Joueur.hpp"





/**
 * @class PanneauInfosJoueur PanneauInfosJoueur.hpp jeu/PanneauInfosJoueur.hpp
 * Cette classe représente un dock widget affichant les informations publiques du joueur.
 */
class PanneauInfosJoueur : public QDockWidget
{
        Q_OBJECT
        
        
    private:
        QWidget* m_widgetCentral;///< Widget central du dock.
        QLabel* m_argent;///< Label affichant l'argent de possède le joueur.
        QGraphicsScene* m_etatPlateau;///< Scène montrant l'état des propriétés du plateau.
        QGraphicsView* m_vueEtatPlateau;///< Vue permettant d'afficher la scène montrant l'état des propriétés du plateau.
        
        
        
    public:
        /**
         * Créé un nouveau panneau d'affichage des informations publiques d'un joueur.
         * @param joueur Joueur à qui appartient le panneau d'information.
         */
        PanneauInfosJoueur(const Joueur* joueur);
        
        
        
        /**
         * Met à jour la cagnotte affichée.
         * @param cagnotte Nouvelle cagnotte à afficher.
         */
        void updateArgent(qint32 cagnotte);
};

#endif // PANNEAUINFOSJOUEUR_HPP
