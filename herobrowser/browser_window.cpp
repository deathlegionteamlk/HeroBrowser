#include "browser_window.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QWebEngineProfile>
#include <QWebEngineSettings>
#include <QToolBar>
#include <QStatusBar>

BrowserWindow::BrowserWindow(QWidget *parent) : QMainWindow(parent), sidebarVisible(true) {
    setupUi();
    setupStyles();
    addNewTab();
}

BrowserWindow::~BrowserWindow() {}

void BrowserWindow::setupUi() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // Side Icon Bar (Opera GX Style)

    QWidget *sideIcons = new QWidget();
    sideIcons->setFixedWidth(60);
    sideIcons->setObjectName("sideIcons");
    QVBoxLayout *sideIconsLayout = new QVBoxLayout(sideIcons);
    sideIconsLayout->setContentsMargins(5, 10, 5, 10);
    sideIconsLayout->setSpacing(20);

    QPushButton *aiBtn = new QPushButton("AI");
    aiBtn->setFixedSize(40, 40);
    aiBtn->setObjectName("sidebarBtn");
    aiBtn->setToolTip("AI Assistant (Death Legion AI)");
    connect(aiBtn, &QPushButton::clicked, this, &BrowserWindow::toggleAiSidebar);
    
    QPushButton *homeBtn = new QPushButton("H");
    homeBtn->setFixedSize(40, 40);
    homeBtn->setObjectName("sidebarBtn");
    homeBtn->setToolTip("Home");
    
    QPushButton *settingsBtn = new QPushButton("S");
    settingsBtn->setFixedSize(40, 40);
    settingsBtn->setObjectName("sidebarBtn");
    settingsBtn->setToolTip("Settings");

    sideIconsLayout->addWidget(homeBtn);
    sideIconsLayout->addWidget(aiBtn);
    sideIconsLayout->addStretch();
    sideIconsLayout->addWidget(settingsBtn);
    
    mainLayout->addWidget(sideIcons);

    // Main Content Area
    QWidget *contentArea = new QWidget();
    QHBoxLayout *contentHLayout = new QHBoxLayout(contentArea);
    contentHLayout->setContentsMargins(0, 0, 0, 0);
    contentHLayout->setSpacing(0);

    QWidget *browserAndHeader = new QWidget();
    QVBoxLayout *contentLayout = new QVBoxLayout(browserAndHeader);
    contentLayout->setContentsMargins(0, 0, 0, 0);
    contentLayout->setSpacing(0);

    // Custom Top Bar / Header
    QWidget *header = new QWidget();
    header->setFixedHeight(50);
    header->setObjectName("header");
    QHBoxLayout *headerLayout = new QHBoxLayout(header);
    
    QLabel *headline = new QLabel("HeroBrowser | By Death Legion Team");
    headline->setObjectName("headline");
    headerLayout->addWidget(headline);
    
    urlLineEdit = new QLineEdit();
    urlLineEdit->setObjectName("urlInput");
    connect(urlLineEdit, &QLineEdit::returnPressed, this, &BrowserWindow::handleUrlEntered);
    headerLayout->addWidget(urlLineEdit);

    contentLayout->addWidget(header);

    // Tab Widget
    tabWidget = new QTabWidget();
    tabWidget->setTabsClosable(true);
    tabWidget->setMovable(true);
    tabWidget->setObjectName("tabWidget");
    connect(tabWidget, &QTabWidget::tabCloseRequested, this, &BrowserWindow::closeTab);
    connect(tabWidget, &QTabWidget::currentChanged, this, &BrowserWindow::handleTabChange);
    
    contentLayout->addWidget(tabWidget);

    // Progress Bar
    progressBar = new QProgressBar();
    progressBar->setFixedHeight(2);
    progressBar->setTextVisible(false);
    progressBar->setMaximum(100);
    contentLayout->addWidget(progressBar);

    contentHLayout->addWidget(browserAndHeader);

    // AI Sidebar Panel
    QWidget *aiPanel = new QWidget();
    aiPanel->setFixedWidth(250);
    aiPanel->setObjectName("aiPanel");
    aiPanel->setVisible(false); // Hidden by default
    QVBoxLayout *aiLayout = new QVBoxLayout(aiPanel);
    
    QLabel *aiTitle = new QLabel("Death Legion AI Assistant");
    aiTitle->setObjectName("aiTitle");
    aiLayout->addWidget(aiTitle);

    aiChat = new QTextEdit();
    aiChat->setReadOnly(true);
    aiChat->setObjectName("aiChat");
    aiChat->append("AI: Welcome to HeroBrowser. How can I help you today?");
    aiLayout->addWidget(aiChat);

    aiInput = new QLineEdit();
    aiInput->setPlaceholderText("Ask anything...");
    aiInput->setObjectName("aiInput");
    connect(aiInput, &QLineEdit::returnPressed, this, &BrowserWindow::handleAiInput);
    aiLayout->addWidget(aiInput);

    contentHLayout->addWidget(aiPanel);
    this->sidebar = aiPanel; // Reuse sidebar pointer for toggle

    mainLayout->addWidget(contentArea);
}

void BrowserWindow::setupStyles() {
    QString style = R"(
        QMainWindow { background-color: #0b0b0b; }
        #sideIcons { background-color: #121212; border-right: 1px solid #ff0033; }
        #aiPanel { background-color: #1a1a1a; border-left: 1px solid #333; }
        #aiTitle { color: #ff0033; font-weight: bold; font-size: 14px; padding: 10px; }
        #aiChat { background-color: #121212; color: #ddd; border: none; }
        #aiInput { background-color: #2a2a2a; color: #ddd; border: 1px solid #444; padding: 5px; }
        #sidebarBtn { 
            background-color: #1a1a1a; color: #ff0033; border: 1px solid #ff0033; 
            border-radius: 5px; font-weight: bold; 
        }
        #sidebarBtn:hover { background-color: #ff0033; color: white; }
        #header { background-color: #1a1a1a; border-bottom: 1px solid #333; }
        #headline { color: #ff0033; font-weight: bold; font-size: 14px; margin-right: 20px; }
        #urlInput { 
            background-color: #2a2a2a; color: #ddd; border: 1px solid #444; 
            border-radius: 15px; padding: 5px 15px; font-size: 13px;
        }
        #tabWidget::pane { border-top: 1px solid #333; background: #0b0b0b; }
        QTabBar::tab {
            background: #1a1a1a; color: #aaa; padding: 8px 15px; 
            border-top-left-radius: 4px; border-top-right-radius: 4px;
            margin-right: 2px;
        }
        QTabBar::tab:selected { background: #ff0033; color: white; }
        QProgressBar { background-color: transparent; border: none; }
        QProgressBar::chunk { background-color: #ff0033; }
    )";
    this->setStyleSheet(style);
}

void BrowserWindow::addNewTab(const QUrl &url) {
    QWebEngineView *view = new QWebEngineView();
    view->load(url);
    
    int index = tabWidget->addTab(view, "New Tab");
    tabWidget->setCurrentIndex(index);

    connect(view, &QWebEngineView::titleChanged, [this, index](const QString &title) {
        tabWidget->setTabText(tabWidget->indexOf((QWidget*)sender()), title);
    });
    
    connect(view, &QWebEngineView::urlChanged, [this](const QUrl &url) {
        if (tabWidget->currentWidget() == sender()) {
            updateUrlLine(url);
        }
    });

    connect(view, &QWebEngineView::loadProgress, this, &BrowserWindow::updateProgress);
}

void BrowserWindow::closeTab(int index) {
    if (tabWidget->count() > 1) {
        QWidget *w = tabWidget->widget(index);
        tabWidget->removeTab(index);
        delete w;
    } else {
        close();
    }
}

void BrowserWindow::updateUrlLine(const QUrl &url) {
    urlLineEdit->setText(url.toString());
}

void BrowserWindow::handleUrlEntered() {
    QString urlStr = urlLineEdit->text();
    if (!urlStr.startsWith("http")) {
        urlStr = "https://" + urlStr;
    }
    QWebEngineView *view = qobject_cast<QWebEngineView*>(tabWidget->currentWidget());
    if (view) {
        view->load(QUrl(urlStr));
    }
}

void BrowserWindow::updateProgress(int progress) {
    progressBar->setValue(progress);
    if (progress >= 100) {
        progressBar->hide();
    } else {
        progressBar->show();
    }
}

void BrowserWindow::handleTabChange(int index) {
    QWebEngineView *view = qobject_cast<QWebEngineView*>(tabWidget->widget(index));
    if (view) {
        updateUrlLine(view->url());
    }
}

void BrowserWindow::toggleAiSidebar() {
    // Basic toggle logic for AI features
    sidebarVisible = !sidebarVisible;
    sidebar->setVisible(sidebarVisible);
}

void BrowserWindow::handleAiInput() {
    QString input = aiInput->text();
    if (input.isEmpty()) return;

    aiChat->append("User: " + input);
    aiInput->clear();

    // Simulated AI response
    QString response;
    if (input.contains("hello", Qt::CaseInsensitive)) {
        response = "Hello! I am your HeroBrowser AI assistant by Death Legion Team. How can I help you browse the web today?";
    } else if (input.contains("who", Qt::CaseInsensitive)) {
        response = "I was created by the Death Legion Team to provide the best AI-powered browsing experience.";
    } else {
        response = "That's an interesting question. I'll search the web for that soon!";
    }
    
    aiChat->append("AI: " + response);
}
