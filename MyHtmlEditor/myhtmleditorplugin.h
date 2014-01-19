#ifndef DONOTHING_H
#define DONOTHING_H

#include <QtWidgets/QMenuBar>

#include <extensionsystem/iplugin.h>
#include <coreplugin/editormanager/ieditorfactory.h>
#include <coreplugin/icontext.h>
#include <coreplugin/mimedatabase.h>

#include "myhtmleditor_global.h"
#include "htmleditorfactory.h"

namespace MyHtmlEditor {
namespace Internal {

class HtmlEditorPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "MyHtmlEditor.json")
    Core::Context m_projectContext;

public:
    HtmlEditorPlugin();
    ~HtmlEditorPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private slots:

};

} // namespace Internal
} // namespace DoNothing

#endif // DONOTHING_H

