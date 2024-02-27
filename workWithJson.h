#ifndef WORKWITHJSON_H
#define WORKWITHJSON_H

#include <jsoncpp/json/json.h>

User getUserFromJson(Json::Value js) {
    std::string name = js["name"].asString();
    std::string lastName = js["lastName"].asString();
    std::string userName = js["userName"].asString();
    std::string password = js["password"].asString();
    User::Gender gender = static_cast<User::Gender>(js["gender"].asInt());  // Extract integer value
    size_t age = js["age"].asUInt();  // Use asUInt for size_t
    return User(name, lastName, userName, password, gender, age);
}

Json::Value makeJsonUser(const User& u) {
    Json::Value jsonUser;
    jsonUser["name"] = u.getName();
    jsonUser["lastName"] = u.getLastName();
    jsonUser["userName"] = u.getUserName();
    jsonUser["password"] = u.getPassword();
    jsonUser["gender"] = static_cast<int>(u.getGender());
    jsonUser["age"] = static_cast<int>(u.getAge());
    return jsonUser;
}

#endif // WORKWITHJSON_H
