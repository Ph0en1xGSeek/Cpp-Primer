#include <bits/stdc++.h>

class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos _width, pos _height): width(_width), height(_height), content(_width*_height, ' ') {}
    Screen(pos _width, pos _height, char c): width(_width), height(_height), content(_width*_height, c) {}

    char get() const {return content[cursor];}
    char get(pos row, pos c) const {return content[row * width + c];}

private:
    pos width = 0;
    pos height = 0;
    pos cursor = 0;
    std::string content = "";
};

int main() {
    Screen scr = Screen(2, 4, 'c');
    std::cout << "ssss" << scr.get() << "ssss" << std::endl;
    return 0;
}