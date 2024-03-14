#ifndef USERFILEMANAGER_H
#define USERFILEMANAGER_H

#include <string>
#include "User.h"
#include "FileManager.h"

class UserFileManager {
public:
    UserFileManager();
    void setName(const std::string& name);
    void setAge(int age);
    void setBirthdayDate(const std::string& birthdayDate);
    std::string getName() const;
    int getAge() const;
    std::string getBirthdayDate() const;
    bool serialize();
    bool deserialize();
    bool isSerialized() const;
private:
    User user;
    FileManager fileManager;
    const QString fileName = "user_data.json";
    bool isSerializedFlag = false;
};


#endif // USERFILEMANAGER_H
