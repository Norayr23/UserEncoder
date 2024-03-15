#include "User.h"

User::User() : name(""), age(0), birthdayDate("") {}

User::User(const std::string& name, int age, const std::string& birthdayDate)
    : name(name), age(age), birthdayDate(birthdayDate) {}

std::string User::getName() const {
    return name;
}

int User::getAge() const {
    return age;
}

std::string User::getBirthdayDate() const {
    return birthdayDate;
}

void User::setName(const std::string& name) {
    this->name = name;
}

void User::setAge(int age) {
    this->age = age;
}

void User::setBirthdayDate(const std::string& birthdayDate) {
    this->birthdayDate = birthdayDate;
}
