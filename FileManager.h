#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "User.h"
#include <memory>
#include <vector>

class FileManager {
public:
    explicit FileManager(const string& fileName);
    std::shared_ptr<std::vector<User>> readUsers() const;
    bool writeUsers(const std::vector<User>& users) const;
private:
    string m_fileName;
};

#endif // FILEMANAGER_H
