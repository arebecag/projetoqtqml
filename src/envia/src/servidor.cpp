#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusMessage>

#include "defs.hpp"
#include "servidor.hpp"

struct ServidorPrivate {
    ServidorPrivate() :
        topico { QString() },
        conteudo { QString() }
    {}

    QString topico;
    QString conteudo;
};

Servidor::Servidor(QObject *parent) noexcept : QObject(parent),
    d { std::make_unique<ServidorPrivate>() }
{}

Servidor::~Servidor() noexcept = default;

QString
Servidor::topico() noexcept
{
    return d->topico;
}

QString
Servidor::conteudo() noexcept
{
    return d->conteudo;
}

void
Servidor::setTopico(const QString &topico) noexcept
{
    d->topico = topico.toLower();
}

void
Servidor::setConteudo(const QString &conteudo) noexcept
{
    d->conteudo = conteudo;
}

struct Erro {
    Erro(const QString &msg) : mensagem { msg } {}

    QString mensagem;
};

QDBusVariant
Servidor::consulta(const QString &topico) noexcept
{
    if (d->topico != topico.toLower()) {
        // TODO(croscato): verificar melhor forma para se retornar um erro
        return QDBusVariant(QString());
    }

    return QDBusVariant(d->conteudo);
}

