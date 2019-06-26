#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <forward_list>
#include <list>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std::placeholders;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void println(vector<string> &vec){
    for(auto item: vec) {
        cout << item << ' ';
    }
    cout << endl;
}

bool check_size(const string &str, size_t sz) {
    return str.size() > sz;
}

void elimDups(vector<string> &vec) {
    stable_sort(vec.begin(), vec.end());
    auto end_unique = unique(vec.begin(), vec.end());
    vec.erase(end_unique, vec.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    println(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) -> bool {
        return a.size() < b.size();
    });
    println(words);
    auto wc = partition(words.begin(), words.end(), bind(check_size, _1, 2));
    for_each(words.begin(), wc, 
        [](const string & s){
            cout << s << " ";
        });
    cout << endl;
}

int main() {
    vector<string> vec = {"aaa", "b", "b", "ccdccccc", "sdfjhsdgf", "aaa", "dfdfdd", "abcs"};
    println(vec);
    biggies(vec, 4);
}
 
 