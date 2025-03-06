#include "File.h"

File::File(std::string f_name)
{
    FileSystemComponent::name = f_name;
}

void File::print(int indent) const
{
    std::cout << std::string(indent, ' ') << name << " (FILE)" << std::endl;
}

bool File::checkType(Type type){
    if(type == Type::File){
        return true;
    } else{
        return false;
    }
}