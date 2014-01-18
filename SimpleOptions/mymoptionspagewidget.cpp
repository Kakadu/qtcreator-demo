#include "mymoptionspagewidget.h"
#include "demoform.h"

using namespace SimpleOptions;

MyMoptionsPageWidget::MyMoptionsPageWidget(QObject *parent)
: Core::IOptionsPage(parent)
{
    setId(Core::Id("MyOptionsPageID"));
    setDisplayName(tr("Simple Options Plugin"));

    // Create a new category for the options page. Here we create a totally
    // new category. In that case we also provide an icon. If we choose in
    // 'setCategory' an already existing category, the options page is added
    // the chosen category and an additional tab. No icon is set in this case.
    setCategory(Constants::MYOPTIONSPAGE_CATEGORY);
    setDisplayCategory(QLatin1String(
        Constants::MYOPTIONSPAGE_CATEGORY_TR_CATEGORY));
    setCategoryIcon(
        QLatin1String(Constants::MYOPTIONSPAGE_CATEGORY_CATEGORY_ICON));
}

QWidget *MyMoptionsPageWidget::widget()
{
    return new DemoForm();
}

void MyMoptionsPageWidget::apply()
{
    qDebug() << "In options `apply` button has been pressed";
}

void MyMoptionsPageWidget::finish()
{
    qDebug() << "In options `finish` button has been pressed";
}

