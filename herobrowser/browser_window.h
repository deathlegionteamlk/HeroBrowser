#ifndef BROWSER_WINDOW_H
#define BROWSER_WINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QLineEdit>
#include <QProgressBar>
#include <QWebEngineView>
#include <QStackedWidget>
#include <QTextEdit>

class BrowserWindow : public QMainWindow {
    Q_OBJECT

public:
    BrowserWindow(QWidget *parent = nullptr);
    ~BrowserWindow();

private slots:
    void addNewTab(const QUrl &url = QUrl("https://www.google.com"));
    void closeTab(int index);
    void updateUrlLine(const QUrl &url);
    void handleUrlEntered();
    void updateProgress(int progress);
    void handleTabChange(int index);
    void toggleAiSidebar();
    void handleAiInput();

private:
    void setupUi();
    void setupStyles();

    QTabWidget *tabWidget;
    QLineEdit *urlLineEdit;
    QProgressBar *progressBar;
    QWidget *sidebar;
    QTextEdit *aiChat;
    QLineEdit *aiInput;
    bool sidebarVisible;
};

#endif // BROWSER_WINDOW_H
