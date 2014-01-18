#ifndef DEMOFORM_H
#define DEMOFORM_H

#include <QtCore/QDebug>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

class DemoForm : public QWidget
{
    Q_OBJECT
public:
    explicit DemoForm(QWidget *parent = 0);

};

#endif // DEMOFORM_H
