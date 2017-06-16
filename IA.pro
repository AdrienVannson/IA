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
    partie/SimulateurPartie.cpp \
    partie/PartieDecrite.cpp \
    partie/Joueur/JoueurFactory.cpp \
    partie/ActionGenerale.cpp \
    partie/SituationJeuGenerale.cpp \
    UI/WidgetPartieGeneral.cpp \
    UI/WJouerPartie.cpp \
    UI/WApercuJoueur.cpp \
    UI/WApercuPartie.cpp \
    EventsManager.cpp

HEADERS  += UI/MainWindow.h \
    partie/Partie.h \
    partie/Tour.h \
    partie/Joueur/Joueur.h \
    partie/SimulateurPartie.h \
    partie/PartieDecrite.h \
    partie/Joueur/JoueurFactory.h \
    partie/ActionGenerale.h \
    partie/SituationJeuGenerale.h \
    UI/WidgetPartieGeneral.h \
    UI/WJouerPartie.h \
    Manager.hpp \
    UI/WManager.hpp \
    UI/WApercuJoueur.hpp \
    UI/WApercuPartie.hpp \
    EventsManager.hpp

RESOURCES += \
    resources/resources.qrc
