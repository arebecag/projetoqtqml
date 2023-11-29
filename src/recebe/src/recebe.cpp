#include <QtWidgets/QApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtDBus/QtDBus>
#include <QtWidgets/QMessageBox>

#include "defs.hpp"
#include "cliente.hpp"
#include "dbus.hpp"

#include <QDebug>

int
main(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication application(argc, argv);

    application.setApplicationName("Envia");
    application.setApplicationVersion(RECEBE_VERSION);
    application.setOrganizationName("Jacto");

    // DBus
    Cliente cliente;

    // QML
    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/recebe.qml"));

    engine.rootContext()->setContextProperty("cliente", &cliente);
    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    QObject::connect(&engine, &QQmlEngine::quit, &application, &QCoreApplication::quit);

    return application.exec();
}

