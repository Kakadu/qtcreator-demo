#ifndef OPTIONSPLUGIN_H
#define OPTIONSPLUGIN_H

#include <extensionsystem/iplugin.h>

#include "options_global.h"

namespace SimpleOptions {
namespace Internal {

class SimpleOptionsPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "Options.json")

public:
    SimpleOptionsPlugin();
    ~SimpleOptionsPlugin();

    bool initialize(const QStringList &arguments, QString *errorString)  Q_DECL_OVERRIDE;
    void extensionsInitialized() Q_DECL_OVERRIDE;
    ShutdownFlag aboutToShutdown() Q_DECL_OVERRIDE;

};

} // namespace Internal
} // namespace SimpleOptions

#endif // OPTIONSPLUGIN_H

