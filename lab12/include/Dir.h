#ifndef DIR_H
#define DIR_H

#include "FileSystemComponent.h"
#include <string>
#include <algorithm>

class Dir final : public FileSystemComponent
{
private:
    std::vector<FileSystemComponent *> components;

public:
    Dir(std::string d_name);
    // Konstruktor, przypisuje podana nazwe katalogu do zmiennej name klasy bazowej

    void add(FileSystemComponent *obj);
    // Metoda ktora dodaje obieky do vector components

    Dir &operator+=(FileSystemComponent *obj);
    // Przeciazenie operatora +=, umozliwia dodawanie elementow do vector components

    Dir *findDir(std::string to_find);
    // Metoda zwracajaca wskaznik do podanego katalogu, jesli nie ma go w vector components zwraca nullptr

    FileSystemComponent *get(const std::string &name_2);
    // Metoda zwracajaca wskaznik do podanego elementu, jesli nie ma go w vector components zwraca nullptr

    void listDirs(int depth);
    // Metoda ktora wypisuje liste katalogow do podanej glebokosci

    ~Dir();
    // Destruktor, usuwa elementy z vector i zwalnia zaalokowana pamiec

    void print(int indent) const override;
    // Nadpisana metoda klasy bazowej, umozliwia odpowiednie formatowanie wypisywanych elementow

    bool checkType(Type type) override;
    // Nadpisana metoda klasy bazowej, sprawdza czy dany obiekt jest obiektem typu Dir

    std::vector<FileSystemComponent *> getContent() const override;
    // Nadpisana metoda klasy bazowej, zwraca vector components

    Type getType() const override;

    friend std::ostream &operator<<(std::ostream &out, const FileSystemComponent &dir);
    std::vector<FileSystemComponent *> getFSElements(int depth, int currentDepth) const;
};

std::ostream &operator<<(std::ostream &out, const FileSystemComponent &dir);
// Przeciazenie operatora <<, umozliwia wypisywanie obiektow typu FileSystemComponent na ekran

#endif