#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User();
    User(const std::string& name, int age, const std::string& birthdayDate);
    std::string getName() const;
    int getAge() const;
    std::string getBirthdayDate() const;
    void setName(const std::string& name);
    void setAge(int age);
    void setBirthdayDate(const std::string& birthdayDate);
private:
    std::string name;
    int age;
    std::string birthdayDate;
};

#endif // USER_H
