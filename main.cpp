#include <iostream>
#include "LinkedList.cpp"
using namespace std;
int main() {
    LinkedList<int> list;
    auto one = std::make_shared<int>(1);
    auto two = std::make_shared<int>(2);
    auto three = std::make_shared<int>(3);
    auto four = std::make_shared<int>(4);
    auto five = std::make_shared<int>(5);

    cout << "Testing Insert Method:\n";
    list.Insert(one);
    list.Insert(two);
    list.Insert(three);
    cout << "Expected List: 1 -> 2 -> 3\n";

    auto node = list.GetFirst();
    while (node != nullptr) {
        cout << "Element: " << *(node->data) << endl;
        node = node->next;
    }

    cout << "\n\nTesting GetSize Method:\n";
    cout << "Expected Size: 3\n";
    cout << "Actual Size: " << list.GetSize() << endl;

    cout << "\n\nTesting Edit Method:\n";
    list.Edit(1, four);
    cout << "Expected List after Edit at index 1: 1 -> 4 -> 3\n";

    node = list.GetFirst();
    while (node != nullptr) {
        cout << "Element: " << *(node->data) << endl;
        node = node->next;
    }

    cout << "\n\nTesting Remove Method:\n";
    list.Remove(four);
    cout << "Expected List after Removing '4': 1 -> 3\n";

    node = list.GetFirst();
    while (node != nullptr) {
        cout << "Element: " << *(node->data) << endl;
        node = node->next;
    }

    cout << "\n\nTesting Remove Method with non-existing element:\n";
    list.Remove(five);
    cout << "Expected List after attempting to Remove '5': 1 -> 3\n";

    node = list.GetFirst();
    while (node != nullptr) {
        cout << "Element: " << *(node->data) << endl;
        node = node->next;
    }

    cout << "\n\nTesting Insert Method Again:\n";
    list.Insert(five);
    cout << "Expected List: 1 -> 3 -> 5\n";

    node = list.GetFirst();
    while (node != nullptr) {
        cout << "Element: " << *(node->data) << endl;
        node = node->next;
    }

    return 0;
}
