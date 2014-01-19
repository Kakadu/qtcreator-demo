#ifndef HTMLFILE_H
#define HTMLFILE_H

#include <coreplugin/coreplugin.h>
#include <coreplugin/ifilewizardextension.h>
#include <QtCore/QFile>

#include "htmleditorwidget.h"
#include "myhtmleditorconstants.h"

struct HtmlFileData;
class HtmlFile : public QObject /* Core::IFile */ {
Q_OBJECT

public:
    HtmlFile(HtmlEditor* editor, HtmlEditorWidget*editorWidget);
    ~HtmlFile();
    void setModified(bool val=true);
    // Declare all the virtual functions from IFile here..
protected slots:
    void modified() { setModified(true); }

private:
    HtmlFileData* d;
};

struct HtmlFileData
{
    HtmlFileData() : mimeType(MyHtmlEditor::Constants::C_HTMLEDITOR_MIMETYPE),
        editorWidget(0), editor(0), modified(false)
    { }

    const QString mimeType;
    HtmlEditorWidget* editorWidget;
    HtmlEditor* editor;
    QString fileName;
    bool modified;
};

#endif // HTMLFILE_H
