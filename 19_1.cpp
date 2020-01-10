#include <cstdlib>
#include <new>
#include <iostream>

void *operator new(size_t size) {
    std::cout << "customized new" << std::endl;
    if(void *mem = malloc(size)) {
        return mem;
    }else {
        throw std::bad_alloc();
    }
}

void operator delete(void *mem) noexcept {
    std::cout << "customized delete" << std::endl;
    free(mem);
}

int main() {
    int *p = new int[3]{1,2,3};
    std::cout << p[0] << std::endl;
    delete [] p;

    return 0;
}

