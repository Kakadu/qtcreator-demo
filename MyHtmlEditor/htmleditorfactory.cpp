#include "htmleditorfactory.h"

HtmlEditorFactory::HtmlEditorFactory(HtmlEditorPlugin* owner)
    : Core::IEditorFactory(owner)
{
    d = new HtmlEditorFactoryData;
}

HtmlEditorFactory::~HtmlEditorFactory()
{
    delete d;
}
QStringList HtmlEditorFactory::mimeTypes() const
{
    return d->mimeTypes;
}

QString HtmlEditorFactory::kind() const
{
    return d->kind;
}

Core::IFile* HtmlEditorFactory::open(const QString& fileName)
{
    Core::EditorManager* em = Core::EditorManager::instance();
    Core::IEditor* iface = em->openEditor(fileName, d->kind);
    return iface ? iface->file() : 0;
}
Core::IEditor* HtmlEditorFactory::createEditor(QWidget* parent)
{
    HtmlEditorWidget* editorWidget = new HtmlEditorWidget(parent);
    return new HtmlEditor(editorWidget);
}
