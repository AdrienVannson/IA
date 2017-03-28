#-------------------------------------------------
#
# Project created by QtCreator 2017-02-21T20:31:42
#
#-------------------------------------------------


# Inclusion du jeu
PATH_JEU = jeux/CodinGame/Tron-Battle

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
    $$PATH_JEU/Simulateur.cpp \
    $$PATH_JEU/Action.cpp \
    $$PATH_JEU/SituationJeu.cpp \
    $$PATH_JEU/WidgetPartie.cpp \
    $$PATH_JEU/InformationsTourJoueur.cpp \
    partie/JoueursManager.cpp \
    UI/PartiesManagerWidget.cpp \
    partie/PartieDecrite.cpp \
    partie/Joueur/JoueurFactory.cpp \
    jeux/CodinGame/Tron-Battle/Joueurs/Glouton1/Glouton1.cpp \
    jeux/CodinGame/Tron-Battle/Joueurs/Glouton1/Glouton1Factory.cpp

HEADERS  += UI/MainWindow.h \
    partie/Partie.h \
    partie/Tour.h \
    partie/Joueur/Joueur.h \
    partie/SimulateurPartie.h \
    partie/PartiesManager.h \
    $$PATH_JEU/Simulateur.h \
    $$PATH_JEU/Action.h \
    $$PATH_JEU/SituationJeu.h \
    $$PATH_JEU/WidgetPartie.h \
    $$PATH_JEU/InformationsTourJoueur.h \
    partie/JoueursManager.h \
    UI/PartiesManagerWidget.h \
    partie/PartieDecrite.h \
    partie/Joueur/JoueurFactory.h \
    jeux/CodinGame/Tron-Battle/Joueurs/Glouton1/Glouton1.h \
    jeux/CodinGame/Tron-Battle/Joueurs/Glouton1/Glouton1Factory.h

FORMS    +=
