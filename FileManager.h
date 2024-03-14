#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "User.h"


#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class FileManager : public QObject
{
    Q_OBJECT
public:
    explicit FileManager(QObject *parent = nullptr);

    bool serializeUser(const User& user, const QString& fileName);
    User deserializeUser(const QString& fileName);

private:
    QJsonDocument readFile(const QString& fileName);
    bool writeFile(const QJsonDocument& jsonDoc, const QString& fileName);
};

#endif // FILEMANAGER_H
