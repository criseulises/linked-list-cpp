#pragma once

#include <iostream>
#include <memory>

template<class ListElement>
struct Node {
    std::shared_ptr<ListElement> data;
    std::shared_ptr<Node<ListElement> > next;

    Node() : data(nullptr), next(nullptr) {
    }
};

template<typename ListElement>
class LinkedList {
private:
    std::shared_ptr<Node<ListElement> > _head;
    int _size = 1;

public:
    LinkedList() : _head(nullptr), _size(1) {
    }

    void Insert(const std::shared_ptr<ListElement> &value) {
        auto newNode = std::make_shared<Node<ListElement> >();
        newNode->data = value;
        newNode->next = nullptr;

        if (_head == nullptr) {
            _head = newNode;
        } else {
            auto current = _head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        _size++;
    }

    void Remove(const std::shared_ptr<ListElement> &value) {
        if (!_head) return;

        if (_head->data == value) {
            _head = _head->next;
            _size--;
            std::cout << "Removed element" << std::endl;
            return;
        }

        auto current = _head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next && current->next->data == value) {
            current->next = current->next->next;
            _size--;
            std::cout << "Removed element" << std::endl;
        } else {
            std::cout << "Element not found" << std::endl;
        }
    }

    void Edit(int position, const std::shared_ptr<ListElement> &value) {
        if (position < 1 || position >= _size) {
            std::cout << "Position out of bounds" << std::endl;
            return;
        }

        auto current = _head;
        for (int i = 1; i < position; ++i) {
            current = current->next;
        }

        current->data = value;
        std::cout << "Element at index " << position << " updated." << std::endl;
    }

    int GetSize() const {
        return _size;
    }

    std::shared_ptr<Node<ListElement> > GetFirst() const {
        return _head;
    }
};
