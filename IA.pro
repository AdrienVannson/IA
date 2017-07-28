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
    UI/WidgetPartieGeneral.cpp \
    UI/WJouerPartie.cpp \
    UI/WApercuJoueur.cpp \
    UI/WApercuPartie.cpp \
    EventsManager.cpp \
    GameRunner.cpp \
    UI/WGameRunner.cpp \
    GameRunnerThread.cpp \
    partie/AbstractGameSituation.cpp \
    partie/Game.cpp \
    players/AbstractExternalPlayer.cpp \
    partie/Joueur/PlayerFactory.cpp \
    partie/DescribedGame.cpp

HEADERS  += \
    partie/Tour.h \
    partie/SimulateurPartie.h \
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
    UI/WGameRunner.hpp \
    GameRunnerThread.hpp \
    partie/AbstractGameSituation.hpp \
    partie/Game.hpp \
    players/AbstractExternalPlayer.hpp \
    partie/Joueur/PlayerFactory.hpp \
    partie/DescribedGame.hpp.h

RESOURCES += \
    resources/resources.qrc
