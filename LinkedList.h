#pragma once

#include <iostream>
#include <memory>

template<typename ListElement>
struct Node {
    std::shared_ptr<ListElement> data;
    std::shared_ptr<Node<ListElement>> next;

    Node() : data(nullptr), next(nullptr) {}
};

template<typename ListElement>
class LinkedList {
private:
    std::shared_ptr<Node<ListElement>> _head;
    int _size = 0;

public:
    LinkedList();
    void Insert(const std::shared_ptr<ListElement>& value);
    void Remove(const std::shared_ptr<ListElement>& value);
    void Edit(int position, const std::shared_ptr<ListElement>& value);
    int GetSize() const;
    std::shared_ptr<Node<ListElement>> GetFirst() const;
};
