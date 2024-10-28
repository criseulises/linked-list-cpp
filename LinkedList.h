//
// Created by scris on 10/27/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template<typename ListElement>
struct Node {
    ListElement *data;
    Node *next;

    Node() : data(nullptr), next(nullptr) {
    };
};

template<typename ListElement>
class LinkedList {
private:
    Node<ListElement> *_head;
    int _size = 0;

public:
    LinkedList() {
        _head = nullptr;
    }

    void Insert(ListElement &value) {
        Node<ListElement> *newNode = new Node<ListElement>;
        newNode->data = &value;
        newNode->next = nullptr;

        if (_head == nullptr) {
            _head = newNode;
        } else {
            Node<ListElement> *current = _head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        _size++;
    }

    void Remove(ListElement *value) {
        if (_head == nullptr) return;
        if (_head->data == value) {
            _head->data = _head->next == nullptr ? nullptr : _head->next->data;
            _head->next = _head->next == nullptr ? nullptr : _head->next->next;
            return;
        }
        Node<ListElement> *current = _head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr && current->next->data == value) {
            Node<ListElement> *temp = current->next;
            current->next = temp->next;
            delete temp;
            _size--;
            cout << "Removed element " << endl;
        } else {
            cout << "Element not found" << endl;
        }
    }

    void Edit(int position, ListElement *value) {
        Node<ListElement> *current = _head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        current->data = value;
        cout << "Element at index " << position << " updated to " << *value << endl;
    }

    int GetSize() {
        return _size;
    }

    Node<ListElement> *GetFirst() {
        return _head;
    }
};


#endif //LINKEDLIST_H
