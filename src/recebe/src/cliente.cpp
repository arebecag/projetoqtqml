#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusReply>
#include <QtDBus/QDBusVariant>
#include <QtWidgets/QMessageBox>

#include "defs.hpp"
#include "cliente.hpp"
#include "dbus.hpp"

struct ClientePrivate {
    ClientePrivate() :
        interface {
            std::make_unique<QDBusInterface>(kDBusService, kDBusPath, "", QDBusConnection::sessionBus())
        }
    {}
    std::unique_ptr<QDBusInterface> interface;
};

Cliente::Cliente(QObject *parent) noexcept : QObject(parent),
    d { std::make_unique<ClientePrivate>() }
{
    if (!d->interface->isValid()) {
        QMessageBox::critical(nullptr,
            QObject::tr("Erro"),
            QObject::tr("Ocorreu um erro na conexão com o DBus. O erro informado foi: %1")
                .arg(QDBusConnection::sessionBus().lastError().message())
        );

        return;
    }
}

Cliente::~Cliente() noexcept = default;

QString
Cliente::consulta(const QString &topico) noexcept
{
    QDBusReply<QDBusVariant> resposta = d->interface->call("consulta", topico);

    if (!resposta.isValid()) {
        QMessageBox::critical(nullptr,
            QObject::tr("Erro"),
            QObject::tr("Ocorreu um erro na conexão com o DBus. O erro informado foi: %1")
                .arg(d->interface->lastError().message())
        );

        return QString();
    }

    QVariant conteudo = resposta.value().variant();

    if (conteudo.canConvert<QDBusError>()) {
        QMessageBox::critical(nullptr,
            QObject::tr("Erro"),
            QObject::tr("Ocorreu um erro na conexão com o DBus. O erro informado foi: %1")
                .arg(conteudo.value<QDBusError>().message())
        );

        return QString();
    }

    return conteudo.toString();
}

