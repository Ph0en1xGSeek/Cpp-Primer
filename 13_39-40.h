#ifndef cpp_13_39_h
#define cpp_13_39_h

#include <string>
#include <memory>

class StrBlobPtr;

class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {};
    StrVec(const StrVec&);
    StrVec(std::initializer_list<std::string>);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const std::string &);
    size_t size() const {
        return first_free - elements;
    }
    size_t capacity() const {return cap - elements;}
    std::string *begin() const {
        return elements;
    }
    std::string *end() const {
        return first_free;
    }

    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const std::string&);
    
private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc() {
        if(size() == capacity())
            reallocate();
    }
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void alloc_n_move(size_t new_cap);
    void range_initialize(const std::string *first, const std::string *last);
    void free();
    void reallocate();
    std::string* elements;
    std::string* first_free;
    std::string* cap;

};

#endif
