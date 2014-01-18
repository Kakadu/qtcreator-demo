#ifndef MYMOPTIONSPAGEWIDGET_H
#define MYMOPTIONSPAGEWIDGET_H

#include <QtCore/QDebug>
#include <coreplugin/dialogs/ioptionspage.h>

#include "optionsconstants.h"

class MyMoptionsPageWidget : public Core::IOptionsPage
{
   Q_OBJECT

public:
    explicit MyMoptionsPageWidget(QObject *parent = 0);

private:
    virtual QWidget* widget()  Q_DECL_OVERRIDE;
    void apply(void);

    void finish();

};

#endif // MYMOPTIONSPAGEWIDGET_H
