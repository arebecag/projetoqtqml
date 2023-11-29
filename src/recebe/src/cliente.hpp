#ifndef RECEBE_SRC_CLIENTE_HPP
#define RECEBE_SRC_CLIENTE_HPP

#pragma once

#include <memory>

#include <QtCore/QObject>

struct ClientePrivate;

class Cliente: public QObject {
    Q_OBJECT

public:
    Cliente(QObject *parent = nullptr) noexcept;
    virtual ~Cliente() noexcept;

    Q_SCRIPTABLE QString consulta(const QString &topico) noexcept;

private:
    std::unique_ptr<ClientePrivate> d;
};

#endif // RECEBE_SRC_CLIENTE_HPP

