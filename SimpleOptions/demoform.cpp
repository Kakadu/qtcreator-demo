#include "demoform.h"

DemoForm::DemoForm(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *l = new QVBoxLayout(this);
    QLabel *l1 = new QLabel();
    l1->setText(QString::fromAscii("1st name"));
    QLineEdit *e1 = new QLineEdit();
    e1->setText(QString::fromAscii("Name"));
    QLabel *l2 = new QLabel();
    l2->setText(QString::fromAscii("2nd name"));
    QLineEdit *e2 = new QLineEdit();
    e2->setText(QString::fromAscii("Surname"));
    l->addWidget(l1);
    l->addWidget(e1);
    l->addWidget(l2);
    l->addWidget(e2);
}
