#ifndef DIR_H
#define DIR_H

#include "FileSystemComponent.h"
#include <vector>
#include <string>
#include <algorithm>

class Dir final : public FileSystemComponent
{
private:
    std::vector<FileSystemComponent *> components;

public:
    Dir(std::string d_name);
    void add(FileSystemComponent *obj);
    Dir &operator+=(FileSystemComponent *obj);
    Dir *findDir(std::string to_find);
    FileSystemComponent *get(const std::string &name_2);
    ~Dir();

    void print(int indent) const override;

    friend std::ostream &operator<<(std::ostream &out, const FileSystemComponent &dir);
};

std::ostream &operator<<(std::ostream &out, const FileSystemComponent &dir);

#endif