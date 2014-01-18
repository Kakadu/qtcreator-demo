#include "optionsplugin.h"
#include "optionsconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QtWidgets/QAction>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>

#include <QtCore/QtPlugin>

#include "mymoptionspagewidget.h"

using namespace SimpleOptions::Internal;

SimpleOptionsPlugin::SimpleOptionsPlugin()
{
}

SimpleOptionsPlugin::~SimpleOptionsPlugin()
{
}

bool SimpleOptionsPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.

    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    addAutoReleasedObject(new MyMoptionsPageWidget);
    return true;
}

void SimpleOptionsPlugin::extensionsInitialized()
{
}

ExtensionSystem::IPlugin::ShutdownFlag SimpleOptionsPlugin::aboutToShutdown()
{
    return SynchronousShutdown;
}

Q_EXPORT_PLUGIN2(SimpleOptions, SimpleOptionsPlugin)
