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
    dialogEdition/donnees/RegroupementData.cpp \
    dialogEdition/donnees/TerrainData.cpp \
    dialogEdition/modeles/EmplacementListModel.cpp \
    dialogEdition/modeles/TerrainListModel.cpp \
    dialogEdition/modeles/SelectionRegroupementListModel.cpp \
    dialogEdition/modeles/RegroupementListModel.cpp \
    dialogEdition/widgetsEditeurs/ConstructionEditWidget.cpp \
    dialogEdition/widgetsEditeurs/DepartEditWidget.cpp \
    dialogEdition/widgetsEditeurs/DeplacementEditWidget.cpp \
    dialogEdition/widgetsEditeurs/EmplacementEditWidget.cpp \
    dialogEdition/widgetsEditeurs/ListeRegroupementEditWidget.cpp \
    dialogEdition/widgetsEditeurs/LoyerCompagnieTransportEditWidget.cpp \
    dialogEdition/widgetsEditeurs/PrisonEditWidget.cpp \
    dialogEdition/widgetsEditeurs/ProprieteEditWidget.cpp \
    dialogEdition/widgetsEditeurs/RegroupementEditWidget.cpp \
    dialogEdition/widgetsEditeurs/TaxeEditWidget.cpp \
    dialogEdition/widgetsEditeurs/TypeEmplacementEditWidget.cpp \
    dialogEdition/EditionEmplacement.cpp \
    dialogEdition/EditionListeRegroupements.cpp \
    donnees/cartes/Action.cpp \
    donnees/cartes/Carte.cpp \
    donnees/cartes/PileCartes.cpp \
    donnees/graphismes/GraphismeEmplacement.cpp \
    donnees/graphismes/GraphismeEmplacementInfos.cpp \
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
    widgetsSelecteurs/ColorSelectWidget.cpp \
    widgetsSelecteurs/FileSelectWidget.cpp \
    widgetsSelecteurs/FontSelectWidget.cpp \
    widgetsSelecteurs/ImageSelectWidget.cpp \
    MainWindow.cpp

HEADERS  += global.hpp \
    assistants/creationPlateau/AssistantCreationPlateau.hpp \
    assistants/creationPlateau/PageGraphisme.hpp \
    assistants/creationPlateau/PageImage.hpp \
    assistants/creationPlateau/PageIntro.hpp \
    assistants/creationPlateau/PageOuvrir.hpp \
    assistants/creationPlateau/PagePrix.hpp \
    assistants/creationPlateau/PageTaille.hpp \
    dialogEdition/donnees/RegroupementData.hpp \
    dialogEdition/donnees/TerrainData.hpp \
    dialogEdition/modeles/EmplacementListModel.hpp \
    dialogEdition/modeles/TerrainListModel.hpp \
    dialogEdition/modeles/SelectionRegroupementListModel.hpp \
    dialogEdition/modeles/RegroupementListModel.hpp \
    dialogEdition/widgetsEditeurs/ConstructionEditWidget.hpp \
    dialogEdition/widgetsEditeurs/DepartEditWidget.hpp \
    dialogEdition/widgetsEditeurs/DeplacementEditWidget.hpp \
    dialogEdition/widgetsEditeurs/EmplacementEditWidget.hpp \
    dialogEdition/widgetsEditeurs/ListeRegroupementEditWidget.hpp \
    dialogEdition/widgetsEditeurs/LoyerCompagnieTransportEditWidget.hpp \
    dialogEdition/widgetsEditeurs/PrisonEditWidget.hpp \
    dialogEdition/widgetsEditeurs/ProprieteEditWidget.hpp \
    dialogEdition/widgetsEditeurs/RegroupementEditWidget.hpp \
    dialogEdition/widgetsEditeurs/TaxeEditWidget.hpp \
    dialogEdition/widgetsEditeurs/TypeEmplacementEditWidget.hpp \
    dialogEdition/EditionEmplacement.hpp \
    dialogEdition/EditionListeRegroupements.hpp \
    donnees/cartes/Action.hpp \
    donnees/cartes/Carte.hpp \
    donnees/cartes/PileCartes.hpp \
    donnees/graphismes/GraphismeEmplacement.hpp \
    donnees/graphismes/GraphismeEmplacementInfos.hpp \
    donnees/emplacements/CompagnieTransport.hpp \
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
    donnees/Regle.hpp \
    widgetsSelecteurs/ColorSelectWidget.hpp \
    widgetsSelecteurs/FileSelectWidget.hpp \
    widgetsSelecteurs/FontSelectWidget.hpp \
    widgetsSelecteurs/ImageSelectWidget.hpp \
    MainWindow.hpp
