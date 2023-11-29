#ifndef ENVIA_SRC_LEITOR_HPP
#define ENVIA_SRC_LEITOR_HPP

#pragma once

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QUrl>
#include <QtQml>

class Leitor : public QObject {
    Q_OBJECT
    QML_ELEMENT

public:
    Leitor(QObject *parent = nullptr) noexcept;
    virtual ~Leitor() noexcept;

    Q_INVOKABLE QString ler(const QUrl &caminho) noexcept;
};

#endif // ENVIA_SRC_LEITOR_HPP


