#include "Validator.h"
#include <algorithm>

bool Validator::isNameValid(const std::string& name) {
    if (name.size() < 2 || name.size() > 50) {
        return false;
    }
    return std::all_of(name.begin(), name.end(), [](char ch) { return isalpha(ch); });
}
bool Validator::isLastNameValid(const std::string& lastName){ return isNameValid(lastName); }
bool Validator::isUserNameValid(const std::string& userName) { return userName.size() > 0 && userName.size() < 50; }
bool Validator::isPasswordValid(const std::string& password) {
    if (password.size() < 8 || password.size() > 100) {
        return false;
    }
    struct PasswordHas {
        bool digit = false;
        bool upper = false;
        bool lower = false;
        bool special = false;
    };
    PasswordHas passHas;
    for (char c : password) {
        if (std::islower(c)) {
            passHas.lower = true;
        }
        else if (isupper(c)) {
            passHas.upper = true;
        }
        else if (isdigit(c)) {
            passHas.digit = true;
        }
        else if (ispunct(c)) {
            passHas.special = true;
        }
    }
    return passHas.digit && passHas.lower && passHas.special && passHas.upper;
}
bool Validator::isAgeValid(const size_t age) { return age < 150; }
void removeSpaces(std::string &str) {
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) {return std::isspace(c); }), str.end());
}
