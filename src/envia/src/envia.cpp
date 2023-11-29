#include <QtWidgets/QApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtDBus/QtDBus>
#include <QtWidgets/QMessageBox>

#include "defs.hpp"
#include "leitor.hpp"
#include "servidor.hpp"
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
    application.setApplicationVersion(ENVIA_VERSION);
    application.setOrganizationName("Jacto");

    // DBus
    if (!QDBusConnection::sessionBus().isConnected()) {
        qDebug() << "Sem conexão com o DBUS";
    }

    if (!QDBusConnection::sessionBus().registerService(kDBusService)) {
        qDebug() << "Falha ou registrar serviço" << QDBusConnection::sessionBus().lastError().message();
    }

    Servidor servidor;

    QDBusConnection::sessionBus().registerObject(kDBusPath, &servidor, QDBusConnection::ExportAllSlots);

    // QML
    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/envia.qml"));

    qmlRegisterType<Leitor>("br.com.jacto", 1, 0, "Leitor");

    engine.rootContext()->setContextProperty("servidor", &servidor);
    engine.load(url);

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    QObject::connect(&engine, &QQmlEngine::quit, &application, &QCoreApplication::quit);

    return application.exec();
}

