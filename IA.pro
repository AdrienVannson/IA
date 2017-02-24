#-------------------------------------------------
#
# Project created by QtCreator 2017-02-21T20:31:42
#
#-------------------------------------------------


# Inclusion du jeu
PATH_JEU = jeux/tron-battle

INCLUDEPATH = $$PATH_JEU



QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IA
TEMPLATE = app

SOURCES += main.cpp\
    UI/MainWindow.cpp \
    partie/PartieManager.cpp \
    partie/Partie.cpp \
    partie/PartieDetaillee.cpp \
    partie/Tour.cpp \
    partie/Simulateur.cpp \
    $$PATH_JEU/Action.cpp \
    $$PATH_JEU/SituationJeu.cpp

HEADERS  += UI/MainWindow.h \
    partie/PartieManager.h \
    partie/Partie.h \
    partie/PartieDetaillee.h \
    partie/Tour.h \
    partie/Simulateur.h \
    config.h \
    $$PATH_JEU/Action.h \
    $$PATH_JEU/SituationJeu.h

FORMS    +=
