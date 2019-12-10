#include <iostream>
#include <stdio.h>

#include "15_3_Quote.h"
#include "15_5-7_Bulk_Quote.h"


double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);

    os << "ISBN: " << item.isbn() << "# sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

int main() {
    Quote q("textbook", 10.6);
    Bulk_Quote bq("textbook", 10.6, 10, 0.3);
    print_total(std::cout, q, 12);
    print_total(std::cout, bq, 12);
    return 0;
}
 
 