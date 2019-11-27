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
#include <algorithm>

class StrBlobPtr;

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);
    friend bool operator<(const StrBlob &, const StrBlob &);
    friend bool operator>(const StrBlob &, const StrBlob &);
    friend bool operator<=(const StrBlob &, const StrBlob &);
    friend bool operator>=(const StrBlob &, const StrBlob &);

    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(const StrBlob &sb): data(std::make_shared<std::vector<std::string>>(*sb.data)){}
    StrBlob(StrBlob &&rhs) noexcept: data(std::move(rhs.data)) {}

    StrBlob& operator=(const StrBlob &);
    StrBlob& operator=(StrBlob &&) noexcept;

    std::string& operator[](size_t);
    const std::string& operator[](size_t) const;


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

StrBlob& StrBlob::operator=(const StrBlob &sb) {
    data = std::make_shared<std::vector<std::string>>(*sb.data);
    return *this;
}

StrBlob& StrBlob::operator=(StrBlob &&sb) noexcept {
    if(this != &sb) {
        data = std::move(sb.data);
        sb.data = nullptr;
    }
    return *this;
}

inline std::string& StrBlob::operator[](size_t n) {
    check(n, "out of range");
    return (*data)[n];
}

inline const std::string& StrBlob::operator[](size_t n) const {
    check(n, "out of range");
    return (*data)[n];
}

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
    
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

    StrBlobPtr& operator++();
    StrBlobPtr operator++(int);
    StrBlobPtr& operator--();
    StrBlobPtr operator--(int);
    StrBlobPtr& operator+=(size_t);
    StrBlobPtr& operator-=(size_t);
    StrBlobPtr operator+(size_t);
    StrBlobPtr operator-(size_t);

    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, std::size_t sz = 0): wptr(a.data), curr(sz) {}
    bool operator!=(StrBlobPtr &p) {return p.curr != curr;}
    std::string& deref() const;
    StrBlobPtr& incr();

    std::string& operator[](size_t);
    const std::string& operator[](size_t) const;

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

inline std::string& StrBlobPtr::operator[](size_t n) {
    auto p = check(n, "dereference out of rnage");
    return (*p)[n];
}

inline const std::string& StrBlobPtr::operator[](size_t n) const {
    auto p = check(n, "dereference out of range");
    return (*p)[n];
}

inline StrBlobPtr& StrBlobPtr::operator++(){
    check(curr, "increment past end of StrBlobPtre");
    ++curr;
    return *this;
}

inline StrBlobPtr StrBlobPtr::operator++(int) {
    StrBlobPtr ret = *this;
    ++(*this);
    return ret;
}

inline StrBlobPtr& StrBlobPtr::operator--() {
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

inline StrBlobPtr StrBlobPtr::operator--(int) {
    StrBlobPtr ret = *this;
    --(*this);
    return ret;
}

inline StrBlobPtr& StrBlobPtr::operator+=(size_t n) {
    curr += n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

inline StrBlobPtr& StrBlobPtr::operator-=(size_t n) {
    curr -= n;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

inline StrBlobPtr StrBlobPtr::operator+(size_t n) {
    StrBlobPtr ret = *this;
    ret += n;
    return ret;
}

inline StrBlobPtr StrBlobPtr::operator-(size_t n) {
    StrBlobPtr ret = *this;
    ret -= n;
    return ret;
}

//-------------------------------StrBlob operator---------------------------------
bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return *(lhs.data) == *(rhs.data);
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
    return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(), rhs.data->begin(), rhs.data->end());
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
    return rhs < lhs;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs < rhs);
}

//==============================StrBlobPtr operator=======================================
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr > rhs.curr;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr <= rhs.curr;
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr >= rhs.curr;
}

#endif
