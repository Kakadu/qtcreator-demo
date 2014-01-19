#include "htmleditorwidget.h"

HtmlEditorWidget::HtmlEditorWidget(QWidget* parent)
    : QTabWidget(parent)
{
    d = new HtmlEditorWidgetData;

    d->webView = new QWebView;
    d->textEdit = new QPlainTextEdit;
    addTab(d->webView, "Preview");
    addTab(d->textEdit, "Source");
    setTabPosition(QTabWidget::South);
    setTabShape(QTabWidget::Triangular);
    d->textEdit->setFont( QFont("Courier", 12) );
    connect(this, SIGNAL(currentChanged(int)),
            this, SLOT(slotCurrentTabChanged(int)));
    connect(d->textEdit, SIGNAL(textChanged()),
            this, SLOT(slotContentModified()));
    connect(d->webView, SIGNAL(titleChanged(QString)),
            this, SIGNAL(titleChanged(QString)));
    d->modified = false;
}

HtmlEditorWidget::~HtmlEditorWidget()
{
    delete d;
}

void HtmlEditorWidget::setContent(const QByteArray& ba, const QString& path)
{
    if(path.isEmpty())
        d->webView->setHtml(ba);
    else
        d->webView->setHtml(ba, "file:///" + path);
    d->textEdit->setPlainText(ba);
    d->modified = false;
    d->path = path;
}

QByteArray HtmlEditorWidget::content() const
{
    QString htmlText = d->textEdit->toPlainText();
    return htmlText.toAscii();
}

QString HtmlEditorWidget::title() const
{
    return d->webView->title();
}

void HtmlEditorWidget::slotCurrentTabChanged(int tab)
{
    if(tab == 0 && d->modified)
        setContent( content(), d->path );
}

void HtmlEditorWidget::slotContentModified()
{
    d->modified = true;
    emit contentModified();
}


