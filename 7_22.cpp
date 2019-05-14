#include <bits/stdc++.h>



class Person {
friend std::ostream &print(std::ostream&, const Person&);
friend std::istream &read(std::istream&, Person&);

private:
    std::string name;
    std::string address;
public:
    Person() = default;

    Person(const std::string &n): name(n) {}

    Person(const std::string &n, const std::string &a): name(n), address(a) {}

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
    os << "Name: " << p.name << " Address: " << p.address;
    return os;
}

std::istream &read(std::istream &is, Person &p) {
    is >> p.name >> p.address;
    return is;
}

int main() {
    Person p = Person("pgs", "fz");
    print(std::cout, p);
    read(std::cin, p);
    print(std::cout, p);
    return 0;
}