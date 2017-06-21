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
    partie/Tour.cpp \
    partie/SimulateurPartie.cpp \
    partie/PartieDecrite.cpp \
    partie/Joueur/JoueurFactory.cpp \
    UI/WidgetPartieGeneral.cpp \
    UI/WJouerPartie.cpp \
    UI/WApercuJoueur.cpp \
    UI/WApercuPartie.cpp \
    EventsManager.cpp \
    GameRunner.cpp \
    WGameRunner.cpp \
    GameRunnerThread.cpp \
    partie/AbstractGameSituation.cpp \
    partie/Game.cpp

HEADERS  += \
    partie/Tour.h \
    partie/SimulateurPartie.h \
    partie/PartieDecrite.h \
    partie/Joueur/JoueurFactory.h \
    UI/WidgetPartieGeneral.h \
    UI/WJouerPartie.h \
    Manager.hpp \
    UI/WManager.hpp \
    UI/WApercuJoueur.hpp \
    UI/WApercuPartie.hpp \
    EventsManager.hpp \
    partie/Joueur/Player.hpp \
    UI/MainWindow.hpp \
    GameRunner.hpp \
    WGameRunner.hpp \
    GameRunnerThread.hpp \
    partie/AbstractGameSituation.hpp \
    partie/Game.hpp

RESOURCES += \
    resources/resources.qrc
