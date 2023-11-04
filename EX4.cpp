//1
#include <set>

int main() {
    std::set<int> mySet;
    for (int i = 1; i <= 100; ++i) {
        mySet.insert(i);
    }
    return 0;
}

//2
#include <set>
#include <algorithm>

bool searchValue(const std::set<int>& mySet, int valueToSearch) {
    return mySet.find(valueToSearch) != mySet.end();
}

//3
#include <set>
#include <algorithm>

bool searchValue(std::set<int>::const_iterator begin, std::set<int>::const_iterator end, int valueToSearch) {
    return std::find(begin, end, valueToSearch) != end;
}

//4
#include <set>
#include <algorithm>

template <typename Iterator>
bool searchValue(Iterator begin, Iterator end, int valueToSearch) {
    return std::find(begin, end, valueToSearch) != end;
}

//Exemple
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::vector<std::string> myVector = {"apple", "banana", "cherry"};
    std::list<int> myList = {1, 2, 3, 4, 5};
    int myArray[] = {1.0, 2.0, 3.0, 4.0, 5.0};

    std::cout << "\"apple\" is in myVector: " << searchValue(myVector.begin(), myVector.end(), "apple") << std::endl;

    std::cout << "2 is in myList: " << searchValue(myList.begin(), myList.end(), 2) << std::endl;

    std::cout << "3.0 is in myArray: " << searchValue(&myArray[0], &myArray[0] + 5, 3.0) << std::endl;

    return 0;
}