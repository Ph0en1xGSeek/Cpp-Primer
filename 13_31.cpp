#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>



class HasPtr {
    friend void swap(HasPtr &lhs, HasPtr &rhs);
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &ptr) : ps(new std::string(*(ptr.ps))), i(ptr.i) { 
    }

    HasPtr& operator=(const HasPtr &ptr) {
        std::string *new_p = new std::string(*(ptr.ps)); // avoid assigning to itself
        delete ps;
        ps = new_p;
        i = ptr.i;
        return *this;
    }

    ~HasPtr() {
        delete ps;
    }

    std::string get_ps() {
        return *ps;
    }

    int get_i() {
        return i;
    }

    bool operator<(HasPtr &rhs) {
        return *ps < *rhs.ps;
    }

    void swap(HasPtr &rhs) {
        std::cout << "swap" << std::endl;
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
    }

private:
    std::string *ps;
    int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "swap" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}


int main() {
    std::vector<HasPtr> arr;
    //need more element to use quicksort
    arr.push_back(HasPtr("3"));
    arr.push_back(HasPtr("4"));
    arr.push_back(HasPtr("2"));
    arr.push_back(HasPtr("1"));
    arr.push_back(HasPtr("3"));
    arr.push_back(HasPtr("4"));
    arr.push_back(HasPtr("2"));
    arr.push_back(HasPtr("1"));
    arr.push_back(HasPtr("3"));
    arr.push_back(HasPtr("4"));
    arr.push_back(HasPtr("2"));
    arr.push_back(HasPtr("1"));
    arr.push_back(HasPtr("3"));
    arr.push_back(HasPtr("4"));
    arr.push_back(HasPtr("2"));
    arr.push_back(HasPtr("1"));
    arr.push_back(HasPtr("3"));
    arr.push_back(HasPtr("4"));
    arr.push_back(HasPtr("2"));
    arr.push_back(HasPtr("1"));
    arr.push_back(HasPtr("3"));
    arr.push_back(HasPtr("4"));
    arr.push_back(HasPtr("2"));
    arr.push_back(HasPtr("1"));
    swap(arr[2], arr[3]);
    for(int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i].get_ps() << " ";
    }
    std::cout << std::endl;
    std::sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i].get_ps() << " ";
    }
    std::cout << std::endl;
    return 0;
}