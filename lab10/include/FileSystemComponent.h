#ifndef FILESYSTEMCOMPONENT_H
#define FILESYSTEMCOMPONENT_H

#include <iostream>

class FileSystemComponent
{
protected:
    std::string name;

public:
    virtual void print(int indent) const = 0;
    //Wirtualna metoda, ktora wymusza jej nadpisanie w klasach dziediczacych, odpowiada za odpowiednie formatowanie wypisywanych elementow

    virtual ~FileSystemComponent() = default;
    //Wirtualny konstruktor

    std::string getName()
    {
        return name;
    }
    //Metoda zwracajaca nazwe danego obiektu
};

#endif