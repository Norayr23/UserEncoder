#ifndef USERCOORDINATOR_H
#define USERCOORDINATOR_H

#include "FileManager.h"

class UserCoordinator {
public:
    UserCoordinator();
    void addUser(const User& user);
    User* getUser(const std::string& userName, const std::string& password) const;
    bool isUserExist(const std::string& userName) const;
    void deleteUser(const std::string& userName, const std::string& password);
    ~UserCoordinator();
private:
    const std::string m_fileName = "User.json";
    FileManager m_fm;
    std::shared_ptr<std::vector<User>> m_users;
};

#endif // USERCOORDINATOR_H
