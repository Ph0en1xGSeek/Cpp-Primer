#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <map>
#include <memory>


class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const {
        return data->size();
    }

    bool empty() const {
        return data->empty();
    }

    void push_back(const std::string &t) {
        data->push_back(t);
    }

    void pop_back();

    std::string &front();
    std::string &back();
    std::string &front() const;
    std::string &back() const;


private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
    if(i >= data->size())
        throw std::out_of_range(msg);
}

std::string &StrBlob::front() {
    check(0, "front from empty StrBlob");
    return data->front();
}
std::string &StrBlob::back() {
    check(0, "back from empty StrBlob");
    return data->back();
}

std::string &StrBlob::front() const{
    check(0, "front from empty StrBlob");
    return data->front();
}
std::string &StrBlob::back() const{
    check(0, "back from empty StrBlob");
    return data->back();
}


void StrBlob::pop_back() {
    check(0, "pop from empty StrBlob");
    data->pop_back();
}




int main() {
    StrBlob a1 = {"1", "hello", "world"};
    const StrBlob a2 = {"Hello", "World"};
    std::cout << a1.front() << " " << a1.back() << std::endl;
    std::cout << a2.front() << " " << a2.back() << std::endl;
     return 0;
}