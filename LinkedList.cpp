#include "LinkedList.h"

template<typename ListElement>
LinkedList<ListElement>::LinkedList() : _head(nullptr), _size(0) {}

template<typename ListElement>
void LinkedList<ListElement>::Insert(const std::shared_ptr<ListElement>& value) {
    auto newNode = std::make_shared<Node<ListElement>>();
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

template<typename ListElement>
void LinkedList<ListElement>::Remove(const std::shared_ptr<ListElement>& value) {
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

template<typename ListElement>
void LinkedList<ListElement>::Edit(int position, const std::shared_ptr<ListElement>& value) {
    if (position < 0 || position >= _size) {
        std::cout << "Position out of bounds" << std::endl;
        return;
    }

    auto current = _head;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }

    current->data = value;
    std::cout << "Element at index " << position << " updated." << std::endl;
}

template<typename ListElement>
int LinkedList<ListElement>::GetSize() const {
    return _size;
}

template<typename ListElement>
std::shared_ptr<Node<ListElement>> LinkedList<ListElement>::GetFirst() const {
    return _head;
}
