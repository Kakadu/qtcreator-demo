#ifndef HTMLEDITORWIDGET_H
#define HTMLEDITORWIDGET_H

#include <QtCore/QByteArray>
#include <QtWidgets/QTabWidget>
#include <QtWebKit/QWebView>

struct HtmlEditorWidgetData;

class HtmlEditorWidget : public QTabWidget {
    Q_OBJECT
public:
    HtmlEditorWidget(QWidget* parent= 0);
    ~HtmlEditorWidget();
    void setContent(const QByteArray& ba, const QString& path=QString());
    QByteArray content() const;

    QString title() const;
protected slots:
    void slotCurrentTabChanged(int tab);
    void slotContentModified();
signals:
    void contentModified();
    void titleChanged(const QString&);
private:
    HtmlEditorWidgetData* d;
};

struct HtmlEditorWidgetData
{
    QWebView* webView;
};

#endif // HTMLEDITORWIDGET_H
