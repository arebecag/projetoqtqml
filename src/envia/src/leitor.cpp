#include "defs.hpp"
#include "leitor.hpp"

#include <QtCore/QFile>

Leitor::Leitor(QObject *parent) noexcept : QObject(parent)
{}

Leitor::~Leitor() noexcept = default;

QString
Leitor::ler(const QUrl &caminho) noexcept
{
    QFile file(caminho.toLocalFile());

    if (!file.open(QIODevice::ReadOnly)) {
        return QString("");
    }

    return QString::fromLatin1(file.readAll());
}

