#-------------------------------------------------
#
# Project created by QtCreator 2012-09-20T19:31:45
#
#-------------------------------------------------

QT       += core gui

TARGET = MonopolAdventureEditor
TEMPLATE = app


SOURCES += main.cpp \
        assistants/creationPlateau/AssistantCreationPlateau.cpp \
        assistants/creationPlateau/PageGraphisme.cpp \
        assistants/creationPlateau/PageImage.cpp \
        assistants/creationPlateau/PageIntro.cpp \
        assistants/creationPlateau/PageOuvrir.cpp \
        assistants/creationPlateau/PagePrix.cpp \
        assistants/creationPlateau/PageTaille.cpp \
        donnees/cartes/Action.cpp \
        donnees/cartes/Carte.cpp \
        donnees/cartes/PileCartes.cpp \
        donnees/graphismes/GraphismeEmplacement.cpp \
        donnees/graphismes/GraphismeEmplacementInfos.cpp \
        donnees/emplacements/CompagnieTranspot.cpp \
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
        widgetsSelecteurs/ColorSelectWidget.cpp \
        widgetsSelecteurs/FileSelectWidget.cpp \
        widgetsSelecteurs/FontSelectWidget.cpp \
        widgetsSelecteurs/ImageSelectWidget.cpp \
        MainWindow.cpp \
    modeles/TerrainListModel.cpp

HEADERS  += global.hpp \
        assistants/creationPlateau/AssistantCreationPlateau.hpp \
        assistants/creationPlateau/PageGraphisme.hpp \
        assistants/creationPlateau/PageImage.hpp \
        assistants/creationPlateau/PageIntro.hpp \
        assistants/creationPlateau/PageOuvrir.hpp \
        assistants/creationPlateau/PagePrix.hpp \
        assistants/creationPlateau/PageTaille.hpp \
        donnees/cartes/Action.hpp \
        donnees/cartes/Carte.hpp \
        donnees/cartes/PileCartes.hpp \
        donnees/graphismes/GraphismeEmplacement.hpp \
        donnees/graphismes/GraphismeEmplacementInfos.hpp \
        donnees/emplacements/CompagnieTranspot.hpp \
        donnees/emplacements/Depart.hpp \
        donnees/emplacements/Deplacement.hpp \
        donnees/emplacements/Emplacement.hpp \
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
        widgetsSelecteurs/ColorSelectWidget.hpp \
        widgetsSelecteurs/FileSelectWidget.hpp \
        widgetsSelecteurs/FontSelectWidget.hpp \
        widgetsSelecteurs/ImageSelectWidget.hpp \
        MainWindow.hpp \
    modeles/TerrainListModel.hpp
