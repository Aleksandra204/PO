#ifndef FILESYSTEMCOMPONENT_H
#define FILESYSTEMCOMPONENT_H

#include <iostream>
#include <vector>
#include <cstring>

class FileSystemComponent
{
protected:
    std::string name_c;
    FileSystemComponent *parent;

    enum Type
    {
        Dir,
        File
    };
    virtual bool checkType(Type) = 0;

public:
    virtual void print(int indent) const = 0;
    // Wirtualna metoda, ktora wymusza jej nadpisanie w klasach dziediczacych, odpowiada za odpowiednie formatowanie wypisywanych elementow

    virtual ~FileSystemComponent() = default;
    // Wirtualny konstruktor

    std::string name();
    // Metoda zwracajaca nazwe danego obiektu

    std::vector<FileSystemComponent *> *getFSElements(Type type, std::vector<FileSystemComponent *> *vec, int depth);
    // Metoda zwracajaca liste obiektow danego typu do podanej glebokosci

    virtual std::vector<FileSystemComponent *> getContent() const;
    // Wirtualna metoda, ktora wymusza jej nadpisanie w klasach dziediczacych, zwraca vector

    virtual Type getType() const = 0;

    std::string getRelativePath() const;
};

#endif