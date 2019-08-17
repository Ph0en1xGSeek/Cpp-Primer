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

struct connection {
    std::string ip;
    int port;
    connection(std::string ip_, int port_): ip(ip_), port(port_){}
};

struct destination {
    std::string ip;
    int port;
    destination(std::string ip_, int port_): ip(ip_), port(port_){}
};

connection connect(destination* pDest) {
    std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    std::cout << "creating connection " << pConn.use_count() << std::endl;
    return *pConn;
}

void disconnect(connection pConn) {
    std::cout << "connection close " << pConn.ip << ":" << pConn.port << std::endl;
}

void f(destination &d) {
    connection conn = connect(&d);
    std::shared_ptr<connection> p(&conn, [](connection *p){disconnect(*p);});
    std::cout << "connecting now " << p.use_count() << std::endl;
 }

int main() {
    destination dest("114.212.12.34", 22);
    f(dest);
    return 0;
}