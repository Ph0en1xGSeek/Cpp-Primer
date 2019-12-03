#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

void println(vector<string> &vec){
    for(auto item: vec) {
        cout << item << ' ';
    }
    cout << endl;
}

class ShorterString {
public:
    bool operator()(const string &a, const string &b) const {
        return a.size() < b.size();
    }
};

class BiggerEqual {
    size_t sz_;
public:
    BiggerEqual(size_t sz): sz_(sz) {}
    bool operator()(const string &s) {
        return s.size() >= sz_;
    }
};

class Print {
public:
    void operator()(const string &s) {
        cout << s << " ";
    }
};

void elimDups(vector<string> &vec) {
    stable_sort(vec.begin(), vec.end());
    unique(vec.begin(), vec.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    ShorterString ss;
    BiggerEqual be(sz);
    Print pt;
    elimDups(words);
    println(words);
    stable_sort(words.begin(), words.end(), ss);
    println(words);
    auto wc = partition(words.begin(), words.end(), be);
    for_each(words.begin(), wc, pt);
    cout << endl;
}

void biggies_stable(vector<string> &words, vector<string>::size_type sz) {
    ShorterString ss;
    BiggerEqual be(sz);
    Print pt;
    elimDups(words);
    println(words);
    stable_sort(words.begin(), words.end(), ss);
    println(words);
    auto wc = stable_partition(words.begin(), words.end(), be);
    for_each(words.begin(), wc, pt);
    cout << endl;
}


int main() {
    vector<string> vec = {"aaa", "b", "b", "ccdccccc", "sdfjhsdgf", "aaa", "dfdfdd", "abcs"};
    println(vec);
    biggies_stable(vec, 4);
}
 
 