#ifndef BULK_QUOTE
#define BULK_QUOTE

#include <stdio.h>
#include "15_3_Quote.h"


class Bulk_Quote: public Quote {
public:
    Bulk_Quote() = default;
    Bulk_Quote(const std::string &b, double p, size_t q, double disc) :Quote(b, p), min_qty(q), discount(disc) {}
    double net_price(size_t n) const override;
private:
    size_t min_qty = 0;
    double discount = 0.0;
};


double Bulk_Quote::net_price(size_t n) const {
    return n * price * (n >= min_qty? 1 - discount: 1);
}

#endif