#include "FileManager.h"

FileManager::FileManager(QObject *parent) : QObject(parent) {}

bool FileManager::serializeUser(const User& user, const QString& fileName)
{
    QJsonObject jsonObj;
    jsonObj["name"] = QString::fromStdString(user.getName());
    jsonObj["age"] = user.getAge();
    jsonObj["birthdayDate"] =  QString::fromStdString(user.getBirthdayDate());
    QJsonDocument jsonDoc(jsonObj);
    return writeFile(jsonDoc, fileName);
}


User FileManager::deserializeUser(const QString& fileName)
{
    QJsonDocument jsonDoc = readFile(fileName);
    QJsonObject jsonObj = jsonDoc.object();
    std::string name = jsonObj["name"].toString().toStdString();
    int age = jsonObj["age"].toInt();
    std::string birthdayDate = jsonObj["birthdayDate"].toString().toStdString();
    return User(name, age, birthdayDate);
}

QJsonDocument FileManager::readFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return QJsonDocument();
    }

    QByteArray jsonData = file.readAll();
    file.close();

    return QJsonDocument::fromJson(jsonData);
}

bool FileManager::writeFile(const QJsonDocument& jsonDoc, const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }

    file.write(jsonDoc.toJson());
    file.close();

    return true;
}
