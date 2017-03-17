#ifndef PARTIESMANAGERWIDGET_H
#define PARTIESMANAGERWIDGET_H

#include <QWidget>
#include <QtWidgets>

#include "partie/PartiesManager.h"


class PartiesManagerWidget : public QWidget
{
    Q_OBJECT

public:

    explicit PartiesManagerWidget (QWidget *parent = 0);

    void setPartiesManager (const PartiesManager *partiesManager);


signals:


public slots:

    void actualiser ();


private:

    const PartiesManager *m_partiesManager;

    QStandardItemModel *m_model;


};

#endif // PARTIESMANAGERWIDGET_H
