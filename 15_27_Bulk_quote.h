#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "15_15_Disc_Quote.h"

class Bulk_quote: public Disc_quote {
public:
    Bulk_quote() {
        std::cout << "Bulk_quote default contructor" << std::endl;
    };
    using Disc_quote::Dis_quote;
    // Bulk_quote(const std::string &b, double p, size_t q, double disc) :
    //     Disc_quote(b, p, q, disc) {}
    //copy
    Bulk_quote(const Bulk_quote &bq): Disc_quote(bq) {
        std::cout << "Bulk_quote copy constructor" << std::endl;
    }

    //move
    Bulk_quote(Bulk &&bq): Disc_quote(std::move(bq)) {
        std::cout << "Bulk_quote move constructor" << std::endl;
    }

    // copy=
    Bulk_quote & operator=(const Bulk_quote & rhs) {
        Disc_quote::operator=(rhs);
        std::cout << "Bulk_quote copy=" << std::endl;
        return *this;
    }

    Bulk_quote & operator=(Bulk_quote && rhs) {
        Disc_quote::operator=(std::move(rhs));
        std::cout << "Bulk_quote move=" << std::endl;
        return *this;
    }

    double net_price(size_t n) const override;

    ~Bulk_quote() override {
        std::cout << "Bulk_quote destructor" << std::endl;
    }
};

double Bulk_quote::net_price(size_t n) const {
    return n * price * (n >= quantity? 1 - discount: 1);
}

#endif