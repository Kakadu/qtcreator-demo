#ifndef HTMLEDITORFACTORY_H
#define HTMLEDITORFACTORY_H

#include <coreplugin/editormanager/ieditorfactory.h>

#include "htmleditorwidget.h"
//#include "myhtmleditorplugin.h"

struct HtmlEditorFactoryData;
#include <extensionsystem/iplugin.h>

class HtmlEditorFactory : public Core::IEditorFactory {
    Q_OBJECT
public:
    HtmlEditorFactory(ExtensionSystem::IPlugin* owner);
    ~HtmlEditorFactory();
    QStringList mimeTypes() const;
    QString kind() const;
    Core::IEditor* createEditor(QWidget* parent);
    Core::IDocument* open(const QString &fileName);
private:
    HtmlEditorFactoryData* d;
};

namespace HtmlEditorConstants
{
const char* const C_HTMLEDITOR_MIMETYPE = "text/html";
const char* const C_HTMLEDITOR  = "HTML Editor";
}
struct HtmlEditorFactoryData
{
    HtmlEditorFactoryData()
        : kind(QString::fromUtf8(HtmlEditorConstants::C_HTMLEDITOR))
    {
        mimeTypes << QString::fromAscii(HtmlEditorConstants::C_HTMLEDITOR_MIMETYPE);
    }
    QString kind;
    QStringList mimeTypes;
};

#endif // HTMLEDITORFACTORY_H
