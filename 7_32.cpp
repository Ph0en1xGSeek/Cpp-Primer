#include <bits/stdc++.h>

class Screen;

//1. define Window_mgr and declare Window_mgr::clear first 
//(cannot be defined because cannot use Screen right now)
class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    inline void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};

//2. define Screen and declare Window_mgr::clear as friend 
class Screen {
public:
    friend void Window_mgr::clear(ScreenIndex);
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

//3. define Window_mgr::clear
inline void Window_mgr::clear(ScreenIndex i) {
    if(i >= screens.size() || i < 0)
        return;
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

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