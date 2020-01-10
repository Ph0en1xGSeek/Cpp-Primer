#include <typeinfo>
#include <iostream>

class Screen {
public:
    typedef std::string::size_type pos;

    static const std::string Screen::*data() {return &Screen::contents;}
    static const pos Screen::*pcursor() {return &Screen::cursor;}

    Screen(): contents("default"), cursor(0) {}

    char get_cursor() const {return contents[cursor];}
    char get() const;
    char get(pos ht, pos wd) const;

private:
    std::string contents;
    pos cursor;
    pos height, width;
};

int main()
{
    const std::string Screen::*pdata = Screen::data();
    Screen myscreen;
    auto s = myscreen.*pdata;
    std::cout << s << std::endl;

    const Screen::pos Screen::*pc = Screen::pcursor();
    auto c = myscreen.*pc;
    std::cout << c << std::endl;
	return 0;
}