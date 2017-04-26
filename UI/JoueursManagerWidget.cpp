#include "JoueursManagerWidget.h"


JoueursManagerWidget::JoueursManagerWidget (QWidget *parent) :
    QWidget (parent)
{
    QVBoxLayout *layout = new QVBoxLayout;

    m_model = new QStandardItemModel;

    QTreeView *tree = new QTreeView();
    tree->setModel(m_model);
    tree->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(tree, SIGNAL(clicked(QModelIndex)), this, SLOT(_selectionnerJoueur(QModelIndex)));

    layout->addWidget(tree);

    setLayout(layout);
}

void JoueursManagerWidget::setJoueursManager (const JoueursManager *joueursManager)
{
    m_joueursManager = joueursManager;
    actualiser();
}


void JoueursManagerWidget::actualiser ()
{
    m_model->clear();

    for (int iJoueur=0; iJoueur<m_joueursManager->nbJoueurs(); iJoueur++) {
        m_model->setItem(iJoueur, 0, new QStandardItem(QString::number(iJoueur)));
    }
}


void JoueursManagerWidget::_selectionnerJoueur (const QModelIndex &index)
{
    const int idJoueur = m_model->data(index).toInt();

    emit joueurSelectionne (idJoueur);
}
