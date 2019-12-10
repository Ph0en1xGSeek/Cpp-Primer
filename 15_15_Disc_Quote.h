#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "15_3_Quote.h"

class Disc_quote: public Quote {
public:
    Disc_quote();
    Disc_quote(const std::string& b, double p, size_t q, double d):
        Quote(b, p), quantity(q), discount(d) {}
    // pure virtual
    virtual double net_price(size_t n) const override = 0;
protected:
    size_t quantity;
    double discount;
};

#endif