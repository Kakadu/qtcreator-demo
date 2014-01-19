#include "htmlfile.h"

HtmlFile::HtmlFile(HtmlEditor* editor, HtmlEditorWidget* editorWidget)
                   : QObject() /* Core::IFile(editor) */
{
    d = new HtmlFileData;
    d->editor = editor;
    d->editorWidget = editorWidget;
}

HtmlFile::~HtmlFile()
{
    delete d;
}

void HtmlFile::setModified(bool val)
{
    if(d->modified == val)
        return;
    d->modified = val;
    emit changed();
}
bool HtmlFile::isModified() const
{
    return d->modified;
}
QString HtmlFile::mimeType() const
{
    return d->mimeType;
}

bool HtmlFile::save(const QString& fileName)
{
    QFile file(fileName);

    if(file.open(QFile::WriteOnly))
    {
        d->fileName = fileName;
        QByteArray content = d->editorWidget->content();
        file.write(content);
        setModified(false);
        return true;
    }
    return false;
}

bool HtmlFile::open(const QString& fileName)
{
    QFile file(fileName);

    if(file.open(QFile::ReadOnly))
    {
        d->fileName = fileName;

        QString path = QFileInfo(fileName).absolutePath();
        d->editorWidget->setContent(file.readAll(), path);
        d->editor->setDisplayName(d->editorWidget->title());
        return true;
    }
    return false;
}

void HtmlFile::setFilename(const QString&filename)
{
    d->fileName = filename;
}

QString HtmlFile::fileName() const
{
    return d->fileName;
}
QString HtmlFile::defaultPath() const
{
    return QString();
}
QString HtmlFile::suggestedFileName() const
{
    return QString();
}

QString HtmlFile::fileFilter() const
{
    return QString();
}
QString HtmlFile::fileExtension() const
{
    return QString();
}
bool HtmlFile::isReadOnly() const {
    return false;
}

bool HtmlFile::isSaveAsAllowed() const{
    return true;
}
void HtmlFile::modified(ReloadBehavior* behavior)
{
    Q_UNUSED(behavior);
}
