#include <QApplication>
#include "browser_window.h"

int main(int argc, char *argv[]) {
    // High DPI support
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication app(argc, argv);
    app.setApplicationName("HeroBrowser");
    app.setOrganizationName("Death Legion Team");

    BrowserWindow window;
    window.showMaximized();

    return app.exec();
}
