#include "UserFileManager.h"
#include <fstream>
#include <iostream>

UserFileManager::UserFileManager() {}

void UserFileManager::setName(const std::string& name) { user.setName(name); }
void UserFileManager::setAge(int age) { user.setAge(age); }
void UserFileManager::setBirthdayDate(const std::string& birthdayDate) { user.setBirthdayDate(birthdayDate); }

std::string UserFileManager::getName() const { return user.getName(); }
int UserFileManager::getAge() const { return user.getAge(); }
std::string UserFileManager::getBirthdayDate() const { return user.getBirthdayDate(); }

bool UserFileManager::serialize() {
    //QString qFileName = QString::fromStdString(fileName);
    isSerializedFlag = fileManager.serializeUser(user, fileName);
    return isSerializedFlag;
}

bool UserFileManager::deserialize() {
    if (isSerialized()) {
        std::string stdFileName = fileName.toStdString(); // Convert QString to std::string
        user = fileManager.deserializeUser(QString::fromStdString(stdFileName));
        std::ofstream ofs(stdFileName, std::ios::out | std::ios::trunc);
        ofs.close();
        isSerializedFlag = false;
        return true;
    } else {
        return false;
    }
}
bool UserFileManager::isSerialized() const { return isSerializedFlag; }
