#-------------------------------------------------
#
# Project created by QtCreator 2012-09-20T19:31:45
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



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
    dialogEdition/modeles/EmplacementListModel.cpp \
    dialogEdition/modeles/PileCartesListModel.cpp \
    dialogEdition/modeles/SelectionRegroupementListModel.cpp \
    dialogEdition/modeles/RegroupementListModel.cpp \
    dialogEdition/widgetsEditeurs/ActionEditWidget.cpp \
    dialogEdition/widgetsEditeurs/CarteEditWidget.cpp \
    dialogEdition/widgetsEditeurs/ConstructionEditWidget.cpp \
    dialogEdition/widgetsEditeurs/DepartEditWidget.cpp \
    dialogEdition/widgetsEditeurs/DeplacementEditWidget.cpp \
    dialogEdition/widgetsEditeurs/EmplacementEditWidget.cpp \
    dialogEdition/widgetsEditeurs/ListePilesCartesEditWidget.cpp \
    dialogEdition/widgetsEditeurs/ListeRegroupementEditWidget.cpp \
    dialogEdition/widgetsEditeurs/LoyerCompagnieTransportEditWidget.cpp \
    dialogEdition/widgetsEditeurs/LoyerServiceEditWidget.cpp \
    dialogEdition/widgetsEditeurs/LoyerTerrainEditWidget.cpp \
    dialogEdition/widgetsEditeurs/PiocheEditWidget.cpp \
    dialogEdition/widgetsEditeurs/PileCartesEditWidget.cpp \
    dialogEdition/widgetsEditeurs/PrisonEditWidget.cpp \
    dialogEdition/widgetsEditeurs/ProprieteEditWidget.cpp \
    dialogEdition/widgetsEditeurs/RegroupementEditWidget.cpp \
    dialogEdition/widgetsEditeurs/TaxeEditWidget.cpp \
    dialogEdition/widgetsEditeurs/TypeEmplacementEditWidget.cpp \
    dialogEdition/EditionCarte.cpp \
    dialogEdition/EditionEmplacement.cpp \
    dialogEdition/EditionListePilesCartes.cpp \
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
    dialogEdition/modeles/EmplacementListModel.hpp \
    dialogEdition/modeles/PileCartesListModel.hpp \
    dialogEdition/modeles/SelectionRegroupementListModel.hpp \
    dialogEdition/modeles/RegroupementListModel.hpp \
    dialogEdition/widgetsEditeurs/ActionEditWidget.hpp \
    dialogEdition/widgetsEditeurs/CarteEditWidget.hpp \
    dialogEdition/widgetsEditeurs/ConstructionEditWidget.hpp \
    dialogEdition/widgetsEditeurs/DepartEditWidget.hpp \
    dialogEdition/widgetsEditeurs/DeplacementEditWidget.hpp \
    dialogEdition/widgetsEditeurs/EmplacementEditWidget.hpp \
    dialogEdition/widgetsEditeurs/ListePilesCartesEditWidget.hpp \
    dialogEdition/widgetsEditeurs/ListeRegroupementEditWidget.hpp \
    dialogEdition/widgetsEditeurs/LoyerCompagnieTransportEditWidget.hpp \
    dialogEdition/widgetsEditeurs/LoyerServiceEditWidget.hpp \
    dialogEdition/widgetsEditeurs/LoyerTerrainEditWidget.hpp \
    dialogEdition/widgetsEditeurs/PiocheEditWidget.hpp \
    dialogEdition/widgetsEditeurs/PileCartesEditWidget.hpp \
    dialogEdition/widgetsEditeurs/PrisonEditWidget.hpp \
    dialogEdition/widgetsEditeurs/ProprieteEditWidget.hpp \
    dialogEdition/widgetsEditeurs/RegroupementEditWidget.hpp \
    dialogEdition/widgetsEditeurs/SauvegardeInterface.hpp \
    dialogEdition/widgetsEditeurs/TaxeEditWidget.hpp \
    dialogEdition/widgetsEditeurs/TypeEmplacementEditWidget.hpp \
    dialogEdition/EditionCarte.hpp \
    dialogEdition/EditionEmplacement.hpp \
    dialogEdition/EditionListePilesCartes.hpp \
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
    widgetsSelecteurs/ColorSelectWidget.hpp \
    widgetsSelecteurs/FileSelectWidget.hpp \
    widgetsSelecteurs/FontSelectWidget.hpp \
    widgetsSelecteurs/ImageSelectWidget.hpp \
    widgetsSelecteurs/PointerComboBox.hpp \
    MainWindow.hpp


