#-------------------------------------------------
#
# Project created by QtCreator 2012-09-03T21:29:43
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MonopolAdventure
TEMPLATE = app


SOURCES += main.cpp \
    assistants/menu/PageMenuAventure.cpp \
    assistants/menu/PageMenuClassique.cpp \
    assistants/menu/PageMenuPrincipal.cpp \
    assistants/partieMultijoueurs/AssistantPartieMultijoueurs.cpp \
    assistants/partieMultijoueurs/PageJoueur.cpp \
    assistants/partieMultijoueurs/PagePlateau.cpp \
    assistants/partieMultijoueurs/PageRegle.cpp \
    assistants/AssistantMenu.cpp \
    config/CouleurListModel.cpp \
    config/JoueurConfigWidget.cpp \
    config/RegleConfigWidget.cpp \
    donnees/cartes/Action.cpp \
    donnees/cartes/Carte.cpp \
    donnees/cartes/PileCartes.cpp \
    donnees/graphismes/GraphismeEmplacement.cpp \
    donnees/graphismes/GraphismeEmplacementInfos.cpp \
    donnees/graphismes/GraphismeJoueur.cpp \
    donnees/emplacements/CompagnieTransport.cpp \
    donnees/emplacements/Depart.cpp \
    donnees/emplacements/Deplacement.cpp \
    donnees/emplacements/Emplacement.cpp \
    donnees/emplacements/ParcGratuit.cpp \
    donnees/emplacements/Pioche.cpp \
    donnees/emplacements/Prison.cpp \
    donnees/emplacements/Propriete.cpp \
    donnees/emplacements/Regroupement.cpp \
    donnees/emplacements/Service.cpp \
    donnees/emplacements/SimpleVisite.cpp \
    donnees/emplacements/Taxe.cpp \
    donnees/emplacements/Terrain.cpp \
    donnees/Plateau.cpp \
    donnees/Regle.cpp \
    jeu/Des.cpp \
    jeu/Joueur.cpp \
    jeu/PanneauInfosJoueur.cpp \
    widgetsSelecteurs/ColorSelectWidget.cpp \
    widgetsSelecteurs/FileSelectWidget.cpp \
    widgetsSelecteurs/FontSelectWidget.cpp \
    widgetsSelecteurs/ImageSelectWidget.cpp \
    MainWindow.cpp

HEADERS  += global.hpp \
    assistants/menu/PageMenuAventure.hpp \
    assistants/menu/PageMenuClassique.hpp \
    assistants/menu/PageMenuPrincipal.hpp \
    assistants/partieMultijoueurs/AssistantPartieMultijoueurs.hpp \
    assistants/partieMultijoueurs/PageJoueur.hpp \
    assistants/partieMultijoueurs/PagePlateau.hpp \
    assistants/partieMultijoueurs/PageRegle.hpp \
    assistants/AssistantMenu.hpp \
    config/CouleurListModel.hpp \
    config/JoueurConfigWidget.hpp \
    config/RegleConfigWidget.hpp \
    donnees/cartes/Action.hpp \
    donnees/cartes/Carte.hpp \
    donnees/cartes/PileCartes.hpp \
    donnees/graphismes/GraphismeEmplacement.hpp \
    donnees/graphismes/GraphismeEmplacementInfos.hpp \
    donnees/graphismes/GraphismeJoueur.hpp \
    donnees/emplacements/CompagnieTransport.hpp \
    donnees/emplacements/Depart.hpp \
    donnees/emplacements/Deplacement.hpp \
    donnees/emplacements/Emplacement.hpp \
    donnees/emplacements/Emplacements.hpp \
    donnees/emplacements/ParcGratuit.hpp \
    donnees/emplacements/Pioche.hpp \
    donnees/emplacements/Prison.hpp \
    donnees/emplacements/Propriete.hpp \
    donnees/emplacements/Regroupement.hpp \
    donnees/emplacements/Service.hpp \
    donnees/emplacements/SimpleVisite.hpp \
    donnees/emplacements/Taxe.hpp \
    donnees/emplacements/Terrain.hpp \
    donnees/Plateau.hpp \
    donnees/Regle.hpp \
    jeu/Des.hpp \
    jeu/Joueur.hpp \
    jeu/PanneauInfosJoueur.hpp \
    widgetsSelecteurs/ColorSelectWidget.hpp \
    widgetsSelecteurs/FileSelectWidget.hpp \
    widgetsSelecteurs/FontSelectWidget.hpp \
    widgetsSelecteurs/ImageSelectWidget.hpp \
    widgetsSelecteurs/PointerComboBox.hpp \
    MainWindow.hpp
