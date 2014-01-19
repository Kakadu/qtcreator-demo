#include "htmleditor.h"

HtmlEditor::HtmlEditor(HtmlEditorWidget* editorWidget)
: Core::IEditor(editorWidget)
{
    d = new HtmlEditorData;
    d->editorWidget = editorWidget;
    d->file = new HtmlFile(this, editorWidget);
    Core::UniqueIDManager* uidm = Core::UniqueIDManager::instance();
    d->context << uidm->uniqueIdentifier(HtmlEditorConstants::C_HTMLEDITOR);
    connect(d->editorWidget, SIGNAL(contentModified()),
            d->file, SLOT(modified()));
    connect(d->editorWidget, SIGNAL(titleChanged(QString)),
            this, SLOT(slotTitleChanged(QString)));
    connect(d->editorWidget, SIGNAL(contentModified()),
            this, SIGNAL(changed()));
}
HtmlEditor::~HtmlEditor()
{
    delete d;
}
QWidget* HtmlEditor::widget()
{
return d->editorWidget;
}
QList<int> HtmlEditor::context() const {
return d->context;
}

Core::IFile* HtmlEditor::file()
{
    return d->file;
}
bool HtmlEditor::createNew(const QString&contents)
{
    Q_UNUSED(contents);
    d->editorWidget->setContent(QByteArray());
    d->file->setFilename(QString());
    return true;
}
bool HtmlEditor::open(const QString &fileName)
{
    return d->file->open(fileName);
}
namespace HtmlEditorConstants
{
    const char* const C_HTMLEDITOR_MIMETYPE = "text/html";
    const char* const C_HTMLEDITOR = "HTML Editor";
}
const char* HtmlEditor::kind() const
{
    return HtmlEditorConstants::C_HTMLEDITOR;
}


QString HtmlEditor::displayName() const
{
    return d->displayName;
}

void HtmlEditor::setDisplayName(const QString& title)
{
    if(d->displayName == title)
        return;
    d->displayName = title;
    emit changed();
}

bool HtmlEditor::duplicateSupported(){
    return false;
}

Core::IEditor* HtmlEditor::duplicate(QWidget* parent) const
{
    Q_UNUSED(parent);
    return 0;
}

QByteArray HtmlEditor::saveState() const
{
    return QByteArray();
}

bool HtmlEditor::restoreState(const QByteArray&state)
{
    Q_UNUSED(state);
    return false;
}
QToolBar* HtmlEditor::toolBar()
{
    return NULL;
}

bool HtmlEditor::isTemporary() const {
    return false;
}
