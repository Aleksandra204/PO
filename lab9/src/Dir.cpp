#include "Dir.h"

Dir::Dir(std::string d_name)
{
    FileSystemComponent::name = d_name;
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
    std::cout << std::string(indent, ' ') << name << " (DIR)" << std::endl;
    for (const auto &component : components)
    {
        component->print(indent + 2);
    }
}

Dir *Dir::findDir(std::string to_find)
{
    if (name == to_find)
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
        if (component->getName() == name_2)
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
    std::cout << "Deleting Dir: " << name << std::endl;

    auto printMessage = [](FileSystemComponent *obj)
    {
        std::cout << "About to delete: " << obj->getName() << std::endl;
    };

    for (auto &component : components)
    {
        printMessage(component);
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
