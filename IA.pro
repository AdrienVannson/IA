# Inclusion du jeu
include(jeu.pri)

INCLUDEPATH = $$DOSSIER_JEU
include($$DOSSIER_JEU/$$FICHIER_JEU)


QT += core gui widgets

TARGET = IA
TEMPLATE = app

SOURCES += main.cpp\
    UI/MainWindow.cpp \
    partie/Tour.cpp \
    UI/WJouerPartie.cpp \
    UI/WApercuJoueur.cpp \
    UI/WApercuPartie.cpp \
    GameRunner.cpp \
    GameRunnerThread.cpp \
    tools/batchrunner/WBatchRunner.cpp \
    UI/WManagerQWidget.cpp \
    partie/Joueur/JoueurFactory.cpp \
    UI/WAbstractPartie.cpp \
    partie/Partie.cpp \
    joueurs/JoueurExterneAbstrait.cpp \
    partie/Joueur/Joueur.cpp \
    partie/simulerPartie.cpp \
    CallbackFinSimulation.cpp

HEADERS  += \
    UI/WJouerPartie.h \
    Manager.hpp \
    UI/WManager.hpp \
    UI/WApercuJoueur.hpp \
    UI/WApercuPartie.hpp \
    UI/MainWindow.hpp \
    GameRunner.hpp \
    GameRunnerThread.hpp \
    tools/batchrunner/WBatchRunner.hpp \
    UI/WManagerQWidget.hpp \
    partie/Joueur/Joueur.hpp \
    partie/Joueur/JoueurFactory.hpp \
    UI/WAbstractPartie.hpp \
    partie/Partie.hpp \
    joueurs/JoueurExterneAbstrait.hpp \
    partie/Tour.hpp \
    unused.hpp \
    partie/simulerPartie.hpp \
    CallbackFinSimulation.hpp

RESOURCES += \
    resources/resources.qrc
