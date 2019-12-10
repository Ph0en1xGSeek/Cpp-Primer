#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "15_15_Disc_Quote.h"

class Bulk_quote: public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &b, double p, size_t q, double disc) :
        Disc_quote(b, p, q, disc) {}
    double net_price(size_t n) const override;
};

double Bulk_quote::net_price(size_t n) const {
    return n * price * (n >= quantity? 1 - discount: 1);
}

#endif