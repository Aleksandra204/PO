#include "File.h"

File::File(std::string f_name)
{
    FileSystemComponent::name_c = f_name;
}

void File::print(int indent) const
{
    std::cout << std::string(indent, ' ') << name_c << " (FILE)" << std::endl;
}

bool File::checkType(Type type){
    if(type == Type::File){
        return true;
    } else{
        return false;
    }
}

FileSystemComponent::Type File::getType() const{
    return FileSystemComponent::Type::File;
}