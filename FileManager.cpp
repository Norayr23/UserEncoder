#include "FileManager.h"
#include "workWithJson.h"

#include <jsoncpp/json/json.h>
#include <fstream>
#include <sstream>
#include <iostream>

FileManager::FileManager(const string& fname) : m_fileName(fname) {}
std::shared_ptr<std::vector<User>> FileManager::readUsers() const {
    auto users = std::make_shared<std::vector<User>>();
    std::ifstream ifs(m_fileName);
    if (ifs.is_open()) {
        std::stringstream buffer;
        buffer << ifs.rdbuf();
        string content = buffer.str();
        Json::Value jsonArray;
        Json::Reader reader;
        if (reader.parse(content, jsonArray)) {
            for (const auto& j : jsonArray) {
                if (!j.empty()) {
                    users->push_back(getUserFromJson(j));
                }
            }
        }
    }
    return users;
}
bool FileManager::writeUsers(const std::vector<User>& users) const {
    std::ofstream ofs(m_fileName);
    if (!ofs.is_open()) {
        return false; // Failed to open the file for writing
    }
    ofs.seekp(0, std::ios::end);
    bool isEmpty = (ofs.tellp() == 0);
    if (isEmpty) {
        ofs << "[";
    }
    for (size_t i = 0; i < users.size(); ++i) {
        if (i > 0 || !isEmpty) {
            ofs << ",";
        }
        Json::Value jsonUser = makeJsonUser(users[i]);
        ofs << jsonUser;
    }
    if (isEmpty) {
        ofs << "]";
    }
    ofs.close();
    return true;
}
