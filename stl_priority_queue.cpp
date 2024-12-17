#include <iostream>
#include <string>
#include <set>

using namespace std;

template<typename T>
class Item {
    T data;
    int priority;
public:
    Item(T d, int p) : data(d), priority(p) {}

    bool operator<(const Item& i) const {
        return this->priority < i.priority;
    }

    bool operator<=(const Item& i) const {
        return this->priority <= i.priority;
    }

    void display() const {
        cout << data << " : " << priority << endl;
    }
};

int main() {
    set<Item<string>> itemlist;

    itemlist.insert(Item<string>("Job 1", 3));
    itemlist.insert(Item<string>("Job 2", 1));
    itemlist.insert(Item<string>("Job 3", 6));
    itemlist.insert(Item<string>("Job 4", 5));
    itemlist.insert(Item<string>("Job 5", 9));

    for (const auto& i : itemlist) {
        i.display();
    }
    return 0;
}
