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
    UI/WJouerPartie.cpp \
    UI/WApercuJoueur.cpp \
    UI/WApercuPartie.cpp \
    EventsManager.cpp \
    GameRunner.cpp \
    UI/WGameRunner.cpp \
    GameRunnerThread.cpp \
    partie/AbstractGameSituation.cpp \
    partie/Game.cpp \
    joueurs/AbstractExternalPlayer.cpp \
    partie/DescribedGame.cpp \
    UI/WAbstractGame.cpp \
    tools/batchrunner/WBatchRunner.cpp \
    UI/WManagerQWidget.cpp \
    partie/Joueur/JoueurFactory.cpp

HEADERS  += \
    partie/Tour.h \
    partie/SimulateurPartie.h \
    UI/WJouerPartie.h \
    Manager.hpp \
    UI/WManager.hpp \
    UI/WApercuJoueur.hpp \
    UI/WApercuPartie.hpp \
    EventsManager.hpp \
    UI/MainWindow.hpp \
    GameRunner.hpp \
    UI/WGameRunner.hpp \
    GameRunnerThread.hpp \
    partie/AbstractGameSituation.hpp \
    partie/Game.hpp \
    joueurs/AbstractExternalPlayer.hpp \
    partie/DescribedGame.hpp.h \
    UI/WAbstractGame.hpp \
    tools/batchrunner/WBatchRunner.hpp \
    UI/WManagerQWidget.hpp \
    partie/Joueur/Joueur.hpp \
    partie/Joueur/JoueurFactory.hpp

RESOURCES += \
    resources/resources.qrc
