#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include <iostream>

namespace cp5 {

    class Delete {
    public:
        template<typename T>
        void operator() (T *p) const {
            delete p;
        }
    };

    class DebugDelete {
    public:
        DebugDelete(std::ostream &s = std::cerr): os(s) {}
        template<typename T>
        void operator() (T *p) const {
            os << "deleteing unique_ptr" << std::endl;
            delete p;
        }
    private:
        std::ostream &os;
    };
}

#endif