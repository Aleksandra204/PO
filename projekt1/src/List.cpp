#include "List.h"

// Klasa Node
Node::Node(const Data &data2, Node *node) : data(data2.clone()), next(node) {}

Node::~Node()
{
    delete data;
}

// Klasa List
void List::copyList(const List &obj)
{
    Node *current = obj.head;

    insert(*(current->data), Begin);
    tail = head;
    current = current->next;

    while (current != nullptr)
    {
        insert(*(current->data));
        current = current->next;
    }
}

List::List() : head(nullptr), tail(nullptr) {}

List::List(const List &obj) : head(nullptr), tail(nullptr)
{
    copyList(obj);
}

List &List::insert(const Data &obj, List::position pos)
{
    if (pos == Begin)
    {
        head = new Node(obj, head);
    }
    else
    {
        Node *new_node = new Node(obj);
        tail->next = new_node;
        tail = new_node;
    }

    if (tail == nullptr)
    {
        tail = head;
    }

    if (head == nullptr)
    {
        head = tail;
    }

    return *this;
}

void List::print()
{
    Node *current = head;
    std::cout << "[";

    while (current != nullptr)
    {
        if (current != head)
        {
            std::cout << ", ";
        }
        current->data->print_data();
        current = current->next;
    }

    std::cout << "]" << std::endl;
}

List &List::operator=(const List &obj)
{
    if (this == &obj)
    {
        return *this;
    }

    copyList(obj);

    return *this;
}

List::~List()
{
    while (head != tail)
    {
        Node *current = head->next;
        Node *previous = head;

        while (current != tail)
        {
            previous = current;
            current = current->next;
        }

        tail = previous;
        tail->next = nullptr;
        delete current;
    }
    delete head;
}