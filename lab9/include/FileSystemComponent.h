#ifndef FILESYSTEMCOMPONENT_H
#define FILESYSTEMCOMPONENT_H

#include <iostream>

class FileSystemComponent
{
protected:
    std::string name;

public:
    virtual void print(int indent) const = 0;
    virtual ~FileSystemComponent() = default;
    std::string getName()
    {
        return name;
    }
};

#endif