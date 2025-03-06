#ifndef LIST_H
#define LIST_H

#include "Data.h"

class Node
{
private:
    Data *data;
    Node *next;

public:
    Node(const Data &data2, Node *node = nullptr);
    // konstruktor, inicjalizuje wartosci dla *data - czyli dane pobrane za pomoca metody clone() - i *node - (jesli nie zostanie podana, domyslnie ustawiana na nullptr)

    ~Node();
    // destruktor, usuwa zawartosc data

    friend class List;
};

class List
{
private:
    Node *tail;
    Node *head;
    void copyList(const List &obj);

public:
    enum position
    {
        Begin,
        End
    };

    List();
    // konstruktor domyslny, inicjalizuje tail i head jako nullptr

    List(const List &obj);
    // konstruktor kopiujacy

    List &insert(const Data &obj, position pos = End);
    // wstawia element na poczatek lub koniec listy (domyslnie na koniec)

    void print();
    // wypisuje zawartosc listy

    List &operator=(const List &obj);
    // przeciazenie operatora =, powoduje skopiowanie zawartosci jednego obiektu i przypisanie go do drugiego obiektu

    ~List();
    // destruktor, dealokuje pamiec po liscie
};

#endif