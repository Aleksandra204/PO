#include "FileSystemComponent.h"

std::string FileSystemComponent::name(){
    return name_c;
}

std::vector<FileSystemComponent *> FileSystemComponent::getContent() const{
    return std::vector <FileSystemComponent*> ();
}

std::vector<FileSystemComponent *> *FileSystemComponent::getFSElements(Type type, std::vector<FileSystemComponent *> *vec, int depth){
    if(checkType(type)){
        vec->push_back(this);
        depth--;
    }

    if(checkType(Type::Dir) && depth >=0){
        std::vector <FileSystemComponent *> dirs = getContent();
        for(auto dir : dirs){
            dir->getFSElements(type, vec, depth);
            if(depth < 0){
                return vec;
            }
        }
    }

    return vec;
}

std::string FileSystemComponent::getRelativePath() const
{
    if (!parent)
        return name_c;
    return parent->getRelativePath() + "/" + name_c;
}