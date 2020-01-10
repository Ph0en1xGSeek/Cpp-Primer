#include <typeinfo>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

class Token {
public:
    Token(): tok(INT), ival(0) {}
    Token(const Token &t): tok(t.tok) {copyUnion(t);}
    Token(const Token &&t) noexcept : tok(t.tok){
        std::cout << "Token(Token &&) onexcept" << std::endl;
        switch (t.tok) {
            case Token::INT: ival = t.ival; break;
            case Token::DBL: dval = t.dval; break;
            case Token::CHAR: cval = t.cval; break;
            case Token::STR: sval = t.sval; break; // move
        }
    }
    ~Token() {
        if(tok == STR) {
            sval.std::string::~string();
        }
    }
    Token &operator=(const Token &t);
    Token &operator=(const Token &&t) noexcept;
    Token &operator=(const std::string &s);
    Token &operator=(int);
    Token &operator=(char);
    Token &operator=(double);

private:
    enum {INT, CHAR, DBL, STR} tok;
    union {
        char cval;
        int ival;
        double dval;
        std::string sval;
    };

    void copyUnion(const Token&);
};

Token &Token::operator=(int i) {
    if(tok == STR)
        sval.std::string::~string();
    tok = INT;
    ival = i;
    return *this;
}

Token &Token::operator=(double d) {
    if(tok == STR) 
        sval.std::string::~string();
    tok = DBL;
    dval = d;
    return *this;
}

Token &Token::operator=(char c) {
    if(tok == STR)
        sval.std::string::~string();
    tok = CHAR;
    cval = c;
    return *this;
}

Token &Token::operator=(const std::string& s) {
    if(tok == STR)
        sval = s;
    else
        new(&sval) std::string(s);
    tok = STR;
    return *this;
}

Token &Token::operator=(const Token &t) {
    if(tok == STR && t.tok != STR) {
        sval.std::string::~string();
    }
    if(tok == STR && t.tok == STR) {
        sval = t.sval;
    }else {
        copyUnion(t);
    }
    tok = t.tok;
    return *this;
}

Token &Token::operator=(const Token &&t) noexcept{
    std::cout << "Token::operator=(const Token &&t) noexcept" << std::endl;
    switch (t.tok) {
        case Token::INT: ival = t.ival; break;
        case Token::DBL: dval = t.dval; break;
        case Token::CHAR: cval = t.cval; break;
        case Token::STR: sval = t.sval; break;
    }
    return *this;
}

void Token::copyUnion(const Token &t) {
    switch (t.tok) {
        case Token::INT: ival = t.ival; break;
        case Token::DBL: dval = t.dval; break;
        case Token::CHAR: cval = t.cval; break;
        case Token::STR: new(&sval) std::string(t.sval); break;
    }
}

int main()
{
    
	return 0;
}