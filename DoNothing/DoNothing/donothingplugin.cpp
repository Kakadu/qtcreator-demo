#include "donothingplugin.h"
#include "donothingconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

#include <QtPlugin>

using namespace DoNothing::Internal;

DoNothingPlugin::DoNothingPlugin()
{
    // Create your members
}

DoNothingPlugin::~DoNothingPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool DoNothingPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.

    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    QAction *action = new QAction(tr("About DoNothing"), this);
    Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
                                                             Core::Context(Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
    connect(action, SIGNAL(triggered()), this, SLOT(about()));

    Core::ActionContainer *menuContainer = Core::ActionManager::createMenu(Constants::MENU_ID);
    menuContainer->menu()->setTitle(tr("DoNothing"));
    menuContainer->addAction(cmd);
    // adding menu to toolbar before Help menu
    // use next line to add to the beginning
    //Core::ActionManager::actionContainer(Core::Constants::MENU_BAR)->addMenu(menu);
    QMenu *helpMenu =
            Core::ActionManager::actionContainer(Core::Constants::M_HELP)->menu();
    QMenuBar *menubar =
            Core::ActionManager::actionContainer(Core::Constants::MENU_BAR)->menuBar();
    menubar->insertMenu(helpMenu->menuAction(), menuContainer->menu());

    return true;
}

void DoNothingPlugin::about()
{
    QMessageBox::information(Core::ICore::mainWindow(),
                             tr("Action triggered"),
                             tr("About DoNothing."));
}

void DoNothingPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag DoNothingPlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

Q_EXPORT_PLUGIN2(DoNothing, DoNothingPlugin)

