#ifndef DONOTHING_H
#define DONOTHING_H

#include "donothing_global.h"

#include <extensionsystem/iplugin.h>
#include <coreplugin/editormanager/ieditorfactory.h>
#include <coreplugin/icontext.h>
#include <QMenuBar>

namespace DoNothing {
namespace Internal {

class DoNothingPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "DoNothing.json")
    Core::Context m_projectContext;

public:
    DoNothingPlugin();
    ~DoNothingPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private slots:
    void about();
};

} // namespace Internal
} // namespace DoNothing

#endif // DONOTHING_H

