# Inclusion du jeu
PATH_JEU = jeux/CodinGame/Tron-Battle

include($$PATH_JEU/Tron-Battle.pri)


INCLUDEPATH = $$PATH_JEU



QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IA
TEMPLATE = app

SOURCES += main.cpp\
    UI/MainWindow.cpp \
    partie/Partie.cpp \
    partie/Tour.cpp \
    partie/Joueur/Joueur.cpp \
    partie/PartiesManager.cpp \
    partie/SimulateurPartie.cpp \
    partie/JoueursManager.cpp \
    UI/PartiesManagerWidget.cpp \
    partie/PartieDecrite.cpp \
    partie/Joueur/JoueurFactory.cpp \
    UI/JoueursManagerWidget.cpp \
    partie/ActionGenerale.cpp \
    partie/SituationJeuGenerale.cpp \
    UI/WidgetPartieGeneral.cpp \
    UI/JouerPartieWidget.cpp

HEADERS  += UI/MainWindow.h \
    partie/Partie.h \
    partie/Tour.h \
    partie/Joueur/Joueur.h \
    partie/SimulateurPartie.h \
    partie/PartiesManager.h \
    partie/JoueursManager.h \
    UI/PartiesManagerWidget.h \
    partie/PartieDecrite.h \
    partie/Joueur/JoueurFactory.h \
    UI/JoueursManagerWidget.h \
    partie/ActionGenerale.h \
    partie/SituationJeuGenerale.h \
    UI/WidgetPartieGeneral.h \
    UI/JouerPartieWidget.h
