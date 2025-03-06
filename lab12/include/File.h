#ifndef FILE_H
#define FILE_H

#include "FileSystemComponent.h"

class File : public FileSystemComponent
{
public:
    File(std::string f_name);
    // Konstruktor, przypisuje podana nazwe pliku do zmiennej name klasy bazowej

    void print(int indent) const override;
    // Nadpisana metoda klasy bazowej, umozliwia odpowiednie formatowanie wypisywanych elementow

    bool checkType(Type) override;
    // Nadpisana metoda klasy bazowej, sprawdza czy dany obiekt jest obiektem typu Dir

    FileSystemComponent::Type getType() const override;
};

#endif