#ifndef FILE_H
#define FILE_H

#include "FileSystemComponent.h"

class File : public FileSystemComponent
{
public:
    File(std::string f_name);
    void print(int indent) const override;
};

#endif