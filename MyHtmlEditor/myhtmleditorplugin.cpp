#include "myhtmleditorplugin.h"
#include "myhtmleditorconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QMainWindow>

using namespace MyHtmlEditor::Internal;

HtmlEditorPlugin::HtmlEditorPlugin()
{
    // Create your members
}

HtmlEditorPlugin::~HtmlEditorPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool HtmlEditorPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.

    Q_UNUSED(arguments)
    Q_UNUSED(errorString)


    //Core::ICore* core = Core::ICore::instance();
    //Core::MimeDatabase* mdb = core->mimeDatabase();

    QLatin1String const mimeTypes("text-html-mimetype.xml");
    if(Core::MimeDatabase::addMimeTypes(mimeTypes, errorString))
        return false;
    addAutoReleasedObject(new HtmlEditorFactory(this));
    return true;

    /*
    QAction *action = new QAction(tr("About MyHtmlEditor"), this);
    Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
                                                             Core::Context(Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
    connect(action, SIGNAL(triggered()), this, SLOT(about()));

    Core::ActionContainer *menuContainer = Core::ActionManager::createMenu(Constants::MENU_ID);
    menuContainer->menu()->setTitle(tr("MyHtmlEditor"));
    menuContainer->addAction(cmd);
    // adding menu to toolbar before Help menu
    // use next line to add to the beginning
    //Core::ActionManager::actionContainer(Core::Constants::MENU_BAR)->addMenu(menu);
    QMenu *helpMenu =
            Core::ActionManager::actionContainer(Core::Constants::M_HELP)->menu();
    QMenuBar *menubar =
            Core::ActionManager::actionContainer(Core::Constants::MENU_BAR)->menuBar();
    menubar->insertMenu(helpMenu->menuAction(), menuContainer->menu());
    */
    return true;
}

void HtmlEditorPlugin::extensionsInitialized()
{
}

ExtensionSystem::IPlugin::ShutdownFlag HtmlEditorPlugin::aboutToShutdown()
{
    return SynchronousShutdown;
}

Q_EXPORT_PLUGIN2(HtmlEditor, HtmlEditorPlugin)

