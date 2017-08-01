#ifndef WMANAGERQWIDGET_HPP
#define WMANAGERQWIDGET_HPP

#include <QWidget>


class WManagerQWidget : public QWidget // Workaround : Qt doesn't support templates
{
    Q_OBJECT


public:

    explicit WManagerQWidget (QWidget *parent=0);


signals:

    void widgetCreated (QWidget *widget);


};

#endif // WMANAGERQWIDGET_HPP
