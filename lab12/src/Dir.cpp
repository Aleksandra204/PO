#include "Dir.h"

Dir::Dir(std::string d_name)
{
    FileSystemComponent::name_c = d_name;
}

void Dir::add(FileSystemComponent *obj)
{
    components.push_back(obj);
}

Dir &Dir::operator+=(FileSystemComponent *obj)
{
    add(obj);
    return *this;
}

void Dir::print(int indent) const
{
    std::cout << std::string(indent, ' ') << name_c << " (DIR)" << std::endl;
    for (const auto &component : components)
    {
        component->print(indent + 2);
    }
}

Dir *Dir::findDir(std::string to_find)
{
    if (name_c == to_find)
        return this;

    for (auto &component : components)
    {
        Dir *dir = dynamic_cast<Dir *>(component);
        if (dir)
        {
            Dir *found = dir->findDir(to_find);
            if (found)
                return found;
        }
    }
    return nullptr;
}

FileSystemComponent *Dir::get(const std::string &name_2)
{
    for (auto &component : components)
    {
        if (component->name() == name_2)
            return component;
    }

    for (auto &component : components)
    {
        Dir *subdir = dynamic_cast<Dir *>(component);
        if (subdir)
        {
            FileSystemComponent *found = subdir->get(name_2);
            if (found)
                return found;
        }
    }

    return nullptr;
}

Dir::~Dir()
{
    for (auto &component : components)
    {
        delete component;
    }

    components.clear();
}

///////////////////////////////
std::ostream &operator<<(std::ostream &out, const FileSystemComponent &obj)
{
    obj.print(0);
    return out;
}

bool Dir::checkType(Type type){
    if(type == Type::Dir){
        return true;
    } else{
        return false;
    }
}

std::vector<FileSystemComponent *> Dir::getContent() const{
    return components;
}

void Dir::listDirs(int depth){
    // std::vector <FileSystemComponent *> elements;
    //getFSElements(Type::Dir, &elements, depth);
    // for(auto element : elements){
    //     std::cout << element->name() << " ";
    // }
    std::string path = getRelativePath();
    std::cout << path << std::endl;
}

std::vector<FileSystemComponent *> Dir::getFSElements(int depth, int currentDepth) const
{
    std::vector<FileSystemComponent *> result;
    if (currentDepth > depth)
        return result;
    for (auto elem : components)
    {
        result.push_back(elem);
        if (elem->getType() == Type::Dir)
        {
            auto dir = static_cast<Dir *>(elem);
            auto subElements = dir->getFSElements(depth, currentDepth + 1);
            result.insert(result.end(), subElements.begin(), subElements.end());
        }
    }
    return result;
}

FileSystemComponent::Type Dir::getType() const{
    return FileSystemComponent::Type::Dir;
}