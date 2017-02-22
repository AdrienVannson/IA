#-------------------------------------------------
#
# Project created by QtCreator 2017-02-21T20:31:42
#
#-------------------------------------------------

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
    partie/SituationJeu.cpp \
    partie/Action.cpp \
    partie/Simulateur.cpp

HEADERS  += UI/MainWindow.h \
    partie/PartieManager.h \
    partie/Partie.h \
    partie/PartieDetaillee.h \
    partie/Tour.h \
    partie/SituationJeu.h \
    partie/Action.h \
    partie/Simulateur.h \
    jeux/defaut/Action.h \
    config.h

FORMS    +=
