#include "UserCoordinator.h"
#include <algorithm>

UserCoordinator::UserCoordinator() : m_fm(m_fileName) {
    m_users = m_fm.readUsers();
}
void UserCoordinator::addUser(const User& user) {
    m_users->push_back(user);
}
void UserCoordinator::deleteUser(const std::string& userName, const std::string& password) {
    auto it = std::find_if(m_users->begin(), m_users->end(), [&userName, &password](const User& u) {
        return u.getUserName() == userName && u.getPassword() == password;
    });
    if (it != m_users->end()) {
        m_users->erase(it);
    }
}
User* UserCoordinator::getUser(const std::string& userName, const std::string& password) const {
    auto it = std::find_if(m_users->begin(), m_users->end(), [&userName, &password](const User& u) {
        return u.getUserName() == userName && u.getPassword() == password;
    });
    if (it != m_users->end()) {
        return &(*it);
    }
    return nullptr;
}
bool UserCoordinator::isUserExist(const std::string& userName) const {
    auto it = std::find_if(m_users->begin(), m_users->end(), [&userName](const User& user) {
        return user.getUserName() == userName;
    });
    return it != m_users->end();
}
UserCoordinator::~UserCoordinator() {
    m_fm.writeUsers(*(m_users));
}
