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
    tools/batchrunner/WBatchRunner.cpp \
    UI/WManagerQWidget.cpp \
    partie/Joueur/JoueurFactory.cpp \
    UI/WAbstractPartie.cpp \
    partie/Partie.cpp \
    joueurs/JoueurExterneAbstrait.cpp \
    partie/SituationJeuAbstraite.cpp \
    partie/Joueur/Joueur.cpp \
    Foncteur.cpp

HEADERS  += \
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
    tools/batchrunner/WBatchRunner.hpp \
    UI/WManagerQWidget.hpp \
    partie/Joueur/Joueur.hpp \
    partie/Joueur/JoueurFactory.hpp \
    UI/WAbstractPartie.hpp \
    partie/Partie.hpp \
    joueurs/JoueurExterneAbstrait.hpp \
    partie/SituationJeuAbstraite.hpp \
    partie/Tour.hpp \
    unused.hpp \
    Foncteur.hpp

RESOURCES += \
    resources/resources.qrc
