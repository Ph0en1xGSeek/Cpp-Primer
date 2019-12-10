#include <iostream>
#include <stdio.h>
#include "15_3_Quote.h"


double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);

    os << "ISBN: " << item.isbn() << "# sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

int main() {
    
    return 0;
}
 
 