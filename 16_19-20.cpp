#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


template <typename Container>
ostream &print(const Container &container, ostream &os) {
    for(typename Container::size_type i = 0; i != container.size(); ++i) {
        os << container[i] << ' ';
    }
    return os;
}

template <typename Container>
ostream &print2(const Container &container, ostream &os) {
    for(auto elem: container) {
        os << elem << ' ';
    }
    return os;
}

int main() {
    vector<int> vec = {1,2,3,5,6,5};
    print(vec, cout);
    cout << endl;
    print2(vec, cout) << endl;
    return 0;
}