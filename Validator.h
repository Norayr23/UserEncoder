#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

namespace Validator {
    bool isNameValid(const std::string& name);
    bool isLastNameValid(const std::string& lastName);
    bool isUserNameValid(const std::string& userName);
    bool isPasswordValid(const std::string& password);
    bool isAgeValid(const size_t age);
};

void removeSpaces(std::string &str);

#endif // VALIDATOR_H
