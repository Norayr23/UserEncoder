#ifndef USER_H
#define USER_H

#include <string>
using std::string;

class User {
public:
    enum class Gender { Male, Female };
    User();
    User(const string& name, const string& lastName, const string& userName, const string& password,
         Gender gender, size_t age);
    void setName(const string& name);
    string getName() const;
    void setLastName(const string& lastName);
    string getLastName() const ;
    void setPassword(const string& password);
    string getPassword() const;
    void setUserName(const string& userName);
    string getUserName() const;
    void setAge(size_t age);
    size_t getAge() const;
    void setGender(Gender gender);
    Gender getGender() const;
private:
    size_t m_age;
    string m_name;
    string m_lastName;
    string m_password;
    string m_userName;
    Gender m_gender;
};

#endif // USER_H
