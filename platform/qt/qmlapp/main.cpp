#include <QGuiApplication>
#include <QIcon>
#include <QQmlApplicationEngine>
#include <qqml.h>

#include <QQuickMapboxGL>
#include <QQuickMapboxStyleProperty>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

#if QT_VERSION >= 0x050300
    app.setWindowIcon(QIcon(":icon.png"));
#endif

    qmlRegisterType<QQuickMapboxGL>("QQuickMapboxGL", 1, 0, "QQuickMapboxGL");
    qmlRegisterType<QQuickMapboxStyleProperty>("QQuickMapboxGL", 1, 0, "QQuickMapboxStyleProperty");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
