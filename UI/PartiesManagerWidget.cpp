#include "PartiesManagerWidget.h"


PartiesManagerWidget::PartiesManagerWidget (QWidget *parent) :
    QWidget (parent)
{
    QVBoxLayout *layout = new QVBoxLayout;

    m_model = new QStandardItemModel;

    QTreeView *tree = new QTreeView();
    tree->setModel(m_model);

    layout->addWidget(tree);

    setLayout(layout);
}

void PartiesManagerWidget::setPartiesManager (const PartiesManager *partiesManager)
{
    m_partiesManager = partiesManager;
}


void PartiesManagerWidget::actualiser ()
{
    m_model->clear();

    int iPartie = 0;

    for (const Partie *partie : *m_partiesManager->parties()) {
        m_model->setItem(iPartie, 0, new QStandardItem(QString::number(iPartie)));


        iPartie++;
    }
}
