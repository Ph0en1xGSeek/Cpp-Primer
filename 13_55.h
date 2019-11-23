#ifndef cpp_12_19_h
#define cpp_12_19_h

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

class StrBlobPtr;

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    friend class StrBlobPtr;

    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const {
        return data->size();
    }

    bool empty() const {
        return data->empty();
    }

    void push_back(const std::string &t) {
        std::cout << "using copy version push_back" << std::endl;
        data->push_back(t);
    }

    void push_back(std::string &&t) {
        std::cout << "using move version push_back" << std::endl;
        data->push_back(std::move(t));
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

class StrBlobPtr {
public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, std::size_t sz = 0): wptr(a.data), curr(sz) {}
    bool operator!=(StrBlobPtr &p) {return p.curr != curr;}
    std::string& deref() const;
    StrBlobPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>> 
    check(std::size_t sz, const std::string &msg) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t sz, const std::string &msg) const{
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("Unbound StrBlobPtr");
    if(sz >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}


StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

#endif
