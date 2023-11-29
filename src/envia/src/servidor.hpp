#ifndef ENVIA_SRC_SERVIDOR_HPP
#define ENVIA_SRC_SERVIDOR_HPP

#pragma once

#include <memory>

#include <QtCore/QObject>
#include <QtDBus/QDBusVariant>

struct ServidorPrivate;

class Servidor : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString topico READ topico WRITE setTopico)
    Q_PROPERTY(QString conteudo READ conteudo WRITE setConteudo)

public:
    Servidor(QObject *parent = nullptr) noexcept;
    virtual ~Servidor() noexcept;

    QString topico() noexcept;
    QString conteudo() noexcept;

    void setTopico(const QString &topico) noexcept;
    void setConteudo(const QString &conteudo) noexcept;

public slots:
    Q_SCRIPTABLE QDBusVariant consulta(const QString &topico) noexcept;

private:
    std::unique_ptr<ServidorPrivate> d;
};

#endif // ENVIA_SRC_SERVIDOR_HPP

