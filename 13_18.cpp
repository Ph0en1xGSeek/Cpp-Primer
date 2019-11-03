#include <iostream>
#include <stdio.h>
#include <string>



class Employee {
public:
    Employee();
    Employee(const std::string &name);
    void print() {
        std::cout << id << " " << name << std::endl;
    }
private:
    int id;
    std::string name;
    static int s_increment;
};

int Employee::s_increment = 0;

Employee::Employee() {
    id = Employee::s_increment++;
}

Employee::Employee(const std::string &name_) {
    id = Employee::s_increment++;
    name = name_;
}

int main() {
    Employee e1;
    Employee e2("aaaaa");
    e1.print();
    e2.print();
    return 0;
}