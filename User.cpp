#include "User.h"

User::User() : m_age{} {}
User::User(const string& name, const string& lastName, const string& userName, const string& password,
           Gender gender, size_t age) : m_name{name}, m_lastName{lastName}, m_userName{userName},
    m_password{password}, m_gender{gender}, m_age{age} {}
void User::setName(const string& name) { m_name = name; }
string User::getName() const { return m_name; }
void  User::setLastName(const string& lastName) { m_lastName = lastName; }
string User::getLastName() const { return m_lastName; }
void  User::setPassword(const string& password) { m_password = password; }
string User::getPassword() const { return m_password; }
void User::setUserName(const string& userName) { m_userName = userName; }
string User::getUserName() const { return m_userName; }
void User::setAge(size_t age) { m_age = age; }
size_t User::getAge() const { return m_age; }
void User::setGender(Gender gender) { m_gender = gender; }
User::Gender User::getGender() const { return m_gender; }
