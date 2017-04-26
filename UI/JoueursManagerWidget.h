#ifndef JOUEURSMANAGERWIDGET_H
#define JOUEURSMANAGERWIDGET_H

#include <QStandardItemModel>
#include <QTreeView>
#include <QVBoxLayout>
#include <QWidget>

#include "partie/JoueursManager.h"


class JoueursManagerWidget : public QWidget
{
    Q_OBJECT


public:

    explicit JoueursManagerWidget (QWidget *parent = 0);

    void setJoueursManager (const JoueursManager *joueursManager);



signals:

    void joueurSelectionne (const int id);



public slots:

    void actualiser ();



private slots:

    void _selectionnerJoueur (const QModelIndex &index); // Appelé lorsqu'un joueur est sélectionné


private:

    const JoueursManager *m_joueursManager;

    QStandardItemModel *m_model;

};

#endif // JOUEURSMANAGERWIDGET_H
