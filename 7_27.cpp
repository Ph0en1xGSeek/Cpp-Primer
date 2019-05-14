#include <bits/stdc++.h>

class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos _width, pos _height): width(_width), height(_height), contents(_width*_height, ' ') {}
    Screen(pos _width, pos _height, char c): width(_width), height(_height), contents(_width*_height, c) {}

    char get() const {return contents[cursor];}
    char get(pos r, pos c) const {return contents[r * width + c];}

    inline Screen &move(pos r, pos c);
    inline Screen &set(char c);
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    };
    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    };

private:
    void do_display(std::ostream &os) const{
        os << contents;
    }

private:
    pos width = 0;
    pos height = 0;
    pos cursor = 0;
    std::string contents = "";

};

inline Screen &Screen::move(pos r, pos c){
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << std::endl;
    myScreen.display(std::cout);
    std::cout << std::endl;
    return 0;
}