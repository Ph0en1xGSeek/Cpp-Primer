#include <bits/stdc++.h>



class Person {
public:
    std::string name;
    std::string address;
    const std::string& getName() const {
        return name;
    }

    const std::string& getAddress() const {
        return address;
    }
};

std::ostream &print(std::ostream&, const Person&);
std::istream &read(std::istream&, Person&);

std::ostream &print(std::ostream &os, const Person &p) {
    os << "Name: " << p.getName() << " Address: " << p.getAddress();
    return os;
}

std::istream &read(std::istream &is, Person &p) {
    is >> p.name >> p.address;
    return is;
}

int main() {
    Person p;
    read(std::cin, p);
    print(std::cout, p);
    return 0;
}