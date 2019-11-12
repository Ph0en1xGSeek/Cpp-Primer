#include <iostream>
#include <stdio.h>
#include <string>



class HasPtr {
public:
    HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
    HasPtr(const HasPtr &ptr) : ps(new std::string(*(ptr.ps))), i(ptr.i), use(ptr.use) { 
        std::cout << "copy" << std::endl;
        ++*use;
    }

    HasPtr& operator=(const HasPtr &ptr) {
        std::cout << "assignment" << std::endl;
        ++*ptr.use;
        if(--*use == 0) {
            delete use;
            delete use;
        }
        use = ptr.use;
        ps = ptr.ps;
        i = ptr.i;
        return *this;
    }

    ~HasPtr() {
        std::cout << "destructor" << std::endl;
        if(--*use == 0) {
            delete use;
            delete ps;
        }
    }

    std::string get_ps() {
        return *ps;
    }
    
    void set_ps(std::string str) {
        *ps = str;
    }

    int get_i() {
        return i;
    }

private:
    std::string *ps;
    std::size_t *use;
    int i;
};


int main() {
    HasPtr hp("123");
    HasPtr hp2 = hp;
    std::cout << hp2.get_ps() << " " << hp2.get_i() << std::endl;
    HasPtr hp3("2222");
    std::cout << hp3.get_ps() << " " << hp3.get_i() << std::endl;
    hp3 = hp2;
    hp2.set_ps("121212121212");
    std::cout << hp3.get_ps() << " " << hp3.get_i() << std::endl;
    return 0;
}